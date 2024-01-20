#include "hashmap.h"

hashmap *create_entry(int data, int key) {
    hashmap *new_node =  (hashmap *) calloc(1, sizeof(hashmap));
    new_node->data = data;
    new_node->key = key;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}


hm_err insert_entry(hashmap **head, hashmap *new_node) {
    GUARD(new_node == NULL, ERR_FAIL);
    if(*head == NULL) {
        *head = new_node;
        return ERR_SUCCESS;
    }

#ifdef AT_BEGIN
    entry->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
#else
    hashmap *curr = *head;
    while(curr->next != NULL) {
        curr=curr->next;
    }
    curr->next = new_node;
    new_node->prev= curr;
    return ERR_SUCCESS;

#endif
}

hm_err delete_entry(hashmap **head, int key) {
    GUARD(*head == NULL, ERR_FAIL);
    hashmap *curr = *head;
    if(curr->key == key) {
        free(head);
        head = NULL;
    }
    
    while(curr->key != key && curr->next != NULL) {
        curr = curr->next;
    }

    if(curr) {
        if(curr->next == NULL) {
            curr->prev->next = NULL;
            free(curr);
        }
        else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            free(curr);
        }
    
    } else {
        PRINT_LOG("NOT Found");
    }    

}


hm_err print_map(hashmap *head) {
    GUARD(head == NULL, ERR_FAIL);
    hashmap *curr = head;
    printf("[%s] \r\n", __FUNCTION__);
    while(curr != NULL) {
        printf("[%d] [%d] \r\n", curr->key, curr->data);
        curr = curr->next;
    }
}

hm_err understand(hashmap *head){
    GUARD(head == NULL, ERR_FAIL);
    PRINT_LOG("WRONG \r\n");
}


int main() {
    hashmap *head = NULL;
    hashmap *new_node = NULL;
    understand(head);
    new_node = create_entry(1,1);
    insert_entry(&head,new_node);
    new_node = create_entry(2,2);
    insert_entry(&head,new_node);
    new_node = create_entry(3,3);
    insert_entry(&head,new_node);

    delete_entry(&head,2);
    print_map(head);

}