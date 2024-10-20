// StuInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "StuInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg dialog
extern CDatabase Database;

CStuInfoDlg::CStuInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStuInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStuInfoDlg)
	m_StuName = FALSE;
	m_StuDomiID = FALSE;
	//}}AFX_DATA_INIT
}


void CStuInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStuInfoDlg)
	DDX_Control(pDX, IDC_STU_LIST, m_StuList);
	DDX_Check(pDX, IDC_STUDENT_NAME, m_StuName);
	DDX_Check(pDX, IDC_STU_DOMI_ID, m_StuDomiID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStuInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CStuInfoDlg)
	ON_BN_CLICKED(IDC_STU_RETRIEVE, OnStuRetrieve)
	ON_BN_CLICKED(IDC_ADD_STU_RECORD, OnAddStuRecord)
	ON_BN_CLICKED(IDC_DEL_STU_RECORD, OnDelStuRecord)
	ON_BN_CLICKED(IDC_CHANGE_STU_RECORD, OnChangeStuRecord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg message handlers

BOOL CStuInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_StuList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_StuList.InsertColumn(0,"学生编号",LVCFMT_LEFT,70);
	m_StuList.InsertColumn(1,"学生姓名",LVCFMT_LEFT,80);
	m_StuList.InsertColumn(2,"年级",LVCFMT_LEFT,60);
	m_StuList.InsertColumn(3,"班级",LVCFMT_LEFT,60);
	m_StuList.InsertColumn(4,"宿舍号",LVCFMT_LEFT,70);
	m_StuList.InsertColumn(5,"备注",LVCFMT_LEFT,80);
    
	CStudentRS TempRS(&Database);
	ShowStuList(TempRS);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStuInfoDlg::ShowStuList(CStudentRS &StudentRS)
{
	int i=0;
	CString Str;
	StudentRS.Open();
	//
	m_StuList.DeleteAllItems();
	while (!StudentRS.IsEOF())
	{
		m_StuList.InsertItem(i," ");
		// 		Str.Format("%d",OnDutyRS.m_ON_DUTY_ID);
		m_StuList.SetItemText(i,0,StudentRS.m_STUDENT_ID);
		m_StuList.SetItemText(i,1,StudentRS.m_NAME);
		m_StuList.SetItemText(i,2,StudentRS.m_GRADE);
		m_StuList.SetItemText(i,3,StudentRS.m_CLASS);
		m_StuList.SetItemText(i,4,StudentRS.m_DOMITORY_ID);
		m_StuList.SetItemText(i,5,StudentRS.m_REMARKS);
		StudentRS.MoveNext();
		i++;
	}
	StudentRS.Close();
}

void CStuInfoDlg::OnStuRetrieve() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	//宿舍号和学生姓名检索条件都为假
	if (m_StuName==FALSE && m_StuDomiID==FALSE)
	{
		MessageBox("请选择检索条件","提示",MB_OK | MB_ICONINFORMATION);
		return;
	}
    //
	CStudentRS StudentRS(&Database);
	//获取检索宿舍号和学生姓名
	CString StrName,StrID;
	GetDlgItemText(IDC_STU_NAME,StrName);
	GetDlgItemText(IDC_STU_DOMITORY_ID,StrID);
	//宿舍号和学生姓名检索条件都为真
	if (m_StuDomiID==TRUE && m_StuName==TRUE)
	{
		StudentRS.m_strFilter="NAME = '" + StrName + "' and DOMITORY_ID = '" + StrID + "'";  
	}
	//宿舍号检索条件为真，学生姓名检索条件为假
	else if (m_StuDomiID==TRUE && m_StuName==FALSE)
	{
		StudentRS.m_strFilter="DOMITORY_ID = '" + StrID + "'";;
	}
	//时间检索条件为假，员工检索条件为真
	else
	{
		StudentRS.m_strFilter="NAME = '" + StrName + "'";
	}
	//显示
	ShowStuList(StudentRS);
}

void CStuInfoDlg::OnAddStuRecord() 
{
	// TODO: Add your control notification handler code here
	CAddStuReDlg AddDlg;
	if (AddDlg.DoModal()==IDOK)
	{
		CStudentRS StudentRS(&Database);
		ShowStuList(StudentRS);
	}
}

void CStuInfoDlg::OnChangeStuRecord() 
{
	// TODO: Add your control notification handler code here
	CAddStuReDlg ChangeDlg;
	ChangeDlg.m_Change=TRUE;
	//设置对话框初始化控件文本显示
	int Index;
	CString Sql;
	POSITION pos=m_StuList.GetFirstSelectedItemPosition();
	if (pos==NULL)
	{
		return;
	}
	Index=m_StuList.GetNextSelectedItem(pos);
	ChangeDlg.m_StuID=m_StuList.GetItemText(Index,0);
	ChangeDlg.m_StuName=m_StuList.GetItemText(Index,1);
	ChangeDlg.m_StuGrade=m_StuList.GetItemText(Index,2);
	ChangeDlg.m_StuClass=m_StuList.GetItemText(Index,3);
	ChangeDlg.m_StuDomiID=m_StuList.GetItemText(Index,4);
	ChangeDlg.m_StuRemarks=m_StuList.GetItemText(Index,5);
	//
	if (ChangeDlg.DoModal()==IDOK)
	{
		CStudentRS StudentRS(&Database);
		ShowStuList(StudentRS);
	}
}

void CStuInfoDlg::OnDelStuRecord() 
{
	// TODO: Add your control notification handler code here
	CString StuDomiID; //保存要删除学生的宿舍号
	//删除选中的学生记录
	int Index;
	CString Sql;
	POSITION pos=m_StuList.GetFirstSelectedItemPosition();
	if (pos==NULL)
	{
		return;
	}
	Index=m_StuList.GetNextSelectedItem(pos);
	StuDomiID=m_StuList.GetItemText(Index,4);//保存要删除学生的宿舍号
	Sql="delete * from STUDENT where STUDENT_ID = '"+m_StuList.GetItemText(Index,0) + "'";
	Database.ExecuteSQL(Sql);
	CStudentRS StudentRS(&Database);
	ShowStuList(StudentRS);
	//数据库中DOMITORY表中学生数目减一
	CDomitoryRS DomitoryRS(&Database);
	DomitoryRS.m_strFilter="DOMITORY_ID = '" + StuDomiID +"'";
	DomitoryRS.Open();
	DomitoryRS.Edit();
	DomitoryRS.m_NUMBER--;
	DomitoryRS.Update();
	DomitoryRS.Close();
}

