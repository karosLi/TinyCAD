// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// TinyCAD.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "TinyCAD.h"
#include "TinyCADMainFrm.h"

#include "TinyCADChildFrm.h"
#include "TinyCADIpFrame.h"
#include "TinyCADDoc.h"
#include "TinyCADView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTinyCADApp

BEGIN_MESSAGE_MAP(CTinyCADApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CTinyCADApp::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CTinyCADApp ����

CTinyCADApp::CTinyCADApp()
{
	EnableHtmlHelp();


	m_bHiColorIcons = TRUE;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CTinyCADApp ����

CTinyCADApp theApp;
// ���ɵĴ˱�ʶ����ͳ���϶�������Ӧ�ó�����Ψһ��
// �������Ըѡ��һ���ض��ı�ʶ��������Ը�����

// {2983F10C-E6AB-4117-924C-28B52D4EDB80}
static const CLSID clsid =
{ 0x2983F10C, 0xE6AB, 0x4117, { 0x92, 0x4C, 0x28, 0xB5, 0x2D, 0x4E, 0xDB, 0x80 } };

const GUID CDECL BASED_CODE _tlid =
		{ 0x90CF4A56, 0xE158, 0x431A, { 0xA3, 0x8C, 0x52, 0x6F, 0xF7, 0x1D, 0xCD, 0xAD } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// CTinyCADApp ��ʼ��

BOOL CTinyCADApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(0);  // ���ر�׼ INI �ļ�ѡ��

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_TinyCADTYPE,
		RUNTIME_CLASS(CTinyCADDoc),
		RUNTIME_CLASS(CTinyCADChildFrame), // �Զ��� MDI �ӿ��
		RUNTIME_CLASS(CTinyCADView));
	if (!pDocTemplate)
		return FALSE;
	pDocTemplate->SetContainerInfo(IDR_TinyCADTYPE_CNTR_IP);
	pDocTemplate->SetServerInfo(
		IDR_TinyCADTYPE_SRVR_EMB, IDR_TinyCADTYPE_SRVR_IP,
		RUNTIME_CLASS(CTinyCADInPlaceFrame));
	AddDocTemplate(pDocTemplate);
	// �� COleTemplateServer ���ӵ��ĵ�ģ��
	// COleTemplateServer ͨ��ʹ��
	// �ĵ�ģ����ָ������Ϣ��Ϊ���� OLE ����
	// �������ĵ�
	m_server.ConnectTemplate(clsid, pDocTemplate, FALSE);
	// �����е� OLE ����������ע��Ϊ�������С��⽫����
	//  OLE ���Դ�����Ӧ�ó����д�������
	COleTemplateServer::RegisterAll();
		// ע��: MDI Ӧ�ó���ע�����еķ��������󣬶�����
		// �������ϵ� /Embedding �� /Automation

	// ������ MDI ��ܴ���
	CTinyCADMainFrame* pMainFrame = new CTinyCADMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� MDI Ӧ�ó����У���Ӧ������ m_pMainWnd ֮����������
	// ������/��
	m_pMainWnd->DragAcceptFiles();

	// ���á�DDE ִ�С�
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	// ������׼������DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Ӧ�ó������� /Embedding �� /Automation ���������ġ�
	//ʹӦ�ó�����Ϊ�Զ������������С�
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// ����ʾ������
		return TRUE;
	}
	// ʹ�� /Unregserver �� /Unregister ��������Ӧ�ó���ע��
	// ���Ϳ⡣����ע�������� ProcessShellCommand() �з�����
	else if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)
	{
		UnregisterShellFileTypes();
		m_server.UpdateRegistry(OAT_DOC_OBJECT_SERVER, NULL, NULL, FALSE);
		AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor);
	}
	// Ӧ�ó������Զ�����ʽ������������(�� /Register
	// �� /Regserver)�����ġ�����ע�����������Ϳ⡣
	else
	{
		m_server.UpdateRegistry(OAT_DOC_OBJECT_SERVER);
		COleObjectFactory::UpdateRegistryAll();
		AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid);
	}

	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// �������ѳ�ʼ���������ʾ����������и���
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CTinyCADApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CTinyCADApp �Զ������/���淽��

void CTinyCADApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CTinyCADApp::LoadCustomState()
{
}

void CTinyCADApp::SaveCustomState()
{
}

// CTinyCADApp ��Ϣ�������



