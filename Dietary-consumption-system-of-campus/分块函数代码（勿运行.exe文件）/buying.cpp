#include<stdio.h>
#include<stdlib.h>
struct ord
{
	int n;
	char na[30];
	char cna[30];
	int cnum;
	char dish[15];
	char ma1[15];
	char zhu[10];
	int ma2;
	char bav[10];
	char ma3[10];
};
int main()
{
	int i=100; 
	struct ord a;
	FILE  *fp;
	//buffer=(char*)malloc(i);
  if((fp=fopen("buying.txt","a+"))==NULL)
     {
	 puts("can’t be opened"); 
	 exit(0);
	 }
	printf("消费记录登记开始\n");
	printf("消费日期(第几天):");
	scanf("%d",&a.n);
	fflush(stdin);
    printf("你的名字:"); 
	gets(a.na);
    printf("食堂名称:");  
	gets(a.cna);
    printf("食堂编号:");
	scanf("%d",&a.cnum);
	fflush(stdin);
    printf("消费菜品名称:"); 
	gets(a.dish);
    printf("消费菜品数量:");
	gets(a.ma1);
	printf("消费主食名称:"); 
	gets(a.zhu);
    printf("消费主食数量:");
	scanf("%d",&a.ma2);
	fflush(stdin);
	printf("消费饮料名称:"); 
	gets(a.bav);
    printf("消费饮料数量:");
	gets(a.ma3);
	fprintf(fp,"%d %s %s %d %s %s %s %d %s %s\n",a.n,a.na,a.cna,a.cnum,a.dish,a.ma1,a.zhu,a.ma2,a.bav,a.ma3);
	fclose(fp);
	return(0);
} 
