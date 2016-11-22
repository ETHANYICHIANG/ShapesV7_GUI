
// ShapesV7Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShapesV7.h"
#include "ShapesV7Dlg.h"
#include "afxdialogex.h"

#include <string>
#include <sstream>
using namespace std;


#include "iShapes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CShapesV7Dlg dialog



CShapesV7Dlg::CShapesV7Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHAPESV7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShapesV7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CShapesV7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CShapesV7Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CShapesV7Dlg::OnBnClickedCancel)
  ON_CBN_SELCHANGE(IDC_COMBO1, &CShapesV7Dlg::OnCbnSelchangeCombo1)
  ON_EN_CHANGE(IDC_EDIT1, &CShapesV7Dlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CShapesV7Dlg message handlers

BOOL CShapesV7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	// TODO: Add extra initialization here

  // combo box
  CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
  pCombo->InsertString(0, _T("Square"));
  pCombo->InsertString(1, _T("Rectangle"));
  pCombo->InsertString(2, _T("Circle"));
  pCombo->InsertString(3, _T("Triangle"));
  pCombo->InsertString(4, _T("Cube"));
  pCombo->InsertString(5, _T("Box"));
  pCombo->InsertString(6, _T("Cylinder"));
  pCombo->InsertString(7, _T("Prism"));
  pCombo->SetCurSel(-1); // or -1 for unselected

  // comsc 200 pic
  CStatic* pPicture = (CStatic*)GetDlgItem(IDC_STATIC8);
  pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
  HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
    MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
  pPicture->SetBitmap(hb);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShapesV7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShapesV7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShapesV7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShapesV7Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
  vector<string> tokens;

  CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
  int n = pCombo->GetCurSel();
  CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
  CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
  CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
  CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
  ostringstream sout;

  switch (n)
  {
    case 0: //Square
    {
      CString token;
      tokens.push_back("Square");
      pEdit1->GetWindowText(token);
      CT2CA pszConvertedAnsiString(token);
      std::string temp(pszConvertedAnsiString);
      tokens.push_back(temp);
      Square square(tokens);
      square.output(sout);
      pEdit4->SetWindowText(CString(sout.str().c_str()));
      break;
    }

    case 1: //Rectangle
    {
      CString token;
      tokens.push_back("Rectangle");
      pEdit1->GetWindowText(token);
      CT2CA pszConvertedAnsiString1(token);
      std::string temp1(pszConvertedAnsiString1);
      tokens.push_back(temp1);
      pEdit2->GetWindowText(token);
      CT2CA pszConvertedAnsiString2(token);
      std::string temp2(pszConvertedAnsiString2);
      tokens.push_back(temp2);
      comsc::Rectangle rectangle(tokens);
      rectangle.output(sout);
      pEdit4->SetWindowText(CString(sout.str().c_str()));
      break;
    }

    case 2: //Circle
    {
      CString token;
      tokens.push_back("Circle");
      pEdit1->GetWindowText(token);
      CT2CA pszConvertedAnsiString(token);
      std::string temp(pszConvertedAnsiString);
      tokens.push_back(temp);
      Circle circle(tokens);
      circle.output(sout);
      pEdit4->SetWindowText(CString(sout.str().c_str()));
      break;
    }

    case 3: //Triangle
    {
      CString token;
      tokens.push_back("Triangle");
      pEdit1->GetWindowText(token);
      CT2CA pszConvertedAnsiString(token);
      std::string temp(pszConvertedAnsiString);
      tokens.push_back(temp);
      Triangle triangle(tokens);
      triangle.output(sout);
      pEdit4->SetWindowText(CString(sout.str().c_str()));
      break;
    }

    case 4: //Cube
    {
      CString token;
      tokens.push_back("Cube");
      pEdit1->GetWindowText(token);
      CT2CA pszConvertedAnsiString(token);
      std::string temp(pszConvertedAnsiString);
      tokens.push_back(temp);
      Cube cube(tokens);
      cube.output(sout);
      pEdit4->SetWindowText(CString(sout.str().c_str()));
      break;
    }

    case 5: //Box
    {
      CString token;
      tokens.push_back("Box");
      pEdit1->GetWindowText(token);
      CT2CA pszConvertedAnsiString1(token);
      std::string temp1(pszConvertedAnsiString1);
      tokens.push_back(temp1);
      pEdit2->GetWindowText(token);
      CT2CA pszConvertedAnsiString2(token);
      std::string temp2(pszConvertedAnsiString2);
      tokens.push_back(temp2);
      pEdit3->GetWindowText(token);
      CT2CA pszConvertedAnsiString3(token);
      std::string temp3(pszConvertedAnsiString3);
      tokens.push_back(temp3);
      Box box(tokens);
      box.output(sout);
      pEdit4->SetWindowText(CString(sout.str().c_str()));
      break;
    }

    case 6: //Cylinder
    {
      CString token;
      tokens.push_back("Cylinder");
      pEdit1->GetWindowText(token);
      CT2CA pszConvertedAnsiString1(token);
      std::string temp1(pszConvertedAnsiString1);
      tokens.push_back(temp1);
      pEdit2->GetWindowText(token);
      CT2CA pszConvertedAnsiString2(token);
      std::string temp2(pszConvertedAnsiString2);
      tokens.push_back(temp2);
      Cylinder cylinder(tokens);
      cylinder.output(sout);
      pEdit4->SetWindowText(CString(sout.str().c_str()));
      break;
    }

    case 7: //Prism
    {
      CString token;
      tokens.push_back("Prism");
      pEdit1->GetWindowText(token);
      CT2CA pszConvertedAnsiString1(token);
      std::string temp1(pszConvertedAnsiString1);
      tokens.push_back(temp1);
      pEdit2->GetWindowText(token);
      CT2CA pszConvertedAnsiString2(token);
      std::string temp2(pszConvertedAnsiString2);
      tokens.push_back(temp2);
      Prism prism(tokens);
      prism.output(sout);
      pEdit4->SetWindowText(CString(sout.str().c_str()));
      break;
    }
  }
 
}


