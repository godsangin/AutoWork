// TestDlg2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Test.h"
#include "TestDlg2.h"
#include "afxdialogex.h"


// TestDlg2 대화 상자입니다.

IMPLEMENT_DYNAMIC(TestDlg2, CDialogEx)

TestDlg2::TestDlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(TestDlg2::IDD, pParent)
{

}

TestDlg2::~TestDlg2()
{
}

void TestDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TestDlg2, CDialogEx)
END_MESSAGE_MAP()


// TestDlg2 메시지 처리기입니다.
