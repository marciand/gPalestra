#include "ext_string.h"
#include "str_tree.h"

str_node *dic_new (){
    return NULL;
}

WORD *dic_add (str_node **node, char str[]){
    str_node	**wrd_cur;
    int     	r;

    wrd_cur = node;

    while (1){
        if (!(*wrd_cur))
            break;

        r = strcmp(str, (*wrd_cur)->str);

        if (r==0)
            return (*wrd_cur);

        if (r>0)
            wrd_cur = &( (*wrd_cur)->right );
        else
            wrd_cur = &( (*wrd_cur)->left );

    }

    *wrd_cur = (WORD *) malloc (sizeof (WORD));

    (*wrd_cur)->str = str;
    (*wrd_cur)->pos = pos;

    (*wrd_cur)->left = NULL;
    (*wrd_cur)->right = NULL;

    if (!node)
        *node = *wrd_cur;

    return (*wrd_cur);
}

void dic_destroy (str_node *node){
    if (!node)
        return;

    dic_destroy(node->left);
    dic_destroy(node->right);

    free(node);
}

int dic_empty (str_node *node){
    return (!node);
}

str_node *dic_find (str_node *node, char str[]){
    int r;
    if (!node)
        return NULL;

    r = strcmp(str, node->str);

    if (!r)
        return node;

    if (r>0)
        return dic_find(node->right, str);
    else
        return dic_find(node->left, str);
}
