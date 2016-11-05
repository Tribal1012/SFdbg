#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "guiDlg.h"
#include "debugger.h"

// PSDlg ��ȭ �����Դϴ�.

class PSDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PSDlg)

public:
	PSDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~PSDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PSLIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

protected:
	virtual BOOL OnInitDialog();	

public:
	afx_msg void OnLvnItemchangedPslistbox(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl LBset1;
	afx_msg void OnBnClickedClose();
	afx_msg void OnBnClickedOk();
};
