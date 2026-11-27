#ifndef STRUCTUREANDENUM
#define STRUCTUREANDENUM

enum type_value {
    OP,
    VAR,
    NUM,
};

enum op_idx {
    ADD,
    SUB,
    MUL,
    DIV,
};
extern const char* opcode[];
union value_un {
    enum op_idx op;
    int         var;
    double      num;
};

struct Node_t {
    enum type_value type;
    value_un value; //TODO: UNION
    Node_t* left;
    Node_t* right;
    int index;
};

struct Tree_t {
    Node_t* root_node;
    int node_count;
};

#endif
