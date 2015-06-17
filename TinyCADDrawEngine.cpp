// TinyCADDrawEngine.cpp : 实现文件
//

#include "stdafx.h"
#include "TinyCAD.h"
#include "TinyCADDrawEngine.h"


// CTinyCADDrawEngine

IMPLEMENT_DYNAMIC(CTinyCADDrawEngine, CCmdTarget)


CTinyCADDrawEngine::CTinyCADDrawEngine()
{
	EnableAutomation();
}

CTinyCADDrawEngine::~CTinyCADDrawEngine()
{
}


void CTinyCADDrawEngine::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CTinyCADDrawEngine, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CTinyCADDrawEngine, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_ITinyCADDrawEngine 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {2521FC3C-70C2-4066-A7D9-8BF5F78044FB}
static const IID IID_ITinyCADDrawEngine =
{ 0x2521FC3C, 0x70C2, 0x4066, { 0xA7, 0xD9, 0x8B, 0xF5, 0xF7, 0x80, 0x44, 0xFB } };

BEGIN_INTERFACE_MAP(CTinyCADDrawEngine, CCmdTarget)
	INTERFACE_PART(CTinyCADDrawEngine, IID_ITinyCADDrawEngine, Dispatch)
END_INTERFACE_MAP()


// CTinyCADDrawEngine 消息处理程序
