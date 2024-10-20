#if !defined(AFX_DOMITORYRS_H__59355872_C798_409A_826E_DC64C696F93D__INCLUDED_)
#define AFX_DOMITORYRS_H__59355872_C798_409A_826E_DC64C696F93D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DomitoryRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDomitoryRS recordset

class CDomitoryRS : public CRecordset
{
public:
	CDomitoryRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDomitoryRS)

// Field/Param Data
	//{{AFX_FIELD(CDomitoryRS, CRecordset)
	long	m_ID;
	CString	m_DOMITORY_ID;
	long	m_NUMBER;
	CString	m_TEACHER_IN_CHARGE;
	CString	m_REMARKS;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDomitoryRS)
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

#endif // !defined(AFX_DOMITORYRS_H__59355872_C798_409A_826E_DC64C696F93D__INCLUDED_)
