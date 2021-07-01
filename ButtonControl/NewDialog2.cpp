// NewDialog2.cpp: 구현 파일
//

#include "pch.h"
#include "ButtonControl.h"
#include "NewDialog2.h"
#include "afxdialogex.h"


// NewDialog2 대화 상자

IMPLEMENT_DYNAMIC(NewDialog2, CDialogEx)

NewDialog2::NewDialog2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
}

NewDialog2::~NewDialog2()
{
}

void NewDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK3, m_check3);
	DDX_Control(pDX, IDC_CHECK4, m_check4);
	DDX_Control(pDX, IDC_CHECK5, m_check5);
	DDX_Control(pDX, IDC_CHECK6, m_check6);
	DDX_Control(pDX, IDC_BUTTON1, m_Done);
	DDX_Control(pDX, IDC_RADIO1, m_male);
	DDX_Control(pDX, IDC_RADIO2, m_female);
}


BEGIN_MESSAGE_MAP(NewDialog2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &NewDialog2::OnBnClickedButton1)
END_MESSAGE_MAP()


// NewDialog2 메시지 처리기


void NewDialog2::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL chk1, chk2, chk3, chk4, chk5, chk6, rad1, rad2;
	chk1 = m_check1.GetCheck();
	chk2 = m_check2.GetCheck();
	chk3 = m_check3.GetCheck();
	chk4 = m_check4.GetCheck();
	chk5 = m_check5.GetCheck();
	chk6 = m_check6.GetCheck();
	rad1 = m_male.GetCheck();
	rad2 = m_female.GetCheck();

	/*CString str;
	str.Format(_T("Apple: %d, Banana: %d, Grape: %d\nDog: %d, Cat: %d, Bird: %d"), chk1, chk2, chk3, chk4, chk5, chk6);
	MessageBox(str, _T("Your Choice"), MB_ICONINFORMATION);
	*/
	CString str;
	CString str1 = _T("You are ");
	CString str2 = _T("Your favorite fruit is ");
	CString str3 = _T("Your favorite animal is ");

	if (rad1 == TRUE) {
		str1 = str1 + _T("male.");
	}
	else {
		str1 = str1 + _T("female.");
	}

	if (chk1 == TRUE) {
		str2 = str2 + _T("Apple, ");
	}
	if (chk2 == TRUE) {
		str2 = str2 + _T("Banana, ");
	}
	if (chk3 == TRUE) {
		str2 = str2 + _T("Grape ");
	}
	if (chk1 == FALSE && chk2 == FALSE && chk3 == FALSE) {
		str2 = str2 + _T("noting.");
	}

	if (chk4 == TRUE) {
		str3 = str3 + _T("Dog, ");
	}
	if (chk5 == TRUE) {
		str3 = str3 + _T("Cat, ");
	}
	if (chk6 == TRUE) {
		str3 = str3 + _T("Bird ");
	}
	if (chk4 == FALSE && chk5 == FALSE && chk6 == FALSE) {
		str3 = str3 + _T("noting.");
	}
	
	str = str1 + "\n" + str2 + "\n" + str3;
	MessageBox(str, _T("Your Choice"), MB_ICONINFORMATION);

}
