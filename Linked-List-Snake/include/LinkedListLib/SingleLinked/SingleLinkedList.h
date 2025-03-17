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
	
		

        class SingleLinkedList : public LinkedList
        {
        protected:
            LinkedListOperations current_linked_list_operation;
            TimeComplexity current_time_complexity;

            virtual Node* createNode() override;

        public:
            SingleLinkedList();
            ~SingleLinkedList();

            void insertNodeAtHead() override;
            void insertNodeAtMiddle() override;
            void insertNodeAtTail() override;
            void insertNodeAtIndex(int index);

            void shiftNodeAfterInsertion(Node* new_node, Node* current_node, Node* previous_node);

            void removeAllNode() override;
            void removeNodeAtHead() override;
            void removeNodeAtMiddle() override;
            void removeNodeAtTail() override;
            void removeNodeAt(int index) override;
            void removeHalfNodes() override;
            void removeNodeAtIndex(int index);

            void shiftNodesAfterRemoval(Node* cur_node);

            Direction reverse() override;
            void reverseNodeDirections();

            TimeComplexity getCurrentTimeComplexity();
            LinkedListOperations getCurrentLinkedListOperation();


        };
	}
}
