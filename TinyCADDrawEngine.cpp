// TinyCADDrawEngine.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TinyCAD.h"
#include "TinyCADDrawEngine.h"


// CTinyCADDrawEngine

IMPLEMENT_DYNAMIC(CTinyCADDrawEngine, CCmdTarget)


CTinyCADDrawEngine::CTinyCADDrawEngine()
{
	EnableAutomation();
}

CTinyCADDrawEngine::~CTinyCADDrawEngine()
{
}


void CTinyCADDrawEngine::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CTinyCADDrawEngine, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CTinyCADDrawEngine, CCmdTarget)
END_DISPATCH_MAP()

// ע��: ������� IID_ITinyCADDrawEngine ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {2521FC3C-70C2-4066-A7D9-8BF5F78044FB}
static const IID IID_ITinyCADDrawEngine =
{ 0x2521FC3C, 0x70C2, 0x4066, { 0xA7, 0xD9, 0x8B, 0xF5, 0xF7, 0x80, 0x44, 0xFB } };

BEGIN_INTERFACE_MAP(CTinyCADDrawEngine, CCmdTarget)
	INTERFACE_PART(CTinyCADDrawEngine, IID_ITinyCADDrawEngine, Dispatch)
END_INTERFACE_MAP()


// CTinyCADDrawEngine ��Ϣ�������
