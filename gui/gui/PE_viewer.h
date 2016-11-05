#pragma once
#include "afxcmn.h"


// PE_viewer 대화 상자입니다.

class PE_viewer : public CDialogEx
{
	DECLARE_DYNAMIC(PE_viewer)

public:
	PE_viewer(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PE_viewer();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PEVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
