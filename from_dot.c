#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"sql.h"

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

}
