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

// TinyCADDoc.cpp : CTinyCADDoc ���ʵ��
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
	// ����Ĭ�ϵ� OLE ����ʵ��
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

// ע��: ��������˶� IID_ITinyCAD ��֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {FF8C90A9-C1B5-4F32-9A78-D4B5DBC6AF7D}
static const IID IID_ITinyCAD =
{ 0xFF8C90A9, 0xC1B5, 0x4F32, { 0x9A, 0x78, 0xD4, 0xB5, 0xDB, 0xC6, 0xAF, 0x7D } };

BEGIN_INTERFACE_MAP(CTinyCADDoc, COleServerDoc)
	INTERFACE_PART(CTinyCADDoc, IID_ITinyCAD, Dispatch)
END_INTERFACE_MAP()


// CTinyCADDoc ����/����

CTinyCADDoc::CTinyCADDoc()
{
	// ʹ�� OLE �����ļ�
	EnableCompoundFile();

	// TODO: �ڴ����һ���Թ������

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

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}


// CTinyCADDoc ������ʵ��

COleServerItem* CTinyCADDoc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem �ɿ�ܵ����Ի�ȡ����ĵ������� COleServerItem��
	//  ֻ�ڱ�Ҫʱ�ŵ�������

	CTinyCADSrvrItem* pItem = new CTinyCADSrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}


// CTinyCADDoc ��ĵ�������ʵ��

CDocObjectServer *CTinyCADDoc::GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite)
{
	return new CDocObjectServer(this, pDocSite);
}




// CTinyCADDoc ���л�

void CTinyCADDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}

	// ���û��� COleServerDoc ������
	//  �����ĵ��� COleClientItem ��������л���
	COleServerDoc::Serialize(ar);
	// �����һ��
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


// CTinyCADDoc ���

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


// CTinyCADDoc ����
