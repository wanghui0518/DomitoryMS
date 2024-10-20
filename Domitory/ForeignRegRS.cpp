// ForeignRegRS.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "ForeignRegRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CForeignRegRS

IMPLEMENT_DYNAMIC(CForeignRegRS, CRecordset)

CForeignRegRS::CForeignRegRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CForeignRegRS)
	m_ID = 0;
	m_NAME = _T("");
	m_DOMITORY_ID = _T("");
	m_STUDENT_NAME = _T("");
	m_ARRIVAL_TIME=_T("");
	m_LEAVE_TIME=_T("");
	m_REMARKS = _T("");
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CForeignRegRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=DOMI");
}

CString CForeignRegRS::GetDefaultSQL()
{
	return _T("[F_REGISTER]");
}

void CForeignRegRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CForeignRegRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Text(pFX, _T("[DOMITORY_ID]"), m_DOMITORY_ID);
	RFX_Text(pFX, _T("[STUDENT_NAME]"), m_STUDENT_NAME);
	RFX_Text(pFX, _T("[ARRIVAL_TIME]"), m_ARRIVAL_TIME);
	RFX_Text(pFX, _T("[LEAVE_TIME]"), m_LEAVE_TIME);
	RFX_Text(pFX, _T("[REMARKS]"), m_REMARKS);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CForeignRegRS diagnostics

#ifdef _DEBUG
void CForeignRegRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CForeignRegRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
