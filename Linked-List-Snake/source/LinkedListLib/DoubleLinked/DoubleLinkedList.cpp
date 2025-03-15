#include "../../include/LinkedListLib/DoubleLinked/DoubleLinkedList.h"

namespace LinkedListLib
{
    namespace DoubleLinked
    {
        DoubleLinkedList::DoubleLinkedList() = default;

        DoubleLinkedList::~DoubleLinkedList() = default;

        Node* DoubleLinkedList::createNode()
        {
            return new DoubleNode();
        }

        void DoubleLinkedList::insertNodeAtHead()
        {
            linked_list_size++;
            Node* new_node = createNode();

            if (head_node == nullptr)
            {
                static_cast<DoubleNode*>(new_node)->previous = nullptr;
                initializeNode(new_node,head_node,Operation::HEAD);
                head_node = new_node;
                return;
            }

            new_node->next = head_node;
            static_cast<DoubleNode*>(head_node)->previous = new_node;

            initializeNode(new_node, head_node, Operation::HEAD);
            head_node = new_node;
        }

        void DoubleLinkedList::insertNodeAtMiddle()
        {
        }

        void DoubleLinkedList::insertNodeAtTail()
        {
        }

        void DoubleLinkedList::insertNodeAtIndex(int index)
        {
        }

        void DoubleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
        {
        }

        void DoubleLinkedList::removeAllNode()
        {
        }

        void DoubleLinkedList::removeNodeAtHead()
        {
        }

        void DoubleLinkedList::removeNodeAtMiddle()
        {
        }

        void DoubleLinkedList::removeNodeAtTail()
        {
        }

        void DoubleLinkedList::removeNodeAt(int index)
        {
        }

        void DoubleLinkedList::removeNodeAtIndex(int index)
        {
        }


        void DoubleLinkedList::removeHalfNodes()
        {
        }

        void DoubleLinkedList::shiftNodesAfterRemoval(Node* cur_node)
        {
        }

        Direction DoubleLinkedList::reverse()
        {
            return Direction();
        }
    }
}