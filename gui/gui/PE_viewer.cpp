// PE_viewer.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "gui.h"
#include "PE_viewer.h"
#include "afxdialogex.h"
#include "PE_header.h"


// PE_viewer ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(PE_viewer, CDialogEx)

PE_viewer::PE_viewer(CWnd* pParent /*=NULL*/)
	: CDialogEx(PE_viewer::IDD, pParent)
{

}

PE_viewer::~PE_viewer()
{
}

void PE_viewer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, pelist);
}

BOOL PE_viewer::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	char *szText[3]={"Define", "Value", "Explain"};
	int nWid[3]={100,150, 290};
	LV_COLUMN lCol;

	lCol.mask=LVCF_FMT|LVCF_SUBITEM|LVCF_TEXT|LVCF_WIDTH;  //����ü�� ����� Ȯ���� �÷��׸� ����
	lCol.fmt=LVCFMT_LEFT;  //Į���� ������ �������ķ� ����(_CENTER, _LEFT, _RIGHT�� ����)

	for(int i=0; i<3; i++){
		lCol.pszText=szText[i];  //Į���� ������ ����
		lCol.iSubItem=i;  //����������� �ε����� ����
		lCol.cx=nWid[i];  //Į���� ���̸� ����
		pelist.InsertColumn(i,&lCol);  //LVCOLUMN����ü�� ������� ���� ���� ����Ʈ ��Ʈ�ѿ� Į���� ����
	}

	return TRUE;
}


BEGIN_MESSAGE_MAP(PE_viewer, CDialogEx)
	ON_BN_CLICKED(IDOK, &PE_viewer::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &PE_viewer::OnBnClickedCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &PE_viewer::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_RADIO1, &PE_viewer::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &PE_viewer::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &PE_viewer::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &PE_viewer::OnBnClickedRadio4)
END_MESSAGE_MAP()


// PE_viewer �޽��� ó�����Դϴ�.


void PE_viewer::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
}


void PE_viewer::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnCancel();
}


void PE_viewer::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


void PE_viewer::OnBnClickedRadio1()		// DOS Header
{
	pelist.DeleteAllItems();
	Print_DOS_Header(&pelist);
}


void PE_viewer::OnBnClickedRadio2()		// NT Header
{
	pelist.DeleteAllItems();
	Print_NT_Header(&pelist);
}


void PE_viewer::OnBnClickedRadio3()		// Section Header
{
	pelist.DeleteAllItems();
	Print_SECTION_Header(&pelist);
}


void PE_viewer::OnBnClickedRadio4()		//IAT EAT
{
	pelist.DeleteAllItems();
}
