#include "../ll/ln.h"

static int data = 0;
void init_ll(ln *node)
{
  printf("[%s] data[%d ] \r\n", __FUNCTION__, data);
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

LLRet InsertCLatStart( ln **head, ln * new_node) {
  if(*head == NULL){
    *head = new_node;
    (*head)->next = *head;
    return ERR_SUCCESS;
  }
  ln *curr = *head;
  while(curr->next != *head) {
    curr = curr->next;
  }
  curr->next = new_node;
  /*insert at begining*/
  new_node->next = *head;
  *head = new_node;

}

LLRet InsertCLatEnd( ln **head, ln * new_node) {
  if(*head == NULL){
    *head = new_node;
    (*head)->next = *head;
    return ERR_SUCCESS;
  }
  ln *curr = *head;
  while(curr->next != *head) {
    curr = curr->next;
  }
  curr->next = new_node;
  /*insert at begining*/
  new_node->next = *head;

}

void print_cl(ln *node) {
    //DEBUG_LOG;
    if(NULL == node){
        printf("empty list err[%d] \r\n", ERR_EMPTY);
    }
    ln *head = node;
    printf("head [%d] [%d]\n", head->num, head->next->num);  
    while(node->next != head) {
        printf("printing CL");
        printf("node_num : [%d] \r\n",node->num);
        node = node->next;
    }
}

int main()
{
    LLRet ret = ERR_FAILURE;
    printf("Link List start \r\n");
    ln *head = NULL;
    ln *new_node = NULL;
    ret = alloca_init_node(&new_node);
    InsertCLatStart(&head, new_node);
    new_node = NULL;
    ret = alloca_init_node(&new_node);
    InsertCLatStart(&head, new_node);    
    new_node = NULL;
    ret = alloca_init_node(&new_node);
    InsertCLatStart(&head, new_node);    
    

    print_cl(head);

}
