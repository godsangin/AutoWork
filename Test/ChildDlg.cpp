// ChildDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Test.h"
#include "ChildDlg.h"
#include "afxdialogex.h"
#include "wchar.h"
#include "locale.h"
#include <stdio.h>


// CChildDlg 대화 상자입니다.

void actionTest();
int BreakHan(wchar_t *str, wchar_t *buffer, UINT nSize);

IMPLEMENT_DYNAMIC(CChildDlg, CDialogEx)

CChildDlg::CChildDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChildDlg::IDD, pParent)
{

}

CChildDlg::~CChildDlg()
{
}

void CChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, mEdit);
}


BEGIN_MESSAGE_MAP(CChildDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CChildDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CChildDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON5, &CChildDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CChildDlg 메시지 처리기입니다.


void CChildDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	actionTest();
}


void actionTest(){
	SetCursorPos(1260, 10);
   mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
   mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
   Sleep(20);
   SetCursorPos(20, 460);
   mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
   mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
   Sleep(20);
   mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
   mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
   Sleep(1000);
   keybd_event(VK_HANGEUL,0,KEYEVENTF_EXTENDEDKEY, 0);
   keybd_event(68,0,KEYEVENTF_EXTENDEDKEY, 0);
   Sleep(100);
   keybd_event(68,0,KEYEVENTF_KEYUP, 0);
   keybd_event(76,0,KEYEVENTF_EXTENDEDKEY, 0);
   Sleep(100);
   keybd_event(76,0,KEYEVENTF_KEYUP, 0);
   keybd_event(84,0,KEYEVENTF_EXTENDEDKEY, 0);
   Sleep(100);
   keybd_event(84,0,KEYEVENTF_KEYUP, 0);
   keybd_event(75,0,KEYEVENTF_EXTENDEDKEY, 0);
   Sleep(100);
   keybd_event(75,0,KEYEVENTF_KEYUP, 0);
   keybd_event(68,0,KEYEVENTF_EXTENDEDKEY, 0);
   Sleep(100);
   keybd_event(68,0,KEYEVENTF_KEYUP, 0);
   keybd_event(68,0,KEYEVENTF_EXTENDEDKEY, 0);
   Sleep(100);
   keybd_event(68,0,KEYEVENTF_KEYUP, 0);
   keybd_event(76,0,KEYEVENTF_EXTENDEDKEY, 0);
   Sleep(100);
   keybd_event(76,0,KEYEVENTF_KEYUP, 0);
   keybd_event(83,0,KEYEVENTF_EXTENDEDKEY, 0);
}


void CChildDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

}


void CChildDlg::OnBnClickedButton5()//키보드 입력
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	mEdit.GetWindowTextW(str);
	char* w_temp = LPSTR(LPCTSTR(str));
	printf("%s", &w_temp);
	setlocale(LC_ALL, "Korean");
	WORD in_char, in_cho, in_jung, in_jong;
	WORD result;
	in_char = *w_temp - 0xAC00;
	in_cho = in_char / (0x0015 * 0x001C);
	in_jung = (in_char / 0x001C) % 0x0015;
	in_jong = in_char % 0x001C;
	
	
	wprintf(L"%c => %c + %c + %c\n", in_char + 0xAC00, in_cho + 0x1100, in_jung + 0x1161, in_jong + 0x11A7);
	
	

	//MessageBox(BreakHan(w_temp, buffer, sizeof buffer));
}


int BreakHan(wchar_t *str, wchar_t *buffer, UINT nSize) 
{ 
    //초성 
    static const wchar_t wcHead[] = {L'ㄱ', L'ㄲ', L'ㄴ', L'ㄷ', 
           L'ㄸ', L'ㄹ', L'ㅁ', L'ㅂ', 
           L'ㅃ', L'ㅅ', L'ㅆ', L'ㅇ', 
           L'ㅈ', L'ㅉ', L'ㅊ', L'ㅋ', 
           L'ㅌ', L'ㅍ', L'ㅎ'};

    //중성 
    static const wchar_t wcMid[] = {L'ㅏ', L'ㅐ', L'ㅑ', L'ㅒ', 
          L'ㅓ', L'ㅔ', L'ㅕ', L'ㅖ', 
          L'ㅗ', L'ㅘ', L'ㅙ', L'ㅚ', 
          L'ㅛ', L'ㅜ', L'ㅝ', L'ㅞ', 
          L'ㅟ', L'ㅠ', L'ㅡ', L'ㅢ', L'ㅣ'};

    //종성 
    static const wchar_t wcTail[] = {L' ', L'ㄱ', L'ㄲ', L'ㄳ', 
           L'ㄴ', L'ㄵ', L'ㄶ', L'ㄷ', 
           L'ㄹ', L'ㄺ', L'ㄻ', L'ㄼ', 
           L'ㄽ', L'ㄾ', L'ㄿ', L'ㅀ', 
           L'ㅁ', L'ㅂ', L'ㅄ', L'ㅅ', 
           L'ㅆ', L'ㅇ', L'ㅈ', L'ㅊ', 
           L'ㅋ', L'ㅌ', L'ㅍ', L'ㅎ'};

    UINT    pos = 0;

    while(*str != '\0') 
    { 
        if(*str < 256) 
        { 
            if(pos+2 >= nSize-1) 
                break;

            buffer[pos] = *str; 
            ++pos; 
        } 
        else 
        { 
            if(pos+4 >= nSize-1) 
                break;

            buffer[pos] = wcHead[(*str - 0xAC00) / (21*28)]; 
            buffer[pos+1] = wcMid[(*str - 0xAC00) % (21 * 28) / 28]; 
            buffer[pos+2] = wcTail[(*str - 0xAC00) % 28];

            pos+=3; 
        }

        ++str; 
    }

    buffer[pos] = '\0'; 
    return pos; 
}