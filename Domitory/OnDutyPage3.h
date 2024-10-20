#if !defined(AFX_ONDUTYPAGE3_H__18763EEB_5D17_4B45_BB15_BFECA81E0421__INCLUDED_)
#define AFX_ONDUTYPAGE3_H__18763EEB_5D17_4B45_BB15_BFECA81E0421__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OnDutyPage3.h : header file
//
#include "ODScoreRS.h"
/////////////////////////////////////////////////////////////////////////////
// COnDutyPage3 dialog

class COnDutyPage3 : public CPropertyPage
{
	DECLARE_DYNCREATE(COnDutyPage3)

// Construction
public:
	COnDutyPage3();
	~COnDutyPage3();

// Dialog Data
	//{{AFX_DATA(COnDutyPage3)
	enum { IDD = IDD_ON_DUTY_PAGE3 };
	CListCtrl	m_CheckList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COnDutyPage3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COnDutyPage3)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void ShowCheckList(CODScoreRS &ODScoreRS);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONDUTYPAGE3_H__18763EEB_5D17_4B45_BB15_BFECA81E0421__INCLUDED_)
