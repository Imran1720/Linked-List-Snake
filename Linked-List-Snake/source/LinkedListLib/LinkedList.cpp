#include "../../include/LinkedListLib/LinkedList.h"

namespace LinkedListLib
{
	LinkedList::LinkedList() { head_node = nullptr; }

	LinkedList::~LinkedList() = default;

	Vector2i LinkedList::getNewNodePosition(Node* reference, Operation operation)
	{
		switch (operation)
		{
		case Operation::HEAD:
			return reference->body_part.getNextPosition();

		case Operation::TAIL:
			return reference->body_part.getPreviousPosition();
		}
		return default_position;
	}

	Direction LinkedList::getReverseDirection(Direction reference_direction)
	{
		switch (reference_direction)
		{
		case Direction::UP:
			return Direction::DOWN;

		case Direction::DOWN:
			return Direction::UP;

		case Direction::LEFT:
			return Direction::RIGHT;

		case Direction::RIGHT:
			return Direction::LEFT;
		}
	}

	int LinkedList::findMiddleNode()
	{
		int current_index = 0;

		Node* slow_node = head_node;
		Node* fast_Node = head_node;

		while (fast_Node != nullptr && fast_Node->next != nullptr)
		{
			slow_node = slow_node->next;
			fast_Node = fast_Node->next->next;
			current_index++;
		}

		return current_index;
	}

	Node* LinkedList::findNodeAtIndex(int index)
	{
		int current_index = 0;
		Node* current_node = head_node;

		if (current_node == nullptr) return nullptr;

		while (current_node != nullptr && current_index < index)
		{
			current_node = current_node->next;
			current_index++;
		}
		return current_node;
	}

	void LinkedList::initializeNode(Node* new_node, Node* reference_node, Operation operation)
	{
		if (reference_node == nullptr)
		{
			new_node->body_part.initialize(node_width,node_height,default_position,default_direction);
			return;
		}

		Vector2i new_position = getNewNodePosition(reference_node, operation);

		new_node->body_part.initialize(node_width,node_height,new_position,reference_node->body_part.getDirection());
	}

	void LinkedList::render()
	{
		Node* current_node = head_node;
		while (current_node->next != nullptr)
		{
			current_node->body_part.render();
			current_node = current_node->next;
		}
	}

	void LinkedList::initialize(float width, float height, Vector2i position, Direction direction)
	{
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
		linked_list_size = 0;
	}

	void LinkedList::updateNodePosition()
	{
		Node* current_node = head_node;

		while (current_node != nullptr)
		{
			current_node->body_part.setPosition(current_node->body_part.getNextPosition());//to be added
			current_node->body_part.updatePosition();
			current_node = current_node->next;
		}
	}

	void LinkedList::updateNodeDirection(Direction direction_to_set)
	{
		Node* current_node = head_node;

		while (current_node != nullptr)
		{
			Direction previous_direction = current_node->body_part.getDirection();

			current_node->body_part.setDirection(direction_to_set);
			direction_to_set = previous_direction;
			current_node = current_node->next;
		}
	}

	Node* LinkedList::getHeadNode()
	{
		return head_node;
	}

	int LinkedList::getLinkedListSize()
	{
		return linked_list_size;
	}

	bool LinkedList::processNodeCollision()
	{
		if (head_node == nullptr) return false;

		Vector2i predicted_position = head_node->body_part.getNextPosition();

		Node* current_node = head_node->next;

		while (current_node != nullptr)
		{
			if (current_node->body_part.getNextPosition() == predicted_position)
			{
				return true;
			}
			current_node = current_node->next;
		}

		return false;
	}

	void LinkedList::reverseNodeDirection()
	{
		Node* current_node = head_node;

		while (current_node != nullptr)
		{
			Direction previous_direction = current_node->body_part.getPreviousDirection();
			current_node->body_part.setDirection(getReverseDirection(previous_direction));
			current_node = current_node->next;
		}
	}

	vector<Vector2i> LinkedList::getNodePositionList()
	{
		vector<Vector2i> node_Positons_list;
		Node* current_node = head_node;

		while (current_node != nullptr)
		{
			node_Positons_list.push_back(current_node->body_part.getPosition());
			current_node = current_node->next;
		}

		return node_Positons_list;
	}

}