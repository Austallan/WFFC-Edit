#include "DisplayObject.h"

DisplayObject::DisplayObject()
{
	m_model = NULL;
	m_texture_diffuse = NULL;
	m_orientation.x = 0.0f;
	m_orientation.y = 0.0f;
	m_orientation.z = 0.0f;
	m_position.x = 0.0f;
	m_position.y = 0.0f;
	m_position.z = 0.0f;
	m_scale.x = 0.0f;
	m_scale.y = 0.0f;
	m_scale.z = 0.0f;
	m_render = true;
	m_wireframe = false;

	m_light_type =0;
	m_light_diffuse_r = 0.0f;	m_light_diffuse_g = 0.0f;	m_light_diffuse_b = 0.0f;
	m_light_specular_r = 0.0f;	m_light_specular_g = 0.0f;	m_light_specular_b = 0.0f;
	m_light_spot_cutoff = 0.0f;
	m_light_constant = 0.0f;
	m_light_linear = 0.0f;
	m_light_quadratic = 0.0f;
}

DisplayObject::DisplayObject(const DisplayObject &obj)
{
	*this = obj;
	
	//THIS WON'T WORK FOR SOME REASON SO I'M HAVING TO USE *this
	//*m_model = *obj.m_model;
	//*m_texture_diffuse = *obj.m_texture_diffuse;
	//m_orientation = obj.m_orientation;

	//m_position = obj.m_position;

	//m_scale = obj.m_scale;

	//m_render = obj.m_render;

	//m_wireframe = obj.m_wireframe;

	//m_light_type = obj.m_light_type;
	//m_light_diffuse_r = obj.m_light_diffuse_r;	m_light_diffuse_g = obj.m_light_diffuse_g;	m_light_diffuse_b = obj.m_light_diffuse_b;
	//m_light_specular_r = obj.m_light_specular_r;	m_light_specular_g = obj.m_light_specular_g;	m_light_specular_b = obj.m_light_specular_b;
	//m_light_spot_cutoff = obj.m_light_spot_cutoff;
	//m_light_constant = obj.m_light_constant;
	//m_light_linear = obj.m_light_linear;
	//m_light_quadratic = obj.m_light_quadratic;
}


DisplayObject::~DisplayObject()
{
//	delete m_texture_diffuse;
}
