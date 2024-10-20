// OnDutyPage2.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "OnDutyPage2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COnDutyPage2 property page
extern CDatabase Database;

IMPLEMENT_DYNCREATE(COnDutyPage2, CPropertyPage)

COnDutyPage2::COnDutyPage2() : CPropertyPage(COnDutyPage2::IDD)
{
	//{{AFX_DATA_INIT(COnDutyPage2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

COnDutyPage2::~COnDutyPage2()
{
}

void COnDutyPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COnDutyPage2)
	DDX_Control(pDX, IDC_PERSON_LIST, m_PList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COnDutyPage2, CPropertyPage)
	//{{AFX_MSG_MAP(COnDutyPage2)
	ON_BN_CLICKED(IDC_ADD_P_RECORD, OnAddPRecord)
	ON_BN_CLICKED(IDC_DELETE_P_RECORD, OnDeletePRecord)
	ON_BN_CLICKED(IDC_CHANGE_P_RECORD, OnChangePRecord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COnDutyPage2 message handlers

BOOL COnDutyPage2::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_PList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_PList.InsertColumn(0,"编号",LVCFMT_LEFT,90);
	m_PList.InsertColumn(1,"姓名",LVCFMT_LEFT,110);
	m_PList.InsertColumn(2,"状态",LVCFMT_LEFT,110);
	m_PList.InsertColumn(3,"备注",LVCFMT_LEFT,150);
    
	CPersonODRS TempRS(&Database);
	ShowPList(TempRS);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COnDutyPage2::ShowPList(CPersonODRS &PersonODRS)
{
	int i=0;
	CString Str;
/*	CPersonODRS PersonODRS(&Database);*/
	PersonODRS.Open();
	//
	m_PList.DeleteAllItems();
	while (!PersonODRS.IsEOF())
	{
		m_PList.InsertItem(i," ");
		m_PList.SetItemText(i,0,PersonODRS.m_PERSON_ID);
		m_PList.SetItemText(i,1,PersonODRS.m_NAME);
		m_PList.SetItemText(i,2,PersonODRS.m_STATE);
		m_PList.SetItemText(i,3,PersonODRS.m_REMARKS);
		PersonODRS.MoveNext();
		i++;
	}
	PersonODRS.Close();
}

void COnDutyPage2::OnAddPRecord() 
{
	// TODO: Add your control notification handler code here
	CAddPRecordDlg AddDlg;
	if (AddDlg.DoModal()==IDOK)
	{
		
		CPersonODRS PersonODRS(&Database);
		ShowPList(PersonODRS);
	}
}

void COnDutyPage2::OnDeletePRecord() 
{
	// TODO: Add your control notification handler code here
	int Index;
	CString Sql;
	POSITION pos=m_PList.GetFirstSelectedItemPosition();
	if (pos==NULL)
	{
		return;
	}
	Index=m_PList.GetNextSelectedItem(pos);
	Sql="delete * from PERSON_ON_DUTY where PERSON_ID = '"+m_PList.GetItemText(Index,0) + "'";
	Database.ExecuteSQL(Sql);
	CPersonODRS TempRS(&Database);
	//
	ShowPList(TempRS);
}

void COnDutyPage2::OnChangePRecord() 
{
	// TODO: Add your control notification handler code here
	int Index;
	CString Sql;
	POSITION pos=m_PList.GetFirstSelectedItemPosition();
	if (pos==NULL)
	{
		return;
	}
	Index=m_PList.GetNextSelectedItem(pos);
	//
	CAddPRecordDlg AddDlg;
	AddDlg.m_Change=TRUE;//添加/修改指示变量
	//
	AddDlg.m_AddPID=m_PList.GetItemText(Index,0);
	AddDlg.m_AddPName=m_PList.GetItemText(Index,1);
	AddDlg.m_AddPState=m_PList.GetItemText(Index,2);
	AddDlg.m_AddPRemarks=m_PList.GetItemText(Index,3);
	//显示对话框
	if (AddDlg.DoModal()==IDOK)
	{
		CPersonODRS TempRS(&Database);
		ShowPList(TempRS);
	}
}
