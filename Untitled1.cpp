#include<stdio.h>
#include <stdlib.h>
int main()
{
	char sex[6],name[15];
	int age,number,i;
	FILE *fp;
	printf("请输入学生信息，格式为：姓名/性别/年龄/学号\n");
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
