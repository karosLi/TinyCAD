// TinyCADCmdInput.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TinyCAD.h"
#include "TinyCADCmdInput.h"


// CTinyCADCmdInput

IMPLEMENT_DYNAMIC(CTinyCADCmdInput, CEdit)

CTinyCADCmdInput::CTinyCADCmdInput()
{

	EnableAutomation();
}

CTinyCADCmdInput::~CTinyCADCmdInput()
{
}

void CTinyCADCmdInput::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CEdit::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CTinyCADCmdInput, CEdit)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CTinyCADCmdInput, CEdit)
END_DISPATCH_MAP()

// ע��: ������� IID_ITinyCADCmdInput ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {B31CC072-91FE-49ED-9D28-450D7DEB624B}
static const IID IID_ITinyCADCmdInput =
{ 0xB31CC072, 0x91FE, 0x49ED, { 0x9D, 0x28, 0x45, 0xD, 0x7D, 0xEB, 0x62, 0x4B } };

BEGIN_INTERFACE_MAP(CTinyCADCmdInput, CEdit)
	INTERFACE_PART(CTinyCADCmdInput, IID_ITinyCADCmdInput, Dispatch)
END_INTERFACE_MAP()


// CTinyCADCmdInput ��Ϣ�������


