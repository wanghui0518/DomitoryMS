// Domitory.h : main header file for the DOMITORY application
//

#if !defined(AFX_DOMITORY_H__CA227317_6488_4102_BAD3_0331A9B30B9C__INCLUDED_)
#define AFX_DOMITORY_H__CA227317_6488_4102_BAD3_0331A9B30B9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
//
#include "LoginDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CDomitoryApp:
// See Domitory.cpp for the implementation of this class
//

class CDomitoryApp : public CWinApp
{
public:
	CDomitoryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDomitoryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDomitoryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	int ExitInstance( );
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOMITORY_H__CA227317_6488_4102_BAD3_0331A9B30B9C__INCLUDED_)
