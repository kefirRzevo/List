#include "../include/list.h"


CList::CList()
{
    assert(this);

    size_= 0;
    head_ = nullptr;
    tail_ = nullptr;
}


static void free_node(Node* p_node)
{
    while(p_node != nullptr)
    {
        Node* new_node = p_node;
        p_node = p_node->next;
        free(new_node);
    }
}


CList:: ~CList()
{
    assert(this);   

    free_node(this->tail_);

    size_ = 0;
    tail_ = nullptr;
    head_ = nullptr;
}


void CList::InsertTail(const item_t item)
{
    assert(this);

    Node* elem = (Node* ) calloc(1, sizeof(Node));
    assert(elem);

    elem->prev = nullptr;
    elem->next = this->tail_;
    elem->data = item;

    if(this->tail_ != nullptr)
    {
        this->tail_->prev = elem;
    }
    else
    {
        this->head_ = elem; 
    }

    this->tail_ = elem;
    this->size_++;
}


void CList::InsertHead(const item_t item)
{
    assert(this);

    Node* elem = (Node* ) calloc(1, sizeof(Node));
    assert(elem);

    elem->prev = this->head_;
    elem->next = nullptr;
    elem->data = item;

    if(this->head_ != nullptr)
    {
        this->head_->next = elem;
    }
    else
    {
        this->tail_ = elem; 
    }

    this->head_ = elem;
    this->size_++;
}


item_t  CList::DeleteTail() 
{
    assert(this);

    if(this->size_ == 0)
    {
        printf("List is empty. Be careful.\n");
        return 0;
    }

    Node*  elem      = this->tail_;
    item_t elem_data = this->tail_->data;

    if(this->tail_->next != nullptr)
    {
        this->tail_->next->prev = nullptr;
        this->tail_ = this->tail_->next;
    }
    else
    {
        this->head_ = nullptr;
        this->tail_ = nullptr;
    }

    free(elem);
    this->size_--;
    return elem_data;
}


item_t  CList::DeleteHead() 
{
    assert(this);

    if(this->size_ == 0)
    {
        printf("List is empty. Be careful.\n");
        return 0;
    }

    Node*  elem      = this->head_;
    item_t elem_data = this->head_->data;

    if(this->head_->prev != nullptr)
    {
        this->head_->prev->next = nullptr;
        this->head_ = this->head_->prev;
    }
    else
    {
        this->head_ = nullptr;
        this->tail_ = nullptr;
    }

    free(elem);
    this->size_--;
    return elem_data;
}
