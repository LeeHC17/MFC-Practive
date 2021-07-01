#pragma once


// NewDialog2 대화 상자

class NewDialog2 : public CDialogEx
{
	DECLARE_DYNAMIC(NewDialog2)

public:
	NewDialog2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~NewDialog2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck5();
	CButton m_check1;
	CButton m_check2;
	CButton m_check3;
	CButton m_check4;
	CButton m_check5;
	CButton m_check6;
	CButton m_Done;
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedButton1();
	CButton m_male;
	CButton m_female;
};
