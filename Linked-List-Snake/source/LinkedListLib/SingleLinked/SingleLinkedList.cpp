#include "../../include/LinkedListLib/SingleLinked/SingleLinkedList.h"

#include <iostream>
using namespace std;

namespace LinkedList
{
    SingleNode* SingleLinkedList::createNode()
    {
        return new SingleNode();
    }

    void SingleLinkedList::insertNodeAtTail()
    {
        linked_list_size++;
        SingleNode* new_node = createNode();
        SingleNode* current_node = head_node;

        if (current_node == nullptr)
        {
            head_node = new_node;
            initializeNode(new_node, current_node, Operation::TAIL);
            return;
        }

        while (current_node->next != nullptr)
        {
            current_node = current_node->next;
        }

        initializeNode(new_node, current_node, Operation::TAIL);
        current_node->next = new_node;

        current_linked_list_operation = LinkedListOperations::INSERT_AT_TAIL;
        current_time_complexity = TimeComplexity::N;
    }

    void SingleLinkedList::insertNodeAtHead()
    {
        linked_list_size++;
        SingleNode* new_node = createNode();
        SingleNode* reference_node = head_node;

        if (reference_node == nullptr)
        {
           initializeNode(new_node,reference_node,Operation::HEAD);
            head_node = new_node;
            return;
        }

        initializeNode(new_node, reference_node, Operation::HEAD);
        new_node->next = head_node;
        head_node = new_node;

        current_linked_list_operation = LinkedListOperations::INSERT_AT_HEAD;
        current_time_complexity = TimeComplexity::ONE;
    }

    void SingleLinkedList::insertNodeAtIndex(int index)
    {
        if (index < 0 || index>=linked_list_size) return;

        if(index==0)
        {
            insertNodeAtHead();
            return;
        }

        int current_index = 0;
        SingleNode* new_node = createNode();
        SingleNode* current_node = head_node;
        SingleNode* previous_node = nullptr;

        while (current_node != nullptr && current_index < index)
        {
            previous_node = current_node;
            current_node = current_node->next;
            current_index++;
        }


        previous_node->next = new_node;
        new_node->next = current_node;
        initializeNode(new_node,previous_node,Operation::TAIL);

        shiftNodeAfterInsertion(new_node, current_node, previous_node);
        linked_list_size++;

        current_linked_list_operation = LinkedListOperations::INSERT_AT_MID;
        current_time_complexity = TimeComplexity::N;
    }

    void SingleLinkedList::insertNodeAtMiddle()
    {
        SingleNode* new_node = createNode();
        SingleNode* current_node = head_node;

        if (current_node == nullptr)
        {
            insertNodeAtHead();
            return;
        }

        int middle_index = findMiddleIndex();
        insertNodeAtIndex(middle_index);
    }

    void SingleLinkedList::insertNodeAt(int index)
    {
        if (index < 0 && index >= linked_list_size)
        {
            return;
        }
        insertNodeAtIndex(index);
    }

    void SingleLinkedList::shiftNodeAfterInsertion(SingleNode* new_node, SingleNode* current_node, SingleNode* previous_node)
    {
        SingleNode* next_node = current_node;
        current_node = new_node;

        while (current_node!=nullptr && next_node!=nullptr)
        {
            current_node->body_part.setPosition(next_node->body_part.getPosition());
            current_node->body_part.setDirection(next_node->body_part.getDirection());

            previous_node = current_node;
            current_node = next_node;
            next_node = current_node->next;
        }

        initializeNode(current_node,previous_node,Operation::TAIL);
    }

    void SingleLinkedList::shiftNodesAfterRemoval(SingleNode* cur_node)
    {
        if (cur_node == nullptr)
            return;
        SingleNode* previous_node = cur_node;
        cur_node = cur_node->next;

        Vector2i previous_position;
        Direction previous_direction;

        Vector2i temp_position;
        Direction temp_direction;

        previous_position = previous_node->body_part.getPosition();
        previous_direction = previous_node->body_part.getDirection();

        while (cur_node != nullptr)
        {
            temp_position = cur_node->body_part.getPosition();
            temp_direction = cur_node->body_part.getDirection();

            cur_node->body_part.setPosition(previous_position);
            cur_node->body_part.setDirection(previous_direction);
            previous_node = cur_node;
            cur_node = cur_node->next;

            previous_direction = temp_direction;
            previous_position = temp_position;
        }
    }

