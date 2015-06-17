// TinyCADCmdInput.cpp : 实现文件
//

#include "stdafx.h"
#include "TinyCAD.h"
#include "TinyCADCmdInput.h"


// CTinyCADCmdInput

IMPLEMENT_DYNAMIC(CTinyCADCmdInput, CEdit)

CTinyCADCmdInput::CTinyCADCmdInput()
{

	EnableAutomation();
}

CTinyCADCmdInput::~CTinyCADCmdInput()
{
}

void CTinyCADCmdInput::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CEdit::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CTinyCADCmdInput, CEdit)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CTinyCADCmdInput, CEdit)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_ITinyCADCmdInput 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {B31CC072-91FE-49ED-9D28-450D7DEB624B}
static const IID IID_ITinyCADCmdInput =
{ 0xB31CC072, 0x91FE, 0x49ED, { 0x9D, 0x28, 0x45, 0xD, 0x7D, 0xEB, 0x62, 0x4B } };

BEGIN_INTERFACE_MAP(CTinyCADCmdInput, CEdit)
	INTERFACE_PART(CTinyCADCmdInput, IID_ITinyCADCmdInput, Dispatch)
END_INTERFACE_MAP()


// CTinyCADCmdInput 消息处理程序


