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

// TinyCADSrvrItem.h : CTinyCADSrvrItem 类的接口
//

#pragma once

class CTinyCADSrvrItem : public CDocObjectServerItem
{
	DECLARE_DYNAMIC(CTinyCADSrvrItem)

// 构造函数
public:
	CTinyCADSrvrItem(CTinyCADDoc* pContainerDoc);

// 属性
	CTinyCADDoc* GetDocument() const
		{ return reinterpret_cast<CTinyCADDoc*>(CDocObjectServerItem::GetDocument()); }

// 重写
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);

// 实现
public:
	~CTinyCADSrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // 为文档 I/O 重写
};

