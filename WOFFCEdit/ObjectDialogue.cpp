// ObjectDialogue.cpp : implementation file
//

#include "afxdialogex.h"
#include "pch.h"
#include "ObjectDialogue.h"


// ObjectDialogue dialog

IMPLEMENT_DYNAMIC(ObjectDialogue, CDialogEx)

//Message map.  Just like MFCMAIN.cpp.  This is where we catch button presses etc and point them to a handy dandy method.
BEGIN_MESSAGE_MAP(ObjectDialogue, CDialogEx)
	ON_COMMAND(IDOK, &ObjectDialogue::End)					//ok button
	ON_BN_CLICKED(IDCLOSE, &ObjectDialogue::End)
	ON_BN_CLICKED(IDCANCEL, &ObjectDialogue::End)
	ON_BN_CLICKED(IDOK, &ObjectDialogue::OnBnClickedOk)
	ON_BN_CLICKED(IDC_UPDATEBUTTON, &ObjectDialogue::OnBnClickedUpdate)//Update Button
	ON_WM_LBUTTONDOWN(IDOK, &ObjectDialogue::OnMouseClicked)//TRY TO MAKE IT UPDATE EVERY CLICK INSTEAD OF ON BUTTON PRESS
END_MESSAGE_MAP()

ObjectDialogue::ObjectDialogue(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGSELECTED, pParent)
{
}

ObjectDialogue::~ObjectDialogue()
{
}

void ObjectDialogue::OnMouseClicked()
{
	MessageBox(L"Update Pressed!!!");
}

void ObjectDialogue::SetObjectData(std::vector<DisplayObject>* SceneGraph, int selection)
{
	UpdateData();

	m_sceneGraph = SceneGraph;
	m_currentSelection = selection;

	
	if (selection >= 0)
	{
		//Get the selected object and then display its data
		std::wstring ObjectName = std::to_wstring(m_sceneGraph->at(m_currentSelection).m_ID);//Object ID
		m_selectedName.SetWindowTextW(ObjectName.c_str());

		std::wstring str = std::to_wstring((m_sceneGraph->at(m_currentSelection).m_position.x));//Xpos
		m_PosX.SetWindowTextW(str.c_str());

		 str = std::to_wstring((m_sceneGraph->at(m_currentSelection).m_position.y));//Ypos
		m_PosY.SetWindowTextW(str.c_str());

		str = std::to_wstring((m_sceneGraph->at(m_currentSelection).m_position.z));//Zpos
		m_PosZ.SetWindowTextW(str.c_str());

		str = std::to_wstring((m_sceneGraph->at(m_currentSelection).m_orientation.x));//RotX
		m_RotX.SetWindowTextW(str.c_str());

		str = std::to_wstring((m_sceneGraph->at(m_currentSelection).m_orientation.y));//RotY
		m_RotY.SetWindowTextW(str.c_str());

		str = std::to_wstring((m_sceneGraph->at(m_currentSelection).m_orientation.z));//RotZ
		m_RotZ.SetWindowTextW(str.c_str());

		str = std::to_wstring((m_sceneGraph->at(m_currentSelection).m_scale.x));//ScaleX
		m_ScaleX.SetWindowTextW(str.c_str());

		str = std::to_wstring((m_sceneGraph->at(m_currentSelection).m_scale.y));//ScaleY
		m_ScaleY.SetWindowTextW(str.c_str());

		str = std::to_wstring((m_sceneGraph->at(m_currentSelection).m_scale.z));//ScaleZ
		m_ScaleZ.SetWindowTextW(str.c_str());
	}
	else
	{
		//An invalid object has been selected
		m_selectedName.SetWindowTextW(L"Invalid Selection");
	}
}

void ObjectDialogue::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SELECTEDNAME, m_selectedName);
	DDX_Control(pDX, IDC_XPOS, m_PosX);
	DDX_Control(pDX, IDC_YPOS, m_PosY);
	DDX_Control(pDX, IDC_ZPOS, m_PosZ);
	DDX_Control(pDX, IDC_XROT, m_RotX);
	DDX_Control(pDX, IDC_YROT, m_RotY);
	DDX_Control(pDX, IDC_ZROT, m_RotZ);
	DDX_Control(pDX, IDC_SCALEX, m_ScaleX);
	DDX_Control(pDX, IDC_SCALEY, m_ScaleY);
	DDX_Control(pDX, IDC_SCALEZ, m_ScaleZ);
}

void ObjectDialogue::End()
{
	DestroyWindow();	//destory the window properly.  INcluding the links and pointers created.  THis is so the dialogue can start again. 
}

void ObjectDialogue::PostNcDestroy()
{
}

void ObjectDialogue::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

void ObjectDialogue::GetCurrentSelection(int latestSelection)
{
	m_currentSelection = latestSelection;
}

void ObjectDialogue::OnBnClickedUpdate()
{
	// TODO: Add your control notification handler code here
	SetObjectData(m_sceneGraph, m_currentSelection);
}

BOOL ObjectDialogue::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//uncomment for modal only
/*	//roll through all the objects in the scene graph and put an entry for each in the listbox
	int numSceneObjects = m_sceneGraph->size();
	for (size_t i = 0; i < numSceneObjects; i++)
	{
		//easily possible to make the data string presented more complex. showing other columns.
		std::wstring listBoxEntry = std::to_wstring(m_sceneGraph->at(i).ID);
		m_listBox.AddString(listBoxEntry.c_str());
	}*/

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

