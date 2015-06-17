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

// TinyCADDoc.cpp : CTinyCADDoc 类的实现
//

#include "stdafx.h"
#include "TinyCAD.h"

#include "TinyCADDoc.h"
#include "TinyCADCntrItem.h"
#include "TinyCADSrvrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTinyCADDoc

IMPLEMENT_DYNCREATE(CTinyCADDoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CTinyCADDoc, COleServerDoc)
	// 启用默认的 OLE 容器实现
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, &COleServerDoc::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, &COleServerDoc::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, &COleServerDoc::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, &COleServerDoc::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &COleServerDoc::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &COleServerDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &COleServerDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CTinyCADDoc, COleServerDoc)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_ITinyCAD 的支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {FF8C90A9-C1B5-4F32-9A78-D4B5DBC6AF7D}
static const IID IID_ITinyCAD =
{ 0xFF8C90A9, 0xC1B5, 0x4F32, { 0x9A, 0x78, 0xD4, 0xB5, 0xDB, 0xC6, 0xAF, 0x7D } };

BEGIN_INTERFACE_MAP(CTinyCADDoc, COleServerDoc)
	INTERFACE_PART(CTinyCADDoc, IID_ITinyCAD, Dispatch)
END_INTERFACE_MAP()


// CTinyCADDoc 构造/析构

CTinyCADDoc::CTinyCADDoc()
{
	// 使用 OLE 复合文件
	EnableCompoundFile();

	// TODO: 在此添加一次性构造代码

	EnableAutomation();

	AfxOleLockApp();
}

CTinyCADDoc::~CTinyCADDoc()
{
	AfxOleUnlockApp();
}

BOOL CTinyCADDoc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}


// CTinyCADDoc 服务器实现

COleServerItem* CTinyCADDoc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem 由框架调用以获取与该文档关联的 COleServerItem。
	//  只在必要时才调用它。

	CTinyCADSrvrItem* pItem = new CTinyCADSrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}


// CTinyCADDoc 活动文档服务器实现

CDocObjectServer *CTinyCADDoc::GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite)
{
	return new CDocObjectServer(this, pDocSite);
}




// CTinyCADDoc 序列化

void CTinyCADDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}

	// 调用基类 COleServerDoc 将启用
	//  容器文档的 COleClientItem 对象的序列化。
	COleServerDoc::Serialize(ar);
	// 激活第一个
	if (!ar.IsStoring())
	{
		POSITION posItem = GetStartPosition();
		if (posItem != NULL)
		{
			CDocItem* pItem = GetNextItem(posItem);
			POSITION posView = GetFirstViewPosition();
			COleDocObjectItem *pDocObjectItem = DYNAMIC_DOWNCAST(COleDocObjectItem, pItem);
			if (posView != NULL && pDocObjectItem != NULL)
			{
				CView* pView = GetNextView(posView);
				pDocObjectItem->DoVerb(OLEIVERB_SHOW, pView);
			}
		}
	}
}


// CTinyCADDoc 诊断

#ifdef _DEBUG
void CTinyCADDoc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void CTinyCADDoc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);
}
#endif //_DEBUG


// CTinyCADDoc 命令
