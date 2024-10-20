#if !defined(AFX_PERSONODRS_H__575021ED_7E59_4E7B_998D_47A8DF89038A__INCLUDED_)
#define AFX_PERSONODRS_H__575021ED_7E59_4E7B_998D_47A8DF89038A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PersonODRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPersonODRS recordset

class CPersonODRS : public CRecordset
{
public:
	CPersonODRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPersonODRS)

// Field/Param Data
	//{{AFX_FIELD(CPersonODRS, CRecordset)
	long	m_ID;
	CString	m_PERSON_ID;
	CString	m_NAME;
	CString	m_STATE;
	CString	m_REMARKS;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersonODRS)
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

#endif // !defined(AFX_PERSONODRS_H__575021ED_7E59_4E7B_998D_47A8DF89038A__INCLUDED_)
