#pragma once


// SUPERMAN 대화 상자

class SUPERMAN : public CDialogEx
{
	DECLARE_DYNAMIC(SUPERMAN)

public:
	SUPERMAN(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SUPERMAN();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	CButton m_seat[55];
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
