#include "../../include/Player/BodyPart.h"
#include "../../include/Global/Config.h"
#include "../../include/Level/LevelView.h"

using namespace Level;
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
		float xPosition = LevelView::border_offset_left + (grid_position.x * bodypart_width) + (bodypart_width / 2);
		float yPosition = LevelView::border_offset_top + (grid_position.y * bodypart_height) + (bodypart_height / 2);

		return Vector2f(xPosition,yPosition);
	}

	float BodyPart::getRotationAngle()
	{
		switch (direction)
		{
		case Player::Direction::UP:
			return 0;
		case Player::Direction::DOWN:
			return 90;
		case Player::Direction::LEFT:
			return 180;
		case Player::Direction::RIGHT:
			return 270;

		}
	}

	void BodyPart::setDirection(Direction new_direction)
	{
		direction = new_direction;
	}

	void BodyPart::updatePosition()
	{
		bodypart_image->setPosition(getBodypartScreenPosition());
		bodypart_image->setRotation(getRotationAngle());
		bodypart_image->update();
	}

	void BodyPart::destroy()
	{
		delete(bodypart_image);
	}
}
