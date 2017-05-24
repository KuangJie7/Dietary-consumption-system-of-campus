// 扫描食堂价位.cpp : 定义控制台应用程序的入口点。
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct ord
{
	int n;
	char ti[2];
	char na[30];
	char cna[30];
	int cnum;
	char dish[10];
	char ma1[10];
	char zhu[10];
	int ma2;
	//char bav[10];
	//char ma3[10];
};

int add(int a[],int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
	c=c+a[i];
	return(c);
}

int xstjxf(int c)
{
    char name[5][20],dish[5][5][20],flavor[5][10],type[6][15],sname[10][20],sex[10][6];
	int i,j,k,n,m,tempmin,tempmax,low,number[5],price[5][5],pay[10]={0},age[10],snumber[10];
	FILE *fp;
	struct ord a;
	if((fp=fopen("D:\\学习\\程序设计\\project\\canteen.txt","rb"))==NULL)
    {
	puts("can’t be opened"); 
	exit(0); 
	}
    for(i=0;i<=4;i++)
    {
	fscanf(fp,"%s%d%s%s%s%s%s%s%s%d%d%d%d%d",name[i],&number[i],flavor[i],type[i],dish[i][0],dish[i][1],dish[i][2],dish[i][3],dish[i][4],&price[i][0],&price[i][1],&price[i][2],&price[i][3],&price[i][4]); fflush;	//读数据
    fprintf(stdout,"%s%d%s%s%s%s%s%s%s%d%d%d%d%d\n",name[i],number[i],flavor[i],type[i],dish[i][0],dish[i][1],dish[i][2],dish[i][3],dish[i][4],price[i][0],price[i][1],price[i][2],price[i][3],price[i][4]);	//输出
	}
	
	fclose(fp); 
	
	if((fp=fopen("D:\\学习\\程序设计\\project\\student.txt","rb"))==NULL)
    {
	puts("can’t be opened"); 
	exit(0); 
	}
    for(j=0;j<10;j++)
    {
	fscanf(fp,"%s%s%d%d",sname[j],sex[j],&age[j],&snumber[j]);//读数据
    fprintf(stdout,"%s %s %d %d\n",sname[j],sex[j],age[j],snumber[j]);	//输出
	}
	fclose(fp); 

	if((fp=fopen("D:\\学习\\程序设计\\project\\buying.txt","rb"))==NULL)
    {
	puts("can’t be opened"); 
	exit(0); 
	}
    while(feof(fp)==0)
    {
	i=0;
	fscanf(fp,"%s%d%s%s%d%s%s%s%d",a.na,&a.n,a.ti,a.cna,&a.cnum,a.dish,a.ma1,a.zhu,&a.ma2); 	//读数据
    fprintf(stdout,"%s %d %s %s %d %s %s %s %d\n",a.na,a.n,a.ti,a.cna,a.cnum,a.dish,a.ma1,a.zhu,a.ma2);
	
	for(n=0;a.dish[n]!='\0';n++)
    {
		for(i=0;strcmp(a.na,sname[i])!=0;i++);
		for(m=0;m<=4;m++)
		{if(a.dish[n]==dish[a.cnum-1][m][0])
    	 pay[i]=pay[i]+(a.ma1[n]-48)*price[a.cnum-1][m];
		 }
	}
    }
	for(k=0;k<10;k++) 
	printf("%s消费了%d元\n",sname[k],pay[k]);
	fclose(fp);	//输出
	for(k=0,tempmax=pay[0];k<9;k++)
	{
		if(tempmax<pay[k+1])
		{
			tempmax=pay[k+1];
		}
	}
	for(k=0,tempmin=pay[0];k<9;k++)
	{
		if(tempmin>pay[k+1])
		{
			tempmin=pay[k+1];
		}
	}
	low=0.1*(add(pay,10)-tempmin-tempmax)/8;
	printf("%d###%d&&&%d\n",tempmin,tempmax,low);
	for(n=0,j=0;n<10;n++)
	{
		if(pay[n]<=low)
			{
				printf("%s可能为贫困生，请给予帮助",sname[n]);
				j=1;
		     }
	}
	if(j==0)
		printf("未找到贫困生\n");
	return(1);
}

int main()
{
	int c=0;
	xstjxf(c);
	return(0);
}
