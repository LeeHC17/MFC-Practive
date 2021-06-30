
// ListBOXView.cpp: CListBOXView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ListBOX.h"
#endif

#include "ListBOXDoc.h"
#include "ListBOXView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListBOXView

IMPLEMENT_DYNCREATE(CListBOXView, CFormView)

BEGIN_MESSAGE_MAP(CListBOXView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_RIGHT, &CListBOXView::OnBnClickedRight)
	ON_BN_CLICKED(IDC_LEFT, &CListBOXView::OnBnClickedLeft)
END_MESSAGE_MAP()

// CListBOXView 생성/소멸

CListBOXView::CListBOXView() noexcept
	: CFormView(IDD_LISTBOX_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CListBOXView::~CListBOXView()
{
}

void CListBOXView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_RIGHT, m_right);
	DDX_Control(pDX, IDC_LEFT, m_left);
}

BOOL CListBOXView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CListBOXView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_list1.AddString(_T("Apple"));
	m_list1.AddString(_T("Strawberry"));
	m_list1.AddString(_T("Pineapple"));
	m_list1.AddString(_T("Peach"));
}


// CListBOXView 인쇄

BOOL CListBOXView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CListBOXView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CListBOXView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CListBOXView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CListBOXView 진단

#ifdef _DEBUG
void CListBOXView::AssertValid() const
{
	CFormView::AssertValid();
}

void CListBOXView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CListBOXDoc* CListBOXView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListBOXDoc)));
	return (CListBOXDoc*)m_pDocument;
}
#endif //_DEBUG


// CListBOXView 메시지 처리기


void CListBOXView::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CListBOXView::OnBnClickedRight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nIndex = m_list1.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_list1.GetText(nIndex, str);
		m_list1.DeleteString(nIndex);
		m_list1.SetCurSel(nIndex);
		m_list2.AddString(str);
		AfxGetMainWnd()->SetWindowTextW(_T("From left to right..."));
	}
}


void CListBOXView::OnBnClickedLeft()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nIndex = m_list2.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_list2.GetText(nIndex, str);
		m_list2.DeleteString(nIndex);
		m_list2.SetCurSel(nIndex);
		m_list1.AddString(str);
		AfxGetMainWnd()->SetWindowTextW(_T("From right to left..."));
	}
}
