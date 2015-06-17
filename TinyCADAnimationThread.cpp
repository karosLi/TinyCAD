// TinyCADAnimationThread.cpp : 实现文件
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
	// TODO: 在此执行任意逐线程初始化
	return TRUE;
}

int CTinyCADAnimationThread::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CTinyCADAnimationThread, CWinThread)
END_MESSAGE_MAP()


// CTinyCADAnimationThread 消息处理程序
