// TinyCADAnimationThread.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TinyCAD.h"
#include "TinyCADAnimationThread.h"


// CTinyCADAnimationThread

IMPLEMENT_DYNCREATE(CTinyCADAnimationThread, CWinThread)

CTinyCADAnimationThread::CTinyCADAnimationThread()
{
}

CTinyCADAnimationThread::~CTinyCADAnimationThread()
{
}

BOOL CTinyCADAnimationThread::InitInstance()
{
	// TODO: �ڴ�ִ���������̳߳�ʼ��
	return TRUE;
}

int CTinyCADAnimationThread::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CTinyCADAnimationThread, CWinThread)
END_MESSAGE_MAP()


// CTinyCADAnimationThread ��Ϣ�������
