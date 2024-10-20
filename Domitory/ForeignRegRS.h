#if !defined(AFX_FOREIGNREGRS_H__BC65D9C2_E9F1_47C0_80AE_075713E29CBC__INCLUDED_)
#define AFX_FOREIGNREGRS_H__BC65D9C2_E9F1_47C0_80AE_075713E29CBC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ForeignRegRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CForeignRegRS recordset

class CForeignRegRS : public CRecordset
{
public:
	CForeignRegRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CForeignRegRS)

// Field/Param Data
	//{{AFX_FIELD(CForeignRegRS, CRecordset)
	long	m_ID;
	CString	m_NAME;
	CString	m_DOMITORY_ID;
	CString	m_STUDENT_NAME;
	CString	m_ARRIVAL_TIME;
	CString	m_LEAVE_TIME;
	CString	m_REMARKS;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CForeignRegRS)
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

#endif // !defined(AFX_FOREIGNREGRS_H__BC65D9C2_E9F1_47C0_80AE_075713E29CBC__INCLUDED_)
