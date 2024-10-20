// OnDutyRS.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "OnDutyRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COnDutyRS

IMPLEMENT_DYNAMIC(COnDutyRS, CRecordset)

COnDutyRS::COnDutyRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(COnDutyRS)
	m_ID = 0;
	m_ON_DUTY_ID = _T("");
	m_NAME = _T("");
	m_DAY_OF_WEEK = 0;
	m_DAY_NIGHT = _T("");
	m_REMARKS = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString COnDutyRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=DOMI");
}

CString COnDutyRS::GetDefaultSQL()
{
	return _T("[ON_DUTY]");
}

void COnDutyRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(COnDutyRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[ON_DUTY_ID]"), m_ON_DUTY_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Long(pFX, _T("[DAY_OF_WEEK]"), m_DAY_OF_WEEK);
	RFX_Text(pFX, _T("[DAY_NIGHT]"), m_DAY_NIGHT);
	RFX_Text(pFX, _T("[REMARKS]"), m_REMARKS);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// COnDutyRS diagnostics

#ifdef _DEBUG
void COnDutyRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void COnDutyRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
