#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "customer.h"

void insertAtEnd()
{ 

    FILE *fp=NULL;
    fp=fopen("customer.txt","a+");
    //FILE *fp=fopen("Customer.txt","r+");
    char ch1[10][20]={{"custID"},{"First_Name"},{"Last_Name"},{"Gender"},{"DOB"},{"Pin"},{"Phone"},{"Area"},{"City"}};

    cust c;
    char line[200];
	
    int cnt=0;
    
    	if(fp==NULL)
	            	printf("File does not found:");

    			fseek (fp, 0, SEEK_END);
   			
  				if (0 == ftell(fp)) 
				{
    			    printf("file is empty\n");
    			 
    	
					fprintf(fp,"%14s |%14s |%14s |%14s |%14s |%14s |%14s |%14s |%14s |\n",ch1[0],ch1[1],ch1[2],ch1[3],ch1[4],ch1[5],ch1[6],ch1[7],ch1[8]);

    			}

		printf("\n%d",ftell(fp));
		fseek(fp,0,0);
		printf("\n\n%d",ftell(fp));
   	   while(!feof(fp))
	    {
	    	while(fgets(line,200,fp))
	    	 {
	    	 	cnt++;
			 }
		}

    printf("\nEnter customer's First name: ");
    scanf("%s",c.FirstName);
    printf("\nEnter customer's Last Name: ");
    scanf("%s",c.MiddleName);
    printf("\nEnter customer's Gender(F/M): ");
    c.gender=getchar();
    scanf("%c",&c.gender);
    printf("\nEnter Date of Birth(dd/mm/yyyy): ");
    scanf("%d/%d/%d",&c.dob.day,&c.dob.mon,&c.dob.year);
    printf("\nEnter pincode: ");
    scanf("%d",&c.pincode);
   // fflush(stdin);
	c.custNum=getchar();
	printf("\nEnter phone number: ");
    scanf("%li",&c.custNum);
    printf("\nEnter your area name: "); 
    scanf("%s",c.add.area);
    printf("\nEnter your city name:");
    scanf("%s",c.add.city);
    
 	fprintf(fp,"\n%13d. |%14s |%14s |%14c |%8d/%2d/%2d |%14d |%14li |%14s |%14s |",cnt,c.FirstName,c.MiddleName,c.gender,c.dob.year,c.dob.mon,c.dob.day,c.pincode,c.custNum,c.add.area,c.add.city);
 
    fclose(fp);
    
    
}

void  displayList()
{
    
    FILE *fp=NULL;
    char ch[100],line[200];
    int i,j=0,cnt=0;
    fp=fopen("customer.txt","r");
  
  	if(fp==NULL)
   	{ 
	    printf("File does not found: ");
	}
	
	else
	{
		fseek(fp,0,SEEK_END);
		if(ftell(fp)<=119)
		{
			printf("\nLIST IS EMPTY: \n");
			fclose(fp);
		}
		fseek(fp,0,0);
		while(fgets(line,200,fp))
		 {
		 	printf("%s",line);
		 }
		
	}
		
		fclose(fp);
}
	  
void delet()
{
	int p,ch,cnt=0,i;
	FILE *fp=fopen("customer.txt","r+");
	printf("Enter Customer ID: ");
	scanf("%d",&p);
	
	if(fp==NULL)
		printf("File does not exist: ");

	else
	{
		ch=fgetc(fp);
		while(!feof(fp))
		{
			cnt++;
			
			if(ch=='\n')
			{
				cnt++;
			}
			if(p==(ch-48))
			{
				printf("in");
				ch=fgetc(fp);
				if(ch=='.')
				{	
					cnt++;
					break;
				}
				else
				{
					cnt--;
					fseek(fp,-1,1);
				}		
			}
			ch=fgetc(fp);
		}
	
		fseek(fp,-5,1);
		for(i=0;i<110;i++)
		{
			fprintf(fp,"\b");
		}
	}
	fclose(fp);
}
 
