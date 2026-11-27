#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "treeop.h"

const char* opcode[] = {
    "+",
    "-",
    "*",
    "/"
};

Node_t* NewNode(enum type_value type, union value_un value, Node_t* left, Node_t* right, Tree_t* tree)
{
    Node_t* node = (Node_t*)calloc(1, sizeof(Node_t));
    if (node == NULL) {
        printf("CALLOC RETURNED NULL IN %s %s:%d\n", __FILE__, __FUNCTION__, __LINE__);
        return NULL;
    }
    (tree->node_count)++;
    node->index = tree->node_count;
    node->type = type;
    switch (type)
    {
        case OP:
            node->value.op = value.op;
            break;
        case VAR:
            node->value.var = value.var;
            break;
        case NUM:
            node->value.num = value.num;
            break;
    }
    node->left = left;
    node->right = right;
    return node;
}
