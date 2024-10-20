// OnDutyPage3.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "OnDutyPage3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COnDutyPage3 property page
extern CDatabase Database;

IMPLEMENT_DYNCREATE(COnDutyPage3, CPropertyPage)

COnDutyPage3::COnDutyPage3() : CPropertyPage(COnDutyPage3::IDD)
{
	//{{AFX_DATA_INIT(COnDutyPage3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

COnDutyPage3::~COnDutyPage3()
{
}

void COnDutyPage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COnDutyPage3)
	DDX_Control(pDX, IDC_CHECK_LIST, m_CheckList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COnDutyPage3, CPropertyPage)
	//{{AFX_MSG_MAP(COnDutyPage3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COnDutyPage3 message handlers

BOOL COnDutyPage3::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
    m_CheckList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_CheckList.InsertColumn(0,"年—月",LVCFMT_LEFT,80);
	m_CheckList.InsertColumn(1,"值班人员编号",LVCFMT_LEFT,90);
	m_CheckList.InsertColumn(2,"平均分",LVCFMT_LEFT,90);
	m_CheckList.InsertColumn(3,"值班期检查次数",LVCFMT_LEFT,100);
	m_CheckList.InsertColumn(3,"总分",LVCFMT_LEFT,90);
    
	CODScoreRS ODScoreRS(&Database);
	ShowCheckList(ODScoreRS);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COnDutyPage3::ShowCheckList(CODScoreRS &ODScoreRS)
{
	int i=0;
	CString Str;
	ODScoreRS.Open();
	//
	m_CheckList.DeleteAllItems();
	while (!ODScoreRS.IsEOF())
	{
		m_CheckList.InsertItem(i," ");
		m_CheckList.SetItemText(i,0,ODScoreRS.m_YEAR_MONTH);
		m_CheckList.SetItemText(i,1,ODScoreRS.m_ON_DUTY_ID);
		Str.Format("%f",ODScoreRS.m_AVERAGE);
		m_CheckList.SetItemText(i,2,Str);
		Str.Format("%d",ODScoreRS.m_COUNTER);
		m_CheckList.SetItemText(i,3,Str);
		Str.Format("%f",ODScoreRS.m_TOTAL_SCORE);
		m_CheckList.SetItemText(i,4,Str);
		ODScoreRS.MoveNext();
		i++;
	}
	ODScoreRS.Close();
}
