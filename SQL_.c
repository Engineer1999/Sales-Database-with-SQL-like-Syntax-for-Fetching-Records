#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"onlyfrom.c"
#include"from_dot.c"
/*void onlyfrom();
void from_with_dot();
void FROM1();
void trans1();
void trans();
void product1();
void order1();
void orderdetail1();
void customer1();
void trans_dot();
void product_dot();
void order_dot();
void orderdetail_dot();
void customer_dot();*/
//void orderby(m2,m3);
void main()
{
 char str[300]; 
 int count1=0,count2=0,i=0,k=0;							  //memory for main SQL query string
 char s[10],m1[200],f[10],m2[35],o[10],m3[35]; 
 char delim[]=" ;";
	printf("\nmysql--> ");						  //ask for SQL query
	gets(str);							  //scan SQL query
for(i=0;str[i]!='\0';i++)
if(str[i]==',')
count1++;

for(i=0;str[i]!='\0';i++)
if(str[i]=='.')
count2++;

if(count1>=0&&count2==0)
onlyfrom(str);
else
from_with_dot(str);



}

//*********************************************************************************************************************************************************************************

/*void onlyfrom(char *str)
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

//*********************************************************************************************************************************************************************************




void from_with_dot(char str[300])
{

char delim1[]=" ;",delim2[]=".,";
char s[10],m1[200],f[10],m2[80];
int i=0,cnt1=0,cnt2=0;

//printf("\nmysql-->");
//gets(str);

strcpy(s,strtok(str,delim1));
strcpy(m1,strtok(NULL,delim1));
strcpy(f,strtok(NULL,delim1));
strcpy(m2,strtok(NULL,delim1));

for(i=0;m1[i]!='\0';i++)
if(m1[i]==',')
cnt1++;

for(i=0;m1[i]!='\0';i++)
if(m1[i]=='.')
cnt2++;


char **z=(char**)malloc(sizeof(char*)*(cnt1+1+cnt2));

for(i=0;i<cnt1+1+cnt2;i++)
z[i]=(char*)malloc(sizeof(char)*20);

strcpy(z[0],strtok(m1,delim2));
for(i=1;i<cnt1+1+cnt2;i++)
strcpy(z[i],strtok(NULL,delim2));

char **a1=(char**)malloc(sizeof(char*)*(cnt2));

for(i=0;i<cnt2;i++)
a1[i]=(char*)malloc(sizeof(char)*20);

for(i=0;i<cnt2;i++)
a1[i]=z[2*i];

char **a2=(char**)malloc(sizeof(char*)*(cnt2));

for(i=0;i<cnt2;i++)
a2[i]=(char*)malloc(sizeof(char)*20);

for(i=0;i<cnt2;i++)
a2[i]=z[2*i+1];


free(z);
trans_dot(a1,a2,cnt2);
}

void trans_dot(char **a1,char **a2,int cnt2)
{
 int a=0,b=0,c=0,d=0;
 int i;
 int fp=0,fo=0,fd=0,fc=0;

	for(i=0;i<cnt2;i++)
	{
		a=strcmp("product",a1[i]);

			if(a==0&&fp==0)
			{
			product_dot(a2,cnt2);
			fp++;
			}
					
			

		b=strcmp("order",a1[i]);

			if(b==0&&fo==0)
			{
			order_dot(a2,cnt2);
			fo++;
			}
		

		c=strcmp("orderdetail",a1[i]);

			if(c==0&&fd==0)
			{
			orderdetail_dot(a2,cnt2);
			fd++;
			}

		d=strcmp("customer",a1[i]);

			if(d==0&&fc==0)
			{
			customer_dot(a2,cnt2);
			fc++;
			}
	}
}



void product_dot(char **a2,int cnt2)
{
char f1[]="        ProdID |   ProductName |     price     |           UOM |";
int i,k,j=0,cnt=0;
char *p,ch;
FILE *fp;
fp=fopen("product","r");


for(i=0;i<cnt2;i++)
{
p=strstr(f1,a2[i]);
if(p)
{
k=strlen(p);

for(int i=0;i<k;i++)
{
if(p[i]=='|')
cnt++;
}
cnt = 4-cnt;

j=16*cnt;
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
printf("\n\n");

cnt=0;
fclose(fp);

}
}

}



void order_dot(char **a2,int cnt2)
{
char f1[]="        custID |     orderDate |       orderID |";
int i,k,j=0,cnt=0;
char *p,ch;
FILE *fp;
fp=fopen("order","r");


for(i=0;i<cnt2;i++)
{
p=strstr(f1,a2[i]);
if(p)
{
k=strlen(p);

for(int i=0;i<k;i++)
{
if(p[i]=='|')
cnt++;
}
cnt = 3-cnt;

j=16*cnt;
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
printf("\n\n");

cnt=0;
fclose(fp);

}
}

}


void orderdetail_dot(char **a2,int cnt2)
{
char f1[]="       orderID |     productID |      quantity |";
int i,k,j=0,cnt=0;
char *p,ch;
FILE *fp;
fp=fopen("orderdetail","r");


for(i=0;i<cnt2;i++)
{
p=strstr(f1,a2[i]);
if(p)
{
k=strlen(p);

for(int i=0;i<k;i++)
{
if(p[i]=='|')
cnt++;
}
cnt = 3-cnt;

j=16*cnt;
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
printf("\n\n");

cnt=0;
fclose(fp);

}
}

}


void customer_dot(char **a2,int cnt2)
{
char f1[]="        custID |    First_Name |     Last_Name |        Gender |           DOB |           Pin |         Phone |          Area |          City |";
int i,k,j=0,cnt=0;
char *p,ch;
FILE *fp;
fp=fopen("customer","r");

for(i=0;i<cnt2;i++)
{
p=strstr(f1,a2[i]);
if(p)
{
k=strlen(p);

for(int i=0;i<k;i++)
{
if(p[i]=='|')
cnt++;
}
cnt = 9-cnt;
j=16*cnt;
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
printf("\n\n");

cnt=0;
fclose(fp);

}
}

}*/
