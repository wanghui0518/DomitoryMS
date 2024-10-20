// OnDutyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "OnDutyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COnDutyDlg dialog
extern CDatabase Database;

COnDutyDlg::COnDutyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COnDutyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COnDutyDlg)

	//}}AFX_DATA_INIT
}


void COnDutyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COnDutyDlg)

	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COnDutyDlg, CDialog)
	//{{AFX_MSG_MAP(COnDutyDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COnDutyDlg message handlers

BOOL COnDutyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
//	TODO: Add extra initialization here
	m_ODProSheet.AddPage(&m_OnDutyPage1); 
	m_ODProSheet.AddPage(&m_OnDutyPage2); 
	m_ODProSheet.AddPage(&m_OnDutyPage3); 
	//
	m_ODProSheet.Create(this, WS_CHILD | WS_VISIBLE, WS_EX_CONTROLPARENT); // 创建窗口
	m_ODProSheet.ModifyStyle( 0, WS_TABSTOP ); // 修改风格
	
	// 设置窗口位置
	m_ODProSheet.SetWindowPos( NULL, 0, 0, 5, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE );
	//
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


