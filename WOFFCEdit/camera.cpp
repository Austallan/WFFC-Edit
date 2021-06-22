#include "camera.h"

camera::camera()
{
	//functional
	m_movespeed = 0.30;
	m_camRotRate = 3.0;

	//camera
	m_camPosition.x = 0.0f;
	m_camPosition.y = 3.7f;
	m_camPosition.z = -3.5f;

	m_camOrientation.x = 0;
	m_camOrientation.y = 0;
	m_camOrientation.z = 0;

	m_camLookAt.x = 0.0f;
	m_camLookAt.y = 0.0f;
	m_camLookAt.z = 0.0f;

	m_camLookDirection.x = 0.0f;
	m_camLookDirection.y = 0.0f;
	m_camLookDirection.z = 0.0f;

	m_camRight.x = 0.0f;
	m_camRight.y = 0.0f;
	m_camRight.z = 0.0f;

	m_camOrientation.x = 0.0f;
	m_camOrientation.y = 0.0f;
	m_camOrientation.z = 0.0f;

	isArcBall		  = false;
	isSnappedToObject = false;
}

camera::~camera()
{

}

DirectX::SimpleMath::Matrix camera::CameraUpdate(InputCommands m_InputCommands, std::vector<DisplayObject> m_highlightObject)
{
	if (m_InputCommands.isO)
	{
		isArcBall = true;
	}

	if (m_InputCommands.mouse_RB_Down && m_InputCommands.ctrl)
	{
		isSnappedToObject = true;
		m_InputCommands.mouse_RB_Down = false;
	}
	//TODO  any more complex than this, and the camera should be abstracted out to somewhere else
//camera motion is on a plane, so kill the 7 component of the look direction
	if (isArcBall && m_highlightObject.size() == 1)
	{
		m_camLookDirection = m_highlightObject[0].m_position - m_camPosition;
	}
	else
	{
		isArcBall = false;
		if (m_InputCommands.cameraMode)
		{
			m_camOrientation.y += m_InputCommands.xChange;

			m_camOrientation.x -= m_InputCommands.yChange;
		}

		//create look direction from Euler angles in m_camOrientation
		m_camLookDirection.x = cos((m_camOrientation.y)*3.1415 / 180) * cos((m_camOrientation.x)*3.1415 / 180); //x = rSinΘ -----> x = rCosΘCosΦ

		m_camLookDirection.y = sin((m_camOrientation.x)*3.1415 / 180); //y = rCosΘ -----> y = rsinΦ

		m_camLookDirection.z = sin((m_camOrientation.y)*3.1415 / 180) * cos((m_camOrientation.x)*3.1415 / 180); //z--------------> z = rSinΘCosΦ
	}


	DirectX::SimpleMath::Vector3 planarMotionVector = m_camLookDirection;
	planarMotionVector.y = 0.0;

	if (m_InputCommands.rotRight)
	{
		m_camOrientation.y += m_camRotRate;
	}
	if (m_InputCommands.rotLeft)
	{
		m_camOrientation.y -= m_camRotRate;
	}

	m_camLookDirection.Normalize();

	//create right vector from look Direction
	m_camLookDirection.Cross(DirectX::SimpleMath::Vector3::UnitY, m_camRight);

	//process input and update stuff
	if (m_InputCommands.forward)
	{
		m_camPosition += m_camLookDirection * m_movespeed;
	}
	if (m_InputCommands.back)
	{
		m_camPosition -= m_camLookDirection * m_movespeed;
	}
	if (m_InputCommands.right)
	{
		m_camPosition += m_camRight * m_movespeed;
	}
	if (m_InputCommands.left)
	{
		m_camPosition -= m_camRight * m_movespeed;
	}
	if (m_InputCommands.isR)//UP
	{
		m_camPosition += m_camRight.Cross(m_camLookDirection);
	}
	if (m_InputCommands.isF)//DOWN
	{
		m_camPosition -= m_camRight.Cross(m_camLookDirection);
	}

	if (isSnappedToObject && m_highlightObject.size() == 1 && !isArcBall)
	{
		DirectX::SimpleMath::Vector3 elSnappo;
		elSnappo = m_highlightObject[0].m_position - m_camLookAt;
		m_camPosition += elSnappo;
		elSnappo = (m_camPosition - m_highlightObject[0].m_position) * 5;

		m_camPosition += elSnappo;
		isSnappedToObject = false;
	}

	//update lookat point
	if (isArcBall && m_highlightObject.size() == 1)
	{
		m_camLookAt = m_highlightObject[0].m_position;
	}
	else
	{
		m_camLookAt = m_camPosition + m_camLookDirection;
		isArcBall = false;
	}

	//apply camera vectors
	return DirectX::SimpleMath::Matrix::CreateLookAt(m_camPosition, m_camLookAt, DirectX::SimpleMath::Vector3::UnitY);
}

float camera::returnCamPosX()
{
	return m_camPosition.x;
}

float camera::returnCamPosZ()
{
	return m_camPosition.z;
}

void camera::snapToSelection()
{
	isSnappedToObject = true;
}