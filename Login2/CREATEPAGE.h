#pragma once


// CREATEPAGE 대화 상자

class CREATEPAGE : public CDialogEx
{
	DECLARE_DYNAMIC(CREATEPAGE)

public:
	CREATEPAGE(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CREATEPAGE();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	CEdit m_Edit_ID;
	CEdit m_Edit_PASS;
public:
	afx_msg void OnBnClickedCreatebt();
protected:
	CButton m_male;
	CButton m_female;
	CEdit m_PHONE;
	CEdit m_AGE;
};
