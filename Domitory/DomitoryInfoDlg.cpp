// DomitoryInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "DomitoryInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDomitoryInfoDlg dialog
extern CDatabase Database;

CDomitoryInfoDlg::CDomitoryInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDomitoryInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDomitoryInfoDlg)
	m_DomiRetrive = 0;
	m_lowNum = 0;
	m_HighNum = 0;
	//}}AFX_DATA_INIT
}


void CDomitoryInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDomitoryInfoDlg)
	DDX_Control(pDX, IDC_D_I_LIST, m_DIList);
	DDX_Radio(pDX, IDC_DOMITORY_ID, m_DomiRetrive);
	DDX_Text(pDX, IDC_LOW_NUMBER, m_lowNum);
	DDX_Text(pDX, IDC_HIGH_NUMBER, m_HighNum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDomitoryInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CDomitoryInfoDlg)
	ON_BN_CLICKED(IDC_BEGIN_RETRIEVE, OnBeginRetrieve)
	ON_BN_CLICKED(IDC_ADD_D_I_RECORD, OnAddDIRecord)
	ON_BN_CLICKED(IDC_DEL_D_I_RECORD, OnDelDIRecord)
	ON_BN_CLICKED(IDC_Change_D_I_RECORD, OnChangeDIRECORD)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDomitoryInfoDlg message handlers

BOOL CDomitoryInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_DIList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_DIList.InsertColumn(0,"宿舍号",LVCFMT_LEFT,90);
	m_DIList.InsertColumn(1,"住宿人数",LVCFMT_LEFT,110);
	m_DIList.InsertColumn(2,"班主任",LVCFMT_LEFT,110);
	m_DIList.InsertColumn(3,"备注",LVCFMT_LEFT,130);
    
	CDomitoryRS TempRS(&Database);
	ShowDIList(TempRS);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDomitoryInfoDlg::ShowDIList(CDomitoryRS &DomitoryRS)
{
	int i=0;
	CString Str;
	DomitoryRS.Open();
	//
	m_DIList.DeleteAllItems();
	while (!DomitoryRS.IsEOF())
	{
		m_DIList.InsertItem(i," ");
		// 		Str.Format("%d",OnDutyRS.m_ON_DUTY_ID);
		m_DIList.SetItemText(i,0,DomitoryRS.m_DOMITORY_ID);
		Str.Format("%d",DomitoryRS.m_NUMBER);
		m_DIList.SetItemText(i,1,Str);
		m_DIList.SetItemText(i,2,DomitoryRS.m_TEACHER_IN_CHARGE);
		m_DIList.SetItemText(i,3,DomitoryRS.m_REMARKS);
		DomitoryRS.MoveNext();
		i++;
	}
	DomitoryRS.Close();
}

void CDomitoryInfoDlg::OnBeginRetrieve() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CDomitoryRS DomitoryRS(&Database);
	CString Temp1,Temp2;
	GetDlgItemText(IDC_DOMI_ID,Temp1);
	if (m_DomiRetrive==0)
	{
		DomitoryRS.m_strFilter="DOMITORY_ID = '" +Temp1 + "'";
	}
	else
	{
		Temp1.Format("%d",m_lowNum);
		Temp2.Format("%d",m_HighNum);
		DomitoryRS.m_strFilter="NUMBER >= " + Temp1 + " and NUMBER <= " + Temp2;
	}
	ShowDIList(DomitoryRS);
}

void CDomitoryInfoDlg::OnAddDIRecord() 
{
	// TODO: Add your control notification handler code here
	CAddDIRecordDlg AddDlg;
	if (AddDlg.DoModal()==IDOK)
	{
		CDomitoryRS TempRS(&Database);
		ShowDIList(TempRS);
	}
}

void CDomitoryInfoDlg::OnDelDIRecord() 
{
	// TODO: Add your control notification handler code here
	int Index;
	CString Sql;
	POSITION pos=m_DIList.GetFirstSelectedItemPosition();
	if (pos==NULL)
	{
		return;
	}
	Index=m_DIList.GetNextSelectedItem(pos);
	Sql="delete * from DOMITORY where DOMITORY_ID = '"+m_DIList.GetItemText(Index,0) + "'";
	Database.ExecuteSQL(Sql);
	CDomitoryRS TempRS(&Database);
	ShowDIList(TempRS);
}

void CDomitoryInfoDlg::OnChangeDIRECORD() 
{
	// TODO: Add your control notification handler code here
	//判断是否有条目被选中
	int Index;
	CString Sql;
	POSITION pos=m_DIList.GetFirstSelectedItemPosition();
	if (pos==NULL)
	{
		return;
	}
	Index=m_DIList.GetNextSelectedItem(pos);
	//
	CAddDIRecordDlg AddDlg;
	AddDlg.m_Change=TRUE;//添加/修改指示变量
	AddDlg.m_ADID=m_DIList.GetItemText(Index,0);
	//
	CString Temp=m_DIList.GetItemText(Index,1);
	AddDlg.m_ADNum=atoi(Temp);
	//
	AddDlg.m_ADTIChange=m_DIList.GetItemText(Index,2);
	AddDlg.m_ADRemarks=m_DIList.GetItemText(Index,3);
	//显示对话框
	if (AddDlg.DoModal()==IDOK)
	{
		CDomitoryRS TempRS(&Database);
		ShowDIList(TempRS);
	}
}
