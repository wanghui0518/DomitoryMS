// AddForeRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "AddForeRecordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddForeRecordDlg dialog
extern CDatabase Database;

CAddForeRecordDlg::CAddForeRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddForeRecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddForeRecordDlg)
	m_ForeName = _T("");
	m_FRemarks = _T("");
	m_VisitDomiID = _T("");
	m_VisutName = _T("");
	//}}AFX_DATA_INIT
}


void CAddForeRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddForeRecordDlg)
	DDX_Text(pDX, IDC_FORE_NAME, m_ForeName);
	DDX_Text(pDX, IDC_REMARKS, m_FRemarks);
	DDX_Text(pDX, IDC_VISIT_DOMI_ID, m_VisitDomiID);
	DDX_Text(pDX, IDC_VISIT_NAME, m_VisutName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddForeRecordDlg, CDialog)
	//{{AFX_MSG_MAP(CAddForeRecordDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddForeRecordDlg message handlers

BOOL CAddForeRecordDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CTime ArriveTime=CTime::GetCurrentTime();
	CString Temp=ArriveTime.Format("%Y-%m-%d %H:%M:%S");
	SetDlgItemText(IDC_ARRIVE_TIME,Temp);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddForeRecordDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	//判断所找人员是否存在
	CStudentRS StudentRS(&Database);
	StudentRS.m_strFilter="NAME = '" + m_VisutName +"'" "and DOMITORY_ID = '" +m_VisitDomiID + "'";
	StudentRS.Open();
	if (StudentRS.GetRecordCount()!=1)
	{
		MessageBox("您所找的学生不存在","提示",MB_OK | MB_ICONINFORMATION);
		StudentRS.Close();
		return;
	}
	StudentRS.Close();
	//
	CForeignRegRS ForeRS(&Database);
	ForeRS.Open();
	ForeRS.AddNew();
	//
	ForeRS.m_NAME=m_ForeName;
	ForeRS.m_DOMITORY_ID=m_VisitDomiID;
	ForeRS.m_STUDENT_NAME=m_VisutName;
	//
	CTime CurTime=CTime::GetCurrentTime();
	CString Str=CurTime.Format("%Y-%m-%d %H:%M:%S");
    ForeRS.m_ARRIVAL_TIME=Str;
	//
	ForeRS.m_REMARKS=m_FRemarks;
	//
	ForeRS.Update();
	ForeRS.Close();
	//
	CDialog::OnOK();
}
