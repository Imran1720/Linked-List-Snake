#pragma once
#include <SFML/Graphics.hpp>
#include "LinkedListLib/SingleLinked/SingleNode.h"
#include <vector>

using namespace sf;
using namespace std;

namespace LinkedList
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};
	enum class TimeComplexity
	{
		NONE,
		ONE,
		N,
	};

	enum class LinkedListOperations
	{
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
	};


	class SingleLinkedList
	{
	private:
		SingleNode* head_node;

		LinkedListOperations current_linked_list_operation;
		TimeComplexity current_time_complexity;

		float node_width;
		float node_height;

		Vector2i default_position;
		Direction default_direction;

		int linked_list_size;

		SingleNode* createNode();

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, Vector2i position, Direction direction);
		void render();

		void initializeNode(SingleNode* new_node,SingleNode* reference_node,Operation operation);

		int getListSize();

		Vector2i getNewNodePosition(SingleNode* reference,Operation operation);
		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();
		bool processNodeCollision();

		void insertNodeAtTail();
		void insertNodeAtHead();
		void insertNodeAtIndex(int index);
		void insertNodeAtMiddle();
		void insertNodeAt(int index);

		void shiftNodeAfterInsertion(SingleNode* new_node,SingleNode* current_node,SingleNode* previous_node);
		void shiftNodesAfterRemoval(SingleNode* cur_node);


		int findMiddleIndex();

		void removeAllHeadNode();
		void removeNodeAtHead();
		void removeNodeAtIndex(int index);
		void removeNodeAt(int index);
		void removeNodeAtMiddle();
		void removeNodeAtTail();
		SingleNode* findNodeAtIndex(int index);
		void removeHalfNodes();
		
		Direction reverse();
		void reverseNodeDirection();

		Direction getReverseDirection(Direction reference_direction);

		TimeComplexity getCurrentTimeComplexity();
		LinkedListOperations getCurrentLinkedListOperation();
		vector<Vector2i> getNodePositionList();
		SingleNode* getHead();


	};
}