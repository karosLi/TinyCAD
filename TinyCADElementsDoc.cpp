// TinyCADElementsDoc.cpp : ʵ���ļ�
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
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDocument::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CTinyCADElementsDoc, CDocument)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CTinyCADElementsDoc, CDocument)
END_DISPATCH_MAP()

// ע��: ������� IID_ITinyCADElementsDoc ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {ED192CCD-6C6C-4FC7-8461-743BD3AC2046}
static const IID IID_ITinyCADElementsDoc =
{ 0xED192CCD, 0x6C6C, 0x4FC7, { 0x84, 0x61, 0x74, 0x3B, 0xD3, 0xAC, 0x20, 0x46 } };

BEGIN_INTERFACE_MAP(CTinyCADElementsDoc, CDocument)
	INTERFACE_PART(CTinyCADElementsDoc, IID_ITinyCADElementsDoc, Dispatch)
END_INTERFACE_MAP()


// CTinyCADElementsDoc ���

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
// CTinyCADElementsDoc ���л�

void CTinyCADElementsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}
#endif


// CTinyCADElementsDoc ����
