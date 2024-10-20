// AddPRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "AddPRecordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddPRecordDlg dialog
extern CDatabase Database;

CAddPRecordDlg::CAddPRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddPRecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddPRecordDlg)
	m_AddPID = _T("");
	m_AddPName = _T("");
	m_AddPRemarks = _T("");
	m_AddPState = _T("");
	m_Change=FALSE;
	//}}AFX_DATA_INIT
}


void CAddPRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddPRecordDlg)
	DDX_Text(pDX, IDC_ADD_P_ID, m_AddPID);
	DDX_Text(pDX, IDC_ADD_P_NAME, m_AddPName);
	DDX_Text(pDX, IDC_ADD_P_REMARKS, m_AddPRemarks);
	DDX_Text(pDX, IDC_ADD_P_STATE, m_AddPState);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddPRecordDlg, CDialog)
	//{{AFX_MSG_MAP(CAddPRecordDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddPRecordDlg message handlers

BOOL CAddPRecordDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if (m_Change==TRUE)
	{
		SetWindowText("修改值班人员记录");
		SetDlgItemText(IDOK,"修改");
		GetDlgItem(IDC_ADD_P_ID)->EnableWindow(FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CAddPRecordDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if (m_Change==FALSE)  //添加记录
	{
		CPersonODRS PerRS(&Database);
		CString Temp;
		//
		PerRS.Open();
		PerRS.AddNew();
		//
		PerRS.m_PERSON_ID=m_AddPID;
		PerRS.m_NAME=m_AddPName;
		PerRS.m_STATE=m_AddPState;
		PerRS.m_REMARKS=m_AddPRemarks;
		//
		PerRS.Update();
		PerRS.Close();
	} 
	else                       //修改记录
	{
		CPersonODRS PerRS(&Database);
		PerRS.m_strFilter="PERSON_ID = '" + m_AddPID + "'";
		PerRS.Open();
		PerRS.Edit();
		//修改值
		PerRS.m_PERSON_ID=m_AddPID;
		PerRS.m_NAME=m_AddPName;
		PerRS.m_STATE=m_AddPState;
		PerRS.m_REMARKS=m_AddPRemarks;
		//
		PerRS.Update();
		PerRS.Close();
	}
	CDialog::OnOK();
}
