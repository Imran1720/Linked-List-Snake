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
            linked_list_size++;
            Node* current_node = head_node;

            if (current_node == nullptr)
            {
                insertNodeAtHead();
                return;
            }

            int node_index = findMiddleNode();
            insertNodeAtIndex(node_index);
        }

        void DoubleLinkedList::insertNodeAtTail()
        {
            Node* new_node = createNode();
            Node* current_node = head_node;

            if (current_node == nullptr)
            {
                initializeNode(new_node, current_node, Operation::TAIL);
                head_node = new_node;
                return;
            }

            while (current_node->next != nullptr)
            {
                current_node = current_node->next;
            }

            current_node->next = new_node;
            static_cast<DoubleNode*>(new_node)->previous = current_node;
            initializeNode(new_node, current_node, Operation::TAIL);
        }

        void DoubleLinkedList::insertNodeAtIndex(int index)
        {
            if (index < 0 || index >= linked_list_size) return;

            linked_list_size++;
            
            if (index == 0)
            {
                insertNodeAtHead();
                return;
            }

            int current_index = 0;

            Node* new_node = createNode();
            Node* current_node = head_node;
            Node* previous_node = nullptr;
           

            while (current_node != nullptr && current_index < index)
            {
                previous_node = current_node;
                current_node = current_node->next;
            }

            previous_node->next = new_node;
            new_node->next = current_node;

            static_cast<DoubleNode*>(current_node)->previous = new_node;
            static_cast<DoubleNode*>(new_node)->previous = previous_node;

            initializeNode(new_node, previous_node, Operation::TAIL);
            shiftNodesAfterInsertion(new_node, current_node, previous_node);
        }

        void DoubleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
        {
            Node* next_node = cur_node;
            cur_node = new_node;

            while (next_node != nullptr && cur_node != nullptr)
            {
                cur_node->body_part.setPosition(next_node->body_part.getPosition());
                cur_node->body_part.setDirection(next_node->body_part.getDirection());

                prev_node = cur_node;
                cur_node = next_node;
                next_node = cur_node->next;
            }

            initializeNode(new_node,prev_node,Operation::TAIL);
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