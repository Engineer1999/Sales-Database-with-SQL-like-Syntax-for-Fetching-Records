#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"sql.h"

void onlyfrom(char *str)
{

  char s[10],f[10],m1[50],m2[50];	                                  //llocate memory to save diffirent part of SQL query 
  char delim[]=" ;";							  //allocate memory to delims					
// char str[100]; 							  //memory for main SQL query string
   short int a,b;

	//printf("\nmysql -> ");						  //ask for SQL query
	//gets(str);							  //scan SQL query

	    strcpy(s, strtok(str , delim));				  //copy different pert of query depending upon delims diclare in starting
	    strcpy(m1, strtok(NULL , delim));
	    strcpy(f , strtok(NULL, delim));
	    strcpy(m2, strtok(NULL , delim));
	
            a=strcmp("SELECT", s);
            b=strcmp("FROM", f);

	FROM1(m1,m2);

}



void FROM1(char m1[50], char m2[50])
{


 char delim[]=",";							   //allocate memory to delims
 int i, cnt =0;
 char ch;

	for(i=0;m2[i]!='\0';i++)
	{                                           //count number of attributes in fourth part of query
		if(m2[i]==',')
			cnt++;
	}



	if(cnt==0)							   //if attribute is 1
		{

			char v1[10];                                     
			strcpy(v1, strtok(m2, delim));
			trans1(v1,m1);                                   //function call to trans1 function when FROm attribute is one

		}

	else								    //number of attributes are more than 1
		{

		char **v = (char**)malloc(sizeof(char*)*(cnt+1));          //generates a double pointer for 2D dynamic memory allocation


			for(i=0;i<=cnt;i++)
				v[i]=(char*)malloc(sizeof(char)*20);       //create a 2D dynamic array 

		strcpy(v[0], strtok(m2, delim));                           //store 1st attribute of fourth part of query

			for(i=1;i<=cnt;i++)
				strcpy(v[i], strtok(NULL, delim));         //store remaining attribute of fourth part of query

				trans(v, cnt, m1);			   //function call to trans function when FROm attribute are more than one

		}
}



void trans1(char v1[10], char m1[50])                             //variy the FROM attribute to print content of that file
{
 int a;

 a=strcmp("product", v1);
	 if(a==0)
	 {
	 product1(m1);
	 }
 a=strcmp("order", v1);
	if(a==0)
	{
	order1(m1);
	}
 a=strcmp("orderdetail", v1);
	if(a==0)
	orderdetail1(m1);

 a=strcmp("customer", v1);
	if(a==0)
	customer1(m1);


}




void trans(char **v, int cnt, char m1[50])
{
 int a=0,b=0,c=0,d=0;
 int i;


	for(i=0;i<=cnt;i++)
	{
		a=strcmp("product",v[i]);

			if(a==0)
			{
			product1(m1);
			}
					
			

		b=strcmp("order",v[i]);

			if(b==0)
			{
			order1(m1);
			}
		

		c=strcmp("orderdetail",v[i]);

			if(c==0)
			{
			orderdetail1(m1);
			}

		d=strcmp("customer",v[i]);

			if(d==0)
			customer1(m1);
	}

}




void product1(char m1[50])
{
char f1[]="        ProdID |   ProductName |     price     |           UOM |";
char a[10],ch;
char *p;
int k,cnt1=0,j=0,cnt2=0,i;
char delim[]=",";
FILE *fp;
fp=fopen("product","r");

	for(i=0;m1[i]!='\0';i++)
	{                                           //count number of attributes in fourth part of query
		if(m1[i]==',')
			cnt1++;
	}

if(m1[0]=='*')
{
while((ch=fgetc(fp))!=EOF)
{
printf("%c", ch);
}
}
else
{

char **v=(char**)malloc(sizeof(char*)*(cnt1+1));

for(i=0;i<=cnt1;i++)
v[i]=(char*)malloc(sizeof(char)*20);

i=0;
strcpy(v[i],strtok(m1,delim));
for(i=1;i<=cnt1;i++)
strcpy(v[i],strtok(NULL,delim));


for(i=0;i<=cnt1;i++)
{
p = strstr(f1,v[i]);

k=strlen(p);

for(int i=0;i<k;i++)
{
if(p[i]=='|')
cnt2++;
}
cnt2 = 4-cnt2;

j=16*cnt2;
fseek(fp,j,SEEK_SET);
printf("|");
while((ch=fgetc(fp))!=EOF)
{
while((ch=fgetc(fp))!='|')
{
printf("%c", ch);
}
printf("|");
printf("\n");
printf("|");
j=j+66;
fseek(fp,j,SEEK_SET);
}

cnt2=0;
}
printf("\n\n");
fclose(fp);
free(v);
}
}



void order1(char m1[50])
{
char f1[]="        custID |     orderDate |       orderID |";
char a[10],ch;
char *p;
int k=0,cnt1=0,j=0,cnt2=0,i=0;
char delim[]=",";
FILE *fp=NULL;
fp=fopen("order","r");


	for(i=0;m1[i]!='\0';i++)
	{                                           //count number of attributes in fourth part of query
		if(m1[i]==',')
			cnt1++;
	}

if(m1[0]=='*')
{
while((ch=fgetc(fp))!=EOF)
{
printf("%c", ch);
}
}

else
{

char **v=(char**)malloc(sizeof(char*)*(cnt1+1));

for(i=0;i<=cnt1;i++)
v[i]=(char*)malloc(sizeof(char)*20);

i=0;
strcpy(v[i],strtok(m1,delim));
for(i=1;i<=cnt1;i++)
strcpy(v[i],strtok(NULL,delim));




for(i=0;i<=cnt1;i++)
{
p = strstr(f1,v[i]);

k=strlen(p);

for(int i=0;i<k;i++)
{
if(p[i]=='|')
cnt2++;
}
cnt2 = 3-cnt2;

j=16*cnt2;
fseek(fp,j,SEEK_SET);
printf("|");
while((ch=fgetc(fp))!=EOF)
{
while((ch=fgetc(fp))!='|')
{
printf("%c", ch);
}
printf("|");
printf("\n");
printf("|");
j=j+50;
fseek(fp,j,SEEK_SET);
}

cnt2=0;
}
printf("\n\n");

fclose(fp);
free(v);
}
}

void orderdetail1(char m1[50])
{
char f1[]="       orderID |     productID |      quantity |";
char a[10],ch;
char *p;
int k=0,cnt1=0,j=0,cnt2=0,i=0;
char delim[]=",";
FILE *fp=NULL;
fp=fopen("orderdetail","r");


	for(i=0;m1[i]!='\0';i++)
	{                                           //count number of attributes in fourth part of query
		if(m1[i]==',')
			cnt1++;
	}
if(m1[0]=='*')
{
while((ch=fgetc(fp))!=EOF)
{
printf("%c", ch);
}
}

else
{

char **v=(char**)malloc(sizeof(char*)*(cnt1+1));

for(i=0;i<=cnt1;i++)
v[i]=(char*)malloc(sizeof(char)*20);

i=0;
strcpy(v[i],strtok(m1,delim));
for(i=1;i<=cnt1;i++)
strcpy(v[i],strtok(NULL,delim));




for(i=0;i<=cnt1;i++)
{
p = strstr(f1,v[i]);

k=strlen(p);

for(int i=0;i<k;i++)
{
if(p[i]=='|')
cnt2++;
}
cnt2 = 3-cnt2;

j=16*cnt2;
fseek(fp,j,SEEK_SET);
printf("|");
while((ch=fgetc(fp))!=EOF)
{
while((ch=fgetc(fp))!='|')
{
printf("%c", ch);
}
printf("|");
printf("\n");
printf("|");
j=j+50;
fseek(fp,j,SEEK_SET);
}

cnt2=0;
}
printf("\n\n");

fclose(fp);
free(v);

}
}


void customer1(char m1[50])
{
char f1[]="        custID |    First_Name |     Last_Name |        Gender |           DOB |           Pin |         Phone |          Area |          City |";
char a[10],ch;
char *p;
int k=0,cnt1=0,j=0,cnt2=0,i=0;
char delim[]=",";
FILE *fp=NULL;
fp=fopen("customer","r");


	for(i=0;m1[i]!='\0';i++)
	{                                           //count number of attributes in fourth part of query
		if(m1[i]==',')
			cnt1++;
	}
if(m1[0]=='*')
{
while((ch=fgetc(fp))!=EOF)
{
printf("%c", ch);
}
}

else
{

char **v=(char**)malloc(sizeof(char*)*(cnt1+1));

for(i=0;i<=cnt1;i++)
v[i]=(char*)malloc(sizeof(char)*20);

i=0;
strcpy(v[i],strtok(m1,delim));
for(i=1;i<=cnt1;i++)
strcpy(v[i],strtok(NULL,delim));




for(i=0;i<=cnt1;i++)
{
p = strstr(f1,v[i]);

k=strlen(p);

for(int i=0;i<k;i++)
{
if(p[i]=='|')
cnt2++;
}
cnt2 = 9-cnt2;

j=16*cnt2;
fseek(fp,j,SEEK_SET);
printf("|");
while((ch=fgetc(fp))!=EOF)
{
while((ch=fgetc(fp))!='|')
{
printf("%c", ch);
}
printf("|");
printf("\n");
printf("|");
j=j+146;
fseek(fp,j,SEEK_SET);
}

cnt2=0;
}
printf("\n\n");

fclose(fp);
free(v);

}
}

