#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

int scrm(int c)		//���ѧ����Ϣ
{
	char sex[6],name[15];
	int age,number,i;
	printf("����  �Ա�  ����  ѧ��\n");
	FILE *fp;
	if((fp=fopen("D:\\ѧϰ\\�������\\project\\student.txt","r"))==NULL)
    {puts("can not be opened"); 
	 exit(0);
	}
	while(feof(fp)==0)
	{
    fscanf(fp,"%s%s%d%d",name,sex,&age,&number); 	//������
    fprintf(stdout,"%s %s %d %d\n",name,sex,age,number); 	//���
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

