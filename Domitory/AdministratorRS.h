#if !defined(AFX_ADMINISTRATORRS_H__F02C8F9A_C8A1_4676_8338_4686E4E08A53__INCLUDED_)
#define AFX_ADMINISTRATORRS_H__F02C8F9A_C8A1_4676_8338_4686E4E08A53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AdministratorRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdministratorRS recordset

class CAdministratorRS : public CRecordset
{
public:
	CAdministratorRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAdministratorRS)

// Field/Param Data
	//{{AFX_FIELD(CAdministratorRS, CRecordset)
	long	m_ID;
	CString	m_USER_NAME;
	CString	m_PASSWORD;
	CString	m_PERMISSIONS;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdministratorRS)
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

#endif // !defined(AFX_ADMINISTRATORRS_H__F02C8F9A_C8A1_4676_8338_4686E4E08A53__INCLUDED_)
