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

// TinyCADView.h : CTinyCADView 类的接口
//


#pragma once
#include "TinyCADZoomView.h"

class CTinyCADCntrItem;

class CTinyCADView : public CTinyCADZoomView
{
protected: // 仅从序列化创建
	CTinyCADView();
	DECLARE_DYNCREATE(CTinyCADView)

// 属性
public:
	CTinyCADDoc* GetDocument() const;
	// m_pSelection 将该选定内容保存在当前的 CTinyCADCntrItem 中。
	// 对于许多应用程序，这种成员变量不足以
	//  表示某个选择，例如在不属于 CTinyCADCntrItem 的对象中
	//  选定的一个或多个对象。提供这种选择
	//  机制的目的只是帮助您入门

	// TODO: 用适合应用程序的选择机制替换此选择机制
	CTinyCADCntrItem* m_pSelection;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// 容器支持

// 实现
public:
	virtual ~CTinyCADView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnFilePrint();
	afx_msg void OnCancelEditSrvr();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnFilePrintPreviewUIUpdate(CCmdUI* pCmdUI);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TinyCADView.cpp 中的调试版本
inline CTinyCADDoc* CTinyCADView::GetDocument() const
   { return reinterpret_cast<CTinyCADDoc*>(m_pDocument); }
#endif

