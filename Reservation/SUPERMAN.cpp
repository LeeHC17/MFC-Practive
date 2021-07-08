// SUPERMAN.cpp: 구현 파일
//

#include "pch.h"
#include "Reservation.h"
#include "SUPERMAN.h"
#include "afxdialogex.h"


// SUPERMAN 대화 상자

IMPLEMENT_DYNAMIC(SUPERMAN, CDialogEx)

SUPERMAN::SUPERMAN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

SUPERMAN::~SUPERMAN()
{
}

void SUPERMAN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_seat[0]);
	DDX_Control(pDX, IDC_CHECK2, m_seat[1]);
	DDX_Control(pDX, IDC_CHECK3, m_seat[2]);
	DDX_Control(pDX, IDC_CHECK4, m_seat[3]);
	DDX_Control(pDX, IDC_CHECK5, m_seat[4]);
	DDX_Control(pDX, IDC_CHECK6, m_seat[5]);
	DDX_Control(pDX, IDC_CHECK7, m_seat[6]);
	DDX_Control(pDX, IDC_CHECK8, m_seat[7]);
	DDX_Control(pDX, IDC_CHECK9, m_seat[8]);
	DDX_Control(pDX, IDC_CHECK10, m_seat[9]);
	DDX_Control(pDX, IDC_CHECK11, m_seat[10]);
	DDX_Control(pDX, IDC_CHECK12, m_seat[11]);
	DDX_Control(pDX, IDC_CHECK13, m_seat[12]);
	DDX_Control(pDX, IDC_CHECK14, m_seat[13]);
	DDX_Control(pDX, IDC_CHECK15, m_seat[14]);
	DDX_Control(pDX, IDC_CHECK16, m_seat[15]);
	DDX_Control(pDX, IDC_CHECK17, m_seat[16]);
	DDX_Control(pDX, IDC_CHECK18, m_seat[17]);
	DDX_Control(pDX, IDC_CHECK19, m_seat[18]);
	DDX_Control(pDX, IDC_CHECK20, m_seat[19]);
	DDX_Control(pDX, IDC_CHECK21, m_seat[20]);
	DDX_Control(pDX, IDC_CHECK22, m_seat[21]);
	DDX_Control(pDX, IDC_CHECK23, m_seat[22]);
	DDX_Control(pDX, IDC_CHECK24, m_seat[23]);
	DDX_Control(pDX, IDC_CHECK25, m_seat[24]);
	DDX_Control(pDX, IDC_CHECK26, m_seat[25]);
	DDX_Control(pDX, IDC_CHECK27, m_seat[26]);
	DDX_Control(pDX, IDC_CHECK28, m_seat[27]);
	DDX_Control(pDX, IDC_CHECK29, m_seat[28]);
	DDX_Control(pDX, IDC_CHECK30, m_seat[29]);
	DDX_Control(pDX, IDC_CHECK31, m_seat[30]);
	DDX_Control(pDX, IDC_CHECK32, m_seat[31]);
	DDX_Control(pDX, IDC_CHECK33, m_seat[32]);
	DDX_Control(pDX, IDC_CHECK34, m_seat[33]);
	DDX_Control(pDX, IDC_CHECK35, m_seat[34]);
	DDX_Control(pDX, IDC_CHECK36, m_seat[35]);
	DDX_Control(pDX, IDC_CHECK37, m_seat[36]);
	DDX_Control(pDX, IDC_CHECK38, m_seat[37]);
	DDX_Control(pDX, IDC_CHECK39, m_seat[38]);
	DDX_Control(pDX, IDC_CHECK40, m_seat[39]);
	DDX_Control(pDX, IDC_CHECK41, m_seat[40]);
	DDX_Control(pDX, IDC_CHECK42, m_seat[41]);
	DDX_Control(pDX, IDC_CHECK43, m_seat[42]);
	DDX_Control(pDX, IDC_CHECK44, m_seat[43]);
	DDX_Control(pDX, IDC_CHECK45, m_seat[44]);
	DDX_Control(pDX, IDC_CHECK46, m_seat[45]);
	DDX_Control(pDX, IDC_CHECK47, m_seat[46]);
	DDX_Control(pDX, IDC_CHECK48, m_seat[47]);
	DDX_Control(pDX, IDC_CHECK49, m_seat[48]);
	DDX_Control(pDX, IDC_CHECK50, m_seat[49]);
	DDX_Control(pDX, IDC_CHECK51, m_seat[50]);
	DDX_Control(pDX, IDC_CHECK52, m_seat[51]);
	DDX_Control(pDX, IDC_CHECK53, m_seat[52]);
	DDX_Control(pDX, IDC_CHECK54, m_seat[53]);
	DDX_Control(pDX, IDC_CHECK55, m_seat[54]);
}


BEGIN_MESSAGE_MAP(SUPERMAN, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &SUPERMAN::OnBnClickedButton1)
END_MESSAGE_MAP()


// SUPERMAN 메시지 처리기


void SUPERMAN::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, seat, seatnum;
	str = "Your reservation seat is ";

	CFile file2;
	file2.Open(_T("SUPERMAN.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
	file2.SeekToEnd();

	for (int i = 0; i < 55; i++) {
		if (m_seat[i].GetCheck()) {
			if (i <= 10) {
				seat.Format(_T("E-%d"), i + 1);
				seatnum.Format(_T("%d\r\n"), i);
				seat += " ";
				str += seat;
				file2.Write(seatnum, seatnum.GetLength() * sizeof(char) * 2);
			}
			else if (i > 10 && i <= 21) {
				seat.Format(_T("D-%d"), i - 10);
				seatnum.Format(_T("%d\r\n"), i);
				seat += " ";
				str += seat;
				file2.Write(seatnum, seatnum.GetLength() * sizeof(char) * 2);
			}
			else if (i > 21 && i <= 32) {
				seat.Format(_T("C-%d"), i - 21);
				seatnum.Format(_T("%d\r\n"), i);
				seat += " ";
				str += seat;
				file2.Write(seatnum, seatnum.GetLength() * sizeof(char) * 2);
			}
			else if (i > 32 && i <= 43) {
				seat.Format(_T("B-%d"), i - 32);
				seatnum.Format(_T("%d\r\n"), i);
				seat += " ";
				str += seat;
				file2.Write(seatnum, seatnum.GetLength() * sizeof(char) * 2);
			}
			else if (i > 43 && i <= 54) {
				seat.Format(_T("A-%d"), i - 43);
				seatnum.Format(_T("%d\r\n"), i);
				seat += " ";
				str += seat;
				file2.Write(seatnum, seatnum.GetLength() * sizeof(char) * 2);
			}
		}
	}
	MessageBox(str);
	file2.Close();
}


BOOL SUPERMAN::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CString snum;
	int seatnum;
	CFile file2;
	file2.Open(_T("SUPERMAN.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead);
	CArchive seat(&file2, CArchive::load);

	while (seat.ReadString(snum)) {
		seatnum = _ttoi(snum);
		m_seat[seatnum].EnableWindow(FALSE);
	}
	seat.Close();
	file2.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
