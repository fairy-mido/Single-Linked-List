#ifndef SINGLE_LL_H_INCLUDED
#define SINGLE_LL_H_INCLUDED

#define First_Node_Created 1

#define Success 1
#define Fail    0

struct node *create_SLL(struct node data_user);
void display_sll();
int insert_node(struct node data_user,int pos);
int delete_node(int pos);
int search_4_data(int entry_id);
void read_data_by_id(int id);
void read_data_by_pos(int pos);
int get_length_list();

typedef struct node{
    int data;
    int id;
    struct node* next;
}sll_node;


#endif // SINGLE_LL_H_INCLUDED
