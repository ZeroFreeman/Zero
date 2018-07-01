
// ��˾Ա������ϵͳDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��˾Ա������ϵͳ.h"
#include "��˾Ա������ϵͳDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma comment(lib,"Shlwapi.lib")

typedef struct
{
	CString number;
	CString password;
	CString name;
	CString sex;
	CString department;
	CString level;
	CString wages;
} STUDENT;

int total=0;
CString data_name;
CString strnumber, strpassword, strname, strsex, strdepartment, strlevel, strwages;
STUDENT *s=NULL;
int current_selected=-1;  //��ǰѡ��ļ�¼ -- ����Ҫ�޸�
bool changed=false;       //ListCtrl�������Ƿ��ѱ䶯

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// C��˾Ա������ϵͳDlg �Ի���




C��˾Ա������ϵͳDlg::C��˾Ա������ϵͳDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��˾Ա������ϵͳDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��˾Ա������ϵͳDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(C��˾Ա������ϵͳDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C��˾Ա������ϵͳDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C��˾Ա������ϵͳDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &C��˾Ա������ϵͳDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &C��˾Ա������ϵͳDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &C��˾Ա������ϵͳDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// C��˾Ա������ϵͳDlg ��Ϣ�������

BOOL C��˾Ա������ϵͳDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	TCHAR temp[100]={'\0'};
	GetModuleFileName(NULL,temp,100);
	data_name=temp;
	data_name=data_name.Left(data_name.ReverseFind('\\'));
	data_name+="\\student.dat";
	if(!PathFileExists(data_name))
	{
		MessageBox(_T("���ݿ��ļ�������,���ڴ���!"));
	}

	DWORD listctrl_style=m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(listctrl_style | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0,_T("���"),LVCFMT_CENTER,150);
	m_list.InsertColumn(1,_T("����"),LVCFMT_CENTER,150);
	m_list.InsertColumn(2,_T("����"),LVCFMT_CENTER,90);
	m_list.InsertColumn(3,_T("�Ա�"),LVCFMT_CENTER,60);
	m_list.InsertColumn(4,_T("����"),LVCFMT_CENTER,90);
	m_list.InsertColumn(5,_T("����"),LVCFMT_CENTER,90);
	m_list.InsertColumn(6,_T("н��/��"),LVCFMT_CENTER,120);

	WriteList();



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C��˾Ա������ϵͳDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C��˾Ա������ϵͳDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

void C��˾Ա������ϵͳDlg::WriteList()   //д���ݵ�ListCtrl�ؼ�
{
	m_list.DeleteAllItems();
	total=::GetPrivateProfileInt(_T("COUNT"),_T("TOTAL"),0,data_name);
	
	if(s!=NULL)
	{
		
		delete[] s;
	}
	s=new STUDENT[total];
	for(int i=1;i<=total;i++)
	{
		CString str;
		str.Format(_T("%d"),i);
		::GetPrivateProfileString(str,_T("number"),_T(""),strnumber.GetBuffer(MAX_PATH),MAX_PATH,data_name);
		m_list.InsertItem(i-1,strnumber);
		s[i-1].number=strnumber;
		::GetPrivateProfileString(str,_T("password"),_T(""),strpassword.GetBuffer(MAX_PATH),MAX_PATH,data_name);
		m_list.SetItemText(i-1,1,strpassword);
		s[i-1].password=strpassword;
		::GetPrivateProfileString(str,_T("name"),_T(""),strname.GetBuffer(MAX_PATH),MAX_PATH,data_name);
		m_list.SetItemText(i-1,2,strname);
		s[i-1].name=strname;
		::GetPrivateProfileString(str,_T("sex"),_T(""),strsex.GetBuffer(MAX_PATH),MAX_PATH,data_name);
		m_list.SetItemText(i-1,3,strsex);
		s[i-1].sex=strsex;
		::GetPrivateProfileString(str,_T("department"),_T(""),strdepartment.GetBuffer(MAX_PATH),MAX_PATH,data_name);
		m_list.SetItemText(i-1,4,strdepartment);
		s[i-1].department=strdepartment;
		::GetPrivateProfileString(str,_T("level"),_T(""),strlevel.GetBuffer(MAX_PATH),MAX_PATH,data_name);
		m_list.SetItemText(i-1,5,strlevel);
		s[i-1].level=strlevel;
		::GetPrivateProfileString(str,_T("wages"),_T(""),strwages.GetBuffer(MAX_PATH),MAX_PATH,data_name);
		m_list.SetItemText(i-1,6,strwages);
		s[i-1].wages=strwages;
	}
}



void C��˾Ա������ϵͳDlg::GetandSetNull()	//������
{
	GetDlgItemText(IDC_EDIT2,strnumber);
	GetDlgItemText(IDC_EDIT3,strpassword);
	GetDlgItemText(IDC_EDIT4,strname);
	GetDlgItemText(IDC_EDIT5,strsex);
	GetDlgItemText(IDC_EDIT6,strdepartment);
	GetDlgItemText(IDC_EDIT7,strlevel);
	GetDlgItemText(IDC_EDIT8,strwages);

	strnumber.Replace(_T(" "),_T(""));
	strpassword.Replace(_T(" "),_T(""));
	strname.Replace(_T(" "),_T(""));
	strsex.Replace(_T(" "),_T(""));
	strdepartment.Replace(_T(" "),_T(""));
	strlevel.Replace(_T(" "),_T(""));
	strwages.Replace(_T(" "),_T(""));

	if(strnumber=="" || strpassword=="" || strname=="" || strsex=="" || strdepartment=="" || strlevel=="" || strwages=="")
	{
		MessageBox(_T("�������ݲ�����! ����������!"),_T("��ʾ"),MB_ICONWARNING);
		return ;
	}
}




void C��˾Ա������ϵͳDlg::OnBnClickedButton1()	//��ѯ��Ϣ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(changed==true)
	{
		SaveData();
	}
	CString str;
	GetDlgItemText(IDC_EDIT1,str);
	str.Replace(_T(" "),_T(""));
	if(str=="")
	{
		MessageBox(_T("��ѯ��������Ϊ��!"),_T("����"),MB_ICONERROR);
		SetDlgItemText(IDC_EDIT1,_T(""));
		return ;
	}
	for(int i=0;i<total;i++)
	{
		if(str==s[i].number || str==s[i].password || str==s[i].name || str==s[i].sex || str==s[i].department || str==s[i].level || str==s[i].wages)
		{
			SetDlgItemText(IDC_EDIT2,s[i].number);
			SetDlgItemText(IDC_EDIT3,s[i].password);
			SetDlgItemText(IDC_EDIT4,s[i].name);
			SetDlgItemText(IDC_EDIT5,s[i].sex);
			SetDlgItemText(IDC_EDIT6,s[i].department);
			SetDlgItemText(IDC_EDIT7,s[i].level);
			SetDlgItemText(IDC_EDIT8,s[i].wages);
			m_list.SetFocus();
			m_list.SetItemState(i,LVNI_FOCUSED | LVIS_SELECTED, LVNI_FOCUSED | LVIS_SELECTED);
			current_selected=i;
			break;
		}
	}
}



