
// ��˾Ա������ϵͳ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��˾Ա������ϵͳApp:
// �йش����ʵ�֣������ ��˾Ա������ϵͳ.cpp
//

class C��˾Ա������ϵͳApp : public CWinApp
{
public:
	C��˾Ա������ϵͳApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��˾Ա������ϵͳApp theApp;