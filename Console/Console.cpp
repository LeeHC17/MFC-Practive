// Console.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "framework.h"
#include "Console.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 애플리케이션 개체입니다.

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // MFC를 초기화합니다. 초기화하지 못한 경우 오류를 인쇄합니다.
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: 여기에 애플리케이션 동작을 코딩합니다.
            wprintf(L"심각한 오류: MFC 초기화 실패\n");
            nRetCode = 1;
        }
        else
        {
            /*CString str;
            str.LoadString(IDS_APP_TITLE);
            _tprintf(_T("Hello from %s!\n"), (LPCTSTR)str);
            getchar();
            */
            
            /*CString str;
            str.Format(_T("x = %d, y = %d"), 100, 200);
            MessageBox(NULL, str, _T("CString::Format() 연습"), MB_OK);
            */

            /*CString str;
            str.LoadString(IDS_APP_TITLE);
            str.Insert(0, _T("Hello from "));
            str.Append(_T("!"));
            MessageBox(NULL, str, _T("CString::LoadString() 연습"), MB_OK);
            */

            _tsetlocale(LC_ALL, _T(""));
            CTime tm;
            tm = CTime::GetCurrentTime();
            
            CString str = tm.Format(_T("%A, %B, %d, %Y"));
            _tprintf(_T("%s\n"), (LPCTSTR)str);
            str.Format(_T("현재 시각은 %d시 %d분 %d초입니다."), tm.GetHour(), tm.GetMinute(), tm.GetSecond());
            _tprintf(_T("%s\n"), (LPCTSTR)str);
        }
    }
    else
    {
        // TODO: 오류 코드를 필요에 따라 수정합니다.
        wprintf(L"심각한 오류: GetModuleHandle 실패\n");
        nRetCode = 1;
    }

    return nRetCode;
}
