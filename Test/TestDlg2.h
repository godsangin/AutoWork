#pragma once


// TestDlg2 ��ȭ �����Դϴ�.

class TestDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(TestDlg2)

public:
	TestDlg2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~TestDlg2();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
