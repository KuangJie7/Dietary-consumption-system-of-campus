#include<stdio.h>
#include <stdlib.h>
int main()
{
	char sex[6],name[15];
	int age,number,i;
	FILE *fp;
	if((fp=fopen("student.txt","w"))==NULL)
     {
	  puts("cannot be opened");
	  exit(0);
	 }
	 fscanf(stdin,"%s%s%d%d",name,sex,&age,&number);
	 fprintf(fp,"%s %s %d %d\n",name,sex,age,number);
	 fclose(fp);
	 for(i=1;i<=9;i++)
	 {
	 	if((fp=fopen("student.txt","a"))==NULL)
     {
	  puts("cannot be opened");
	  exit(0);
	 }
	 fscanf(stdin,"%s%s%d%d",name,sex,&age,&number);
	 fprintf(fp,"%s %s %d %d\n",name,sex,age,number);
	 fclose(fp);
	 }
	 return(0);
}
