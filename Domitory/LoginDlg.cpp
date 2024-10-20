// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Domitory.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog
extern CDatabase Database;

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

BOOL CLoginDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox *)GetDlgItem(IDC_COMBO1))->AddString("DOMI");
	((CComboBox *)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	SetFont();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLoginDlg::SetFont()
{
	LOGFONT LogFont;
	GetFont()->GetLogFont(&LogFont);
	LogFont.lfHeight+=LogFont.lfHeight/2;
	LogFont.lfWidth+=LogFont.lfWidth/2;
	//set typeface
	strcpy(LogFont.lfFaceName,"黑体");
	m_Font.CreateFontIndirect(&LogFont);  //
	GetDlgItem(IDC_IDC_LOGIN_TITLE)->SetFont(&m_Font);
}

void CLoginDlg::OnOK() 
{
	// TODO: Add extra validation here
	CAdministratorRS AdminRS(&Database);
	CString UserName,PassWord;
	/*CEncryption Encrypt;*/
	GetDlgItemText(IDC_USER_NAME,UserName);
	GetDlgItemText(IDC_PASSWORD,PassWord);
	/*PassWord=Encrypt.Encrypt(PassWord,123);*/
    AdminRS.m_strFilter="USER_NAME = '" + UserName + "' and PASSWORD = '" + PassWord + "' and PERMISSIONS = 'H'";
	AdminRS.Open();
	if (AdminRS.GetRecordCount()==1)
	{
		CDialog::OnOK();
	}
	else
	{
		MessageBox("登陆失败，请重新检查用户名、密码，注意大小写","提示",MB_OK);
	}
	/*CDialog::OnOK();*/
}
