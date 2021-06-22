#include "RotateMode.h"

RotateMode::RotateMode()
{
	m_movementRate = 1.0f;
}

RotateMode::~RotateMode()
{

}


void RotateMode::RotateUpdate(InputCommands m_InputCommands, std::vector<DisplayObject> m_highlightObject, std::vector<DisplayObject*> m_EditObjectsList)
{
	if (m_InputCommands.Lshift)
		m_movementRate = 0.1f;
	else
		m_movementRate = 1.0f;

	if (m_InputCommands.forward)
	{
		for (int i = 0; i < m_highlightObject.size(); i++)
		{
			m_EditObjectsList[m_highlightObject[i].m_ID]->m_orientation.x += m_movementRate;
		}
	}

	if (m_InputCommands.back)
	{
		for (int i = 0; i < m_highlightObject.size(); i++)
		{
			m_EditObjectsList[m_highlightObject[i].m_ID]->m_orientation.x -= m_movementRate;
		}
	}

	if (m_InputCommands.right)
	{
		for (int i = 0; i < m_highlightObject.size(); i++)
		{
			m_EditObjectsList[m_highlightObject[i].m_ID]->m_orientation.z += m_movementRate;
		}
	}

	if (m_InputCommands.left)
	{
		for (int i = 0; i < m_highlightObject.size(); i++)
		{
			m_EditObjectsList[m_highlightObject[i].m_ID]->m_orientation.z -= m_movementRate;
		}
	}

	if (m_InputCommands.isR)
	{
		for (int i = 0; i < m_highlightObject.size(); i++)
		{
			m_EditObjectsList[m_highlightObject[i].m_ID]->m_orientation.y += m_movementRate;
		}
	}

	if (m_InputCommands.isF)
	{
		for (int i = 0; i < m_highlightObject.size(); i++)
		{
			m_EditObjectsList[m_highlightObject[i].m_ID]->m_orientation.y -= m_movementRate;
		}
	}
}