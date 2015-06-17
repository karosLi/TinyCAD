// TinyCADErrorOutput.cpp : 实现文件
//

#include "stdafx.h"
#include "TinyCAD.h"
#include "TinyCADErrorOutput.h"


// CTinyCADErrorOutput

IMPLEMENT_DYNAMIC(CTinyCADErrorOutput, CListBox)

CTinyCADErrorOutput::CTinyCADErrorOutput()
{

	EnableAutomation();
}

CTinyCADErrorOutput::~CTinyCADErrorOutput()
{
}

void CTinyCADErrorOutput::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CListBox::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CTinyCADErrorOutput, CListBox)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CTinyCADErrorOutput, CListBox)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_ITinyCADErrorOutput 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {A31C5A0D-1923-42DD-BD75-DF36C3120919}
static const IID IID_ITinyCADErrorOutput =
{ 0xA31C5A0D, 0x1923, 0x42DD, { 0xBD, 0x75, 0xDF, 0x36, 0xC3, 0x12, 0x9, 0x19 } };

BEGIN_INTERFACE_MAP(CTinyCADErrorOutput, CListBox)
	INTERFACE_PART(CTinyCADErrorOutput, IID_ITinyCADErrorOutput, Dispatch)
END_INTERFACE_MAP()


// CTinyCADErrorOutput 消息处理程序


