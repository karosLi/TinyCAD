// TinyCADZoomView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TinyCAD.h"
#include "TinyCADZoomView.h"


// CTinyCADZoomView

IMPLEMENT_DYNCREATE(CTinyCADZoomView, CScrollView)

CTinyCADZoomView::CTinyCADZoomView()
:m_fScale(1.0f)
{

	EnableAutomation();
}

CTinyCADZoomView::~CTinyCADZoomView()
{
}

void CTinyCADZoomView::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CScrollView::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CTinyCADZoomView, CScrollView)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CTinyCADZoomView, CScrollView)
END_DISPATCH_MAP()

// ע��: ������� IID_ITinyCADZoomView ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {A7758C35-992B-4A45-A61B-DBFFDBD3836B}
static const IID IID_ITinyCADZoomView =
{ 0xA7758C35, 0x992B, 0x4A45, { 0xA6, 0x1B, 0xDB, 0xFF, 0xDB, 0xD3, 0x83, 0x6B } };

BEGIN_INTERFACE_MAP(CTinyCADZoomView, CScrollView)
	INTERFACE_PART(CTinyCADZoomView, IID_ITinyCADZoomView, Dispatch)
END_INTERFACE_MAP()


// CTinyCADZoomView ��ͼ

void CTinyCADZoomView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CTinyCADZoomView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
}


// CTinyCADZoomView ���

#ifdef _DEBUG
void CTinyCADZoomView::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CTinyCADZoomView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
	dc << _T("CTinyCADZoomView(0x") << (DWORD)this << _T(") m_fScale = ") << m_fScale;
}
#endif
#endif //_DEBUG


void CTinyCADZoomView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: �ڴ����ר�ô����/����û���

	CScrollView::OnPrepareDC(pDC, pInfo);

	pDC->SetGraphicsMode(GM_ADVANCED);
	XFORM xForm = {};
	if (pDC->IsPrinting())
	{
		xForm.eM11 = 1.0f;
		xForm.eM22 = 1.0f;
	} 
	else
	{
		xForm.eM11 = m_fScale;
		xForm.eM22 = m_fScale;
	}

	

	pDC->SetWorldTransform(&xForm);

}
