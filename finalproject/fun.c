#include "headerfile.h"


//welcoming funtion with the details of the system offers
char welcome_fn(linkedlist *ptr_List)
{
    printf("\t \t \t \t \t \t W E L C O M E   T O    O U R    B A N K  \n");
    printf("Choose the operation you want to do \n");
    printf(" 1- New customer\n 2- Delete customer \n 3- View customers information \n 4- Edit customer account \n 5- Deposit/withdraw \n 6- Customer deposit/withdraw History \n 7- specific customer information \n");
}

//function to initiate and start the linked list
void CreateList(linkedlist *ptr_List)
{
    ptr_List->head=0;        // creating a list its head is points to null cause its still empty
    ptr_List->num_ofcustomers=0;    //number of customers still zero
}
 // function to add node to the linked list (new customer sign up)
void AddNode(linkedlist *ptr_List)
{
    node *current=NULL;   // defining a pointer to a struct of type node to move it and to access any part of the linked list and initializing it to NULL
    struct node *pn=(struct node*)malloc(sizeof(struct node)); // creating a memory location its address stored in PL

    //------------------------------------Entering the data of the customer-------------------------------
    printf("Enter Customer name \n");
    scanf("%s",pn->entry.name);

    printf("Enter Customer Address \n");
    scanf("%s",pn->entry.address);

    printf("Enter Customer date of birth \n");
    scanf("%s",pn->entry.birthdate);

    printf("Enter Customer ID \n");
    scanf("%s",pn->entry.ID);

    printf("Enter Customer phone number \n");
    scanf("%s",pn->entry.phone);

    printf("Enter Customer Balance \n");
    scanf("%s",pn->entry.balance);

    pn->entry.counter2=0;      //  initializing the counter of the number of operations done by the customer by zero because its new customer and no previous operations

    //checking if the list is empty
    if(ptr_List->head==NULL)
    {
        ptr_List->head=pn;   //if the list is empty so the new node will be the first one so putting the node in the head
    }
    else // if its not the first node in the linked list
    {
        current=ptr_List->head; // the current pointer we initialized will be as the head and we will start moving it to reach what i want to access
        while(current->next != NULL) // i will moving it to the end of the linked list which is NULL to find the last node to add the new one after it
        {
            current=current->next; //will move again till reaching NULL or by the real meaning reach the end of the list and loop again
        }
        current->next=pn; // when the current pointer find the null so the last node so we will put our new node in the next of current=NULL
    }
    ptr_List->num_ofcustomers++; // we will increase the number of customers signed up in our system
    pn->next=NULL; // to make it the last node we should put its next by NULL
}

//function to print all the customers in the system
void printList(linkedlist *ptr_List)
{
    struct node *ptr=ptr_List->head; // initializing a pointer and put it as the head of our top pointer
    int counter =1; // initializing counter by 1 something only to print the customer list by its number
    if(ptr_List->head==NULL) // checking if the list is empty and no customers signed up
    {
        printf("list is empty \n ");
        return;
    }
    while(ptr != NULL)// looping while our pointer did not reach the end of our list
    {
        printf("\t \t \t \t \t \t CUSTOMER NUMBER  %d \n",counter);

//----------------------------------------------printing the customers details------------------------------------------------
        printf("customer name : %s \n",ptr->entry.name);
        printf("customer ID : %s \n",ptr->entry.ID);
        printf("customer phoner number : %s \n",ptr->entry.phone);
        printf("customer adddress : %s \n",ptr->entry.address);
        printf("customer date of birth : %s \n",ptr->entry.birthdate);
        printf("customer balance: %s \n",ptr->entry.balance);

        ptr=ptr->next; // moving the pointer to next
        printf("\n");
        counter++;
    }
}

