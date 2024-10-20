#if !defined(AFX_FOREIGNREGDLG_H__ACDE6EFC_753F_48A5_9437_35DA1197F348__INCLUDED_)
#define AFX_FOREIGNREGDLG_H__ACDE6EFC_753F_48A5_9437_35DA1197F348__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ForeignRegDlg.h : header file
//
#include "ForeignRegRS.h"
#include "AddForeRecordDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CForeignRegDlg dialog

class CForeignRegDlg : public CDialog
{
// Construction
public:
	CForeignRegDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CForeignRegDlg)
	enum { IDD = IDD_FOREIGN_REG };
	CListCtrl	m_ForeignList;
	/*BOOL	m_TimeRetrieve;*/
	BOOL	m_NameRetrieve;
	/*CTime	m_FTime;*/
	CString	m_FName;
	CString	m_VDomitory;
	BOOL	m_V_D_Retrieve;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CForeignRegDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CForeignRegDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAddForeRecord();
	afx_msg void OnDelForeRecord();
	afx_msg void OnAddLeaveTime();
	afx_msg void OnFBRetrieve();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ShowForeList(CForeignRegRS &ForeignRegRS);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOREIGNREGDLG_H__ACDE6EFC_753F_48A5_9437_35DA1197F348__INCLUDED_)
