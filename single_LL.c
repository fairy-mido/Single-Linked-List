#include <stdio.h>
#include <stdlib.h>
#include "Single_LL.h"

sll_node *head, *prev_node, *new_node, *current_node, *next_node, *tail; // NULL
char check_entry_pos = 1;

struct node *create_SLL(struct node data_user) // Creation Of Single Linked List
{

    if (head == NULL) // List is empty
    {
        new_node = (sll_node *)malloc(sizeof(sll_node));
        new_node->data = data_user.data;
        new_node->id = data_user.id;
        head = new_node;
        new_node->next = NULL;
        return new_node; // Returning Head Pointer Address
    }
    else
    {
        new_node = (sll_node *)malloc(sizeof(sll_node));
        new_node->data = data_user.data;
        new_node->id = data_user.id;
        prev_node = head;
        // Created a Node Successfully
        while (prev_node->next != NULL) // Transversing the list until the last node
        {
            prev_node = prev_node->next; // Incrementing the node to the another
        }
        prev_node->next = new_node; // Linked Previous Node with the current created :>
        return new_node;
    }
}

void display_sll() // Display All Elements of The list
{
    int i = 0;
    current_node = head;
    if (current_node != NULL)
    {
        while (current_node->next != NULL)
        {
            ++i;
            printf("Data of The %d Node is %d with ID Of %d\n", i, current_node->data, current_node->id);
            printf("--------------------------------------------------\n");
            current_node = current_node->next;
        }
        printf("Data of The %d Node is %d with ID Of %d\n", ++i, current_node->data, current_node->id);
        printf("--------------------------------------------------\n");
    }
    else
    {
        printf("List is Empty, There is nothing to display!\n");
        printf("--------------------------------------------------\n");
    }
}

int insert_node() // Insert any node at any specific required position
{
    sll_node data_user;
    int user_data, user_id, pos, i = 0, k, list_length, check_data_entered = 1;

    printf("Enter Position For Placing Data!\n");
    scanf("%d", &pos);
    printf("--------------------------------------------------\n");
    list_length = get_length_list();
    while (((pos - 1) > list_length) || (pos < 0))
    {
        if (pos < 0)
        {
            printf("Negative Positions are not permitted..\n");
            printf("Please, Enter a positive integer position\n");
            scanf("%d", &pos);
            printf("--------------------------------------------------\n");
        }
        else if (pos > list_length)
        {
            printf("The Position Entered exceedded the list length!\n");
            printf("Please, Enter a positive integer position\n");
            scanf("%d", &pos);
            printf("--------------------------------------------------\n");
        }
    }
    if ((head == NULL) && (pos == 1))
    {
        check_entry_pos = 1;
        printf("List is Already Empty..!\n");
        printf("-------------------------------------------\n");
        printf("Making a Node At Begining...\n");
        printf("--------------------------------------------------\n");
        printf("Enter Data of The Node!\n");
        scanf("%d", &user_data);
        printf("-------------------------------------------\n");
        printf("Enter ID of The Given Data!\n");
        scanf("%d", &user_id);
        printf("-------------------------------------------\n");
        // data_user.data = user_data;
        // data_user.id = user_id;

        new_node = (sll_node *)malloc(sizeof(sll_node));
        // new_node->data = data_user.data;
        // new_node->id = data_user.id;
        new_node->data = user_data;
        new_node->id = user_id;
        head = new_node;
        new_node->next = NULL;
        printf("Data %d and ID %d\n", new_node->data, new_node->id);
        printf("Node has successfully been added!\n");
        printf("--------------------------------------------------\n");
        return Success;
    }
    else if ((head == NULL) && (pos > 1))
    {
        printf("The Position Entered exceedded the list length!\n");
        printf("Please, Enter a positive integer position\n");
        printf("--------------------------------------------------\n");
        return Fail;
    }
    else
    {
        if (pos == (list_length + 1)) // Last Position Entry
        {
            printf("Maknig Node At End.....\n");
            printf("--------------------------------------------------\n");
            new_node = (sll_node *)malloc(sizeof(sll_node));
            printf("Enter Data of The Node!\n");
            scanf("%d", &user_data);
            printf("-------------------------------------------\n");
            printf("Enter ID of The Given Data!\n");
            scanf("%d", &user_id);
            printf("-------------------------------------------\n");
            new_node->data = user_data;
            new_node->id = user_id;
            new_node->next = NULL;
            current_node = head;
            while (current_node->next != NULL) // Transverse the list till the end pos :>
            {
                current_node = current_node->next; // Incrementing..
            }
            current_node->next = new_node;
            i = 0;
            while (i < 10)
            {
                i++;
            }
            printf("Data %d and ID %d\n", new_node->data, new_node->id);
            printf("--------------------------------------------------\n");
            printf("Node has successfully been added!\n");
            printf("--------------------------------------------------\n");
            return Success;
        }
        else if (pos == 1)
        {
            // Insertion At Begining
            printf("Maknig Node At Begining.....\n");
            printf("--------------------------------------------------\n");
            next_node = head;
            next_node = next_node->next;
            current_node = (sll_node *)malloc(sizeof(sll_node));
            printf("Enter Data of The Node!\n");
            scanf("%d", &user_data);
            printf("-------------------------------------------\n");
            printf("Enter ID of The Given Data!\n");
            scanf("%d", &user_id);
            printf("-------------------------------------------\n");
            current_node->data = user_data;
            current_node->id = user_id;
            current_node->next = next_node;
            head = current_node;
            printf("Node has successfully been added!\n");
            printf("--------------------------------------------------\n");
        }
        else
        {

            /* For Any Position Except Ending and Begining...
               We need two pointers.. One before the position needed and Second After the position Required
            */
            printf("Making a Node at Required Position...\n");
            printf("--------------------------------------------------\n");
            new_node = (sll_node *)malloc(sizeof(sll_node));
            printf("Enter Data of The Node!\n");
            scanf("%d", &user_data);
            printf("-------------------------------------------\n");
            printf("Enter ID of The Given Data!\n");
            scanf("%d", &user_id);
            printf("-------------------------------------------\n");
            new_node->data = user_data;
            new_node->id = user_id;
            new_node->next = NULL;
            prev_node = head;
            i = 1;
            while (i < pos - 1) // Transverse the list till the Required Position :>
            {
                prev_node = prev_node->next; // Incrementing..
                i++;
                // printf("increementing value is %d\n",i);
            }
            current_node = prev_node->next; // For the Node After Position
            // Linking the node inserted newly
            prev_node->next = new_node;
            new_node->next = current_node;
            printf("Node has successfully been added!\n");
            printf("--------------------------------------------------\n");
            return Success;
        }
    }
}