//function to delete a customer from the system
void DeleteCustomer(linkedlist *ptr_List)
{
    int pos=1;
    char ID[30];
//-----------initializing 3 pointers for current previous and the node need to be deleted helping me to move freely in the list------------------------
    struct node *delete_node=NULL;
    struct node *current=NULL;
    struct node *prev=NULL;

    printf("please enter cutsomer ID \n ");  // the user will enter the id of the customer that needed to be deleted
    scanf("%s",ID);

    //check the list if empty
    if(ptr_List->head==NULL)
    {
        printf("list is empty \n");
        return;
    }
    //check the first node in linked list
    if(! strcmp(ptr_List->head->entry.ID,ID))
    {
        delete_node=ptr_List->head;  // if found in the first node will put it in the delete pointer to free it
        ptr_List->head=ptr_List->head->next;  // the head of the top will be the same as its next to connect between the top and the second node in this case
        printf("%s found at position &d and deleted \n ",ID,pos);
        free(delete_node); // free the pointer holding the node or the customer i want to delete
        return;
    }
    //check the other nodes
    pos++;
    current=ptr_List->head->next; // moving to the other nodes with current pointer
    prev=ptr_List->head; // putting its head to prev to save it to connect after deleting
    while (current != NULL) // looping till the end of the linked list
    {
        if(! strcmp(current->entry.ID,ID)) // if the id found
        {
            //element found
            delete_node=current; // putting the wanted node in deleting pointer
            prev->next=current->next; // the next of the previous node will be connected to the next of the cell i want to delete to save the link between the first and the third node
            printf("%s found at position %d and deleted \n",ID,pos);
            free(delete_node); // deleting the node i want
            return;
        }
        // if i did not find the id
        prev=current; // puuting the current node i was in in the prev
        current=current->next; // and moving to the next with current pointer
        pos++;
    }
    //in case data not found
    if(delete_node==NULL)
    {
        printf("%s not found in the customer list \n",ID);
    }
}

// updating info about the customer
void UpdateCustomerInfo(linkedlist *ptr_List)
{
    int pos=1;
    int op;
    char id[30];
    struct node *current=NULL; // pointer to move

    if(ptr_List->head==NULL) // check if empty
    {
        printf("no customers in the list \n");
        return;
    }

    //taking its id
    printf("enter ID of the customer you want to update its info \n");
    scanf("%s",id);

    //start checking from the first node
    current=ptr_List->head;
    while(current != NULL)
    {
        if(! strcmp(current->entry.ID,id))
        {
            printf("you want to change \n"); //when find id we want to know what the user want to update
            printf("1- Name \n 2- Address \n 3- Date of birth \n 4- phone number \n ");
            scanf("%d",&op);

            //switch case to direct the software where to go upon the user input (what the user want to change)
            switch(op)
            {
            case 1:
                printf("please enter The Customer new name \n");
                scanf("%s",current->entry.name);
                printf("%s found at position %d and the name changed \n",id,pos);
                break;
            case 2:
                printf("please enter The Customer new address \n");
                scanf("%s",current->entry.address);
                printf("%s found at position %d and the address changed \n",id,pos);
                break;
            case 3:
                printf("please enter The Customer new date of birth \n");
                scanf("%s",current->entry.birthdate);
                printf("%s found at position %d and the birth date changed \n",id,pos);
                break;
            case 4:
                printf("please enter The Customer new phone number \n");
                scanf("%s",current->entry.phone);
                printf("%s found at position %d and the phone number changed \n",id,pos);
                break;
            default :
                printf("enter a valed operation \n");
                break;
            }
            return;
        }
        current=current->next; // moving to next if not found
        pos++;
    }
}

