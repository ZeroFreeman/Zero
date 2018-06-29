// StudentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Student.h"
#include "StudentDlg.h"
#include "shlwapi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma comment(lib,"Shlwapi.lib")

typedef struct
{
	CString name;
	CString yw;
	CString sx;
} STUDENT;

int total=0;
CString data_name;
CString strname,stryw,strsx;
STUDENT *s=NULL;
int current_selected=-1;  //当前选择的记录 -- 比如要修改
bool changed=false;       //ListCtrl中数据是否已变动

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg dialog

CStudentDlg::CStudentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStudentDlg, CDialog)
	//{{AFX_MSG_MAP(CStudentDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg message handlers

BOOL CStudentDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	TCHAR temp[100]={'\0'};
	GetModuleFileNameA(NULL,temp,100);
	data_name=temp;
	data_name=data_name.Left(data_name.ReverseFind('\\'));
	data_name+="\\student.dat";
	if(!PathFileExists(data_name))
	{
		MessageBox("数据库文件不存在,正在创建!");
	}
	DWORD listctrl_style=m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(listctrl_style | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0,"姓名",LVCFMT_CENTER,90);
	m_list.InsertColumn(1,"语言",LVCFMT_CENTER,90);
	m_list.InsertColumn(3,"数学",LVCFMT_CENTER,90);

	WriteList();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStudentDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStudentDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStudentDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStudentDlg::WriteList()   //写数据到ListCtrl控件
{
	m_list.DeleteAllItems();
	total=::GetPrivateProfileInt("COUNT","TOTAL",0,data_name);
	
	if(s!=NULL)
	{
		
		delete[] s;
	}
	s=new STUDENT[total];
	for(int i=1;i<=total;i++)
	{
		CString str;
		str.Format("%d",i);
		::GetPrivateProfileString(str,"name","",strname.GetBuffer(MAX_PATH),MAX_PATH,data_name);
		m_list.InsertItem(i-1,strname);
		s[i-1].name=strname;
		::GetPrivateProfileString(str,"yw","",stryw.GetBuffer(MAX_PATH),MAX_PATH,data_name);
		m_list.SetItemText(i-1,1,stryw);
		s[i-1].yw=stryw;
		::GetPrivateProfileString(str,"sx","",strsx.GetBuffer(MAX_PATH),MAX_PATH,data_name);
		m_list.SetItemText(i-1,2,strsx);
		s[i-1].sx=strsx;
	}
}

void CStudentDlg::OnButton1()   //查询
{
	if(changed==true)
	{
		SaveData();
	}
	CString str;
	GetDlgItemText(IDC_EDIT1,str);
	str.Replace(" ","");
	if(str=="")
	{
		MessageBox("查询条件不能为空!","错误",MB_ICONERROR);
		SetDlgItemText(IDC_EDIT1,"");
		return ;
	}
	for(int i=0;i<total;i++)
	{
		if(str==s[i].name || str==s[i].yw || str==s[i].sx)
		{
			SetDlgItemText(IDC_EDIT2,s[i].name);
			SetDlgItemText(IDC_EDIT3,s[i].yw);
			SetDlgItemText(IDC_EDIT4,s[i].sx);
			m_list.SetFocus();
			m_list.SetItemState(i,LVNI_FOCUSED | LVIS_SELECTED, LVNI_FOCUSED | LVIS_SELECTED);
			current_selected=i;
			break;
		}
	}
}

void CStudentDlg::OnButton5()    //清空
{
	SetDlgItemText(IDC_EDIT1,"");
	SetDlgItemText(IDC_EDIT2,"");
	SetDlgItemText(IDC_EDIT3,"");
	SetDlgItemText(IDC_EDIT4,"");
	current_selected=-1;
}

void CStudentDlg::OnButton2()    //修改
{
	GetDlgItemText(IDC_EDIT2,strname);
	GetDlgItemText(IDC_EDIT3,stryw);
	GetDlgItemText(IDC_EDIT4,strsx);
	strname.Replace(" ","");
	stryw.Replace(" ","");
	strsx.Replace(" ","");
	if(strname=="" || stryw=="" || strsx=="")
	{
		MessageBox("输入数据不完整! 请重新输入!","提示",MB_ICONWARNING);
		return ;
	}
	m_list.SetItemText(current_selected,0,strname);
	m_list.SetItemText(current_selected,1,stryw);
	m_list.SetItemText(current_selected,2,strsx);
	s[current_selected].name=strname;
	s[current_selected].yw=stryw;
	s[current_selected].sx=strsx;
	changed=true;
	SetDlgItemText(IDC_EDIT1,"");
	OnButton5();
//	SaveData();
}

void CStudentDlg::SaveData()  //写入数据到文件
{
	
	WinExec("c:\\windows\\system32\\cmd.exe /c del .\\student.bak /q",SW_HIDE);
	Sleep(200);
	WinExec("c:\\windows\\system32\\cmd.exe /c ren .\\student.dat student.bak",SW_HIDE);
	Sleep(200);
	
	CString s;
	int n=m_list.GetItemCount();
	s.Format("%d",n);
	::WritePrivateProfileString("COUNT","TOTAL",s,data_name);
	
	for(int i=0;i<n;i++)
	{
		s.Format("%d",i+1);
		strname=m_list.GetItemText(i,0);
		::WritePrivateProfileString(s,"name",strname,data_name);
		stryw=m_list.GetItemText(i,1);
		::WritePrivateProfileString(s,"yw",stryw,data_name);
		strsx=m_list.GetItemText(i,2);
		::WritePrivateProfileString(s,"sx",strsx,data_name);
	}
	
	WriteList();
}

void CStudentDlg::OnButton3()   //增加
{
	GetDlgItemText(IDC_EDIT2,strname);
	GetDlgItemText(IDC_EDIT3,stryw);
	GetDlgItemText(IDC_EDIT4,strsx);
	strname.Replace(" ","");
	stryw.Replace(" ","");
	strsx.Replace(" ","");
	if(strname=="" || stryw=="" || strsx=="")
	{
		MessageBox("输入数据不完整! 请重新输入!","提示",MB_ICONWARNING);
		return ;
	}

	int n=m_list.GetItemCount();
	m_list.InsertItem(n,strname);
	m_list.SetItemText(n,1,stryw);
	m_list.SetItemText(n,2,strsx);
	OnButton5();
	SaveData();
}

void CStudentDlg::OnButton4()   //删除
{
	POSITION pos=m_list.GetFirstSelectedItemPosition();
	int n=m_list.GetNextSelectedItem(pos);
	if(n==-1)
	{
		MessageBox("未选择要删除的记录!","提示",MB_ICONERROR);
		return ;
	}
	SetDlgItemText(IDC_EDIT1,"");
	m_list.DeleteItem(n);
	m_list.UpdateData();
	Sleep(10);
	OnButton5();
	SaveData();
}

BOOL CStudentDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_RETURN || pMsg->wParam==VK_ESCAPE)
		{
			return true;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}
