#pragma once



// CTinyCADAnimationThread

class CTinyCADAnimationThread : public CWinThread
{
	DECLARE_DYNCREATE(CTinyCADAnimationThread)

protected:
	CTinyCADAnimationThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CTinyCADAnimationThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


