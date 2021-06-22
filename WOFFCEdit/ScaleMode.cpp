#include "ScaleMode.h"

ScaleMode::ScaleMode()
{
	m_movementRate = 0.1f;
}

ScaleMode::~ScaleMode()
{

}


void ScaleMode::ScaleUpdate(InputCommands m_InputCommands, std::vector<DisplayObject> m_highlightObject, std::vector<DisplayObject*> m_EditObjectsList)
{
	if (m_InputCommands.Lshift)
		m_movementRate = 0.01f;
	else
		m_movementRate = 0.1f;

	if (m_InputCommands.forward)
	{
		for (int i = 0; i < m_highlightObject.size(); i++)
		{
			m_EditObjectsList[m_highlightObject[i].m_ID]->m_scale.x += m_movementRate;
		}
	}

	if (m_InputCommands.back)
	{
		for (int i = 0; i < m_highlightObject.size(); i++)
		{
			m_EditObjectsList[m_highlightObject[i].m_ID]->m_scale.x -= m_movementRate;
		}
	}

	if (m_InputCommands.right)
	{
		for (int i = 0; i < m_highlightObject.size(); i++)
		{
			m_EditObjectsList[m_highlightObject[i].m_ID]->m_scale.z += m_movementRate;
		}
	}

	if (m_InputCommands.left)
	{
		for (int i = 0; i < m_highlightObject.size(); i++)
		{
			m_EditObjectsList[m_highlightObject[i].m_ID]->m_scale.z -= m_movementRate;
		}
	}

	if (m_InputCommands.isR)
	{
		for (int i = 0; i < m_highlightObject.size(); i++)
		{
			m_EditObjectsList[m_highlightObject[i].m_ID]->m_scale.y += m_movementRate;
		}
	}

	if (m_InputCommands.isF)
	{
		for (int i = 0; i < m_highlightObject.size(); i++)
		{
			m_EditObjectsList[m_highlightObject[i].m_ID]->m_scale.y -= m_movementRate;
		}
	}
}