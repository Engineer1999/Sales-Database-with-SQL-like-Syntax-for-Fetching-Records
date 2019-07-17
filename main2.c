#include <stdio.h>
#include <stdlib.h>
#include"menu.c"


void prod_order()
{
	int choice=1,cnt=0,custID,orderID;
	
		printf("Enter your customer ID:");
		scanf("%d",&custID);
		FILE *fp=NULL;
        char line[200];
	    fp=fopen("order.txt","a+");	
	    	  while(!feof(fp))
	    {
	    	while(fgets(line,200,fp))
	    	 {
	    	 	orderID++;
			 }
		}
	fseek(fp,0,SEEK_END);


	
	while(choice!=0)
	{
        printf("\n\nPRODUCT MENU:\n\n");
	    printf("\n1. GUJRATI:");
	    printf("\n2. PANJABI:");
	    printf("\n3. CHINISE:");
	    printf("\n0. EXIT:");
	    printf("\n\nENTER YOUR CHOICE:");
	    scanf("%d",&choice);
	    
		switch(choice)
		{
			case 1:
			  cnt+=	prodGmenu(orderID);
				break;
			case 2:
			  cnt+=	prodPmenu(orderID);
				break;
			case 3:
			  cnt+=	prodCmenu(orderID);
				break;
			default:
				printf("Invalid choice!!!\n");
		}
	}
	if(cnt!=0)
	{
	   orderfile(custID,orderID);
	}

}