    void SingleLinkedList::removeNodeAtIndex(int index)
    {
        int current_index = 0;
        SingleNode* current_node = head_node;
        SingleNode* previous_node = nullptr;

        while (current_node != nullptr && current_index <= index)
        {
            previous_node = current_node;
            current_node = current_node->next;
            current_index++;
        }
        
        previous_node->next = current_node->next;

        linked_list_size--;
        shiftNodesAfterRemoval(current_node);
        delete(current_node);
        current_linked_list_operation = LinkedListOperations::REMOVE_AT_MID;
        current_time_complexity = TimeComplexity::N;
    }

    void SingleLinkedList::removeNodeAt(int index)
    {
        if (index < 0 && index >= linked_list_size)
        {
            return;
        }
        removeNodeAtIndex(index);
    }

    void SingleLinkedList::removeNodeAtMiddle()
    {
        if (head_node == nullptr)
        {
            return;
        }

        int index = findMiddleIndex();

        removeNodeAtIndex(index);
    }

    void SingleLinkedList::removeNodeAtTail()
    {
        if (head_node == nullptr)
        {
            return;
        }
            linked_list_size--;

        if (head_node->next == nullptr)
        {
            removeNodeAtHead();
            return;
        }

        SingleNode* previous_node = nullptr;
        SingleNode* currentNode = head_node;

        while (currentNode != nullptr)
        {
            previous_node = currentNode;
            currentNode = currentNode->next;
        }

        previous_node->next = nullptr;
        delete(currentNode);

        current_linked_list_operation = LinkedListOperations::REMOVE_AT_TAIL;
        current_time_complexity = TimeComplexity::N;
    }

    void SingleLinkedList::removeHalfNodes()
    {
        if (linked_list_size <= 1) return;
        int half_length = linked_list_size / 2;
        int new_tail_index = half_length - 1;

        SingleNode* previous_node = findNodeAtIndex(new_tail_index);
        SingleNode* current_node = previous_node->next;
        previous_node->next = nullptr;

        while (current_node != nullptr)
        {
            SingleNode* node_to_delete = current_node;
            current_node = current_node->next;

            node_to_delete->next = nullptr;
            delete(node_to_delete);
            linked_list_size--;
        }

        current_linked_list_operation = LinkedListOperations::DELETE_HALF_LIST;
        current_time_complexity = TimeComplexity::N;
    }

    Direction SingleLinkedList::reverse()
    {
        SingleNode* current_node = head_node;
        SingleNode* previous_node = nullptr;
        SingleNode* next_node = nullptr;

        while (current_node != nullptr)
        {
            next_node = current_node->next;
            current_node->next = previous_node;
            reverseNodeDirection();
            previous_node = current_node;
            current_node = next_node;
        }

        head_node = previous_node;
        reverseNodeDirection();

        current_linked_list_operation = LinkedListOperations::REVERSE_LIST;
        current_time_complexity = TimeComplexity::N;

        return head_node->body_part.getDirection();
    }

  
   

    TimeComplexity SingleLinkedList::getCurrentTimeComplexity()
    {
        return current_time_complexity;
    }

    LinkedListOperations SingleLinkedList::getCurrentLinkedListOperation()
    {
        return current_linked_list_operation;
    }

    void SingleLinkedList::removeAllHeadNode()
    {
        if (head_node == nullptr) return;

        while (head_node!=nullptr)
        {
            removeNodeAtHead();
        }
        
    }

    void SingleLinkedList::removeNodeAtHead()
    {
        SingleNode* current_node = head_node;
        head_node = head_node->next;
        current_node->next = nullptr;
        delete(current_node);
        linked_list_size--;

        current_linked_list_operation = LinkedListOperations::REMOVE_AT_HEAD;
        current_time_complexity = TimeComplexity::ONE;
    }


 



}
