#if !defined(AFX_ODSCORERS_H__5E61CD7B_E580_4A12_B826_957ECD0855F4__INCLUDED_)
#define AFX_ODSCORERS_H__5E61CD7B_E580_4A12_B826_957ECD0855F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ODScoreRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CODScoreRS recordset

class CODScoreRS : public CRecordset
{
public:
	CODScoreRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CODScoreRS)

// Field/Param Data
	//{{AFX_FIELD(CODScoreRS, CRecordset)
	long	m_ID;
	CString	m_YEAR_MONTH;
	CString	m_ON_DUTY_ID;
	float	m_AVERAGE;
	long	m_COUNTER;
	float	m_TOTAL_SCORE;
	//}}AFX_FIELD
// 	CString	m_YEAR_MONTH;
// 	CString	m_ON_DUTY_ID;
// 	float	m_AVERAGE;
// 	long	m_COUNTER;
// 	float	m_TOTAL_SCORE;
// 	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODScoreRS)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODSCORERS_H__5E61CD7B_E580_4A12_B826_957ECD0855F4__INCLUDED_)
