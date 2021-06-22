#pragma once
#include "afxwin.h"
#include "afxdialogex.h"
#include "resource.h"
#include "SceneObject.h"
#include "DisplayObject.h"
#include <vector>

// ObjectDialogue dialog

class ObjectDialogue : public CDialogEx
{
	DECLARE_DYNAMIC(ObjectDialogue)

public:
	ObjectDialogue(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ObjectDialogue();
	void SetObjectData(std::vector<DisplayObject>* SceneGraph, int Selection);	//passing in pointers to the data the class will operate on.

	void GetCurrentSelection(int latestSelection);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGSELECTED };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void End();		//kill the dialogue

	std::vector<DisplayObject> * m_sceneGraph;
	int m_currentSelection;

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_selectedName;
	CEdit m_PosX;
	CEdit m_PosY;
	CEdit m_PosZ;
	CEdit m_RotX;
	CEdit m_RotY;
	CEdit m_RotZ;
	CEdit m_ScaleX;
	CEdit m_ScaleY;
	CEdit m_ScaleZ;
	CButton m_SnapCheck;
	CButton m_UpdateButton;
	virtual BOOL OnInitDialog() override;
	virtual void PostNcDestroy();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedUpdate();
	afx_msg void OnMouseClicked();
};

INT_PTR CALLBACK ObjectProc(HWND   hwndDlg, UINT   uMsg, WPARAM wParam, LPARAM lParam);