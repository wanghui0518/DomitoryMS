#if !defined(AFX_ADDFORERECORDDLG_H__811FBE9B_C3D2_4CCE_8E8B_B712BBD3E127__INCLUDED_)
#define AFX_ADDFORERECORDDLG_H__811FBE9B_C3D2_4CCE_8E8B_B712BBD3E127__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddForeRecordDlg.h : header file
//
#include "AddForeRecordDlg.h"
#include "ForeignRegRS.h"
#include "StudentRS.h"
/////////////////////////////////////////////////////////////////////////////
// CAddForeRecordDlg dialog

class CAddForeRecordDlg : public CDialog
{
// Construction
public:
	CAddForeRecordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddForeRecordDlg)
	enum { IDD = IDD_ADD_F_RECORD };
	CString	m_ForeName;
	CString	m_FRemarks;
	CString	m_VisitDomiID;
	CString	m_VisutName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddForeRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddForeRecordDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDFORERECORDDLG_H__811FBE9B_C3D2_4CCE_8E8B_B712BBD3E127__INCLUDED_)
