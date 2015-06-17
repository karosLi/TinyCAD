#pragma once


// CTinyCADCmdInput

class CTinyCADCmdInput : public CEdit
{
	DECLARE_DYNAMIC(CTinyCADCmdInput)

public:
	CTinyCADCmdInput();
	virtual ~CTinyCADCmdInput();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};


