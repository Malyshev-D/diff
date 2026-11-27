#include "struct.h"
#ifndef GRAPHICSDRAWTREE
#define GRAPHICSDRAWTREE

FILE* DumpBegin ();
void TreeDump(FILE* file, Node_t node);
void  CreateHtml(FILE*  file);
void  DrawGraph (Node_t node);
void  DrawNode  (FILE*  file, Node_t  node);
void  DumpEnd   (FILE*  file);

#endif
