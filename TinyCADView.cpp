// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// ("Fluent UI")，该示例仅作为参考资料提供， 
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://msdn.microsoft.com/officeui。
//
// 版权所有 (C) Microsoft Corporation
// 保留所有权利。

// TinyCADView.cpp : CTinyCADView 类的实现
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

// CTinyCADView 构造/析构

CTinyCADView::CTinyCADView()
{
	m_pSelection = NULL;
	// TODO: 在此处添加构造代码

}

CTinyCADView::~CTinyCADView()
{
}

BOOL CTinyCADView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CTinyCADZoomView::PreCreateWindow(cs);
}

// CTinyCADView 绘制

void CTinyCADView::OnDraw(CDC* /*pDC*/)
{
	CTinyCADDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}
void CTinyCADView::OnInitialUpdate()
{
	CTinyCADZoomView::OnInitialUpdate();


	// TODO: 写入最终选择模式代码之后移除此代码
	m_pSelection = NULL;    // 初始化选定内容

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CTinyCADView 打印

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
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTinyCADView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CTinyCADView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: 在此处添加自定义打印代码
	if(pInfo->m_bDocObject)
		COleDocObjectItem::OnPrint(this, pInfo, TRUE);
	else
		CView::OnPrint(pDC, pInfo);
}

void CTinyCADView::OnDestroy()
{
	// 析构时停用此项；这在
	// 使用拆分视图时非常重要 
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CTinyCADZoomView::OnDestroy();
}



// OLE 客户端支持和命令

BOOL CTinyCADView::IsSelected(const CObject* pDocItem) const
{
	// 如果选定内容只包括
	//  CTinyCADCntrItem 对象，则以下实现就足够了。若要处理其他选择机制，
	//  则应替换此处的实现

	// TODO: 实现对所选 OLE 客户端项进行测试的函数

	return pDocItem == m_pSelection;
}

void CTinyCADView::OnInsertObject()
{
	// 调用标准的“插入对象”对话框以获得有关
	//  新 CTinyCADCntrItem 对象的信息
	COleInsertDialog dlg;
	if (dlg.DoModal(COleInsertDialog::DocObjectsOnly) != IDOK)
		return;

	BeginWaitCursor();

	CTinyCADCntrItem* pItem = NULL;
	TRY
	{
		// 创建与此文档相连接的新项
		CTinyCADDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CTinyCADCntrItem(pDoc);
		ASSERT_VALID(pItem);

		// 通过对话框数据初始化该项
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // 任何异常都将导致该结果
		ASSERT_VALID(pItem);
		
		pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);
		// 作为任意用户界面设计，这会将选定内容
		//  设置为插入的最后一项

		// TODO: 重新实现选定内容，使其适合于您的应用程序
		m_pSelection = pItem;   // 将选定内容设置为插入的最后一项
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

// 以下命令处理程序提供了标准键盘
//  用户界面以取消就地编辑会话。此处，
//  容器(而不是服务器)将导致停用
void CTinyCADView::OnCancelEditCntr()
{
	// 关闭此视图中的任何就地活动项。
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// 在就地编辑一个对象时，容器需要对 OnSetFocus 和 OnSize 
//  进行特殊处理
void CTinyCADView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// 如果该项处于同一视图中，则需要将焦点设置到该项
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // 不要调用基类
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
	//默认情况下，要求活动文档使用 IOleCommandTarget 打印自身。
	//如果不需要此行为，
	//请移除对 COleDocObjectItem::DoDefaultPrinting 调用。
	//如果由于某种原因调用失败，则将尝试使用 IPrint 接口打印
	//该文档对象。
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

// OLE 服务器支持

// 以下命令处理程序提供了标准键盘
//  用户界面以取消就地编辑会话。此处，
//  服务器(而不是容器)将导致停用
void CTinyCADView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}


// CTinyCADView 诊断

#ifdef _DEBUG
void CTinyCADView::AssertValid() const
{
	CTinyCADZoomView::AssertValid();
}

void CTinyCADView::Dump(CDumpContext& dc) const
{
	CTinyCADZoomView::Dump(dc);
}

CTinyCADDoc* CTinyCADView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTinyCADDoc)));
	return (CTinyCADDoc*)m_pDocument;
}
#endif //_DEBUG


// CTinyCADView 消息处理程序