void CShapesV7Dlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CShapesV7Dlg::OnCbnSelchangeCombo1()
{
  // TODO: Add your control notification handler code here
  CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
  int n = pCombo->GetCurSel();


  switch(n)
  {
    case 0: // Square
      SetDlgItemText(IDC_STATIC3, _T("Side"));
      SetDlgItemText(IDC_STATIC4, _T("N/A"));
      SetDlgItemText(IDC_STATIC5, _T("N/A"));
      break;

    case 1: // Rectangle
      SetDlgItemText(IDC_STATIC3, _T("Length"));
      SetDlgItemText(IDC_STATIC4, _T("Width"));
      SetDlgItemText(IDC_STATIC5, _T("N/A"));
      break;

    case 2: // Circle
      SetDlgItemText(IDC_STATIC3, _T("Radius"));
      SetDlgItemText(IDC_STATIC4, _T("N/A"));
      SetDlgItemText(IDC_STATIC5, _T("N/A"));
      break;

    case 3: // Trianlge
      SetDlgItemText(IDC_STATIC3, _T("Side"));
      SetDlgItemText(IDC_STATIC4, _T("N/A"));
      SetDlgItemText(IDC_STATIC5, _T("N/A"));
      break;

    case 4: // Cube
      SetDlgItemText(IDC_STATIC3, _T("Side"));
      SetDlgItemText(IDC_STATIC4, _T("N/A"));
      SetDlgItemText(IDC_STATIC5, _T("N/A"));
      break;

    case 5: // Box
      SetDlgItemText(IDC_STATIC3, _T("Length"));
      SetDlgItemText(IDC_STATIC4, _T("Width"));
      SetDlgItemText(IDC_STATIC5, _T("Height"));
      break;

    case 6: // Cylinder
      SetDlgItemText(IDC_STATIC3, _T("Radius"));
      SetDlgItemText(IDC_STATIC4, _T("Height"));
      SetDlgItemText(IDC_STATIC5, _T("N/A"));
      break;

    case 7: // Prism
      SetDlgItemText(IDC_STATIC3, _T("Side"));
      SetDlgItemText(IDC_STATIC4, _T("Height"));
      SetDlgItemText(IDC_STATIC5, _T("N/A"));
      break;
  }
}


void CShapesV7Dlg::OnEnChangeEdit1()
{
  // TODO:  If this is a RICHEDIT control, the control will not
  // send this notification unless you override the CDialogEx::OnInitDialog()
  // function and call CRichEditCtrl().SetEventMask()
  // with the ENM_CHANGE flag ORed into the mask.

  // TODO:  Add your control notification handler code here
}