void C��˾Ա������ϵͳDlg::SaveData()  //д�����ݵ��ļ�
{
	WinExec("c:\\windows\\system32\\cmd.exe /c del .\\student.bak /q",SW_HIDE);
	Sleep(200);
	WinExec("c:\\windows\\system32\\cmd.exe /c ren .\\student.dat student.bak",SW_HIDE);
	Sleep(200);
	
	CString s;
	int n=m_list.GetItemCount();
	s.Format(_T("%d"),n);
	::WritePrivateProfileString(_T("COUNT"),_T("TOTAL"),s,data_name);
	
	for(int i=0;i<n;i++)
	{
		s.Format(_T("%d"),i+1);
		strnumber=m_list.GetItemText(i,0);
		::WritePrivateProfileString(s,_T("number"),strnumber,data_name);
		strpassword=m_list.GetItemText(i,1);
		::WritePrivateProfileString(s,_T("password"),strpassword,data_name);
		strname=m_list.GetItemText(i,2);
		::WritePrivateProfileString(s,_T("name"),strname,data_name);
		strsex=m_list.GetItemText(i,3);
		::WritePrivateProfileString(s,_T("sex"),strsex,data_name);
		strdepartment=m_list.GetItemText(i,4);
		::WritePrivateProfileString(s,_T("department"),strdepartment,data_name);
		strlevel=m_list.GetItemText(i,5);
		::WritePrivateProfileString(s,_T("level"),strlevel,data_name);
		strwages=m_list.GetItemText(i,6);
		::WritePrivateProfileString(s,_T("wages"),strwages,data_name);
	}
	
	WriteList();
	changed=false;
}

