// #include "TXLib.h"
#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "graphics.h"

const char html_code[] = "meow.html";
const char graph_code[] = "meow.txt";

// начало дампа = открытие html файла
FILE* DumpBegin()
{
    FILE* file = fopen(html_code, "w");
    fprintf(file, "<!DOCTYPE html>\n"
        "<head>\n"
        "\t<title>List Dump</title>\n"
        "\t<link rel=\"stylesheet\" href=\"style.css\">\n"
        "</head>\n"
    );
    return file;
}

// закрытие файла
void DumpEnd(FILE* file)
{
    fprintf(file,
    "</body>\n"
    "</html>\n");
    fclose(file);
    system("start meow.html");
}

// дамп дерева
void TreeDump(FILE* file, Node_t node)
{
    DrawGraph(node);
    // snprintf() - создаем форматированную строку и вставляем в system
    char command[150] = {};
    snprintf(command, sizeof(command), "dot -Tpng meow.txt -o meow.png");
    system(command);
    CreateHtml(file);
}

// рисуем граф
void DrawGraph(Node_t node)
{
    FILE* g_file = fopen(graph_code, "w");
    fprintf(g_file, "digraph G {\n");
    fprintf(g_file, "bgcolor=\"#0a0b17\";\n");
    fprintf(g_file, "node[fontsize=14, color=\"#8bf3ff\","
        "style=\"filled\", fillcolor=\"#060844\","
        "fontname=\"Arial\", fontcolor=\"#8bf3ff\"];\n"
        "edge [style=solid, color=\"#24ffed\"];\n");

    DrawNode(g_file, node);

    fprintf(g_file, "}");
    fclose(g_file);
}

// рисуем узел, используем рекурсию
void DrawNode(FILE* file, Node_t node)
{
    if (node.type == OP)
        fprintf(file, "\"%d\"[shape=ellipse, fontsize=20, label=\"%s\"];\n",
        node.index, opcode[node.value.op]);
    if (node.type == NUM)
        fprintf(file, "\"%d\"[shape=square, label=\"%.3lg\"];\n",
        node.index, node.value.num);
    if (node.type == VAR)
        fprintf(file, "\"%d\"[shape=triangle, label=\"X\"];\n",   //|{left = %zu|right = %zu}
        node.index);

    if (node.left != NULL)
    {
        DrawNode(file, *node.left);
        fprintf(file, "\"%d\"->\"%d\";\n", node.index, node.left->index);
    }
    if (node.right != NULL)
    {
        DrawNode(file, *node.right);
        fprintf(file, "\"%d\"->\"%d\";\n", node.index, node.right->index);
    }
}

// создание html файла
void CreateHtml(FILE* file)
{
    fprintf(file,
        "<!DOCTYPE html>\n"
        "<head>\n"
        "\t<title>Tree dump</title>\n"
        "\t<link rel=\"stylesheet\" href=\"style.css\">\n"
        "</head>\n"
        "\t<img src=\"meow.png\" alt=\"Graph\" width=\"480\">\n");
}