int delete_node()
{
    int list_length, i, pos;
    list_length = get_length_list();
    printf("Enter Position For Placing Data!\n");
    scanf("%d", &pos);
    printf("--------------------------------------------------\n");
    while ((pos > list_length) || (pos <= 0))
    {

        if (pos < 0)
        {
            printf("Negative Positions are not permitted..\n");
            printf("Please, Enter a positive integer position\n");
            scanf("%d", &pos);
            printf("--------------------------------------------------\n");
        }
        else if (pos > list_length)
        {
            printf("The Position Entered exceedded the list length!\n");
            printf("Please, Enter a positive integer position\n");
            scanf("%d", &pos);
            printf("--------------------------------------------------\n");
        }
    }

    if (head == NULL)
    {
        printf("List is Empty, There is no Node to delete.\n");
        printf("--------------------------------------------------\n");
    }
    else
    {

        // Here we need 2 pointers to delete from End
        list_length = get_length_list();
        i = 1;
        if (pos == list_length) // Deleting the last Node
        {
            printf("Deleting Desired Node From End....\n");
            printf("--------------------------------------------------\n");
            prev_node = head;
            while (i < pos - 1)
            {
                prev_node = prev_node->next;
                i++;
            }
            printf("%d\n",prev_node -> next);
            current_node = prev_node->next;
            prev_node->next = NULL;
            free(current_node); // Deleted the node
            printf("Node has successfully been deleted!\n");
            printf("--------------------------------------------------\n");
            return Success;
        }
        else if (pos == 1) // Deleting From Begining
        {
            if (pos == list_length) // One Node In the List
            {
                printf("Deleting Desired Node From Begining....\n");
                printf("--------------------------------------------------\n");
                free(head);
                printf("Node has successfully been deleted!\n");
                printf("--------------------------------------------------\n");
            }
            else
            {
                printf("Deleting Desired Node From Begining....\n");
                printf("--------------------------------------------------\n");
                current_node = head;
                head = head->next;
                free(current_node);
                printf("Node has successfully been deleted!\n");
                printf("--------------------------------------------------\n");
            }
        }
        else
        {
            // Deleting Any Node in Any Desired Position
            // Here We need 3 pointers to delete from any position -> prev,current,next <-
            printf("Deleting Desired Node From Required Position....\n");
            printf("--------------------------------------------------\n");
            i = 0;
            prev_node = head;
            while (i < pos - 1) // Tranversing list till meeting the node preceeding the desired node to delete ^^
            {
                prev_node = prev_node->next;
                i++;
            }
            current_node = prev_node->next;    // The Desired Node
            next_node = prev_node->next->next; // After Desired Node
            current_node->next = NULL;
            prev_node->next = next_node;
            free(current_node); // Deleted the Desired Node
            printf("Node has successfully been deleted!\n");
            printf("--------------------------------------------------\n");
            return Success;
        }
    }
}

