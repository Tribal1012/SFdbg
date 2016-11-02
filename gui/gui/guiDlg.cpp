// guiDlg.cpp : 구현 파일
//
#include "stdafx.h"
#include "gui.h"
#include "guiDlg.h"
#include "afxdialogex.h"
#include "winuser.h"
#include "PSDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
using namespace SFdbg;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CguiDlg 대화 상자




CguiDlg::CguiDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CguiDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CguiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_LIST4, m_list4);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_LIST3, m_list3);
	DDX_Control(pDX, IDC_LIST5, m_list5);
}

BEGIN_MESSAGE_MAP(CguiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CguiDlg::OnBnClickedButton1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CguiDlg::OnLvnItemchangedList1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CguiDlg::OnLvnItemchangedList2)
	ON_LBN_SELCHANGE(IDC_LIST3, &CguiDlg::OnLbnSelchangeList3)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST4, &CguiDlg::OnLvnItemchangedList4)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST5, &CguiDlg::OnLvnItemchangedList5)
	ON_BN_CLICKED(IDC_BUTTON2, &CguiDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CguiDlg::OnBnClickedButton3)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON4, &CguiDlg::OnBnClickedButton4)
END_MESSAGE_MAP()

void MakeColumn(CListCtrl* m_list, const char** szText, const unsigned int* nWid, const unsigned int count)
{
	LV_COLUMN lCol;

	lCol.mask=LVCF_FMT|LVCF_SUBITEM|LVCF_TEXT|LVCF_WIDTH;  //구조체의 기능을 확장할 플래그를 지정
	lCol.fmt=LVCFMT_LEFT;  //칼럼의 정렬을 왼쪽정렬로 지정(_CENTER, _LEFT, _RIGHT중 선택)

	for(unsigned int i=0; i<count; i++){
		lCol.pszText=(LPSTR)szText[i];  //칼럼의 제목을 지정
		lCol.iSubItem=i;  //서브아이템의 인덱스를 지정
		lCol.cx=nWid[i];  //칼럼의 넓이를 지정
		m_list->InsertColumn(i,&lCol);  //LVCOLUMN구조체로 만들어진 값을 토대로 리스트 컨트롤에 칼럼을 삽입
	}
}

// CguiDlg 메시지 처리기

BOOL CguiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	//SetBackgroundColor(RGB(0,0,0)); 배경색 검은색.....리스트박스, 도구들은 색안바뀜

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	const char *szText1[]={"Offset","Instruction","Disassemble"};
	unsigned int nWid1[]={100,300,700};
	const char *szText2[]={"Register","Value"};
	unsigned int nWid2[]={100,400};
	const char *szText4[]={"TimeStamp", "EAX", "EBX", "ECX", "EDX", "EBP", "ESP", "ESI", "EDI", "EIP", "EFLAGS"};
	unsigned int nWid4[]={100, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80};
	const char *szText5[]={"Address","0x0", "0x4", "0x8", "0xC"};
	unsigned int nWid5[]={100, 100, 100, 100, 100};

	MakeColumn(&m_list1, szText1, nWid1, 3);
	MakeColumn(&m_list2, szText2, nWid2, 2);
	MakeColumn(&m_list5, szText5, nWid5, 5);
	MakeColumn(&m_list4, szText4, nWid4, 11);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CguiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		if(nID == SC_CLOSE) {			//종료
			OnClose();
			OnDestroy();
		}else if(nID == SC_MAXIMIZE) {	//최대화
		}else if(nID == SC_MINIMIZE) {	//최소화
		}else if(nID == SC_RESTORE) {	//최소화에서 다시 돌아오거나 할 때
			AfxMessageBox("hi...");
		}

		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CguiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

/*HBRUSH CguiDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) //리스트박스 색변경, 색변경이 안됨...............................
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	 if(nCtlColor == CTLCOLOR_LISTBOX)
    {
        if(pWnd->GetDlgCtrlID() == IDC_LIST1)
        {
            //pDC->SetTextColor(RGB(255, 0, 0));
            pDC->SetBackgroundColor(RGB(255,255,0));
        }
    }
	return hbr;
}*/

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CguiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//프로그램 종료
BOOL CguiDlg::OnClose()
{
	return TRUE;
}

//프로그램 종료
void CguiDlg::OnDestroy()
{
	//Destroy_PE_Format();
	//if(!Destroy_DB()) exit(-1);
}


void CguiDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}

void CguiDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)		//Disassem
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CguiDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)		//Register
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}

void CguiDlg::OnLbnSelchangeList3()
{
	// 현재 위치, 레지스터 값 등 출력?
}


void CguiDlg::OnLvnItemchangedList4(NMHDR *pNMHDR, LRESULT *pResult)		//Timeless
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CguiDlg::OnLvnItemchangedList5(NMHDR *pNMHDR, LRESULT *pResult)		//Stack
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CguiDlg::OnBnClickedButton1()
{
	// 파일 불러오기 아이콘 및 기능추가
	TCHAR szFilters[]=_T("실행파일(*.exe)|.exe|모든파일(*.*)|*.*||");

	CFileDialog dlgFile(TRUE,_T("exe"),_T("*.exe"),OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);
	if(dlgFile.DoModal()==IDOK)
	{
		CString pathName = dlgFile.GetPathName();
		CString fileName = dlgFile.GetFileTitle();
		//불러온 파일의 분석내용을 ListBox에 출력하도록
		if(!g_mydebugger.Open_Process(fileName, pathName)) exit(-1);
		//if(!Init_DB()) exit(-1);
		g_mydebugger.Start_Debug(&m_list1, &m_list2, NULL, &m_list4, &m_list5);
	}
}

void CguiDlg::OnBnClickedButton2()
{
	// Attach
	PSDlg psdlg;
	psdlg.DoModal();
}

void CguiDlg::OnBnClickedButton3()
{
	if(g_mydebugger.Get_ExecConfig(0)) {
		// Single Step
		g_mydebugger.Set_ExecConfig(3);
		g_mydebugger.Start_Debug(&m_list1, &m_list2, NULL, &m_list4, &m_list5);
	}
	else {
		AfxMessageBox("Please Open or Attach Process for Debugging.");
	}
}

void CguiDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(g_mydebugger.Get_ExecConfig(0)) {
		// Single Step
		g_mydebugger.Set_ExecConfig(2);
		while(g_mydebugger.Get_ExecConfig(3)) {
			g_mydebugger.Start_Debug(&m_list1, &m_list2, NULL, &m_list4, &m_list5);
		}
	}
	else {
		AfxMessageBox("Please Open or Attach Process for Debugging.");
	}
}
