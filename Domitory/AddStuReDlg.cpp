// AddStuReDlg.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "AddStuReDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddStuReDlg dialog
extern CDatabase Database;

CAddStuReDlg::CAddStuReDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddStuReDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddStuReDlg)
	m_StuClass = _T("");
	m_StuDomiID = _T("");
	m_StuGrade = _T("");
	m_StuID = _T("");
	m_StuName = _T("");
	m_StuRemarks = _T("");
	m_Change=FALSE;
	//}}AFX_DATA_INIT
}


void CAddStuReDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddStuReDlg)
	DDX_Text(pDX, IDC_ADD_STU_CLASS, m_StuClass);
	DDX_Text(pDX, IDC_ADD_STU_D_ID, m_StuDomiID);
	DDX_Text(pDX, IDC_ADD_STU_GRADE, m_StuGrade);
	DDX_Text(pDX, IDC_ADD_STU_ID, m_StuID);
	DDX_Text(pDX, IDC_ADD_STU_NAME, m_StuName);
	DDX_Text(pDX, IDC_ADD_STU_REMARKS, m_StuRemarks);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddStuReDlg, CDialog)
	//{{AFX_MSG_MAP(CAddStuReDlg)
	ON_BN_CLICKED(IDC_ADD_STU_RECORD, OnAddStuRecord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddStuReDlg message handlers

void CAddStuReDlg::OnAddStuRecord() 
{
	// TODO: Add your control notification handler code here
	//增加学生记录
	if (m_Change==FALSE)            //m_Change值为FALSE为增加学生记录，值为TRUE为修改学生记录
	{
		UpdateData();
		CStudentRS StudentRS(&Database);
		StudentRS.Open();
		StudentRS.AddNew();
		//
		StudentRS.m_STUDENT_ID=m_StuID;
		StudentRS.m_NAME=m_StuName;
		StudentRS.m_GRADE=m_StuGrade;
		StudentRS.m_CLASS=m_StuClass;
		StudentRS.m_DOMITORY_ID=m_StuDomiID;
		StudentRS.m_REMARKS=m_StuRemarks;
		//
		StudentRS.Update();
		StudentRS.Close();
		//增加数据库中DOMITORY表中学生数目
		CDomitoryRS DomitoryRS(&Database);
		DomitoryRS.m_strFilter="DOMITORY_ID = '" + m_StuDomiID +"'";
		DomitoryRS.Open();
		DomitoryRS.Edit();
		DomitoryRS.m_NUMBER++;
		DomitoryRS.Update();
	    DomitoryRS.Close();
	}
	else          //修改学生记录
	{
		UpdateData();
		CStudentRS StudentRS(&Database);
		StudentRS.m_strFilter="STUDENT_ID = '" + m_StuID + "'";
		StudentRS.Open();
		StudentRS.Edit();
		//
		StudentRS.m_STUDENT_ID=m_StuID;
		StudentRS.m_NAME=m_StuName;
		StudentRS.m_GRADE=m_StuGrade;
		StudentRS.m_CLASS=m_StuClass;
		StudentRS.m_DOMITORY_ID=m_StuDomiID;
		StudentRS.m_REMARKS=m_StuRemarks;
		//
		StudentRS.Update();
		StudentRS.Close();
	}
	//
	CDialog::OnOK();

}

BOOL CAddStuReDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if (m_Change==TRUE)
	{
		SetWindowText("修改学生记录");
		SetDlgItemText(IDC_ADD_STU_RECORD,"修改");
		GetDlgItem(IDC_ADD_STU_ID)->EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
