#if !defined(AFX_ONDUTYRS_H__C4E08BC9_103D_40A7_B5A1_DFDA550950BE__INCLUDED_)
#define AFX_ONDUTYRS_H__C4E08BC9_103D_40A7_B5A1_DFDA550950BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OnDutyRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COnDutyRS recordset

class COnDutyRS : public CRecordset
{
public:
	COnDutyRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(COnDutyRS)

// Field/Param Data
	//{{AFX_FIELD(COnDutyRS, CRecordset)
	long	m_ID;
	CString	m_ON_DUTY_ID;
	CString	m_NAME;
	long	m_DAY_OF_WEEK;
	CString	m_DAY_NIGHT;
	CString	m_REMARKS;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COnDutyRS)
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

#endif // !defined(AFX_ONDUTYRS_H__C4E08BC9_103D_40A7_B5A1_DFDA550950BE__INCLUDED_)
