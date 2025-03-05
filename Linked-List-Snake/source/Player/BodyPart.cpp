#include "../../include/Player/BodyPart.h"
#include "../../include/Global/Config.h"

using namespace Global;

namespace Player
{
	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new ImageView();
	}
	
	BodyPart::BodyPart()
	{
		grid_position = Vector2i(0,0);
	}

	BodyPart::~BodyPart()
	{
		destroy();
	}

	void BodyPart::initialize(float width, float height, Vector2i position, Direction move_directiion)
	{
		bodypart_width = width;
		bodypart_height = height;

		grid_position = position;
		direction = move_directiion;

		initializeBodypartImage();
	}

	void BodyPart::initializeBodypartImage()
	{
		bodypart_image->initialize(Config::snake_body_texture_path,bodypart_width,bodypart_height,getBodypartScreenPosition());
		bodypart_image->setOriginAtCentre();
	}

	void BodyPart::render()
	{
		bodypart_image->render();
	}

	Vector2f BodyPart::getBodypartScreenPosition()
	{
		return Vector2f(0,0);
	}

	void BodyPart::destroy()
	{
		delete(bodypart_image);
	}
}
