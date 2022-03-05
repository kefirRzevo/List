#include "../include/list.h"
#include "../include/dot.h"


static size_t N_NODES = 1;


FILE* open_dot_txt(const char* const dot_path)
{
    assert(dot_path);

    FILE* dotfile   = nullptr;
    dotfile         = fopen(dot_path, "w");
    
    fprintf(dotfile,    "digraph G \n{\n"
                        "\tgraph[rankdir = LR]\n"
                        "\tnode[shape = box, fontsize = 8]\n\n");
    return dotfile;
}


void close_dot_txt(FILE* const dotfile)
{
    assert(dotfile);

    fprintf(dotfile, "}");
    fclose(dotfile);
}


static void print_node(Node* node, FILE* const dotfile)
{
    while(node != nullptr)
    {
        fprintf(dotfile,    "\tsubgraph cluster%zi\n\t{\n"
                            "\t\tmargin = 0\n"
                            "\t\tlabel  = %zu\n"
                            "\t\tNode%p[shape = record, label = \"item: %" SPECIFICATOR " | <n>next: %p | <p>prev: %p\"]\n"
                            "\t}\n", N_NODES, N_NODES, node, node->data, node->next, node->prev);
        if(node->next != nullptr)
        {
            fprintf(dotfile,    "\t\tNode%p:n -> Node%p:n[color = \"red\"]\n\n", node, node->next);
        }
        node = node->next;
        N_NODES++;
    }
}


void CList::print_nodes(FILE* const dotfile)
{
    assert(dotfile);
    assert(this);

    print_node(this->tail_, dotfile);
    fprintf(dotfile, "\n");
}