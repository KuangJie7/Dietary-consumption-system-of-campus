#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

int scrm(int c)		//输出学生信息
{
	char sex[6],name[15];
	int age,number,i;
	printf("姓名  性别  年龄  学号\n");
	FILE *fp;
	if((fp=fopen("D:\\学习\\程序设计\\project\\student.txt","r"))==NULL)
    {puts("can not be opened"); 
	 exit(0);
	}
	while(feof(fp)==0)
	{
    fscanf(fp,"%s%s%d%d",name,sex,&age,&number); 	//读数据
    fprintf(stdout,"%s %s %d %d\n",name,sex,age,number); 	//输出
	}	
    fclose(fp); 
    return (0);
}

int main()
{
 int c;
 scrm(c);
 return(0);
}