// void delete_node_by_data_value(int data_user)
// {
//
// }

int search_4_data() // Returns the position of the element
{
    int i = 1, entry_id;
    printf("Please, Enter ID To access Data stored!\n");
    scanf("%d", &entry_id);
    printf("--------------------------------------------------\n");
    if (head == NULL)
    {
        printf("List is Empty!\n");
        printf("--------------------------------------------------\n");
    }
    else
    {
        current_node = head;
        if (entry_id == current_node->id)
        {
            printf("ID has been found in First Node!\n");
            printf("--------------------------------------------------\n");
            // printf("Value of The Data = %d\n",current_node -> data);
            return 1;
        }
        else
        {
            while (current_node->next != NULL)
            {
                i++;
                if (entry_id == current_node->id)
                {
                    printf("ID has been found!\n");
                    printf("--------------------------------------------------\n");
                    // printf("Value of The Data = %d\n",current_node -> data);
                    return i;
                }
                current_node = current_node->next;
            }
            if (current_node->next == NULL)
            {
                if (entry_id == current_node->id)
                {
                    printf("ID has been found in End!\n");
                    printf("--------------------------------------------------\n");
                    return i;
                }
                else
                {
                    printf("ID has Not been found!\n");
                    printf("--------------------------------------------------\n");
                    return Fail;
                }
            }
        }
    }
}

void read_or_change_data_by_pos(int choice)
{
    int i = 1, pos, data_change, list_length;
    if (choice == Choice_Read)
    {
        printf("Enter Position To Access Read Procedure From!\n");
    }
    else if (choice == Choice_Change)
    {
        printf("Enter Position To Change Data Stored in it!\n");
    }
    scanf("%d", &pos);
    printf("--------------------------------------------------\n");
    list_length = get_length_list();
    if ((pos <= list_length) && (pos > 0))
    {
        if (choice == Choice_Change)
        {
            printf("Enter Data To be Changed with the stored!\n");
            scanf("%d", &data_change);
            printf("--------------------------------------------------\n");
        }

        if (head == NULL)
        {
            printf("List is Empty!\n");
            printf("--------------------------------------------------\n");
        }
        else
        {
            current_node = head;
            while (i < pos)
            {
                current_node = current_node->next;
                i++;
            }
            if (choice == Choice_Read)
            {
                printf("Data of The Given ID = %d\n", current_node->data);
                printf("--------------------------------------------------\n");
            }
            else if (choice == Choice_Change)
            {
                current_node->data = data_change;
                printf("Data has successfully been changed to %d for ID %d\n", current_node->data, current_node->id);
                printf("--------------------------------------------------\n");
            }
        }
    }
    else
    {
        if (list_length == 0)
        {
            printf("List is Empty!\n");
        }
        else
        {

            printf("Position Given invalid!\n");
            printf("--------------------------------------------------\n");
        }
    }
}

