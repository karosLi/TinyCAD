// TinyCADErrorOutput.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TinyCAD.h"
#include "TinyCADErrorOutput.h"


// CTinyCADErrorOutput

IMPLEMENT_DYNAMIC(CTinyCADErrorOutput, CListBox)

CTinyCADErrorOutput::CTinyCADErrorOutput()
{

	EnableAutomation();
}

CTinyCADErrorOutput::~CTinyCADErrorOutput()
{
}

void CTinyCADErrorOutput::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CListBox::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CTinyCADErrorOutput, CListBox)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CTinyCADErrorOutput, CListBox)
END_DISPATCH_MAP()

// ע��: ������� IID_ITinyCADErrorOutput ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {A31C5A0D-1923-42DD-BD75-DF36C3120919}
static const IID IID_ITinyCADErrorOutput =
{ 0xA31C5A0D, 0x1923, 0x42DD, { 0xBD, 0x75, 0xDF, 0x36, 0xC3, 0x12, 0x9, 0x19 } };

BEGIN_INTERFACE_MAP(CTinyCADErrorOutput, CListBox)
	INTERFACE_PART(CTinyCADErrorOutput, IID_ITinyCADErrorOutput, Dispatch)
END_INTERFACE_MAP()


// CTinyCADErrorOutput ��Ϣ�������


