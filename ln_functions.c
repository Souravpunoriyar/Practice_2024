#include "ln.h"

/*insert an element in front linklist*/

LLRet InsertNodeAtStart(ln **head, ln *new_node){
    LL_GUARD((NULL == new_node ||
             NULL == *head), ERR_FAILURE, "begi_add_fail");
    new_node->next = *head;
    *head = new_node;
    return ERR_SUCCESS;
} 

/*insert an element at end of linklist*/

LLRet InsertNodeAtEnd(ln *head, ln *new_node){
    LL_GUARD((NULL == new_node ||
             NULL == head), ERR_FAILURE, "end_add_fail");
    /*traverse till last node*/
    ln *temp_node = head;
    while(temp_node->next != NULL){
        DEBUG_LOG;
        temp_node = temp_node->next;
    }   
    temp_node->next = new_node;
    return ERR_SUCCESS;
} 