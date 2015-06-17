#pragma once


// CTinyCADErrorOutput

class CTinyCADErrorOutput : public CListBox
{
	DECLARE_DYNAMIC(CTinyCADErrorOutput)

public:
	CTinyCADErrorOutput();
	virtual ~CTinyCADErrorOutput();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};


