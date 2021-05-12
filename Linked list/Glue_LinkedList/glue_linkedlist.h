#ifndef GLUE_LL_H
#define GLUE_LL_H

#define OFFSET(struct_name, field_name)                                        \
        ( (size_t)(&(((struct_name *)0)->field_name)) )

/*Iterative macro to Iterate Over List*/
#define ITERATE_LIST_BEGIN(lstptr, struct_type, ptr)                           \
{                                                                              \
    Glue_t *_glnode = NULL, *_next = NULL;                                     \
    unsigned int cnt = (lstptr)->Count;                                        \
    for(_glnode = (lstptr)->Head; cnt > 0; _glnode = _next){                   \
        _next = _glnode->Right;                                                \
        cnt--;                                                                 \
        ptr = (struct_type *)((char *)_glnode - (lstptr)->Offset);
#define ITERATE_LIST_END                                                      }}

typedef struct glue{
  struct glue *Left;
  struct glue *Right;
}Glue_t; 

typedef struct list{
  Glue_t       *Head;
  unsigned int Count;
  unsigned int Offset;
}List_t;

void List_Init(List_t *list, unsigned int offset);
void List_Add(List_t *list, Glue_t *glnode);
void List_Remove(List_t *list, Glue_t *glnode);

#endif /* GLUE_LL_H */