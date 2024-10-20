// AdministratorRS.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "AdministratorRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdministratorRS

IMPLEMENT_DYNAMIC(CAdministratorRS, CRecordset)

CAdministratorRS::CAdministratorRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAdministratorRS)
	m_ID = 0;
	m_USER_NAME = _T("");
	m_PASSWORD = _T("");
	m_PERMISSIONS = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAdministratorRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=DOMI");
}

CString CAdministratorRS::GetDefaultSQL()
{
	return _T("[ADMINISTRATOR]");
}

void CAdministratorRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAdministratorRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[USER_NAME]"), m_USER_NAME);
	RFX_Text(pFX, _T("[PASSWORD]"), m_PASSWORD);
	RFX_Text(pFX, _T("[PERMISSIONS]"), m_PERMISSIONS);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAdministratorRS diagnostics

#ifdef _DEBUG
void CAdministratorRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAdministratorRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
