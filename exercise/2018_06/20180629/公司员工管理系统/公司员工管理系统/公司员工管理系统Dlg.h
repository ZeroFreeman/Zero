
// ��˾Ա������ϵͳDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// C��˾Ա������ϵͳDlg �Ի���
class C��˾Ա������ϵͳDlg : public CDialogEx
{
// ����
public:
	void SaveData();
	void WriteList(); 
	void GetandSetNull();
	C��˾Ա������ϵͳDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
};
