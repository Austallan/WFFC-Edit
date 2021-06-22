// ModeDialogue.cpp : implementation file
//


#include "afxdialogex.h"
#include "pch.h"
#include "ModeDialogue.h"



// ModeDialogue dialog

IMPLEMENT_DYNAMIC(ModeDialogue, CDialogEx)

BEGIN_MESSAGE_MAP(ModeDialogue, CDialogEx)
	ON_COMMAND(IDOK, &ModeDialogue::End)					//ok button
	ON_BN_CLICKED(IDCLOSE, &ModeDialogue::End)
	ON_BN_CLICKED(IDCANCEL, &ModeDialogue::End)
	ON_BN_CLICKED(IDOK, &ModeDialogue::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTONCAMERA, &ModeDialogue::OnBnClickedCamera)
	ON_BN_CLICKED(IDC_BUTTONMOVE, &ModeDialogue::OnBnClickedMove)
	ON_BN_CLICKED(IDC_BUTTONROTATE, &ModeDialogue::OnBnClickedRotate)
	ON_BN_CLICKED(IDC_BUTTONSCALE, &ModeDialogue::OnBnClickedScale)
END_MESSAGE_MAP()

ModeDialogue::ModeDialogue(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGMODE, pParent)
{

}

ModeDialogue::~ModeDialogue()
{
}

void ModeDialogue::SetObjectData(int * Mode)
{
	m_currentMode = Mode;
}

void ModeDialogue::ResetChecks()
{
	m_CheckCamera.SetCheck(0);//Camera
	m_CheckMove.SetCheck(0);//Camera
	m_CheckRotate.SetCheck(0);//Camera
	m_CheckScale.SetCheck(0);//Camera
}

void ModeDialogue::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_CHECKCAMERA, m_CheckCamera);
	DDX_Control(pDX, IDC_CHECKMOVE, m_CheckMove);
	DDX_Control(pDX, IDC_CHECKROTATE, m_CheckRotate);
	DDX_Control(pDX, IDC_CHECKSCALE, m_CheckScale);
}

void ModeDialogue::End()
{
	DestroyWindow();	//destory the window properly.  INcluding the links and pointers created.  THis is so the dialogue can start again. 
}

void ModeDialogue::PostNcDestroy()
{
}

void ModeDialogue::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

void ModeDialogue::OnBnClickedCamera()
{
	ResetChecks();
	m_CheckCamera.SetCheck(1);//Camera
	*m_currentMode = 1;
}

void ModeDialogue::OnBnClickedMove()
{
	ResetChecks();
	m_CheckMove.SetCheck(1);//Move
	*m_currentMode = 2;
}

void ModeDialogue::OnBnClickedRotate()
{
	ResetChecks();
	m_CheckRotate.SetCheck(1);//Rotate
	*m_currentMode = 3;
}

void ModeDialogue::OnBnClickedScale()
{
	ResetChecks();
	m_CheckScale.SetCheck(1);//Scale
	*m_currentMode = 4;
}

// ModeDialogue message handlers
