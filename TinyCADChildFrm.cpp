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

// TinyCADChildFrm.cpp : CTinyCADChildFrame 类的实现
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

// CTinyCADChildFrame 构造/析构

CTinyCADChildFrame::CTinyCADChildFrame()
:m_pDrawEngine(NULL)
{
	// TODO: 在此添加成员初始化代码
}

CTinyCADChildFrame::~CTinyCADChildFrame()
{
}

BOOL CTinyCADChildFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	return m_wndSplitter.Create(this,
		2, 2,			// TODO: 调整行数和列数
		CSize(10, 10),	// TODO: 调整最小窗格大小
		pContext);
}

BOOL CTinyCADChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CTinyCADChildFrame 诊断

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

// CTinyCADChildFrame 消息处理程序

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
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_CLOSE);  // 强制关闭“打印预览”模式
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

	// TODO:  在此添加您专用的创建代码
	m_pDrawEngine = new CTinyCADDrawEngine;

	return 0;
}
