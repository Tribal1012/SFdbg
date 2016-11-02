// PSDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "gui.h"
#include "PSDlg.h"
#include "afxdialogex.h"
#include "debugger.h"

using namespace SFdbg;
// PSDlg 대화 상자입니다.

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

	lCol.mask=LVCF_FMT|LVCF_SUBITEM|LVCF_TEXT|LVCF_WIDTH;  //구조체의 기능을 확장할 플래그를 지정
	lCol.fmt=LVCFMT_LEFT;  //칼럼의 정렬을 왼쪽정렬로 지정(_CENTER, _LEFT, _RIGHT중 선택)

	for(int i=0; i<2; i++){
		lCol.pszText=szText[i];  //칼럼의 제목을 지정
		lCol.iSubItem=i;  //서브아이템의 인덱스를 지정
		lCol.cx=nWid[i];  //칼럼의 넓이를 지정
		LBset1.InsertColumn(i,&lCol);  //LVCOLUMN구조체로 만들어진 값을 토대로 리스트 컨트롤에 칼럼을 삽입
	}

	g_mydebugger.View_Processlist(&LBset1);

	return TRUE;
}

BEGIN_MESSAGE_MAP(PSDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_PSLISTBOX, &PSDlg::OnLvnItemchangedPslistbox)
END_MESSAGE_MAP()


// PSDlg 메시지 처리기입니다.

void PSDlg::OnLvnItemchangedPslistbox(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