void C��˾Ա������ϵͳDlg::OnBnClickedButton2()	//��������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetandSetNull();

	int n=m_list.GetItemCount();
	m_list.InsertItem(n,strnumber);
	m_list.SetItemText(n,1,strpassword);
	m_list.SetItemText(n,2,strname);
	m_list.SetItemText(n,3,strsex);
	m_list.SetItemText(n,4,strdepartment);
	m_list.SetItemText(n,5,strlevel);
	m_list.SetItemText(n,6,strwages);
	
	OnBnClickedButton4();
	SaveData();
}


void C��˾Ա������ϵͳDlg::OnBnClickedButton5()	//ɾ��һ����Ϣ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos=m_list.GetFirstSelectedItemPosition();
	int n=m_list.GetNextSelectedItem(pos);
	if(n==-1)
	{
		MessageBox(_T("δѡ��Ҫɾ���ļ�¼!"),_T("��ʾ"),MB_ICONERROR);
		return ;
	}
	m_list.DeleteItem(n);
	m_list.UpdateData();
	Sleep(10);

	OnBnClickedButton4();
	SaveData();
}


void C��˾Ա������ϵͳDlg::OnBnClickedButton4()	//���
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetDlgItemText(IDC_EDIT1,_T(""));
	SetDlgItemText(IDC_EDIT2,_T(""));
	SetDlgItemText(IDC_EDIT3,_T(""));
	SetDlgItemText(IDC_EDIT4,_T(""));
	SetDlgItemText(IDC_EDIT5,_T(""));
	SetDlgItemText(IDC_EDIT6,_T(""));
	SetDlgItemText(IDC_EDIT7,_T(""));
	SetDlgItemText(IDC_EDIT8,_T(""));

	current_selected=-1;
}


void C��˾Ա������ϵͳDlg::OnBnClickedButton3()	//�޸ģ���Ҫ�Ȳ�ѯ��ָ�������ٽ����޸�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetandSetNull();

	m_list.SetItemText(current_selected,0,strnumber);
	m_list.SetItemText(current_selected,1,strpassword);
	m_list.SetItemText(current_selected,2,strname);
	m_list.SetItemText(current_selected,3,strsex);
	m_list.SetItemText(current_selected,4,strdepartment);
	m_list.SetItemText(current_selected,5,strlevel);
	m_list.SetItemText(current_selected,6,strwages);

	s[current_selected].number=strnumber;
	s[current_selected].password=strpassword;
	s[current_selected].name=strname;
	s[current_selected].sex=strsex;
	s[current_selected].department=strdepartment;
	s[current_selected].level=strlevel;
	s[current_selected].wages=strwages;
	changed=true;

	OnBnClickedButton4();
	SaveData();
}





//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C��˾Ա������ϵͳDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



