#if !defined(AFX_ONDUTYPAGE2_H__00E207E7_7FF4_484E_AE89_1337BEFAC188__INCLUDED_)
#define AFX_ONDUTYPAGE2_H__00E207E7_7FF4_484E_AE89_1337BEFAC188__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OnDutyPage2.h : header file
//
#include "PersonODRS.h"
#include "AddPRecordDlg.h"
/////////////////////////////////////////////////////////////////////////////
// COnDutyPage2 dialog

class COnDutyPage2 : public CPropertyPage
{
	DECLARE_DYNCREATE(COnDutyPage2)

// Construction
public:
	COnDutyPage2();
	~COnDutyPage2();

// Dialog Data
	//{{AFX_DATA(COnDutyPage2)
	enum { IDD = IDD_ON_DUTY_PAGE2 };
	CListCtrl	m_PList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COnDutyPage2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COnDutyPage2)
	virtual BOOL OnInitDialog();
	afx_msg void OnAddPRecord();
	afx_msg void OnDeletePRecord();
	afx_msg void OnChangePRecord();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void ShowPList(CPersonODRS &PersonODRS);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONDUTYPAGE2_H__00E207E7_7FF4_484E_AE89_1337BEFAC188__INCLUDED_)
