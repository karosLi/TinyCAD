// TinyCADElementsDoc.cpp : 实现文件
//

#include "stdafx.h"
#include "TinyCAD.h"
#include "TinyCADElementsDoc.h"


// CTinyCADElementsDoc

IMPLEMENT_DYNCREATE(CTinyCADElementsDoc, CDocument)

CTinyCADElementsDoc::CTinyCADElementsDoc()
{
	EnableAutomation();
}

BOOL CTinyCADElementsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CTinyCADElementsDoc::~CTinyCADElementsDoc()
{
}

void CTinyCADElementsDoc::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDocument::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CTinyCADElementsDoc, CDocument)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CTinyCADElementsDoc, CDocument)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_ITinyCADElementsDoc 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {ED192CCD-6C6C-4FC7-8461-743BD3AC2046}
static const IID IID_ITinyCADElementsDoc =
{ 0xED192CCD, 0x6C6C, 0x4FC7, { 0x84, 0x61, 0x74, 0x3B, 0xD3, 0xAC, 0x20, 0x46 } };

BEGIN_INTERFACE_MAP(CTinyCADElementsDoc, CDocument)
	INTERFACE_PART(CTinyCADElementsDoc, IID_ITinyCADElementsDoc, Dispatch)
END_INTERFACE_MAP()


// CTinyCADElementsDoc 诊断

#ifdef _DEBUG
void CTinyCADElementsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CTinyCADElementsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CTinyCADElementsDoc 序列化

void CTinyCADElementsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}
#endif


// CTinyCADElementsDoc 命令
