// CREATEPAGE.cpp: 구현 파일
//

#include "pch.h"
#include "Login2.h"
#include "CREATEPAGE.h"
#include "afxdialogex.h"


// CREATEPAGE 대화 상자

IMPLEMENT_DYNAMIC(CREATEPAGE, CDialogEx)

CREATEPAGE::CREATEPAGE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CREATEPAGE::~CREATEPAGE()
{
}

void CREATEPAGE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit_ID);
	DDX_Control(pDX, IDC_EDIT2, m_Edit_PASS);
	DDX_Control(pDX, IDC_RADIO1, m_male);
	DDX_Control(pDX, IDC_RADIO2, m_female);
	DDX_Control(pDX, IDC_EDIT3, m_PHONE);
	DDX_Control(pDX, IDC_EDIT4, m_AGE);
}


BEGIN_MESSAGE_MAP(CREATEPAGE, CDialogEx)
	ON_BN_CLICKED(IDC_CREATEBT, &CREATEPAGE::OnBnClickedCreatebt)
END_MESSAGE_MAP()


// CREATEPAGE 메시지 처리기


void CREATEPAGE::OnBnClickedCreatebt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/* ID, Password를 account.txt에 저장*/
	CString str_id, str_pass, account;
	m_Edit_ID.GetWindowText(str_id);
	m_Edit_PASS.GetWindowText(str_pass);

	if (str_id == "") {
		MessageBox(_T("Blank ID is not allowed!!"), _T("error"), MB_ICONERROR);
		return;
	}
	if (str_pass == "") {
		MessageBox(_T("Blank Password is not allowed!!"), _T("error"), MB_ICONERROR);
		return;
	}

	account = str_id + " " + str_pass;
	account += "\r\n";

	CFile file;
	file.Open(_T("account.txt"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
	file.SeekToEnd();

	file.Write(account, account.GetLength() * sizeof(char) * 2);

	file.Close();

	/* User 정보를 UserData.txt에 저장 */
	CString UserData, phone, age;
	BOOL rad1, rad2;
	
	m_PHONE.GetWindowText(phone);
	m_AGE.GetWindowText(age);
	rad1 = m_male.GetCheck();
	rad2 = m_female.GetCheck();

	if (phone == "") {
		MessageBox(_T("Please input phone number!!"), _T("error"), MB_ICONERROR);
		return;
	}
	if (age == "") {
		MessageBox(_T("Please input age!!"), _T("error"), MB_ICONERROR);
		return;
	}

	UserData = str_id;

	if(rad1 == TRUE){
		UserData += " | Male | ";
	}
	else if (rad2 == TRUE) {
		UserData += " | Female | ";
	}
	else if (rad2 == FALSE && rad1 == FALSE) {
		MessageBox(_T("Please choose gender!!"), _T("error"), MB_ICONERROR);
		return;
	}
	
	UserData += phone;
	UserData += " | ";
	UserData += age;
	UserData += "\r\n";

	CFile file2;
	file2.Open(_T("UserData.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
	file2.SeekToEnd();

	file2.Write(UserData, UserData.GetLength() * sizeof(char) * 2);

	file2.Close();
	MessageBox(_T("Create account success!!"), _T("Success"), NULL);
	SendMessage(WM_CLOSE, 0, 0);
}
