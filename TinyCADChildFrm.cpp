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

// TinyCADChildFrm.cpp : CTinyCADChildFrame ���ʵ��
//

#include "stdafx.h"
#include "TinyCAD.h"

#include "TinyCADChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTinyCADChildFrame

IMPLEMENT_DYNCREATE(CTinyCADChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CTinyCADChildFrame, CMDIChildWndEx)
	ON_COMMAND(ID_FILE_PRINT, &CTinyCADChildFrame::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CTinyCADChildFrame::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTinyCADChildFrame::OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, &CTinyCADChildFrame::OnUpdateFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CTinyCADChildFrame ����/����

CTinyCADChildFrame::CTinyCADChildFrame()
:m_pDrawEngine(NULL)
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CTinyCADChildFrame::~CTinyCADChildFrame()
{
}

BOOL CTinyCADChildFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	return m_wndSplitter.Create(this,
		2, 2,			// TODO: ��������������
		CSize(10, 10),	// TODO: ������С�����С
		pContext);
}

BOOL CTinyCADChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CTinyCADChildFrame ���

#ifdef _DEBUG
void CTinyCADChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CTinyCADChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CTinyCADChildFrame ��Ϣ�������

void CTinyCADChildFrame::OnFilePrint()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_PRINT);
	}
}

void CTinyCADChildFrame::OnFilePrintPreview()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_CLOSE);  // ǿ�ƹرա���ӡԤ����ģʽ
	}
}

void CTinyCADChildFrame::OnUpdateFilePrintPreview(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_dockManager.IsPrintPreviewValid());
}

int CTinyCADChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIChildWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_pDrawEngine = new CTinyCADDrawEngine;

	return 0;
}
