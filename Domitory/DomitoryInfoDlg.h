#if !defined(AFX_DOMITORYINFODLG_H__5B348188_2C5F_4D1C_BA7D_BD6FF7CCEA7F__INCLUDED_)
#define AFX_DOMITORYINFODLG_H__5B348188_2C5F_4D1C_BA7D_BD6FF7CCEA7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DomitoryInfoDlg.h : header file
//
#include "DomitoryRS.h"
#include "AddDIRecordDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CDomitoryInfoDlg dialog

class CDomitoryInfoDlg : public CDialog
{
// Construction
public:
	CDomitoryInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDomitoryInfoDlg)
	enum { IDD = IDD_DOMITORY_INFO };
	CListCtrl	m_DIList;
	int		m_DomiRetrive;
	long	m_lowNum;
	long	m_HighNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDomitoryInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDomitoryInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBeginRetrieve();
	afx_msg void OnAddDIRecord();
	afx_msg void OnDelDIRecord();
	afx_msg void OnChangeDIRECORD();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ShowDIList(CDomitoryRS &DomitoryRS);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOMITORYINFODLG_H__5B348188_2C5F_4D1C_BA7D_BD6FF7CCEA7F__INCLUDED_)
