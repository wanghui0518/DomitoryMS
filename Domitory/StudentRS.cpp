// StudentRS.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "StudentRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentRS

IMPLEMENT_DYNAMIC(CStudentRS, CRecordset)

CStudentRS::CStudentRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CStudentRS)
	m_ID = 0;
	m_STUDENT_ID = _T("");
	m_NAME = _T("");
	m_GRADE = _T("");
	m_CLASS = _T("");
	m_DOMITORY_ID = _T("");
	m_REMARKS = _T("");
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CStudentRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=DOMI");
}

CString CStudentRS::GetDefaultSQL()
{
	return _T("[STUDENT]");
}

void CStudentRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CStudentRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[STUDENT_ID]"), m_STUDENT_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Text(pFX, _T("[GRADE]"), m_GRADE);
	RFX_Text(pFX, _T("[CLASS]"), m_CLASS);
	RFX_Text(pFX, _T("[DOMITORY_ID]"), m_DOMITORY_ID);
	RFX_Text(pFX, _T("[REMARKS]"), m_REMARKS);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CStudentRS diagnostics

#ifdef _DEBUG
void CStudentRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStudentRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
