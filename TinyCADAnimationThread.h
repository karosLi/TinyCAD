#pragma once



// CTinyCADAnimationThread

class CTinyCADAnimationThread : public CWinThread
{
	DECLARE_DYNCREATE(CTinyCADAnimationThread)

protected:
	CTinyCADAnimationThread();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CTinyCADAnimationThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


