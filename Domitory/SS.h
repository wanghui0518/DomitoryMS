#if !defined(AFX_SS_H__7BC3D339_A99D_4A15_80D3_67B8E8CB1821__INCLUDED_)
#define AFX_SS_H__7BC3D339_A99D_4A15_80D3_67B8E8CB1821__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSS dialog

class CSS : public CDialog
{
// Construction
public:
	CSS(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSS)
	enum { IDD = IDD_ADD_O_D_SCORE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSS)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSS)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SS_H__7BC3D339_A99D_4A15_80D3_67B8E8CB1821__INCLUDED_)
