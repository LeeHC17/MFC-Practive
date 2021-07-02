
// ModalDialogView.cpp: CModalDialogView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ModalDialog.h"
#endif

#include "ModalDialogDoc.h"
#include "ModalDialogView.h"
#include "CMyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModalDialogView

IMPLEMENT_DYNCREATE(CModalDialogView, CView)

BEGIN_MESSAGE_MAP(CModalDialogView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CModalDialogView 생성/소멸

CModalDialogView::CModalDialogView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_str = _T("");
	m_font = 0;

}

CModalDialogView::~CModalDialogView()
{
}

BOOL CModalDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CModalDialogView 그리기

void CModalDialogView::OnDraw(CDC* pDC)
{
	CModalDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFont font;
	CString fontname;

	if (m_font == 0) {
		fontname = _T("굴림");
	}
	else if (m_font == 1) {
		fontname = _T("궁서");
	}
	else if (m_font == 2) {
		fontname = _T("바탕");
	}
	font.CreatePointFont(400, fontname);

	pDC->SelectObject(&font);
	pDC->TextOut(10, 10, m_str);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CModalDialogView 인쇄

BOOL CModalDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CModalDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CModalDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CModalDialogView 진단

#ifdef _DEBUG
void CModalDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CModalDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CModalDialogDoc* CModalDialogView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModalDialogDoc)));
	return (CModalDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CModalDialogView 메시지 처리기


void CModalDialogView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMyDialog dlg;
	dlg.m_str = m_str;
	dlg.m_font = m_font;

	int result = dlg.DoModal();
	if (result == IDOK) {
		m_str = dlg.m_str;
		m_font = dlg.m_font;
		Invalidate();
	}
	else if (result == IDC_CLEAR) {
		m_str = _T("");
		Invalidate();
	}
	CView::OnLButtonDown(nFlags, point);
}
