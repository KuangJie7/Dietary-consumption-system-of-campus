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
	 puts("can��t be opened"); 
	 exit(0);
	 }
	printf("���Ѽ�¼�Ǽǿ�ʼ\n");
	printf("��������(�ڼ���):");
	scanf("%d",&a.n);
	fflush(stdin);
    printf("�������:"); 
	gets(a.na);
    printf("ʳ������:");  
	gets(a.cna);
    printf("ʳ�ñ��:");
	scanf("%d",&a.cnum);
	fflush(stdin);
    printf("���Ѳ�Ʒ����:"); 
	gets(a.dish);
    printf("���Ѳ�Ʒ����:");
	gets(a.ma1);
	printf("������ʳ����:"); 
	gets(a.zhu);
    printf("������ʳ����:");
	scanf("%d",&a.ma2);
	fflush(stdin);
	printf("������������:"); 
	gets(a.bav);
    printf("������������:");
	gets(a.ma3);
	fprintf(fp,"%d %s %s %d %s %s %s %d %s %s\n",a.n,a.na,a.cna,a.cnum,a.dish,a.ma1,a.zhu,a.ma2,a.bav,a.ma3);
	fclose(fp);
	return(0);
} 
