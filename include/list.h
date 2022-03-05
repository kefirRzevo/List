#ifndef LIST_H
#define LIST_H


#include <stdio.h>
#include <stdlib.h>
#include <cstddef>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <iostream>


typedef int item_t;
#define SPECIFICATOR "d"


struct Node
{
        item_t  data;
        Node*   next;
        Node*   prev;
};


class CList
{
    private:
        Node*   head_;
        Node*   tail_;
        size_t  size_;
    void print_nodes(FILE* const dotfile);
    void make_one_dump(char* img_path);

    public:
        explicit    CList();
                   ~CList();
            void    InsertTail(const item_t item);    
            void    InsertHead(const item_t item); 
            item_t  DeleteTail(); 
            item_t  DeleteHead(); 
            void    Dump();
};


#endif