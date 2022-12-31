#include "headerfile.h"

int main()
{
    int operation;
    linkedlist tanany;

    linkedlist *ptr_l=&tanany;
    CreateList(&ptr_l);

while(1)
{
    welcome_fn(&ptr_l);
    scanf("%d",&operation);
    if (1<=operation<=7)
    {
        switch(operation)
        {
        case 1:
            AddNode(&ptr_l);
            break;
        case 2:
            DeleteCustomer(&ptr_l);
            break;
        case 3:
            printList(&ptr_l);
            break;
        case 4:
            UpdateCustomerInfo(&ptr_l);
            break;
        case 5:
            Transact(&ptr_l);
            break;
        case 6:
            Customerhistory(&ptr_l);
            break;
        case 7:
            specific(&ptr_l);
        default:
            printf("end");
        }
    }
}
return 0;
}
