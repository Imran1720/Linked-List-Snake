#pragma once
#include <SFML/Graphics.hpp>
#include "LinkedListLib/SingleLinked/SingleNode.h"
#include <vector>

namespace LinkedListLib
{
	using namespace SingleLinked;
	using namespace sf;
	using namespace std;
	
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
		LinkedListOperations current_linked_list_operation;
		TimeComplexity current_time_complexity;

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void shiftNodeAfterInsertion(SingleNode* new_node,SingleNode* current_node,SingleNode* previous_node);
		void shiftNodesAfterRemoval(SingleNode* cur_node);

		int findMiddleIndex();

		TimeComplexity getCurrentTimeComplexity();
		LinkedListOperations getCurrentLinkedListOperation();
	};
}