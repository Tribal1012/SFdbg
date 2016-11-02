// guiDlg.cpp : ���� ����
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

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CguiDlg ��ȭ ����




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

	lCol.mask=LVCF_FMT|LVCF_SUBITEM|LVCF_TEXT|LVCF_WIDTH;  //����ü�� ����� Ȯ���� �÷��׸� ����
	lCol.fmt=LVCFMT_LEFT;  //Į���� ������ �������ķ� ����(_CENTER, _LEFT, _RIGHT�� ����)

	for(unsigned int i=0; i<count; i++){
		lCol.pszText=(LPSTR)szText[i];  //Į���� ������ ����
		lCol.iSubItem=i;  //����������� �ε����� ����
		lCol.cx=nWid[i];  //Į���� ���̸� ����
		m_list->InsertColumn(i,&lCol);  //LVCOLUMN����ü�� ������� ���� ���� ����Ʈ ��Ʈ�ѿ� Į���� ����
	}
}

// CguiDlg �޽��� ó����

BOOL CguiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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
	//SetBackgroundColor(RGB(0,0,0)); ���� ������.....����Ʈ�ڽ�, �������� ���ȹٲ�

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
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

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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
		if(nID == SC_CLOSE) {			//����
			OnClose();
			OnDestroy();
		}else if(nID == SC_MAXIMIZE) {	//�ִ�ȭ
		}else if(nID == SC_MINIMIZE) {	//�ּ�ȭ
		}else if(nID == SC_RESTORE) {	//�ּ�ȭ���� �ٽ� ���ƿ��ų� �� ��
			AfxMessageBox("hi...");
		}

		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CguiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

/*HBRUSH CguiDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) //����Ʈ�ڽ� ������, �������� �ȵ�...............................
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

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CguiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//���α׷� ����
BOOL CguiDlg::OnClose()
{
	return TRUE;
}

//���α׷� ����
void CguiDlg::OnDestroy()
{
	//Destroy_PE_Format();
	//if(!Destroy_DB()) exit(-1);
}


void CguiDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}

void CguiDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)		//Disassem
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


void CguiDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)		//Register
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}

void CguiDlg::OnLbnSelchangeList3()
{
	// ���� ��ġ, �������� �� �� ���?
}


void CguiDlg::OnLvnItemchangedList4(NMHDR *pNMHDR, LRESULT *pResult)		//Timeless
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


void CguiDlg::OnLvnItemchangedList5(NMHDR *pNMHDR, LRESULT *pResult)		//Stack
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


void CguiDlg::OnBnClickedButton1()
{
	// ���� �ҷ����� ������ �� ����߰�
	TCHAR szFilters[]=_T("��������(*.exe)|.exe|�������(*.*)|*.*||");

	CFileDialog dlgFile(TRUE,_T("exe"),_T("*.exe"),OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);
	if(dlgFile.DoModal()==IDOK)
	{
		CString pathName = dlgFile.GetPathName();
		CString fileName = dlgFile.GetFileTitle();
		//�ҷ��� ������ �м������� ListBox�� ����ϵ���
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
