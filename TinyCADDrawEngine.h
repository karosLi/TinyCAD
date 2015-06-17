
#pragma once


// CTinyCADDrawEngine ÃüÁîÄ¿±ê

class CTinyCADDrawEngine : public CCmdTarget
{
	DECLARE_DYNAMIC(CTinyCADDrawEngine)

public:
	CTinyCADDrawEngine();
	virtual ~CTinyCADDrawEngine();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};


