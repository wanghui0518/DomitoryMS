// DomitoryRS.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "DomitoryRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDomitoryRS

IMPLEMENT_DYNAMIC(CDomitoryRS, CRecordset)

CDomitoryRS::CDomitoryRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDomitoryRS)
	m_ID = 0;
	m_DOMITORY_ID = _T("");
	m_NUMBER = 0;
	m_TEACHER_IN_CHARGE = _T("");
	m_REMARKS = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CDomitoryRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=DOMI");
}

CString CDomitoryRS::GetDefaultSQL()
{
	return _T("[DOMITORY]");
}

void CDomitoryRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDomitoryRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[DOMITORY_ID]"), m_DOMITORY_ID);
	RFX_Long(pFX, _T("[NUMBER]"), m_NUMBER);
	RFX_Text(pFX, _T("[TEACHER_IN_CHARGE]"), m_TEACHER_IN_CHARGE);
	RFX_Text(pFX, _T("[REMARKS]"), m_REMARKS);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDomitoryRS diagnostics

#ifdef _DEBUG
void CDomitoryRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDomitoryRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
