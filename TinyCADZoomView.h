#pragma once



// CTinyCADZoomView ��ͼ

class CTinyCADZoomView : public CScrollView
{
	DECLARE_DYNCREATE(CTinyCADZoomView)

protected:
	CTinyCADZoomView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CTinyCADZoomView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
	virtual void OnFinalRelease();

protected:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
	virtual void OnInitialUpdate();     // �����ĵ�һ��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	// ��ͼ���ű������� �������һ ������float�����ֵ
	FLOAT m_fScale;
public:

	// �õ����ű�������
	FLOAT GetScale(void)
	{
		return m_fScale;
	}
	// �������ű�������bReDraw ����ָʾ�Ƿ��ػ�
	FLOAT SetScale(FLOAT fNewScale, BOOL bReDraw = FALSE)
	{
		if (m_fScale <= 0.0f)
		{
			ASSERT(FALSE);
			return 1.0f;
		}

		FLOAT fOldScale = m_fScale;
		m_fScale = fNewScale;

		if (bReDraw)
		{
			Invalidate();
		}

		return fOldScale;
	}
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
};


