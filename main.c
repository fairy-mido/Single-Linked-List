#include <stdio.h>
#include <stdlib.h>
#include "Single_LL.h"

int main(void)
{

    int i, choice, exit_code;
    // sll_node *current_node,entry_data;
    // int yt = entry_number_of_elements();
    // display_sll();
    // read_or_change_data_by_id(9004,Choice_Read,100);
    // insert_node();
    // display_sll();
    // int x = get_length_list();
    // printf("list size is... %d\n",x);
    // printf("-------------------------------------------\n");
    // read_or_change_data_by_id(123,Choice_Change,1241);
    // // int y = delete_node(1);
    // // int z = get_length_list();
    // // printf("list size is... %d\n",z);
    // i = 0;
    // int id_some;
    // while(i<3)
    // {
    //     scanf("%d",&id_some);
    //     read_or_change_data_by_id(id_some,Choice_Read,0);
    //     i++;
    // }
    // // read_data_by_pos(3);
    // search_4_data(9000);
    // search_4_data(123);
    while (1)
    {
        printf("---------------------------------------------------------------------\n");
        printf("1- Create List   2- Insert Node    3- Delete Node 4- Search for Data\n");
        printf("---------------------------------------------------------------------\n");
        printf("5- Read Data by ID      6- Read Data By Pos     7- Change Data By ID\n");
        printf("---------------------------------------------------------------------\n");
        printf("8- Change Data By Pos   9- List Size       10- Display List Elements\n");
        printf("---------------------------------------------------------------------\n");
        printf("\t\t      11- Exit Whole Code\n");
        printf("---------------------------------------------------------------------\n");
        printf("Enter Number Preceeding the Operation you want to execute : ");
        while (1)
        {
            scanf("%d", &choice);
            printf("--------------------------------------------------\n");
            if ((choice > 11) || (choice < 0))
            {
                // Nothing
                printf("Please, Enter The Correct Choice!\n");
            }
            else
            {
                break;
                // Correct Choice
            }
        }
        exit_code = User_Choice(choice);
        if (exit_code == Exit_Code_Choice)
        {
            break;
        }
    }
    printf("End Of Code.... :>");
    return 0;
}
