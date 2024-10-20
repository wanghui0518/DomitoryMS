#if !defined(AFX_ONDUTYPAGE1_H__8F2B789E_6FBF_4764_AFD0_A3DB92BFDEBE__INCLUDED_)
#define AFX_ONDUTYPAGE1_H__8F2B789E_6FBF_4764_AFD0_A3DB92BFDEBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OnDutyPage1.h : header file
//
#include "OnDutyRS.h"
#include "PersonODRS.h"
#include "AddOnDutyRDlg.h"
/////////////////////////////////////////////////////////////////////////////
// COnDutyPage1 dialog

class COnDutyPage1 : public CPropertyPage
{
	DECLARE_DYNCREATE(COnDutyPage1)

// Construction
public:
	COnDutyPage1();
	~COnDutyPage1();

// Dialog Data
	//{{AFX_DATA(COnDutyPage1)
	enum { IDD = IDD_ON_DUTY_PAGE1 };
	CListCtrl	m_CurList;
	BOOL	m_Date_Retrieve;
	BOOL	m_ID_Retrieve;
	CTime	m_OnDutyTime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COnDutyPage1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COnDutyPage1)
	virtual BOOL OnInitDialog();
	afx_msg void OnRetrieve();
	afx_msg void OnAllRecord();
	afx_msg void OnChangeOnDutyId();
	afx_msg void OnAddRecord();
	afx_msg void OnDeleteRecord();
	afx_msg void OnChangeRecord();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CString TransformTime(long a,CString b);
	void ShowODList(COnDutyRS &OnDutyRS);
	BOOL m_State;//指示列表显示的是当前记录还是所有记录
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONDUTYPAGE1_H__8F2B789E_6FBF_4764_AFD0_A3DB92BFDEBE__INCLUDED_)
