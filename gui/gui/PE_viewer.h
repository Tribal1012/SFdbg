#pragma once
#include "afxcmn.h"


// PE_viewer ��ȭ �����Դϴ�.

class PE_viewer : public CDialogEx
{
	DECLARE_DYNAMIC(PE_viewer)

public:
	PE_viewer(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~PE_viewer();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PEVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

protected:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	CListCtrl pelist;
};
