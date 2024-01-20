#ifndef HASHMAP_H
#define HASHMAP_H

#include<stdio.h>
#include<stdlib.h>


struct hashmap_t {
    int data;
    int key;
    struct hashmap_t *next;
    struct hashmap_t *prev;
};

typedef struct hashmap_t hashmap;


#define GUARD(cond, err) \
    if((cond)) {\
        printf("err [%d] [%s] [%d]\r\n", (err), __FUNCTION__, __LINE__ );\
        return err;\
    }

enum hm_err_t {
    ERR_SUCCESS =0,
    ERR_FAIL =0,
};

typedef enum hm_err_t hm_err; 

#define PRINT_LOG(string) \
    printf("[%s] FUNC [%s] LINE[%s]\r\n", (string), __FUNCTION__, __LINE__);

#endif