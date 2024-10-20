#if !defined(AFX_ADDPRECORDDLG_H__75F20E4A_47F3_4D1B_8EC4_C073B9816DD9__INCLUDED_)
#define AFX_ADDPRECORDDLG_H__75F20E4A_47F3_4D1B_8EC4_C073B9816DD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddPRecordDlg.h : header file
//
#include "PersonODRS.h"
/////////////////////////////////////////////////////////////////////////////
// CAddPRecordDlg dialog

class CAddPRecordDlg : public CDialog
{
// Construction
public:
	CAddPRecordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddPRecordDlg)
	enum { IDD = IDD_ADD_O_D_PERSON };
	CString	m_AddPID;
	CString	m_AddPName;
	CString	m_AddPRemarks;
	CString	m_AddPState;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddPRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddPRecordDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	BOOL m_Change;   //指示是增加还是修改,值为TRUE时为修改，值为FALSE时为增加
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDPRECORDDLG_H__75F20E4A_47F3_4D1B_8EC4_C073B9816DD9__INCLUDED_)
