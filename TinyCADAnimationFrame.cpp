// TinyCADAnimationFrame.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TinyCAD.h"
#include "TinyCADAnimationFrame.h"


// CTinyCADAnimationFrame

IMPLEMENT_DYNCREATE(CTinyCADAnimationFrame, CFrameWndEx)

CTinyCADAnimationFrame::CTinyCADAnimationFrame()
{

	EnableAutomation();
}

CTinyCADAnimationFrame::~CTinyCADAnimationFrame()
{
}

void CTinyCADAnimationFrame::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CFrameWndEx::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CTinyCADAnimationFrame, CFrameWndEx)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CTinyCADAnimationFrame, CFrameWndEx)
END_DISPATCH_MAP()

// ע��: ������� IID_ITinyCADAnimationFrame ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {B501F7A9-9765-4C33-B0C6-252A688D100C}
static const IID IID_ITinyCADAnimationFrame =
{ 0xB501F7A9, 0x9765, 0x4C33, { 0xB0, 0xC6, 0x25, 0x2A, 0x68, 0x8D, 0x10, 0xC } };

BEGIN_INTERFACE_MAP(CTinyCADAnimationFrame, CFrameWndEx)
	INTERFACE_PART(CTinyCADAnimationFrame, IID_ITinyCADAnimationFrame, Dispatch)
END_INTERFACE_MAP()


// CTinyCADAnimationFrame ��Ϣ�������
