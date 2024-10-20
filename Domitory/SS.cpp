// SS.cpp : implementation file
//

#include "stdafx.h"
#include "domitory.h"
#include "SS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSS dialog


CSS::CSS(CWnd* pParent /*=NULL*/)
	: CDialog(CSS::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSS)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSS)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSS, CDialog)
	//{{AFX_MSG_MAP(CSS)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSS message handlers
