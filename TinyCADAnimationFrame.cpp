// TinyCADAnimationFrame.cpp : 实现文件
//

#include "stdafx.h"
#include "TinyCAD.h"
#include "TinyCADAnimationFrame.h"


// CTinyCADAnimationFrame

IMPLEMENT_DYNCREATE(CTinyCADAnimationFrame, CFrameWndEx)

CTinyCADAnimationFrame::CTinyCADAnimationFrame()
{

	EnableAutomation();
}

CTinyCADAnimationFrame::~CTinyCADAnimationFrame()
{
}

void CTinyCADAnimationFrame::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CFrameWndEx::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CTinyCADAnimationFrame, CFrameWndEx)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CTinyCADAnimationFrame, CFrameWndEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_ITinyCADAnimationFrame 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {B501F7A9-9765-4C33-B0C6-252A688D100C}
static const IID IID_ITinyCADAnimationFrame =
{ 0xB501F7A9, 0x9765, 0x4C33, { 0xB0, 0xC6, 0x25, 0x2A, 0x68, 0x8D, 0x10, 0xC } };

BEGIN_INTERFACE_MAP(CTinyCADAnimationFrame, CFrameWndEx)
	INTERFACE_PART(CTinyCADAnimationFrame, IID_ITinyCADAnimationFrame, Dispatch)
END_INTERFACE_MAP()


// CTinyCADAnimationFrame 消息处理程序
