#pragma once


// CTinyCADAnimationFrame ���

class CTinyCADAnimationFrame : public CFrameWndEx
{
	DECLARE_DYNCREATE(CTinyCADAnimationFrame)
protected:
	CTinyCADAnimationFrame();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CTinyCADAnimationFrame();

public:
	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};


