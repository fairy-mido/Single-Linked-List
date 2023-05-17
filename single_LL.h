#ifndef SINGLE_LL_H_
#define SINGLE_LL_H_

#define First_Node_Created      1

// Used Along The Code To trace whether a feature working or not
#define Success                 1
#define Fail                    0

// Used in Read & Chnage Functions
#define Choice_Change           1     
#define Choice_Read             2

// Definitions of User Choice
#define Choice_Create_SLL           1
#define Choice_Insert_Node          2
#define Choice_Delete_Node          3
#define Choice_Search_4_Data        4
#define Choice_Read_Data_By_ID      5
#define Choice_Read_Data_By_pos     6
#define Choice_Change_Data_By_ID    7
#define Choice_Change_Data_By_pos   8 
#define Choice_Get_List_Length      9
#define Choice_Dislpay_List         10
#define Exit_Code_Choice            11


#define Choice_Change 1
#define Choice_Read   2

struct node *create_SLL(struct node data_user);
void display_sll();
int insert_node();
int delete_node();
int search_4_data();
void read_or_change_data_by_id(int choice);
void read_or_change_data_by_pos(int choice);
int get_length_list();
int entry_number_of_elements();
int User_Choice(int choice);

typedef struct node{
    int data;
    int id;
    struct node* next;
}sll_node;


#endif // SINGLE_LL_H_INCLUDED
