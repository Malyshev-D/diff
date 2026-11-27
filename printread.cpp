#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "treeop.h"
#include "printread.h"

Node_t* PreOrderRead(const char* name, Tree_t* tree)
{
    FILE* file = fopen(name, "r");
    if (file == 0)
    {
        printf("Error: file is equal NULL in file: %s in line %d", __FILE__, __LINE__);
        return NULL;
    }

    Node_t* root_node = ReadNode(file, tree);

    fclose(file);
    return root_node;
}

Node_t* ReadNode(FILE* file, Tree_t* tree)
{
    getc(file);
    char string[100] = {};
    ungetc(ReadString(file, string), file);

    if (strcmp(string, "nil") != 0)
    {
        for (int idx = 0; idx < (int)(sizeof(opcode)/sizeof(opcode[0])); idx++)
        {
            if (strcmp(string, opcode[idx]) == 0)
            {
                Node_t* node = NewNode(OP, (value_un){.op = (enum op_idx) idx}, NULL, NULL, tree);
                StartRecursion(file, node, tree);
                return node;
            }
        }
        if (strcmp(string, "x") == 0)
        {
            Node_t* node = NewNode(VAR, (value_un){.var = 0}, NULL, NULL, tree);
            StartRecursion(file, node, tree);
            return node;
        }
        Node_t* node = NewNode(NUM, (value_un){.num = atof(string)}, NULL, NULL, tree);
        StartRecursion(file, node, tree);
        return node;
    }
    else
    {
        ReadNil(file);
        return NULL;
    }
}

void ReadNil(FILE* file)
{
    char sym = getc(file);
    while (sym != ')')
        sym = getc(file);
}

char ReadString(FILE* file, char* string)
{
    char sym = getc(file);
    for (int idx = 0; sym != ')' && sym != '('; idx++)
    {
        string[idx] = sym;
        sym = getc(file);
    }
    return sym;
}

void StartRecursion(FILE* file, Node_t* node, Tree_t* tree)
{
    node->left = ReadNode(file, tree);
    node->right = ReadNode(file, tree);
    getc(file);
}

void PreOrderPrint(FILE* file, Node_t* node)
{
    fprintf(file, "(");
    switch (node->type)
    {
        case OP:
            fprintf(file, "%s", opcode[node->value.op]);
            break;
        case NUM:
            fprintf(file, "%lg", node->value.num);
            break;
        case VAR:
            fprintf(file, "x");
    }

    if (node->left)
        PreOrderPrint(file, node->left);
    else
        fprintf(file, "(nil)");

    if (node->right)
        PreOrderPrint(file, node->right);
    else
        fprintf(file, "(nil)");

    fprintf(file, ")");
}
