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

// TinyCADSrvrItem.cpp : CTinyCADSrvrItem ���ʵ��
//

#include "stdafx.h"
#include "TinyCAD.h"

#include "TinyCADDoc.h"
#include "TinyCADSrvrItem.h"
#include "TinyCADCntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTinyCADSrvrItem ʵ��

IMPLEMENT_DYNAMIC(CTinyCADSrvrItem, CDocObjectServerItem)

CTinyCADSrvrItem::CTinyCADSrvrItem(CTinyCADDoc* pContainerDoc)
	: CDocObjectServerItem(pContainerDoc, TRUE)
{
	// TODO: �ڴ����һ���Թ������
	//  (�罫���Ӽ������ʽ��ӵ��������Դ��)
}

CTinyCADSrvrItem::~CTinyCADSrvrItem()
{
	// TODO: �ڴ˴�����������
}

void CTinyCADSrvrItem::Serialize(CArchive& ar)
{
	// ���������Ƶ��������У����ܽ����� CTinyCADSrvrItem::Serialize��
	//  �����
	//  ͨ�� OLE �ص� OnGetClipboardData ���Զ�ִ�С�
	//  ����Ƕ���Ĭ�����ֱ��ί�и��ĵ��� Serialize ������
	//  ���֧�����ӣ���ֻ�����л�
	//  �ĵ���һ���֡�

	if (!IsLinkedItem())
	{
		CTinyCADDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (pDoc)
			pDoc->Serialize(ar);
	}
}

BOOL CTinyCADSrvrItem::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
	// �����������Ƶ�Ӧ�ó���ֻ�Ի����������
	//  ������д������ϣ��֧���������棬��
	//  DVASPECT_THUMBNAIL (ͨ����д OnDrawEx)����Ӧ�޸�
	//  OnGetExtent �Ĵ�ʵ���Դ���
	//  �������档

	if (dwDrawAspect != DVASPECT_CONTENT)
		return CDocObjectServerItem::OnGetExtent(dwDrawAspect, rSize);

	// ���� CTinyCADSrvrItem::OnGetExtent �Ա��ȡ�������
	//  HIMETRIC ��Ԫ��ʾ�ķ�Χ���˴���Ĭ��ʵ��
	//  ֻ���ص�Ԫ��Ӳ�������֡�

	// TODO: �滻�������С

	rSize = CSize(3000, 3000);   // 3000 x 3000 HIMETRIC ��Ԫ

	return TRUE;
}

BOOL CTinyCADSrvrItem::OnDraw(CDC* pDC, CSize& rSize)
{
	if (!pDC)
		return FALSE;

	// ���ʹ�� rSize���򽫴��Ƴ�
	UNREFERENCED_PARAMETER(rSize);

	// TODO: ����ӳ��ģʽ�ͷ�Χ
	//  (�˷�Χͨ����� OnGetExtent ���صĴ�С��ͬ)
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowOrg(0,0);
	pDC->SetWindowExt(3000, 3000);

	// TODO: �ڴ˴���ӻ��ƴ��롣Ҳ������� HIMETRIC ��Χ��
	//  ���л��ƶ�����ͼԪ�ļ��豸������(pDC)�н��С�

	// TODO: ͬʱ����Ƕ��� CTinyCADCntrItem ����

	// ���´��뽫������λ�û��Ƶ�һ���

	// TODO: ��������Ļ��ƴ���󣬽��Ƴ��˴���

	CTinyCADDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return FALSE;

	POSITION pos = pDoc->GetStartPosition();
	CTinyCADCntrItem* pItem = DYNAMIC_DOWNCAST(CTinyCADCntrItem, pDoc->GetNextClientItem(pos));
	if (pItem != NULL)
		pItem->Draw(pDC, CRect(10, 10, 1010, 1010));
	return TRUE;
}


// CTinyCADSrvrItem ���

#ifdef _DEBUG
void CTinyCADSrvrItem::AssertValid() const
{
	CDocObjectServerItem::AssertValid();
}

void CTinyCADSrvrItem::Dump(CDumpContext& dc) const
{
	CDocObjectServerItem::Dump(dc);
}
#endif

