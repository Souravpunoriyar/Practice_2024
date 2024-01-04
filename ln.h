#include<stdio.h>

/*Declaring linklist structure>>>>>>>>>
The typedef keyword is unnecessary for C struct types. The only advantage it gives you is that it creates a one-word name for the type.

The declaration in your example:
struct demo
{
   ...
} synth;
is actually two declarations, one for the type struct demo, and one for an object of that type named synth. It is perhaps more clearly written as two separate declarations:

struct demo
{
    ...
};

struct demo synth;
The first declaration creates a new structure type. Its name is struct demo. The second defines an object of that type, named synth.

The identifier demo by itself, given these declarations, is meaningless; it's a struct tag, and it's meaningful only when preceded by the struct keyword.

synth, on the other hand, is the name of an object (variable). It does not need to be, and in fact cannot be, preceded by the struct keyword.

You can, if you prefer, add a typedef to give the type struct demo a second name. (A typedef does not define a new type; it merely defines a new name, an alias, for an existing type.) For example, a common idiom is:

typedef struct demo {
    ...
} demo;
Like your original declaration, this is really two declarations, a struct definition that creates the type struct demo, and a typedef that creates a new name demo for that type. It could be written as:

struct demo {
    ...
};
typedef struct demo demo;
followed, if you like, by an object declaration:
demo synth;

*/

struct llnode {
    int num;
    int data[10];
    struct llnode *next;
};
typedef struct llnode ln;

enum ln_return {
    ERR_SUCCESS = 0,
    ERR_FAILURE  = 1,
    ERR_EMPTY = 2,
};

typedef enum ln_return LLRet;




