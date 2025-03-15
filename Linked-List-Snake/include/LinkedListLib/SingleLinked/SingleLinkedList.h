#pragma once
#include <SFML/Graphics.hpp>
#include "LinkedListLib/SingleLinked/SingleNode.h"
#include "LinkedListLib/LinkedList.h"
#include <vector>

namespace LinkedListLib
{
	namespace SingleLinked 
	{
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

        class SingleLinkedList : public LinkedList
        {
        protected:
            LinkedListOperations current_linked_list_operation;
            TimeComplexity current_time_complexity;

            virtual SingleNode* createNode() override;

        public:
            SingleLinkedList();
            ~SingleLinkedList();

            void insertNodeAtHead() override;
            void insertNodeAtMiddle() override;
            void insertNodeAtTail() override;
            void insertNodeAtIndex(int index);

            void shiftNodeAfterInsertion(SingleNode* new_node, SingleNode* current_node, SingleNode* previous_node);

            void removeAllNode() override;
            void removeNodeAtHead() override;
            void removeNodeAtMiddle() override;
            void removeNodeAtTail() override;
            void removeNodeAt(int index) override;
            void removeHalfNodes() override;
            void removeNodeAtIndex(int index);

            void shiftNodesAfterRemoval(SingleNode* cur_node);

            Direction reverse() override;
            void reverseNodeDirections();

            TimeComplexity getCurrentTimeComplexity();
            LinkedListOperations getCurrentLinkedListOperation();


        };
	}
}
