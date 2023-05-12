#include <stdio.h>
#include <stdlib.h>
#include "Single_LL.h"


int main(void)
{

    int no_of_elements,i,user_data,user_id;
    sll_node entry_data;
    sll_node *current_node;
    // int x = get_length_list();
    // printf("list size is... %d\n",x);
    while(1)
    {

        printf("Enter How many elements Needed in List!\n");
        scanf("%d",&no_of_elements);
        if(no_of_elements <= 0)
        {
            printf("Failed Process, You Entered -ve number\n");
            printf("Please, Enter a +ve integer number....\n");

        }
        else
        {
            break;
        }
    }
    printf("-------------------------------------------\n");
    while(i<no_of_elements)
    {
        printf("Enter Data of The Node!\n");
        scanf("%d",&user_data);
        printf("-------------------------------------------\n");
        printf("Enter ID of The Given Data!\n");
        scanf("%d",&user_id);
        printf("-------------------------------------------\n");
        entry_data.data = user_data;
        entry_data.id = user_id;
        current_node = create_SLL(entry_data);
        printf("User_data is %d with ID Of %d\n",current_node-> data,current_node -> id);
        printf("-------------------------------------------\n");
        i++;
    }
    display_sll();
    struct node something = {40,123};
    insert_node(something,3);
    display_sll();
    int x = get_length_list();
    printf("list size is... %d\n",x);
    // int y = delete_node(1);
    // int z = get_length_list();
    // printf("list size is... %d\n",z);
    i = 0;
    int id_some;
    while(i<3)
    {
        scanf("%d",&id_some);
        read_data_by_id(id_some);
        i++;
    }
    read_data_by_pos(3);
    printf("End Of Code.... :>");
    return 0;
}
