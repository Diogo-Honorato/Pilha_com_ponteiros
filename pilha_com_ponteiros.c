#include<stdio.h>
#include<stdlib.h>

typedef struct Cell
{
    int key;
    struct Cell *next;
}Cell;

typedef struct
{
    Cell *top;
    int size;
}Stack;

Stack *AllocoteStack()
{
    return (Stack*)malloc(sizeof(Stack));
}

void StartStack(Stack *cell)
{
    cell->top=NULL;
    cell->size = 0;
}

int InsertStack(Stack *cell,int key)
{
    Cell *newcell = (Cell*)malloc(sizeof(Cell));
    newcell->key = key;
    newcell->next= NULL;
    
    if(cell->top == NULL)
    {
        cell->top = newcell;
    }
    else
    {
       newcell->next = cell->top;
    }
    cell->top = newcell;
    cell->size++;
    printf("\n\nStacked item: %d\n\n",key);
}

int RemoveStack(Stack *cell)
{
    if(cell->size == 0)
    {
        printf("\n\nEmpty stack!\n\n");
        exit(0);
    }

    Cell *aux = cell->top;
    cell->top = cell->top->next;
    printf("\nItem removed: %d\n",aux->key);
    free(aux);
}

int PrintStack(Stack *cell)
{
    if(cell->size == 0)
    {
        printf("\n\nEmpty stack!\n\n");
        exit(0);
    }
    printf("\n\n");
    Cell *aux = cell->top;
    
    while(aux != NULL)
    {
        printf("(%d)\n",aux->key);
        aux = aux->next;
    }
}


int main()
{
    Stack *cell = AllocoteStack();
    
    StartStack(cell);
    
    InsertStack(cell,4);
    InsertStack(cell,56);
    InsertStack(cell,100);
    InsertStack(cell,30);
    PrintStack(cell);
    RemoveStack(cell);
    PrintStack(cell);
}    