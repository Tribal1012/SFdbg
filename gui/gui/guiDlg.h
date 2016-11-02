
// guiDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "Disassem.h"
#include "debugger.h"
#include "PE_header.h"
#include "Timeless.h"
#include "afxcmn.h"

// CguiDlg ��ȭ ����
class CguiDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CguiDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_GUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnClose();
	virtual void OnDestroy();
public:
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLbnSelchangeList3();
	afx_msg void OnLvnItemchangedList4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();		//Open
	afx_msg void OnBnClickedButton2();		//Attach
	afx_msg void OnBnClickedButton3();		//Single Step
	afx_msg void OnBnClickedButton4();		//Process List
	//afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CListCtrl m_list1;
	CListCtrl m_list2;
	CListBox m_list3;
	CListCtrl m_list4;
	CListCtrl m_list5;
};
