#if !defined(AFX_ADDDIRECORDDLG_H__644E2F20_B5E2_4A36_9ADD_53F76672D8D0__INCLUDED_)
#define AFX_ADDDIRECORDDLG_H__644E2F20_B5E2_4A36_9ADD_53F76672D8D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddDIRecordDlg.h : header file
//
#include "DomitoryRS.h"
/////////////////////////////////////////////////////////////////////////////
// CAddDIRecordDlg dialog

class CAddDIRecordDlg : public CDialog
{
// Construction
public:
	CAddDIRecordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddDIRecordDlg)
	enum { IDD = IDD_ADD_DOMITORY };
	CString	m_ADID;
	long	m_ADNum;
	CString	m_ADRemarks;
	CString	m_ADTIChange;
	BOOL m_Change;//指示是增加还是修改,值为TRUE时为修改，值为FALSE时为增加
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddDIRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddDIRecordDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDIRECORDDLG_H__644E2F20_B5E2_4A36_9ADD_53F76672D8D0__INCLUDED_)
