#include<stdio.h>
#include"main1.c"
#include"main2.c"

void database()
{
	int choice=1;

    while(choice!=0)
  		{
			printf("\n1. DO operation on customer file:");
			printf("\n2. Give a order:");
			printf("\n0.Exit");
			printf("\nEnter your choice:");
			scanf("%d",&choice);
			
			switch(choice)
				{
					case 1:
						customer();
					break;
					case 2:
						prod_order();
					break;
					case 0:
						break;
	
					default:
						printf("Invalid choice!!!\n\n");
				}
 		}

}
