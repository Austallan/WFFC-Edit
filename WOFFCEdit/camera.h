#pragma once
#include "DisplayObject.h"
#include "InputCommands.h"

class camera
{
public:
	camera();
	~camera();
	DirectX::SimpleMath::Matrix CameraUpdate(InputCommands m_InputCommands, std::vector<DisplayObject> m_highlightObject);
	float returnCamPosX();
	float returnCamPosZ();
	void snapToSelection();
	
private:

	//camera
	DirectX::SimpleMath::Vector3		m_camPosition;
	DirectX::SimpleMath::Vector3		m_camOrientation;
	DirectX::SimpleMath::Vector3		m_camLookAt;
	DirectX::SimpleMath::Vector3		m_camLookDirection;
	DirectX::SimpleMath::Vector3		m_camRight;
	float								m_camRotRate;
	float								m_movespeed;
	bool								isArcBall;
	bool								isSnappedToObject;
};