#pragma once


// TestDlg2 대화 상자입니다.

class TestDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(TestDlg2)

public:
	TestDlg2(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~TestDlg2();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
