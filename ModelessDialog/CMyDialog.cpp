// CMyDialog.cpp: 구현 파일
//

#include "pch.h"
#include "ModelessDialog.h"
#include "CMyDialog.h"
#include "afxdialogex.h"
#include "ModelessDialogDoc.h"
#include "ModelessDialogView.h"


// CMyDialog 대화 상자

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_str(_T(""))
	, m_font(0)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STR, m_str);
	DDV_MaxChars(pDX, m_str, 10);
	DDX_CBIndex(pDX, IDC_FONT, m_font);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDAPPLY, &CMyDialog::OnBnClickedApply)
END_MESSAGE_MAP()


// CMyDialog 메시지 처리기


void CMyDialog::OnBnClickedApply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_pView->m_str = m_str;
	m_pView->m_font = m_font;
	m_pView->Invalidate();
}


void CMyDialog::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	DestroyWindow();
	//CDialog::OnCancel();
}


void CMyDialog::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pView->m_pDlg = NULL;
	delete this;
	//CDialog::PostNcDestroy();
}
