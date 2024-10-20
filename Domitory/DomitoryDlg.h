// DomitoryDlg.h : header file
//

#if !defined(AFX_DOMITORYDLG_H__8D2E074F_2FA9_47A5_A8ED_311F72E5DF35__INCLUDED_)
#define AFX_DOMITORYDLG_H__8D2E074F_2FA9_47A5_A8ED_311F72E5DF35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//
#include "OnDutyDlg.h"
#include "DomitoryInfoDlg.h"
#include "StuInfoDlg.h"
#include "ForeignRegDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CDomitoryDlg dialog

class CDomitoryDlg : public CDialog
{
// Construction
public:
	CDomitoryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDomitoryDlg)
	enum { IDD = IDD_DOMITORY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDomitoryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDomitoryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRelogin();
	afx_msg void OnOnDutyInfo();
	afx_msg void OnDomitoryInfo();
	afx_msg void OnStudentInfo();
	afx_msg void OnForeignInfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetFont();
	CFont m_Font;
public:
	~CDomitoryDlg();
	COnDutyDlg *m_OnDutyDlg;
	CDomitoryInfoDlg *m_DomiInfoDlg;
	CStuInfoDlg *m_StuInfoDlg;
	CForeignRegDlg *m_ForeignRegDlg;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOMITORYDLG_H__8D2E074F_2FA9_47A5_A8ED_311F72E5DF35__INCLUDED_)
