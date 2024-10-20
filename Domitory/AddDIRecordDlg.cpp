// AddDIRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "AddDIRecordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddDIRecordDlg dialog
extern CDatabase Database;

CAddDIRecordDlg::CAddDIRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddDIRecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddDIRecordDlg)
	m_ADID = _T("");
	m_ADNum = 0;
	m_ADRemarks = _T("");
	m_ADTIChange = _T("");
	m_Change=FALSE;
	//}}AFX_DATA_INIT
}


void CAddDIRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddDIRecordDlg)
	DDX_Text(pDX, IDC_A_D_ID, m_ADID);
	DDX_Text(pDX, IDC_A_D_NUM, m_ADNum);
	DDX_Text(pDX, IDC_A_D_REMARKS, m_ADRemarks);
	DDX_Text(pDX, IDC_A_D_T_I_Charge, m_ADTIChange);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddDIRecordDlg, CDialog)
	//{{AFX_MSG_MAP(CAddDIRecordDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddDIRecordDlg message handlers

void CAddDIRecordDlg::OnOK() 
{
	// TODO: Add extra validation here
	if (m_Change==FALSE)  //添加记录
	{
		CDomitoryRS DomitoryRS(&Database);
		CString Temp;
		//
		DomitoryRS.Open();
		DomitoryRS.AddNew();
		//
		GetDlgItemText(IDC_A_D_ID,Temp);
		DomitoryRS.m_DOMITORY_ID=Temp;
		//
		int Num=0;
		GetDlgItemInt(IDC_A_D_NUM);
		DomitoryRS.m_NUMBER=Num;
		//
		GetDlgItemText(IDC_A_D_T_I_Charge,Temp);
		DomitoryRS.m_TEACHER_IN_CHARGE=Temp;
		//
		GetDlgItemText(IDC_A_D_REMARKS,Temp);
		DomitoryRS.m_REMARKS=Temp;
		//
		DomitoryRS.Update();
		DomitoryRS.Close(); 
	} 
	else                       //修改记录
	{
		UpdateData(TRUE);
		CDomitoryRS DomitoryRS(&Database);
		DomitoryRS.m_strFilter="DOMITORY_ID = '" + m_ADID + "'";
		DomitoryRS.Open();
		DomitoryRS.Edit();
		//修改值
		DomitoryRS.m_NUMBER=m_ADNum;
		DomitoryRS.m_TEACHER_IN_CHARGE=m_ADTIChange;
		DomitoryRS.m_REMARKS=m_ADRemarks;
		//
		DomitoryRS.Update();
		DomitoryRS.Close();
	}
	//
	CDialog::OnOK();
}

BOOL CAddDIRecordDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if (m_Change==TRUE)
	{
		SetWindowText("修改宿舍记录");
		SetDlgItemText(IDOK,"修改");
		GetDlgItem(IDC_A_D_ID)->EnableWindow(FALSE);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
