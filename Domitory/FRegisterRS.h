#if !defined(AFX_FREGISTERRS_H__AAD4AA99_87FE_43F1_8480_FAF93578D735__INCLUDED_)
#define AFX_FREGISTERRS_H__AAD4AA99_87FE_43F1_8480_FAF93578D735__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FRegisterRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFRegisterRS recordset

class CFRegisterRS : public CRecordset
{
public:
	CFRegisterRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CFRegisterRS)

// Field/Param Data
	//{{AFX_FIELD(CFRegisterRS, CRecordset)
	long	m_ID;
	CString	m_NAME;
	CString	m_DOMITORY_ID;
	CString	m_STUDENT_NAME;
	CTime	m_ARRIVAL_TIME;
	CTime	m_LEAVE_TIME;
	CString	m_REMARKS;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFRegisterRS)
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

#endif // !defined(AFX_FREGISTERRS_H__AAD4AA99_87FE_43F1_8480_FAF93578D735__INCLUDED_)
