#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// DONE: понять как устроены узлы
// DONE: NewNode
// DONE: DSL
// DONE: Читалка (хотя бы преордер)
// TODO: несколько простейших деревьев => графика + ТеХ

#include "struct.h"
#include "graphics.h"
#include "treeop.h"
#include "printread.h"

//DSL!!
// #define _ADD(left, right) NewNode(OP, (union value_un){.op = ADD}, left, right, &(tree.node_count))
// #define _SUB(left, right) NewNode(OP, (union value_un){.op = SUB}, left, right, &(tree.node_count))
// #define _MUL(left, right) NewNode(OP, (union value_un){.op = MUL}, left, right, &(tree.node_count))
// #define _DIV(left, right) NewNode(OP, (union value_un){.op = DIV}, left, right, &(tree.node_count))
//
// #define _NUM(value)       NewNode(NUM, (union value_un){.num = value}, NULL, NULL, &(tree.node_count))
// #define _VAR(value)       NewNode(VAR, (union value_un){.var = value}, NULL, NULL, &(tree.node_count))

int main()
{
    Tree_t tree = {};

    tree.root_node = PreOrderRead("print.txt", &tree);
    FILE* file = DumpBegin();
    TreeDump(file, *(tree.root_node));
    DumpEnd(file);
}
