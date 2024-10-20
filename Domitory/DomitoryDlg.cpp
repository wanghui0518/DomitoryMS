// DomitoryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Domitory.h"
#include "DomitoryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDomitoryDlg dialog

CDomitoryDlg::CDomitoryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDomitoryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDomitoryDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//
	m_OnDutyDlg=NULL;
	m_DomiInfoDlg=NULL;
	m_StuInfoDlg=NULL;
	m_ForeignRegDlg=NULL;
}

void CDomitoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDomitoryDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDomitoryDlg, CDialog)
	//{{AFX_MSG_MAP(CDomitoryDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RELOGIN, OnRelogin)
	ON_BN_CLICKED(IDC_ON_DUTY_INFO, OnOnDutyInfo)
	ON_BN_CLICKED(IDC_DOMITORY_INFO, OnDomitoryInfo)
	ON_BN_CLICKED(IDC_STUDENT_INFO, OnStudentInfo)
	ON_BN_CLICKED(IDC_FOREIGN_INFO, OnForeignInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDomitoryDlg message handlers

BOOL CDomitoryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	//
	SetFont();
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDomitoryDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDomitoryDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDomitoryDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDomitoryDlg::SetFont()
{
	LOGFONT LogFont;
	GetFont()->GetLogFont(&LogFont);
	LogFont.lfHeight+=LogFont.lfHeight;
	LogFont.lfWidth+=LogFont.lfWidth;
	//set typeface
	strcpy(LogFont.lfFaceName,"黑体");
	m_Font.CreateFontIndirect(&LogFont);  //
	GetDlgItem(IDC_BIG_TITLE)->SetFont(&m_Font);
}

void CDomitoryDlg::OnRelogin()  //重登陆对话框
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_HIDE);
	CLoginDlg LoginDlg;
	if (LoginDlg.DoModal()==IDOK)
	{
		ShowWindow(SW_SHOW);
	}
	else
	{
		CDialog::OnOK();
	}
}

void CDomitoryDlg::OnOnDutyInfo()  //动态创建值班人员信息对话框
{
	// TODO: Add your control notification handler code here
	if (m_OnDutyDlg==NULL)
	{
		m_OnDutyDlg=new COnDutyDlg;
		m_OnDutyDlg->Create(IDD_ON_DUTY,this);
		m_OnDutyDlg->ShowWindow(SW_SHOW);
	}
	else
	{
		m_OnDutyDlg->ShowWindow(SW_SHOW);
	}
}

void CDomitoryDlg::OnDomitoryInfo() 
{
	// TODO: Add your control notification handler code here
	if (m_DomiInfoDlg==NULL)
	{
		m_DomiInfoDlg=new CDomitoryInfoDlg;
		m_DomiInfoDlg->Create(IDD_DOMITORY_INFO,this);
		m_DomiInfoDlg->ShowWindow(SW_SHOW);
	}
	else
	{
		m_DomiInfoDlg->ShowWindow(SW_SHOW);
	}
}

void CDomitoryDlg::OnStudentInfo() 
{
	// TODO: Add your control notification handler code here
	if (m_StuInfoDlg==NULL)
	{
		m_StuInfoDlg=new CStuInfoDlg;
		m_StuInfoDlg->Create(IDD_STU_INFO,this);
		m_StuInfoDlg->ShowWindow(SW_SHOW);
	}
	else
	{
		m_StuInfoDlg->ShowWindow(SW_SHOW);
	}

}

void CDomitoryDlg::OnForeignInfo() 
{
	// TODO: Add your control notification handler code here
	if (m_ForeignRegDlg==NULL)
	{
		m_ForeignRegDlg=new CForeignRegDlg;
		m_ForeignRegDlg->Create(IDD_FOREIGN_REG,this);
		m_ForeignRegDlg->ShowWindow(SW_SHOW);
	}
	else
	{
		m_ForeignRegDlg->ShowWindow(SW_SHOW);
	}
}


CDomitoryDlg::~CDomitoryDlg()
{
	if (m_OnDutyDlg!=NULL)
	{
		delete m_OnDutyDlg;
	}
	if (m_DomiInfoDlg!=NULL)
	{
		delete m_DomiInfoDlg;
	}
	if (m_StuInfoDlg!=NULL)
	{
		delete m_StuInfoDlg;
	}
	if (m_ForeignRegDlg!=NULL)
	{
		delete m_ForeignRegDlg;
	}
}