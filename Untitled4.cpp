#include<stdio.h>
#include"SQL_FINAL.c"
#include"database.c"
void sql();
void database();

void main()
{
	int choice=1;
  	
	while(choice!=0)
	 {
		printf("\n1. Do database:");
		printf("\n2. Run sql:");
		printf("\n0.exit");
		printf("\nenter your choice:");
		scanf("%d",choice);

        switch(choice)
			{
				case 1:
					database();
					break;
				case 2:
					sql();
      				break;
				case 0:
	break;

			}
	 }

}
