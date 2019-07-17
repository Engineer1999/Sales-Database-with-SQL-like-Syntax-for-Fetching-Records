#include <stdio.h>
#include<string.h>
#include"llist.c"


void customer()
 {

    int choice=1;
    while(choice!=0)
    {
        printf("\n1. Enter new customer detail: ");
        printf("\n2. Delet  ");
        printf("\n3. Diplay customer list: ");
		printf("\n0. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
            
                insertAtEnd();
                break;
            	
            case 2: 
            	delet();
            	break;
            
			case 3:
                displayList();
                break;
                  
			default:
				printf("Invalid choice!!!!\n");
             
        }
    }
    
}





