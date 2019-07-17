#include<stdio.h>
#include"order.c"

int prodGmenu(int orderID)	
{
	char filename[20]="gujarati_menu.txt";
   int cnt= readfromFile(filename,orderID);
   return cnt;
}

int prodPmenu(int orderID)
{
   	char filename[20]="panjabi_menu.txt";
   int cnt= readfromFile(filename,orderID);
   return cnt;
}

int prodCmenu(int orderID)
{
	char filename[20]="chinese_menu.txt";
   int cnt= readfromFile(filename,orderID);
   return cnt;
}
	

//user defined function for reading a file
int readfromFile(char *filename,int orderID)
{
	FILE *fp=NULL;
	char line[200];
	fp=fopen(filename,"r");

	fgets(line,200,fp);	
 	while(!feof(fp))
	{
		printf("%s",line);		
		fgets(line,200,fp);
	}
	fclose(fp);
     int cnt=custorder(orderID); 
     return cnt;
}

void orderfile(int custID,int orderID)
{
	int day,month,year;
     FILE *fp=NULL;
     //char line[200];
	 fp=fopen("order.txt","a");	
	 
	printf("Enter today's date(yyyy/mm/dd):");
	scanf("%d/%d/%d",&year,&month,&day);
//	printf("Enetr OrderID:");
//	scanf("%d",&orderID);
	 /* while(!feof(fp))
	    {
	    	while(fgets(line,200,fp))
	    	 {
	    	 	cnt++;
			 }
		}
	fseek(fp,0,SEEK_END);*/
	fprintf(fp,"\n%13d. |%7d/%2d/%3d |%14d |",custID,year,month,day,orderID);
	fclose(fp);

}

