#include<stdio.h>
#include<stdlib.h>
#include"product.h"



int custorder(int orderID)
{
	//FILE *fp=NULL;
    //fp=fopen("order.txt","a");
	int choice=0,cnt,custID;
      while(choice==0)
     {    
     
	     printf("\nFor Order Press 0 Or else you Exit:");
         scanf("%d",&choice);
           /*if(choice==0 && cnt==0)
             {
             	printf("ENTER YOUR CUSTOMER ID FOR ORDER:");
             	scanf("%d",&custID);
				fprintf(fp,"\n%6d |",custID);
			 }*/
           if(choice==0)
	         {
			   order(orderID);
			   cnt++;
			 }
	       else
	          printf("YOU ARE EXIT FROM CURRENT DISH!!!\n");
			
     }
     return cnt;
    /// fclose(fp);
}
void order(int orderID)
{
	int productID,qun,i;
   	FILE *fp=NULL;
    fp=fopen("order_deatail.txt","a");
	
		
	printf("For Order Enter Food Id:");
	scanf("%d",&productID);
	printf("Enter Quntity:");
	scanf("%d",&qun);
	
	if(productID==01)
	 	printf("You ordered fixed dish. Quntity-%d",qun);
   else if(productID==02)
	 	printf("You ordered dal-rise. Quntity-%d",qun);
   else if(productID==03)
     	printf("You ordered papad. Quntity-%d",qun);
   else if(productID==04)
	 	printf("You ordered aloo paratha. Quntity-%d",qun);
   else if(productID==05)
	 	printf("You ordered tandoori. Quntity-%d",qun);
	else if(productID==06)
	 	printf("You ordered lachhi. Quntity-%d",qun);
	else if(productID==07)
	 	printf("You ordered noodles. Quntity-%d",qun);
	else if(productID==10)
	 	printf("You ordered MANCHURIAN. Quntity-%d",qun);
	else if(productID==11)
	 	printf("You ordered soup. Quntity-%d",qun);
    else
	    printf("Error in give oeder.Try again.\n");	 	

  fprintf(fp,"\n%14d |%14d |%14d |",orderID,productID,qun);

  fclose(fp);
}

