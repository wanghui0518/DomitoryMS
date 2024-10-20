#if !defined(AFX_STUINFODLG_H__990DE988_62C8_4A00_94AC_AB23535EE7B2__INCLUDED_)
#define AFX_STUINFODLG_H__990DE988_62C8_4A00_94AC_AB23535EE7B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StuInfoDlg.h : header file
//
#include "StudentRS.h"
#include "AddStuReDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg dialog

class CStuInfoDlg : public CDialog
{
// Construction
public:
	CStuInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStuInfoDlg)
	enum { IDD = IDD_STU_INFO };
	CListCtrl	m_StuList;
	BOOL	m_StuName;
	BOOL	m_StuDomiID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStuInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnStuRetrieve();
	afx_msg void OnAddStuRecord();
	afx_msg void OnDelStuRecord();
	afx_msg void OnChangeStuRecord();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ShowStuList(CStudentRS &StudentRS);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUINFODLG_H__990DE988_62C8_4A00_94AC_AB23535EE7B2__INCLUDED_)
