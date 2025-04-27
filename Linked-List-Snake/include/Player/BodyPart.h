#pragma once
#include <SFML/Graphics.hpp>
#include "Player/Direction.h"
#include "UI/UIElement/ImageView.h"


using namespace sf;
using namespace UI::UIElement;

namespace Player
{
	class BodyPart
	{
	protected:
		ImageView* bodypart_image;

		Vector2i grid_position;
		Direction direction;

		float bodypart_width;
		float bodypart_height;

		void createBodyPartImage();
		void destroy();
	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, Vector2i position, Direction moving_directiion);
		void initializeBodypartImage();

		void render();
		Vector2f getBodypartScreenPosition();
		float getRotationAngle();
		void setDirection(Direction direction);

		void updatePosition();

		Vector2i getNextPosition();

		Vector2i getnextPositionUp();
		Vector2i getnextPositionDown();
		Vector2i getnextPositionLeft();
		Vector2i getnextPositionRight();

		void setPosition(Vector2i position);

		Direction getDirection();

		Vector2i getPosition();

	};
}