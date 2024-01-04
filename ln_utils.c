#include "ln.h"


void print_ln(ln *node ) {
    if(NULL == node){
        printf("empty list err[%d] \r\n", ERR_EMPTY);
    }
    while(node != NULL) {
        printf("node_num : [%d] \r\n",node->num);
        node = node->next;
    }
}



