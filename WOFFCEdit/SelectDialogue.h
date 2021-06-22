#pragma once
#include "afxdialogex.h"
#include "resource.h"
#include "afxwin.h"
#include "SceneObject.h"
#include "DisplayObject.h"
#include <vector>

// SelectDialogue dialog

class SelectDialogue : public CDialogEx
{
	DECLARE_DYNAMIC(SelectDialogue)

public:
	SelectDialogue(CWnd* pParent, std::vector<DisplayObject>* SceneGraph);   // modal // takes in out scenegraph in the constructor
	SelectDialogue(CWnd* pParent = NULL);
	virtual ~SelectDialogue();
	void SetObjectData(std::vector<DisplayObject>* SceneGraph, int * Selection, bool * freshSelect);	//passing in pointers to the data the class will operate on.
	
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void End();		//kill the dialogue
	afx_msg void Select();	//Item has been selected

	std::vector<DisplayObject> * m_sceneGraph;
	int * m_currentSelection;
	bool * m_freshSelect;
	

	DECLARE_MESSAGE_MAP()
public:
	// Control variable for more efficient access of the listbox
	CListBox m_listBox;
	virtual BOOL OnInitDialog() override;
	virtual void PostNcDestroy();
	afx_msg void OnBnClickedOk();
	afx_msg void OnLbnSelchangeList1();
};


INT_PTR CALLBACK SelectProc( HWND   hwndDlg,UINT   uMsg,WPARAM wParam,LPARAM lParam);