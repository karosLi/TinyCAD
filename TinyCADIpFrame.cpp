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

// TinyCADIpFrame.cpp : CTinyCADInPlaceFrame 类的实现
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
	// 全局帮助命令
	ON_COMMAND(ID_HELP_FINDER, &COleDocIPFrameWndEx::OnHelpFinder)
	ON_COMMAND(ID_HELP, &COleDocIPFrameWndEx::OnHelp)
	ON_COMMAND(ID_DEFAULT_HELP, &COleDocIPFrameWndEx::OnHelpFinder)
	ON_COMMAND(ID_CONTEXT_HELP, &COleDocIPFrameWndEx::OnContextHelp)
END_MESSAGE_MAP()


// CTinyCADInPlaceFrame 构造/析构

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

	// CResizeBar 实现就地调整大小。
	if (!m_wndResizeBar.Create(this))
	{
		TRACE0("未能创建大小调整栏\n");
		return -1;      // 未能创建
	}

	// 默认情况下，最好注册一个与框架窗口
	//  无关的放置目标。这将防止
	//  拖放对象“错过”支持拖放的容器中。
	m_dropTarget.Register(this);

	return 0;
}

// 框架将调用 OnCreateControlBars 以便在
//  容器应用程序的窗口上创建控件条。pWndFrame 是容器的顶级框架窗口，
//  并且始终不为 NULL。pWndDoc 是文档级框架窗口，
//  并且在容器是 SDI 应用程序时为 NULL。
//  服务器应用程序可以将 MFC 控件条放在这两个窗口中的任何一个上。
BOOL CTinyCADInPlaceFrame::OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc)
{
	// 如果使用 pWndDoc，则将此移除
	UNREFERENCED_PARAMETER(pWndDoc);

	// 设置此窗口的所有者，以便将消息发送到正确的应用程序
	m_wndToolBar.SetOwner(this);

	// 在客户端的框架窗口上创建工具栏
	if (!m_wndToolBar.CreateEx(pWndFrame, TBSTYLE_FLAT,WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_TinyCADTYPE_SRVR_IP))
	{
		TRACE0("未能创建工具栏\n");
		return FALSE;
	}

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->DockControlBar(&m_wndToolBar);

	return TRUE;
}

BOOL CTinyCADInPlaceFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式

	return COleDocIPFrameWndEx::PreCreateWindow(cs);
}


// CTinyCADInPlaceFrame 诊断

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


// CTinyCADInPlaceFrame 命令

