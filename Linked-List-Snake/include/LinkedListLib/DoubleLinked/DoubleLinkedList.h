#pragma once
#include "../../include/LinkedListLib/LinkedList.h"
#include "../../include/LinkedListLib/DoubleLinked/DoubleNode.h"

namespace LinkedListLib
{
	namespace DoubleLinked
	{
		class DoubleLinkedList : public LinkedList
		{
		protected:
			virtual DoubleNode* createNode() override;

		public:
			DoubleLinkedList();
			~DoubleLinkedList();

			void insertNodeAtHead() override;
			void insertNodeAtMiddle() override;
			void insertNodeAtTail() override;
			void insertNodeAtIndex(int index) override;

			void shiftNodesAfterInsertion(DoubleNode* new_node, DoubleNode* cur_node, DoubleNode* prev_node);


			void removeAllNode() override;
			void removeNodeAtHead() override;
			void removeNodeAtMiddle() override;
			void removeNodeAtTail() override;
			void removeNodeAt(int index) override;
			void removeNodeAtIndex(int index);
			void removeHalfNodes() override;

			void shiftNodesAfterRemoval(DoubleNode* cur_node);
			Direction reverse() override;
		};
	}
}