#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// PSDlg 대화 상자입니다.

class PSDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PSDlg)

public:
	PSDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PSDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PSLIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

protected:
	virtual BOOL OnInitDialog();	

public:
	afx_msg void OnLvnItemchangedPslistbox(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl LBset1;
};
