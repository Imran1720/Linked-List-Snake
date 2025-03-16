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
            if (head_node == nullptr) return;

            Node* current_node = head_node;
            Node* previous_node = nullptr;
            while (current_node != nullptr)
            {
                previous_node = current_node;
                current_node = current_node->next;
                previous_node->next = nullptr;
                static_cast<DoubleNode*>(current_node)->previous = nullptr;
                delete previous_node;
            }
        }

        void DoubleLinkedList::removeNodeAtHead()
        {
            if (head_node == nullptr) return;

            linked_list_size--;
            Node* current_node = head_node;

            if (head_node->next != nullptr)
            {
                head_node = head_node->next;
                static_cast<DoubleNode*>(head_node)->previous = nullptr;
            }

            current_node->next = nullptr;
            delete current_node;
        }

        void DoubleLinkedList::removeNodeAtMiddle()
        {
            if (head_node == nullptr) return;

            int index = findMiddleNode();

            removeNodeAtIndex(index);
        }

        void DoubleLinkedList::removeNodeAtTail()
        {
            if (head_node == nullptr) return;
            linked_list_size--;

            Node* current_node = head_node;

            if (current_node->next = nullptr)
            {
                removeNodeAtHead();
                return;
            }

            while (current_node->next != nullptr)
            {
                current_node = current_node->next;
            }

            Node* previous_node = static_cast<DoubleNode*>(current_node)->previous;

            previous_node->next = nullptr;

            delete current_node;

        }

        void DoubleLinkedList::removeNodeAt(int index)
        {
            removeNodeAtIndex(index);
        }

        void DoubleLinkedList::removeNodeAtIndex(int index)
        {
            if (index < 0 && index >= linked_list_size) return;
            linked_list_size--;
            int current_index = 0;
            Node* current_node = head_node;

            while (current_node != nullptr && current_index<index)
            {
                current_node = current_node->next;
                current_index++;
            }

            Node* previous_node = static_cast<DoubleNode*>(current_node)->previous;
            Node* next_node = current_node->next;
            
            shiftNodesAfterRemoval(current_node);
            
            previous_node->next = next_node;
            static_cast<DoubleNode*>(next_node)->previous = previous_node;
            current_node->next = nullptr;
            static_cast<DoubleNode*>(current_node)->previous = nullptr;

            delete current_node;
        }


        void DoubleLinkedList::removeHalfNodes()
        {
        }

        void DoubleLinkedList::shiftNodesAfterRemoval(Node* cur_node)
        {
            if (cur_node == nullptr) return;

            Node* previous_node = cur_node;
            cur_node = cur_node->next;

            Vector2i previous_position = previous_node->body_part.getPosition();
            Direction previous_direction = previous_node->body_part.getDirection();

            Vector2i temp_position;
            Direction temp_direction;

            while (cur_node != nullptr)
            {
                temp_position = cur_node->body_part.getPosition();
                temp_direction = cur_node->body_part.getDirection();

                cur_node->body_part.setPosition(previous_position);
                cur_node->body_part.setDirection(previous_direction);

                cur_node = cur_node->next;

                previous_position = temp_position;
                previous_direction = temp_direction;
            }
        }

        Direction DoubleLinkedList::reverse()
        {
            return Direction();
        }
    }
}