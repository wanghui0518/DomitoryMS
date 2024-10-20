#if !defined(AFX_ONDUTYDLG_H__441348B8_6BE6_4FB2_9DBE_741546828D03__INCLUDED_)
#define AFX_ONDUTYDLG_H__441348B8_6BE6_4FB2_9DBE_741546828D03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OnDutyDlg.h : header file
//
#include "OnDutyPage1.h"
#include "OnDutyPage2.h"
#include "OnDutyPage3.h"
/////////////////////////////////////////////////////////////////////////////
// COnDutyDlg dialog

class COnDutyDlg : public CDialog
{
// Construction
public:
	COnDutyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COnDutyDlg)
	enum { IDD = IDD_ON_DUTY };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COnDutyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COnDutyDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	COnDutyPage1 m_OnDutyPage1;
	COnDutyPage2 m_OnDutyPage2;
	COnDutyPage3 m_OnDutyPage3;
	CPropertySheet m_ODProSheet;
private:
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONDUTYDLG_H__441348B8_6BE6_4FB2_9DBE_741546828D03__INCLUDED_)
