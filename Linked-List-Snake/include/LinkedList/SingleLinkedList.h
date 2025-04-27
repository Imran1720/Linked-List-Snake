#pragma once
#include <SFML/Graphics.hpp>
#include "LinkedList/Node.h"

using namespace sf;
using namespace Player;

namespace LinkedList
{
	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;
		Vector2i default_position;
		Direction default_direction;

		Node* createNode();

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, Vector2i position, Direction direction);
		void render();

		Vector2i getNewNodePosition(Node* reference);
		void insertNodeAtTail();
		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();

		bool processNodeCollision();

		void removeAllHeadNode();
		void removeNodeAtHead();
		Node* getHead();
	};
}