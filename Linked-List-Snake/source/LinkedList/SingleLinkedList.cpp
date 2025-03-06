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

    Node* SingleLinkedList::createNode()
    {
        return new Node();
    }

    Vector2i SingleLinkedList::getNewNodePosition(Node* reference)
    {
        Direction reference_direction = reference->body_part.getDirection();
        Vector2i reference_position = reference->body_part.getPosition();

        switch (reference_direction)
        {
        case Direction::UP:
            return Vector2i(reference_position.x,reference_position.y-1);

        case Direction::DOWN:
            return Vector2i(reference_position.x,reference_position.y+1);

        case Direction::LEFT:
            return Vector2i(reference_position.x+1,reference_position.y);

        case Direction::RIGHT:
            return Vector2i(reference_position.x-1,reference_position.y);

        
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
        new_node->body_part.initialize(node_width,node_height,getNewNodePosition(current_node),current_node->body_part.getDirection());
    }
}
