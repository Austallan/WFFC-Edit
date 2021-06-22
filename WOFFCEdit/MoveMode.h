#pragma once
#include "DisplayObject.h"
#include "InputCommands.h"

class MoveMode
{
public:
	MoveMode();
	~MoveMode();
	void MoveUpdate(InputCommands m_InputCommands, std::vector<DisplayObject> m_highlightObject, std::vector<DisplayObject*> m_displayList);

private:
	float m_movementRate;
};

