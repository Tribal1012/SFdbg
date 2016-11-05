// PE_viewer.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "gui.h"
#include "PE_viewer.h"
#include "afxdialogex.h"
#include "PE_header.h"


// PE_viewer 대화 상자입니다.

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

	lCol.mask=LVCF_FMT|LVCF_SUBITEM|LVCF_TEXT|LVCF_WIDTH;  //구조체의 기능을 확장할 플래그를 지정
	lCol.fmt=LVCFMT_LEFT;  //칼럼의 정렬을 왼쪽정렬로 지정(_CENTER, _LEFT, _RIGHT중 선택)

	for(int i=0; i<3; i++){
		lCol.pszText=szText[i];  //칼럼의 제목을 지정
		lCol.iSubItem=i;  //서브아이템의 인덱스를 지정
		lCol.cx=nWid[i];  //칼럼의 넓이를 지정
		pelist.InsertColumn(i,&lCol);  //LVCOLUMN구조체로 만들어진 값을 토대로 리스트 컨트롤에 칼럼을 삽입
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


// PE_viewer 메시지 처리기입니다.


void PE_viewer::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void PE_viewer::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void PE_viewer::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
