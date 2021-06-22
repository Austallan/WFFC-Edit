#pragma once
#include "afxwin.h"
#include "afxdialogex.h"
#include "resource.h"
#include <vector>

// ModeDialogue dialog

class ModeDialogue : public CDialogEx
{
	DECLARE_DYNAMIC(ModeDialogue)

public:
	ModeDialogue(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ModeDialogue();
	void SetObjectData(int * Mode);	//passing in pointers to the data the class will operate on.

	void ResetChecks();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGMODE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void End();		//kill the dialogue

	int * m_currentMode;

	DECLARE_MESSAGE_MAP()
public:
	CButton m_CheckCamera;
	CButton m_CheckMove;
	CButton m_CheckRotate;
	CButton m_CheckScale;
	virtual void PostNcDestroy();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCamera();
	afx_msg void OnBnClickedMove();
	afx_msg void OnBnClickedRotate();
	afx_msg void OnBnClickedScale();
};

INT_PTR CALLBACK ModeProc(HWND   hwndDlg, UINT   uMsg, WPARAM wParam, LPARAM lParam);
