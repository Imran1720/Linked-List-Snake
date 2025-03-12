#include "../../include/LinkedList/SingleLinkedList.h"

namespace LinkedList
{
    
    SingleLinkedList::SingleLinkedList()
    {
        head_node = nullptr;
    }

    SingleLinkedList::~SingleLinkedList() = default;

    void SingleLinkedList::initialize(float width, float height, Vector2i position, Direction direction)
    {
        node_width = width;
        node_height = height;
        default_position = position;
        default_direction = direction;
        linked_list_size = 0;
    }
    void SingleLinkedList::render()
    {
        Node* current_node = head_node;

        while (current_node->next != nullptr)
        {
            current_node->body_part.render();
            current_node = current_node->next;
        }
    }

    void SingleLinkedList::initializeNode(Node* new_node, Node* reference_node, Operation operation)
    {
        if (reference_node == nullptr)
        {
            new_node->body_part.initialize(node_width, node_height, default_position, default_direction);
            return;
        }

        Vector2i new_position = getNewNodePosition(reference_node, operation);

        new_node->body_part.initialize(node_width,node_height,new_position,reference_node->body_part.getDirection());
    }

    Node* SingleLinkedList::createNode()
    {
        return new Node();
    }

    Vector2i SingleLinkedList::getNewNodePosition(Node* reference,Operation operation)
    {
       /* Direction reference_direction = reference->body_part.getDirection();
        Vector2i reference_position = reference->body_part.getPosition();

        switch (reference_direction)
        {
        case Direction::UP:
            return Vector2i(reference_position.x,reference_position.y+1);

        case Direction::DOWN:
            return Vector2i(reference_position.x,reference_position.y-1);

        case Direction::LEFT:
            return Vector2i(reference_position.x+1,reference_position.y);

        case Direction::RIGHT:
            return Vector2i(reference_position.x-1,reference_position.y);

        
        }*/

        switch (operation)
        {
        case LinkedList::Operation::HEAD:
            reference->body_part.getNextPosition();
            break;
        case LinkedList::Operation::TAIL:
            reference->body_part.getPreviousPosition();
            break;
       
        }

        return default_position;
    }

    void SingleLinkedList::insertNodeAtTail()
    {
        Node* new_node = createNode();
        Node* current_node = head_node;

        if (current_node == nullptr)
        {
            head_node = new_node;
            new_node->body_part.initialize(node_width, node_height, default_position, default_direction);
            return;
        }

        while (current_node->next != nullptr)
        {
            current_node = current_node->next;
        }

        current_node->next = new_node;
        new_node->body_part.initialize(node_width,node_height,getNewNodePosition(current_node,Operation::TAIL),current_node->body_part.getDirection());
    }

    void SingleLinkedList::insertNodeAtHead()
    {
        linked_list_size++;
        Node* new_node = createNode();
        Node* reference_node = head_node;

        if (reference_node == nullptr)
        {
           initializeNode(new_node,reference_node,Operation::HEAD);
            head_node = new_node;
            return;
        }

        initializeNode(new_node, reference_node, Operation::HEAD);
        new_node->next = head_node;
        head_node = new_node;
    }

    void SingleLinkedList::updateNodeDirection(Direction direction_to_set)
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

    void SingleLinkedList::updateNodePosition()
    {
        Node* current_node = head_node;

        while (current_node!=nullptr)
        {

            current_node->body_part.setPosition(current_node->body_part.getNextPosition());//to be added
            current_node->body_part.updatePosition();
            current_node = current_node->next;
        }
    }

    bool SingleLinkedList::processNodeCollision()
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
        Node* current_node = head_node;
        head_node = head_node->next;
        current_node->next = nullptr;
        delete(current_node);
    }

    vector<Vector2i> SingleLinkedList::getNodePositionList()
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

    Node* SingleLinkedList::getHead()
    {
        return head_node;
    }



}
