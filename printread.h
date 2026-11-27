#ifndef PRINTANDREAD
#define PRINTANDREAD

void    PreOrderPrint(FILE* file, Node_t* node);
Node_t* PreOrderRead(const char* name, Tree_t* tree);
Node_t* ReadNode(FILE* file, Tree_t* tree);

void    StartRecursion(FILE* file, Node_t* node, Tree_t* tree);
char    ReadString(FILE* file, char* string);
void    ReadNil(FILE* file);

#endif
