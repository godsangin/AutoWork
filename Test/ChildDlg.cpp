// ChildDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Test.h"
#include "ChildDlg.h"
#include "afxdialogex.h"
#include "wchar.h"
#include "locale.h"
#include <stdio.h>


// CChildDlg ��ȭ �����Դϴ�.

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


// CChildDlg �޽��� ó�����Դϴ�.


void CChildDlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

}


void CChildDlg::OnBnClickedButton5()//Ű���� �Է�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
    //�ʼ� 
    static const wchar_t wcHead[] = {L'��', L'��', L'��', L'��', 
           L'��', L'��', L'��', L'��', 
           L'��', L'��', L'��', L'��', 
           L'��', L'��', L'��', L'��', 
           L'��', L'��', L'��'};

    //�߼� 
    static const wchar_t wcMid[] = {L'��', L'��', L'��', L'��', 
          L'��', L'��', L'��', L'��', 
          L'��', L'��', L'��', L'��', 
          L'��', L'��', L'��', L'��', 
          L'��', L'��', L'��', L'��', L'��'};

    //���� 
    static const wchar_t wcTail[] = {L' ', L'��', L'��', L'��', 
           L'��', L'��', L'��', L'��', 
           L'��', L'��', L'��', L'��', 
           L'��', L'��', L'��', L'��', 
           L'��', L'��', L'��', L'��', 
           L'��', L'��', L'��', L'��', 
           L'��', L'��', L'��', L'��'};

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