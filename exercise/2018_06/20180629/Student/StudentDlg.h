// StudentDlg.h : header file
//

#if !defined(AFX_STUDENTDLG_H__CE4A1E8E_86F3_4AD6_A7D1_1F86220D5B1E__INCLUDED_)
#define AFX_STUDENTDLG_H__CE4A1E8E_86F3_4AD6_A7D1_1F86220D5B1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg dialog

class CStudentDlg : public CDialog
{
// Construction
public:
	void SaveData();
	void WriteList();
	CStudentDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStudentDlg)
	enum { IDD = IDD_STUDENT_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStudentDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton5();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTDLG_H__CE4A1E8E_86F3_4AD6_A7D1_1F86220D5B1E__INCLUDED_)
