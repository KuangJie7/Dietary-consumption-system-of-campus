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
	printf("���������Ƿ񿪷�(yes/no)?\n");
	gets(a);
	if((sp=fopen("yinliao.txt","r"))==NULL) 
		{ 
		printf("file can��t be opened"); 
		exit(0); 
		}
	fscanf(sp,"%d %d %d",&cola,&xuebi,&cheng);
	if(strcmp(a,e)==0)
	{
	printf("��������Ҫ���������ϣ�(Kele/Xuebi/Chengzhi)?\n");
	gets(d);
	if(strcmp(d,i)==0)
	 {
	 cola++;
	 printf("�����˻��ɹ�\n");
     }
    if(strcmp(d,j)==0)
	 {
	 xuebi++;
	 printf("ѩ���˻��ɹ�\n");
     }
     if(strcmp(d,m)==0)
	 {
	 cheng++;
	 printf("��֭�˻��ɹ�\n");
     }
    }
    if(strcmp(a,b)==0)
    printf("�˻�ʧ��(�����ѱ��򿪣��޷��˻�)\n");
    fclose(sp);
    if((sp=fopen("yinliao.txt","w+"))==NULL) 
		{ 
		printf("file can��t be opened"); 
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
    	printf("file can��t be opened"); 
	    exit(0); 
	}
	fscanf(sp,"%d %d %d",&cola,&xuebi,&cheng);
	while(leap=1)
	{
		printf("������Ҫ��������(Kele,Xuebi,Chengzhi)?\n");
		gets(k);
		if(strcmp(k,i)==0)
		{
		if(cola==0)
		printf("�������޴�����빺�������ϡ�\n");
		else
		cola--;
		}
		if(strcmp(k,j)==0)
		{
		if(xuebi==0)
		printf("ѩ�����޴�����빺�������ϡ�\n");
		else
		xuebi--;
		}
		if(strcmp(k,m)==0)
		{
		if(cheng==0)
		printf("��֭���޴�����빺�������ϡ�\n");
		else
		cheng--;
		}
		printf("���ʻ���Ҫ����������(yes/no)?\n");
		gets(a);
		if(strcmp(a,n)==0)
		leap=1;
		if(strcmp(a,l)==0)
		break;	
	}
	fclose(sp);
	if((sp=fopen("yinliao.txt","w+"))==NULL) 
		{ 
		printf("file can��t be opened"); 
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
		printf("file can��t be opened"); 
		exit(0); 
		}
	fscanf(sp,"%d %d %d",&cola,&xuebi,&cheng);
	printf("���ֵĿ��Ϊ%d\n",cola);
	printf("ѩ�̵Ŀ��Ϊ%d\n",xuebi);
	printf("��֭�Ŀ��Ϊ%d\n",cheng);
	if(cola<3)
	printf("���ֿ�治�㣬�뾡�����\n");
	if(xuebi<3)
	printf("ѩ�̿�治�㣬�뾡�����\n");
	if(cheng<3)
	printf("��֭��治�㣬�뾡�����\n");
	fclose(sp);
	return(c);
}

int main()
{
	int c=0;
	char a[10];
	char b[10]="mai",d[10]="cha",e[10]="tui";
	printf("�������빺�����ϡ��˻����ǲ�ѯ��棿(mai/tui/cha)\n");
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
	
