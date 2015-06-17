#pragma once

// CTinyCADElementsDoc 文档

class CTinyCADElementsDoc : public CDocument
{
	DECLARE_DYNCREATE(CTinyCADElementsDoc)

public:
	CTinyCADElementsDoc();
	virtual ~CTinyCADElementsDoc();

	virtual void OnFinalRelease();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // 为文档 I/O 重写
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};
