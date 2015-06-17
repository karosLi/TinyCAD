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

// TinyCADIpFrame.cpp : CTinyCADInPlaceFrame ���ʵ��
//

#include "stdafx.h"
#include "TinyCAD.h"

#include "TinyCADIpFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTinyCADInPlaceFrame

IMPLEMENT_DYNCREATE(CTinyCADInPlaceFrame, COleDocIPFrameWndEx)

BEGIN_MESSAGE_MAP(CTinyCADInPlaceFrame, COleDocIPFrameWndEx)
	ON_WM_CREATE()
	// ȫ�ְ�������
	ON_COMMAND(ID_HELP_FINDER, &COleDocIPFrameWndEx::OnHelpFinder)
	ON_COMMAND(ID_HELP, &COleDocIPFrameWndEx::OnHelp)
	ON_COMMAND(ID_DEFAULT_HELP, &COleDocIPFrameWndEx::OnHelpFinder)
	ON_COMMAND(ID_CONTEXT_HELP, &COleDocIPFrameWndEx::OnContextHelp)
END_MESSAGE_MAP()


// CTinyCADInPlaceFrame ����/����

CTinyCADInPlaceFrame::CTinyCADInPlaceFrame()
{
}

CTinyCADInPlaceFrame::~CTinyCADInPlaceFrame()
{
}

int CTinyCADInPlaceFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleDocIPFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// CResizeBar ʵ�־͵ص�����С��
	if (!m_wndResizeBar.Create(this))
	{
		TRACE0("δ�ܴ�����С������\n");
		return -1;      // δ�ܴ���
	}

	// Ĭ������£����ע��һ�����ܴ���
	//  �޹صķ���Ŀ�ꡣ�⽫��ֹ
	//  �ϷŶ��󡰴����֧���Ϸŵ������С�
	m_dropTarget.Register(this);

	return 0;
}

// ��ܽ����� OnCreateControlBars �Ա���
//  ����Ӧ�ó���Ĵ����ϴ����ؼ�����pWndFrame �������Ķ�����ܴ��ڣ�
//  ����ʼ�ղ�Ϊ NULL��pWndDoc ���ĵ�����ܴ��ڣ�
//  ������������ SDI Ӧ�ó���ʱΪ NULL��
//  ������Ӧ�ó�����Խ� MFC �ؼ������������������е��κ�һ���ϡ�
BOOL CTinyCADInPlaceFrame::OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc)
{
	// ���ʹ�� pWndDoc���򽫴��Ƴ�
	UNREFERENCED_PARAMETER(pWndDoc);

	// ���ô˴��ڵ������ߣ��Ա㽫��Ϣ���͵���ȷ��Ӧ�ó���
	m_wndToolBar.SetOwner(this);

	// �ڿͻ��˵Ŀ�ܴ����ϴ���������
	if (!m_wndToolBar.CreateEx(pWndFrame, TBSTYLE_FLAT,WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_TinyCADTYPE_SRVR_IP))
	{
		TRACE0("δ�ܴ���������\n");
		return FALSE;
	}

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->DockControlBar(&m_wndToolBar);

	return TRUE;
}

BOOL CTinyCADInPlaceFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ

	return COleDocIPFrameWndEx::PreCreateWindow(cs);
}


// CTinyCADInPlaceFrame ���

#ifdef _DEBUG
void CTinyCADInPlaceFrame::AssertValid() const
{
	COleDocIPFrameWndEx::AssertValid();
}

void CTinyCADInPlaceFrame::Dump(CDumpContext& dc) const
{
	COleDocIPFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CTinyCADInPlaceFrame ����

