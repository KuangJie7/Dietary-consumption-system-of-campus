#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cola;
int xuebi;
int cheng;
int tuiyl(int c)
{
	FILE *sp; 
	char a[10],d[10];
	char b[10]="yes",e[10]="no",i[10]="Kele",j[10]="Xuebi",m[10]="Chengzhi";
	printf("请问饮料是否开封(yes/no)?\n");
	gets(a);
	if((sp=fopen("yinliao.txt","r"))==NULL) 
		{ 
		printf("file can’t be opened"); 
		exit(0); 
		}
	fscanf(sp,"%d %d %d",&cola,&xuebi,&cheng);
	if(strcmp(a,e)==0)
	{
	printf("请问您需要退那种饮料？(Kele/Xuebi/Chengzhi)?\n");
	gets(d);
	if(strcmp(d,i)==0)
	 {
	 cola++;
	 printf("可乐退货成功\n");
     }
    if(strcmp(d,j)==0)
	 {
	 xuebi++;
	 printf("雪碧退货成功\n");
     }
     if(strcmp(d,m)==0)
	 {
	 cheng++;
	 printf("橙汁退货成功\n");
     }
    }
    if(strcmp(a,b)==0)
    printf("退货失败(饮料已被打开，无法退货)\n");
    fclose(sp);
    if((sp=fopen("yinliao.txt","w+"))==NULL) 
		{ 
		printf("file can’t be opened"); 
		exit(0); 
		}
		fprintf(sp,"%d %d %d",cola,xuebi,cheng);
		fclose(sp);
	return(c); 
 } 
int maiyl(int c)
{
	FILE *sp; 
	char k[15],a[10];
	int leap=1;
	char i[10]="Kele",j[10]="Xuebi",m[10]="Chengzhi",n[10]="yes",l[10]="no";
	if((sp=fopen("yinliao.txt","r"))==NULL) 
	{ 
    	printf("file can’t be opened"); 
	    exit(0); 
	}
	fscanf(sp,"%d %d %d",&cola,&xuebi,&cheng);
	while(leap=1)
	{
		printf("请问需要哪种饮料(Kele,Xuebi,Chengzhi)?\n");
		gets(k);
		if(strcmp(k,i)==0)
		{
		if(cola==0)
		printf("可乐已无存货，请购买别的饮料。\n");
		else
		cola--;
		}
		if(strcmp(k,j)==0)
		{
		if(xuebi==0)
		printf("雪碧已无存货，请购买别的饮料。\n");
		else
		xuebi--;
		}
		if(strcmp(k,m)==0)
		{
		if(cheng==0)
		printf("橙汁已无存货，请购买别的饮料。\n");
		else
		cheng--;
		}
		printf("请问还需要购买饮料吗？(yes/no)?\n");
		gets(a);
		if(strcmp(a,n)==0)
		leap=1;
		if(strcmp(a,l)==0)
		break;	
	}
	fclose(sp);
	if((sp=fopen("yinliao.txt","w+"))==NULL) 
		{ 
		printf("file can’t be opened"); 
		exit(0); 
		}
		fprintf(sp,"%d %d %d",cola,xuebi,cheng);
		fclose(sp);
	return(c);
}

int chayl(int c)
{
	FILE *sp;
	if((sp=fopen("yinliao.txt","r"))==NULL) 
		{ 
		printf("file can’t be opened"); 
		exit(0); 
		}
	fscanf(sp,"%d %d %d",&cola,&xuebi,&cheng);
	printf("可乐的库存为%d\n",cola);
	printf("雪碧的库存为%d\n",xuebi);
	printf("橙汁的库存为%d\n",cheng);
	if(cola<3)
	printf("可乐库存不足，请尽快进货\n");
	if(xuebi<3)
	printf("雪碧库存不足，请尽快进货\n");
	if(cheng<3)
	printf("橙汁库存不足，请尽快进货\n");
	fclose(sp);
	return(c);
}

int main()
{
	int c=0;
	char a[10];
	char b[10]="mai",d[10]="cha",e[10]="tui";
	printf("请问您想购买饮料、退货还是查询库存？(mai/tui/cha)\n");
	gets(a);
	if(strcmp(a,b)==0)
	{
	maiyl(c);
	chayl(c);
    }
	if(strcmp(a,d)==0)
	chayl(c);
	if(strcmp(a,e)==0)
	{
	tuiyl(c);
	chayl(c);
    }
	return(0);
}
	
