#if !defined(AFX_STUDENTRS_H__67F582AB_5B0E_4FCB_A910_687FD495723A__INCLUDED_)
#define AFX_STUDENTRS_H__67F582AB_5B0E_4FCB_A910_687FD495723A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentRS recordset

class CStudentRS : public CRecordset
{
public:
	CStudentRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStudentRS)

// Field/Param Data
	//{{AFX_FIELD(CStudentRS, CRecordset)
	long	m_ID;
	CString	m_STUDENT_ID;
	CString	m_NAME;
	CString	m_GRADE;
	CString	m_CLASS;
	CString	m_DOMITORY_ID;
	CString	m_REMARKS;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentRS)
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

#endif // !defined(AFX_STUDENTRS_H__67F582AB_5B0E_4FCB_A910_687FD495723A__INCLUDED_)
