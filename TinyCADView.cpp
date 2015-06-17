// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// TinyCADView.cpp : CTinyCADView ���ʵ��
//

#include "stdafx.h"
#include "TinyCAD.h"

#include "TinyCADDoc.h"
#include "TinyCADCntrItem.h"
#include "TinyCADView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTinyCADView

IMPLEMENT_DYNCREATE(CTinyCADView, CTinyCADZoomView)

BEGIN_MESSAGE_MAP(CTinyCADView, CTinyCADZoomView)
	ON_WM_DESTROY()
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, &CTinyCADView::OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, &CTinyCADView::OnCancelEditCntr)
	ON_COMMAND(ID_FILE_PRINT, &CTinyCADView::OnFilePrint)
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, &CTinyCADView::OnCancelEditSrvr)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CTinyCADZoomView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTinyCADView::OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, &OnFilePrintPreviewUIUpdate)
END_MESSAGE_MAP()

// CTinyCADView ����/����

CTinyCADView::CTinyCADView()
{
	m_pSelection = NULL;
	// TODO: �ڴ˴���ӹ������

}

CTinyCADView::~CTinyCADView()
{
}

BOOL CTinyCADView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CTinyCADZoomView::PreCreateWindow(cs);
}

// CTinyCADView ����

void CTinyCADView::OnDraw(CDC* /*pDC*/)
{
	CTinyCADDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}
void CTinyCADView::OnInitialUpdate()
{
	CTinyCADZoomView::OnInitialUpdate();


	// TODO: д������ѡ��ģʽ����֮���Ƴ��˴���
	m_pSelection = NULL;    // ��ʼ��ѡ������

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CTinyCADView ��ӡ

void CTinyCADView::OnFilePrintPreviewUIUpdate(CCmdUI* pCmdUI)
{
	if (!pCmdUI)
		return;

	if (m_pSelection != NULL)
	{
		DWORD dwStatus = 0;
		if (SUCCEEDED(m_pSelection->QueryCommand(OLECMDID_PRINTPREVIEW, &dwStatus)) &&
			dwStatus & OLECMDF_ENABLED)
		{
				pCmdUI->Enable(TRUE);
				return;
		}
	}
	pCmdUI->Enable(FALSE);
}

void CTinyCADView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CTinyCADView::OnPreparePrinting(CPrintInfo* pInfo)
{
	if (!CView::DoPreparePrinting(pInfo))
		return FALSE;
	
	if (!COleDocObjectItem::OnPreparePrinting(this, pInfo))
		return FALSE;

	return TRUE;
}

void CTinyCADView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTinyCADView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CTinyCADView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: �ڴ˴�����Զ����ӡ����
	if(pInfo->m_bDocObject)
		COleDocObjectItem::OnPrint(this, pInfo, TRUE);
	else
		CView::OnPrint(pDC, pInfo);
}

void CTinyCADView::OnDestroy()
{
	// ����ʱͣ�ô������
	// ʹ�ò����ͼʱ�ǳ���Ҫ 
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CTinyCADZoomView::OnDestroy();
}



// OLE �ͻ���֧�ֺ�����

BOOL CTinyCADView::IsSelected(const CObject* pDocItem) const
{
	// ���ѡ������ֻ����
	//  CTinyCADCntrItem ����������ʵ�־��㹻�ˡ���Ҫ��������ѡ����ƣ�
	//  ��Ӧ�滻�˴���ʵ��

	// TODO: ʵ�ֶ���ѡ OLE �ͻ�������в��Եĺ���

	return pDocItem == m_pSelection;
}

void CTinyCADView::OnInsertObject()
{
	// ���ñ�׼�ġ�������󡱶Ի����Ի���й�
	//  �� CTinyCADCntrItem �������Ϣ
	COleInsertDialog dlg;
	if (dlg.DoModal(COleInsertDialog::DocObjectsOnly) != IDOK)
		return;

	BeginWaitCursor();

	CTinyCADCntrItem* pItem = NULL;
	TRY
	{
		// ��������ĵ������ӵ�����
		CTinyCADDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CTinyCADCntrItem(pDoc);
		ASSERT_VALID(pItem);

		// ͨ���Ի������ݳ�ʼ������
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // �κ��쳣�������¸ý��
		ASSERT_VALID(pItem);
		
		pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);
		// ��Ϊ�����û�������ƣ���Ὣѡ������
		//  ����Ϊ��������һ��

		// TODO: ����ʵ��ѡ�����ݣ�ʹ���ʺ�������Ӧ�ó���
		m_pSelection = pItem;   // ��ѡ����������Ϊ��������һ��
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// �������������ṩ�˱�׼����
//  �û�������ȡ���͵ر༭�Ự���˴���
//  ����(�����Ƿ�����)������ͣ��
void CTinyCADView::OnCancelEditCntr()
{
	// �رմ���ͼ�е��κξ͵ػ�
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// �ھ͵ر༭һ������ʱ��������Ҫ�� OnSetFocus �� OnSize 
//  �������⴦��
void CTinyCADView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// ��������ͬһ��ͼ�У�����Ҫ���������õ�����
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // ��Ҫ���û���
			return;
		}
	}

	CTinyCADZoomView::OnSetFocus(pOldWnd);
}

void CTinyCADView::OnSize(UINT nType, int cx, int cy)
{
	CTinyCADZoomView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

void CTinyCADView::OnFilePrint()
{
	//Ĭ������£�Ҫ���ĵ�ʹ�� IOleCommandTarget ��ӡ����
	//�������Ҫ����Ϊ��
	//���Ƴ��� COleDocObjectItem::DoDefaultPrinting ���á�
	//�������ĳ��ԭ�����ʧ�ܣ��򽫳���ʹ�� IPrint �ӿڴ�ӡ
	//���ĵ�����
	CPrintInfo printInfo;
	ASSERT(printInfo.m_pPD != NULL); 
	if (S_OK == COleDocObjectItem::DoDefaultPrinting(this, &printInfo))
		return;
	
	CView::OnFilePrint();

}


void CTinyCADView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTinyCADView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}

// OLE ������֧��

// �������������ṩ�˱�׼����
//  �û�������ȡ���͵ر༭�Ự���˴���
//  ������(����������)������ͣ��
void CTinyCADView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}


// CTinyCADView ���

#ifdef _DEBUG
void CTinyCADView::AssertValid() const
{
	CTinyCADZoomView::AssertValid();
}

void CTinyCADView::Dump(CDumpContext& dc) const
{
	CTinyCADZoomView::Dump(dc);
}

CTinyCADDoc* CTinyCADView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTinyCADDoc)));
	return (CTinyCADDoc*)m_pDocument;
}
#endif //_DEBUG


// CTinyCADView ��Ϣ�������
