// PersonODRS.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "PersonODRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPersonODRS

IMPLEMENT_DYNAMIC(CPersonODRS, CRecordset)

CPersonODRS::CPersonODRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPersonODRS)
	m_ID = 0;
	m_PERSON_ID = _T("");
	m_NAME = _T("");
	m_STATE = _T("");
	m_REMARKS = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CPersonODRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=DOMI");
}

CString CPersonODRS::GetDefaultSQL()
{
	return _T("[PERSON_ON_DUTY]");
}

void CPersonODRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPersonODRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[PERSON_ID]"), m_PERSON_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Text(pFX, _T("[STATE]"), m_STATE);
	RFX_Text(pFX, _T("[REMARKS]"), m_REMARKS);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CPersonODRS diagnostics

#ifdef _DEBUG
void CPersonODRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPersonODRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
