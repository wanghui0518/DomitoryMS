// ODScoreRS.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "ODScoreRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODScoreRS

IMPLEMENT_DYNAMIC(CODScoreRS, CRecordset)

CODScoreRS::CODScoreRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CODScoreRS)
	m_ID = 0;
	m_YEAR_MONTH = _T("");
	m_ON_DUTY_ID = _T("");
	m_AVERAGE = 0.0f;
	m_COUNTER = 0;
	m_TOTAL_SCORE = 0.0f;
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CODScoreRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=DOMI");
}

CString CODScoreRS::GetDefaultSQL()
{
	return _T("[ON_DUTY_SCORE]");
}

void CODScoreRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CODScoreRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[YEAR_MONTH]"), m_YEAR_MONTH);
	RFX_Text(pFX, _T("[ON_DUTY_ID]"), m_ON_DUTY_ID);
	RFX_Single(pFX, _T("[AVERAGE]"), m_AVERAGE);
	RFX_Long(pFX, _T("[COUNTER]"), m_COUNTER);
	RFX_Single(pFX, _T("[TOTAL_SCORE]"), m_TOTAL_SCORE);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CODScoreRS diagnostics

#ifdef _DEBUG
void CODScoreRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CODScoreRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
