
// Login1Dlg.h: 헤더 파일
//

#pragma once


// CLogin1Dlg 대화 상자
class CLogin1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CLogin1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CEdit m_EDIT_ID;
	CEdit m_EDIT_PASS;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCreatbtn();
	afx_msg void OnBnClickedLoginbtn();
};
