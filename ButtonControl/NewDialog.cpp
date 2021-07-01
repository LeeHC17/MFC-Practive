// NewDialog.cpp: 구현 파일
//

#include "pch.h"
#include "ButtonControl.h"
#include "NewDialog.h"
#include "afxdialogex.h"


// NewDialog 대화 상자

IMPLEMENT_DYNAMIC(NewDialog, CDialogEx)

NewDialog::NewDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

NewDialog::~NewDialog()
{
}

void NewDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NewDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &NewDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO1, &NewDialog::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &NewDialog::OnBnClickedRadio2)
END_MESSAGE_MAP()


// NewDialog 메시지 처리기


void NewDialog::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void NewDialog::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox(_T("ID is 'abc!"), _T("ID"));
}


void NewDialog::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox(_T("Password is '123'!"), _T("Password"));
}
