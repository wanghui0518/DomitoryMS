#if !defined(AFX_ADDONDUTYRDLG_H__8D929F44_1CAD_495C_9DFD_361A91AC1E92__INCLUDED_)
#define AFX_ADDONDUTYRDLG_H__8D929F44_1CAD_495C_9DFD_361A91AC1E92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddOnDutyRDlg.h : header file
//
#include "OnDutyRS.h"
/////////////////////////////////////////////////////////////////////////////
// CAddOnDutyRDlg dialog

class CAddOnDutyRDlg : public CDialog
{
// Construction
public:
	CAddOnDutyRDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddOnDutyRDlg)
	enum { IDD = IDD_ADD_ON_DUTY_R };
	CComboBox	m_ComBox2;
	CComboBox	m_ComBox1;
	CString	m_AddOnDutyID;
	CString	m_AddODName;
	CString	m_AddODRemarks;
	BOOL m_Change;   //指示是增加还是修改,值为TRUE时为修改，值为FALSE时为增加
/*	int m_CurSel1,m_CurSel2;//指示两个CComboBox控件当前默认选中第几行*/
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddOnDutyRDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddOnDutyRDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitComBox();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDONDUTYRDLG_H__8D929F44_1CAD_495C_9DFD_361A91AC1E92__INCLUDED_)