//function to withdraw or deposit
void Transact(linkedlist *ptr_List)
{

    struct node *current=NULL;
    int op;
    char id[30]; // to copy entry by user
    char money[30]; // to copy thev value of money deposit or withdraw
    char *pend=NULL; // pointer needed in the function of strtof

    //requesting id from the user
    printf("enter customer ID \n");
    scanf("%s",id);


    if(ptr_List->head==NULL) // if list is empty
    {
        printf("no customers in the list \n");
        return;
    }

    current=ptr_List->head; // start initializing the moving pointer

    //trying to find the ID in the list
    while(current != NULL)
    {
        if(! strcmp(current->entry.ID,id))
        {
            printf("your current balance = %s \n",current->entry.balance); // printing the current balance
            printf("1- deposit \n 2- withdrawl \n "); // to know he ewant to deposit or to withdraw
            scanf("%d",&op);

            //switch case direct the software to withdraw or deposit upon user entry
            switch(op)
            {
            case 1: // in case user want to deposit

                //taking the value from the user as a string
                printf("how much money you want to deposit \n");
                scanf("%s",money);

                float f1 = strtof(money,&pend); // change string money to float to make a mathematical operations

                pend=NULL; // reinitialize pointer to NULL to use it again

                float f2 =strtof(current->entry.balance,&pend);//change the balance from string to float

                sprintf(current->entry.balance,"%f",f1+f2); // adding the two floats and using this function to add them again to balance of type string

                printf("your current balance after your deposit = %s \n",current->entry.balance);

//-------------------saving the operations for the customer history-------------------------

                //only six operations will saved for the customer
                if (current->entry.counter2==6)
                {
                    current->entry.counter2=0;
                }
                current->entry.customerh[current->entry.counter2].arr=f1; // putting the value as float in the array of structure
                current->entry.customerh[current->entry.counter2].type=1; // putting the typer of operation 1=deposite 0=withdraw
                break; // end of case 1

            case 2: // in case of withdraw

                printf("how much money you want to withdraw \n");
                scanf("%s",money);

                f1 = strtof(money,&pend);

                pend=NULL;

                f2 =strtof(current->entry.balance,&pend);

                sprintf(current->entry.balance,"%f",f2-f1);

                printf("your current balance after your withdraw = %s \n",current->entry.balance);

//-------------------saving the operations for the customer history-------------------------

                if (current->entry.counter2==6)
                {
                    current->entry.counter2=0;
                }
                current->entry.customerh[current->entry.counter2].arr=f1;
                current->entry.customerh[current->entry.counter2].type=0;
                break;
            default:
                printf("wrong operation \n");
                break;
            }
            current->entry.counter2++;
            return;
        }
        current=current->next;
    }
    printf("%s is not found in the list \n",id);
}
void Customerhistory(linkedlist *ptr_List)
{
    char id[30];
    int i=0;
    struct node *current=NULL;

    printf("Please customer ID to show your transcript \n");
    scanf("%s",id);

    if(ptr_List->head==NULL)
    {
        printf("no customers in the list \n");
        return;
    }
    current=ptr_List->head;

    while(current != NULL)
    {
        if(! strcmp(current->entry.ID,id))
        {
            for (i ; i<current->entry.counter2;i++)
            {
                if(current->entry.customerh[i].type == 1)
                {
                    printf("you made deposit by : %f \n",current->entry.customerh[i].arr);
                }
                else if(current->entry.customerh[i].type == 0)
                {
                    printf("you made withdraw by : %f \n",current->entry.customerh[i].arr);
                }
            }
                return;
            }
            current=current->next;
        }
}
void specific(linkedlist *ptr_List)
{
    char id[30];
    struct node *current=NULL;

    if(ptr_List->head==NULL)
    {
        printf("no customers in the list \n");
        return;
    }
    printf("enter ID of the customer you want to show its info \n");
    scanf("%s",id);
    //start checking from the first node
    current=ptr_List->head;
    while(current != NULL)
    {
        if(! strcmp(current->entry.ID,id))
        {
            printf("customer name : %s \n",current->entry.name);
            printf("customer ID : %s \n",current->entry.ID);
            printf("customer phoner number : %s \n",current->entry.phone);
            printf("customer adddress : %s \n",current->entry.address);
            printf("customer date of birth : %s \n",current->entry.birthdate);
            printf("customer balance: %s \n",current->entry.balance);
        }
           current=current->next;
    }
}

