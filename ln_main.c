#include "ln.h"

static int data = 0;
void init_ll(ln *node)
{
  (node)->num = data;
  (node)->next = NULL;
  data++;

}

LLRet alloca_init_node(ln **node) {
    LL_GUARD(*node != NULL, ERR_FAILURE, "Not null check");
    *node = calloc(sizeof(ln), 1);
    LL_GUARD(*node == NULL, ERR_FAILURE, "alloc_fail");
    init_ll(*node);
    return ERR_SUCCESS;
}


int main()
{
    LLRet ret = ERR_FAILURE;
    printf("Link List start \r\n");
    ln *head = NULL;
    ln *node1 = NULL;
    ln *node2 = NULL;
    ret = alloca_init_node(&head);
    LL_GUARD(ret != ERR_SUCCESS, ERR_FAILURE, "main_fail");
    ret = alloca_init_node(&node1);
    LL_GUARD(ret != ERR_SUCCESS, ERR_FAILURE, "main_fail");
    ret = alloca_init_node(&node2);
    LL_GUARD(ret != ERR_SUCCESS, ERR_FAILURE, "main_fail");
    InsertNodeAtEnd(head, node1);
    InsertNodeAtEnd(head, node2);

    print_ln(head);

}