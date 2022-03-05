#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "include/list.h"

/*
gcc -g -Wextra -Wall -Wpedantic -fsanitize=address -c main.cpp src/list.cpp src/dot.cpp src/dump.cpp
gcc -g -Wextra -Wall -Wpedantic -fsanitize=address -o a main.o list.o dot.o dump.o
*/

int main()
{
    CList lst;
    lst.InsertTail(10);
    lst.InsertHead(20);
    lst.InsertTail(13);
    lst.Dump();
    return 0;
}