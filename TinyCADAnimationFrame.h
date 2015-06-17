#pragma once


// CTinyCADAnimationFrame 框架

class CTinyCADAnimationFrame : public CFrameWndEx
{
	DECLARE_DYNCREATE(CTinyCADAnimationFrame)
protected:
	CTinyCADAnimationFrame();           // 动态创建所使用的受保护的构造函数
	virtual ~CTinyCADAnimationFrame();

public:
	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};


