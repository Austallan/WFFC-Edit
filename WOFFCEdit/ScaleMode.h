#pragma once
#include "DisplayObject.h"
#include "InputCommands.h"

class ScaleMode
{
public:
	ScaleMode();
	~ScaleMode();
	void ScaleUpdate(InputCommands m_InputCommands, std::vector<DisplayObject> m_highlightObject, std::vector<DisplayObject*> m_displayList);

private:
	float m_movementRate;
};

