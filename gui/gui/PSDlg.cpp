// PSDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "gui.h"
#include "PSDlg.h"
#include "afxdialogex.h"
#include "debugger.h"

using namespace SFdbg;
// PSDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(PSDlg, CDialogEx)

PSDlg::PSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(PSDlg::IDD, pParent)
{

}

PSDlg::~PSDlg()
{
}

void PSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PSLISTBOX, LBset1);
}

BOOL PSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	char *szText[2]={"index","Process Name"};
	int nWid[2]={70,250};
	LV_COLUMN lCol;

	lCol.mask=LVCF_FMT|LVCF_SUBITEM|LVCF_TEXT|LVCF_WIDTH;  //����ü�� ����� Ȯ���� �÷��׸� ����
	lCol.fmt=LVCFMT_LEFT;  //Į���� ������ �������ķ� ����(_CENTER, _LEFT, _RIGHT�� ����)

	for(int i=0; i<2; i++){
		lCol.pszText=szText[i];  //Į���� ������ ����
		lCol.iSubItem=i;  //����������� �ε����� ����
		lCol.cx=nWid[i];  //Į���� ���̸� ����
		LBset1.InsertColumn(i,&lCol);  //LVCOLUMN����ü�� ������� ���� ���� ����Ʈ ��Ʈ�ѿ� Į���� ����
	}

	g_mydebugger.View_Processlist(&LBset1);

	return TRUE;
}

BEGIN_MESSAGE_MAP(PSDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_PSLISTBOX, &PSDlg::OnLvnItemchangedPslistbox)
END_MESSAGE_MAP()


// PSDlg �޽��� ó�����Դϴ�.

void PSDlg::OnLvnItemchangedPslistbox(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}
