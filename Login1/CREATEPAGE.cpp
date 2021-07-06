// CREATEPAGE.cpp: 구현 파일
//

#include "pch.h"
#include "Login1.h"
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
}


BEGIN_MESSAGE_MAP(CREATEPAGE, CDialogEx)
	ON_BN_CLICKED(IDC_CREATE, &CREATEPAGE::OnBnClickedCreate)
END_MESSAGE_MAP()


// CREATEPAGE 메시지 처리기


void CREATEPAGE::OnBnClickedCreate()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString account, str_id, str_pass;

	m_Edit_ID.GetWindowText(str_id);
	m_Edit_PASS.GetWindowText(str_pass);

	account = str_id + " " + str_pass;

	CFile file;
	file.Open(_T("account.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);

	file.Write(account, account.GetLength() * sizeof(char) * 2);
	MessageBox(_T("Create account success!!"), _T("Success"), NULL);
	file.Close();


	/*CArchive Account(&file, CArchive::store);
	Account << account;
	MessageBox(_T("Create account success!!"), _T("Success"), NULL);
	*/
}
