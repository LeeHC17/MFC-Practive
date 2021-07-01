
// ButtonControlView.cpp: CButtonControlView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ButtonControl.h"
#endif

#include "ButtonControlDoc.h"
#include "ButtonControlView.h"

#include "NewDialog.h"
#include "NewDialog2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButtonControlView

IMPLEMENT_DYNCREATE(CButtonControlView, CFormView)

BEGIN_MESSAGE_MAP(CButtonControlView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CButtonControlView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CButtonControlView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CButtonControlView::OnBnClickedButton3)
END_MESSAGE_MAP()

// CButtonControlView 생성/소멸

CButtonControlView::CButtonControlView() noexcept
	: CFormView(IDD_BUTTONCONTROL_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CButtonControlView::~CButtonControlView()
{
}

void CButtonControlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
}

BOOL CButtonControlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CButtonControlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_edit.SetLimitText(20);
}


// CButtonControlView 인쇄

BOOL CButtonControlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CButtonControlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CButtonControlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CButtonControlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CButtonControlView 진단

#ifdef _DEBUG
void CButtonControlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CButtonControlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CButtonControlDoc* CButtonControlView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CButtonControlDoc)));
	return (CButtonControlDoc*)m_pDocument;
}
#endif //_DEBUG


// CButtonControlView 메시지 처리기


void CButtonControlView::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	NewDialog dlg;
	dlg.DoModal();
}


void CButtonControlView::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString id, pass;
	m_edit.GetWindowText(id);
	m_edit2.GetWindowText(pass);
	if (id == "abc") {
		if (pass == "123") {
			NewDialog2 dlg2;
			dlg2.DoModal();
		}
		else {
			MessageBox(_T("Invalid password!"), _T("Wrong"), MB_ICONERROR);
		}
	}
	else {
		MessageBox(_T("Invalid ID!"), _T("Wrong"), MB_ICONERROR);
	}

}


void CButtonControlView::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxGetMainWnd()->SendMessage(WM_COMMAND, ID_APP_EXIT, NULL);
}
