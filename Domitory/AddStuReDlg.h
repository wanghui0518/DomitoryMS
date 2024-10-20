#if !defined(AFX_ADDSTUREDLG_H__C228CB1C_BCAE_4DC7_A4A3_53AB558A10BF__INCLUDED_)
#define AFX_ADDSTUREDLG_H__C228CB1C_BCAE_4DC7_A4A3_53AB558A10BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddStuReDlg.h : header file
//
#include "StudentRS.h"
#include "DomitoryRS.h"
/////////////////////////////////////////////////////////////////////////////
// CAddStuReDlg dialog

class CAddStuReDlg : public CDialog
{
// Construction
public:
	CAddStuReDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddStuReDlg)
	enum { IDD = IDD_ADD_STU_RECORD };
	CString	m_StuClass;
	CString	m_StuDomiID;
	CString	m_StuGrade;
	CString	m_StuID;
	CString	m_StuName;
	CString	m_StuRemarks;
	BOOL m_Change;//指示是增加还是修改,值为TRUE时为修改，值为FALSE时为增加
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddStuReDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddStuReDlg)
	afx_msg void OnAddStuRecord();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSTUREDLG_H__C228CB1C_BCAE_4DC7_A4A3_53AB558A10BF__INCLUDED_)
