#pragma once
#include <SFML/Graphics.hpp>
#include "LinkedList/Node.h"
#include <vector>


using namespace sf;
using namespace std;
using namespace Player;

namespace LinkedList
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};
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

		void initializeNode(Node* new_node,Node* reference_node,Operation operation);

		Vector2i getNewNodePosition(Node* reference,Operation operation);
		void insertNodeAtTail();
		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();

		bool processNodeCollision();

		void removeAllHeadNode();
		void removeNodeAtHead();
		vector<Vector2i> getNodePositionList();
		Node* getHead();


	};
}