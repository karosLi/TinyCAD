#pragma once



// CTinyCADZoomView 视图

class CTinyCADZoomView : public CScrollView
{
	DECLARE_DYNCREATE(CTinyCADZoomView)

protected:
	CTinyCADZoomView();           // 动态创建所使用的受保护的构造函数
	virtual ~CTinyCADZoomView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
	virtual void OnFinalRelease();

protected:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
	virtual void OnInitialUpdate();     // 构造后的第一次

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	// 视图缩放比例因子 必须大于一 上限是float的最大值
	FLOAT m_fScale;
public:

	// 得到缩放比例因子
	FLOAT GetScale(void)
	{
		return m_fScale;
	}
	// 设置缩放比例因子bReDraw 用来指示是否重绘
	FLOAT SetScale(FLOAT fNewScale, BOOL bReDraw = FALSE)
	{
		if (m_fScale <= 0.0f)
		{
			ASSERT(FALSE);
			return 1.0f;
		}

		FLOAT fOldScale = m_fScale;
		m_fScale = fNewScale;

		if (bReDraw)
		{
			Invalidate();
		}

		return fOldScale;
	}
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
};