// void read_similar_data(int data_sim)
// {
//
// }
void read_or_change_data_by_id(int choice) // 2 Choices... 1- Read 2- Change
{
    int id, data_change;
    if (choice == Choice_Read)
    {
        printf("Enter ID To Read From!\n");
        scanf("%d", &id);
        printf("--------------------------------------------------\n");
    }
    else if (choice == Choice_Change)
    {
        printf("Enter ID To Change Data Stored in it!\n");
        scanf("%d", &id);
        printf("--------------------------------------------------\n");
        printf("Enter Data To be Changed with the stored!\n");
        scanf("%d", &data_change);
        printf("--------------------------------------------------\n");
    }

    if (head == NULL)
    {
        printf("List is Empty!\n");
        printf("--------------------------------------------------\n");
    }
    else
    {
        current_node = head;
        if (id == current_node->id)
        {
            if (choice == Choice_Read)
            {
                printf("Data of The Given ID = %d\n", current_node->data);
                printf("--------------------------------------------------\n");
            }
            else if (choice == Choice_Change)
            {
                current_node->data = data_change;
                printf("Data has successfully been changed to %d for ID %d\n", current_node->data, current_node->id);
                printf("--------------------------------------------------\n");
            }
        }
        else
        {
            while (current_node->next != NULL)
            {
                if (id == current_node->id)
                {

                    if (choice == Choice_Read)
                    {
                        printf("Data of The Given ID = %d\n", current_node->data);
                        printf("--------------------------------------------------\n");
                    }
                    else if (choice == Choice_Change)
                    {
                        current_node->data = data_change;
                        printf("Data has successfully been changed to %d for ID %d\n", current_node->data, current_node->id);
                        printf("--------------------------------------------------\n");
                    }
                }
                current_node = current_node->next;
            }
            if (current_node->next == NULL)
            {
                if (id == current_node->id)
                {
                    if (choice == Choice_Read)
                    {
                        printf("Data of The Given ID = %d\n", current_node->data);
                        printf("--------------------------------------------------\n");
                    }
                    else if (choice == Choice_Change)
                    {
                        current_node->data = data_change;
                        printf("Data has successfully been changed to %d for ID %d\n", current_node->data, current_node->id);
                        printf("--------------------------------------------------\n");
                    }
                }
                else
                {
                    printf("There is No ID similar to what you enter!\n");
                    printf("--------------------------------------------------\n");
                }
            }
        }
    }
}

int get_length_list()
{
    sll_node *temp;
    int i = 1;
    temp = head;
    if (head == NULL)
    {
        // printf("List is Empty\n");
        // printf("--------------------------------------------------\n");
        return i - 1; // Return 0
    }
    else
    {
        while (temp->next != NULL)
        {
            // printf("Data of The %d Node = %d\n",i++,temp -> data);
            // printf("----------------------------\n");
            temp = temp->next;
            i++;
        }
        return i;
        // printf("Data of The %d Node = %d\n",i,temp -> data);
        // printf("----------------------------\n");
    }
}
int entry_number_of_elements()
{
    int no_of_elements, user_data, user_id, i = 0;
    sll_node entry_data;
    while (1)
    {

        printf("Enter How many elements Needed in List!\n");
        scanf("%d", &no_of_elements);
        if (no_of_elements <= 0)
        {
            printf("Failed Process, You Entered -ve number Or Zero\n");
            printf("Please, Enter a +ve integer number....\n");
            printf("-------------------------------------------\n");
        }
        else
        {
            break;
        }
    }
    printf("-------------------------------------------\n");

    // PROBLEM FROM HERE
    while (i < no_of_elements)
    {
        printf("Enter Data of The Node!\n");
        scanf("%d", &user_data);
        printf("-------------------------------------------\n");
        printf("Enter ID of The Given Data!\n");
        scanf("%d", &user_id);
        printf("-------------------------------------------\n");
        entry_data.data = user_data;
        entry_data.id = user_id;
        current_node = create_SLL(entry_data);
        printf("User_data is %d with ID Of %d\n", current_node->data, current_node->id);
        printf("-------------------------------------------\n");
        i++;
    }

    return no_of_elements;
}
int User_Choice(int choice)
{
    int list_length;
    switch (choice)
    {
    case Choice_Create_SLL:
        entry_number_of_elements();
        break;
    case Choice_Insert_Node:
        insert_node();
        break;
    case Choice_Delete_Node:
        delete_node();
        break;
    case Choice_Search_4_Data:
        search_4_data();
        break;
    case Choice_Read_Data_By_ID:
        read_or_change_data_by_id(Choice_Read);
        break;
    case Choice_Read_Data_By_pos:
        read_or_change_data_by_pos(Choice_Read);
        break;
    case Choice_Change_Data_By_ID:
        read_or_change_data_by_id(Choice_Change);
        break;
    case Choice_Change_Data_By_pos:
        read_or_change_data_by_pos(Choice_Change);
        break;
    case Choice_Get_List_Length:
        list_length = get_length_list();
        printf("List Size is %d\n",list_length);
        break;
    case Choice_Dislpay_List:
        display_sll();
        break;
    case Exit_Code_Choice:
        return Exit_Code_Choice;
        break;
    default:
        return 0;
    }
}