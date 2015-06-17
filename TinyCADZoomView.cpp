// TinyCADZoomView.cpp : 实现文件
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
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CScrollView::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CTinyCADZoomView, CScrollView)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CTinyCADZoomView, CScrollView)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_ITinyCADZoomView 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {A7758C35-992B-4A45-A61B-DBFFDBD3836B}
static const IID IID_ITinyCADZoomView =
{ 0xA7758C35, 0x992B, 0x4A45, { 0xA6, 0x1B, 0xDB, 0xFF, 0xDB, 0xD3, 0x83, 0x6B } };

BEGIN_INTERFACE_MAP(CTinyCADZoomView, CScrollView)
	INTERFACE_PART(CTinyCADZoomView, IID_ITinyCADZoomView, Dispatch)
END_INTERFACE_MAP()


// CTinyCADZoomView 绘图

void CTinyCADZoomView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CTinyCADZoomView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
}


// CTinyCADZoomView 诊断

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
	// TODO: 在此添加专用代码和/或调用基类

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
