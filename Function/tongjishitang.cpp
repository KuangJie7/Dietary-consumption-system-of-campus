#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int add(int a[])
{
	int i=1,c=0;
	for(i=1;i<=5;i++)
	c=c+a[i];
	return(c);
 } 

int main()
{
	//int c;
	//zheng(c);
	FILE *fp;
	struct ord a;
	struct ord *f;
	int i=0,d=0,ZIA[6]={0},ZIB[6]={0},ZIC[6]={0},ZID[6]={0},ZIE[6]={0},TAOA[6]={0},TAOF[6]={0},TAOI[6]={0},TAOJ[6]={0},TAOK[6]={0},YUA[6]={0},YUB[6]={0},YUL[6]={0},YUM[6]={0},YUN[6]={0},DINGD[6]={0},DINGO[6]={0},DINGP[6]={0},DINGQ[6]={0},DINGR[6]={0},ZHIB[6]={0},ZHIC[6]={0},ZHIE[6]={0},ZHIX[6]={0},ZHIY[6]={0}; 
	if((fp=fopen("buying.txt","rb"))==NULL)
    {
	puts("can��t be opened"); 
	exit(0); 
	}
    while(feof(fp)==0)
    {
	fscanf(fp,"%s%d%s%s%d%s%s%s%d",a.na,&a.n,a.ti,a.cna,&a.cnum,a.dish,a.ma1,a.zhu,&a.ma2); 	//������
    fprintf(stdout,"%s %d %s %s %d %s %s %s %d\n",a.na,a.n,a.ti,a.cna,a.cnum,a.dish,a.ma1,a.zhu,a.ma2);	//���
    if(a.cnum==1)
    {
		d=a.n;
		for(i=0;a.dish[i]!=0;i++)
		{
			if(a.dish[i]==65)
			  ZIA[d]=ZIA[d]+a.ma1[i]-48;
			if(a.dish[i]==66)
			  ZIB[d]=ZIB[d]+a.ma1[i]-48;
			if(a.dish[i]==67)
			  ZIC[d]=ZIC[d]+a.ma1[i]-48;
			if(a.dish[i]==68)
			  ZID[d]=ZID[d]+a.ma1[i]-48;
			if(a.dish[i]==69)
			  ZIE[d]=ZIE[d]+a.ma1[i]-48;
		}
	}
	if(a.cnum==2)
    {
    	d=a.n;
		for(i=0;a.dish[i]!=0;i++)
		{
			if(a.dish[i]==65)
			  TAOA[d]=TAOA[d]+a.ma1[i]-48;
			if(a.dish[i]==70)
			  TAOF[d]=TAOF[d]+a.ma1[i]-48;
			if(a.dish[i]==73)
			  TAOI[d]=TAOI[d]+a.ma1[i]-48;
			if(a.dish[i]==74)
			  TAOJ[d]=TAOJ[d]+a.ma1[i]-48;
			if(a.dish[i]==75)
			  TAOK[d]=TAOK[d]+a.ma1[i]-48;
		}
	}
	if(a.cnum==3)
    {
    	d=a.n;
		for(i=0;a.dish[i]!=0;i++)
		{
			if(a.dish[i]==65)
			  YUA[d]=YUA[d]+a.ma1[i]-48;
			if(a.dish[i]==66)
			  YUB[d]=YUB[d]+a.ma1[i]-48;
			if(a.dish[i]==76)
			  YUL[d]=YUL[d]+a.ma1[i]-48;
			if(a.dish[i]==77)
			  YUN[d]=YUN[d]+a.ma1[i]-48;
			if(a.dish[i]==78)
			  YUM[d]=YUM[d]+a.ma1[i]-48;
		}
	}
	if(a.cnum==4)
    {
    	d=a.n;
		for(i=0;a.dish[i]!=0;i++)
		{
			if(a.dish[i]==68)
			  DINGD[d]=DINGD[d]+a.ma1[i]-48;
			if(a.dish[i]==79)
			  DINGO[d]=DINGO[d]+a.ma1[i]-48;
			if(a.dish[i]==80)
			  DINGP[d]=DINGP[d]+a.ma1[i]-48;
			if(a.dish[i]==81)
			  DINGQ[d]=DINGQ[d]+a.ma1[i]-48;
			if(a.dish[i]==82)
			  DINGR[d]=DINGR[d]+a.ma1[i]-48;
		}
	}
	if(a.cnum==5)
    {
    	d=a.n;
		for(i=0;a.dish[i]!=0;i++)
		{
			if(a.dish[i]==66)
			  ZHIB[d]=ZHIB[d]+a.ma1[i]-48;
			if(a.dish[i]==67)
			  ZHIC[d]=ZHIC[d]+a.ma1[i]-48;
			if(a.dish[i]==69)
			  ZHIE[d]=ZHIE[d]+a.ma1[i]-48;
			if(a.dish[i]==88)
			  ZHIX[d]=ZHIX[d]+a.ma1[i]-48;
			if(a.dish[i]==89)
			  ZHIY[d]=ZHIY[d]+a.ma1[i]-48;
		}
	}
	}
	fclose(fp); 
	/*ZIALL=ZIA*6+ZIB*5+ZIC*4+ZID*3+ZIE*2;
	TAOALL=TAOA*6+TAOF*5+TAOI*4+TAOJ*3+TAOK*3;
	YUALL=YUA*6+YUB*5+YUL*5+YUM*7+YUN*9;
	DINGALL=DINGD*3+DINGO*6+DINGP*8+DINGQ*8+DINGR*6;
	ZHIALL=ZHIB*5+ZHIC*4+ZHIE*2+ZHIX*10+ZHIY*9;*/ 
	//printf("�Ͼ�ʳ��5����ÿ�ֲ��ȵ����������ֱ�ΪA %d�ݡ�B %d�ݡ�C %d�ݡ�D %d�ݡ�E %d��\n����ʳ��5����ÿ�ֲ��ȵ����������ֱ�ΪA %d�ݡ�F %d�ݡ�I %d�ݡ�J %d�ݡ�K %d��\n����ʳ��5����ÿ�ֲ��ȵ����������ֱ�ΪA %d�ݡ�B %d�ݡ�L %d�ݡ�M %d�ݡ�N %d��\n����ʳ��5����ÿ�ֲ��ȵ����������ֱ�ΪD %d�ݡ�O %d�ݡ�P %d�ݡ�Q %d�ݡ�R %d��\n֥��ʳ��5����ÿ�ֲ��ȵ����������ֱ�ΪB %d�ݡ�C %d�ݡ�E %d�ݡ�X %d�ݡ�Y %d��\n",ZIA,ZIB,ZIC,ZID,ZIE,TAOA,TAOF,TAOI,TAOJ,TAOK,YUA,YUB,YUL,YUM,YUN,DINGD,DINGO,DINGP,DINGQ,DINGR,ZHIB,ZHIC,ZHIE,ZHIX,ZHIY);
	//printf("�Ͼ�ʳ��5����ÿ�ֲ��ȵ������ܶ�ֱ�ΪA %dԪ��B %dԪ��C %dԪ��D %dԪ��E %dԪ\n����ʳ��5����ÿ�ֲ��ȵ������ܶ�ֱ�ΪA %dԪ��F %dԪ��I %dԪ��J %dԪ��K %dԪ\n����ʳ��5����ÿ�ֲ��ȵ������ܶ�ֱ�ΪA %dԪ��B %dԪ��L %dԪ��M %dԪ��N %dԪ\n����ʳ��5����ÿ�ֲ��ȵ������ܶ�ֱ�ΪD %dԪ��O %dԪ��P %dԪ��Q %dԪ��R %dԪ\n֥��ʳ��5����ÿ�ֲ��ȵ������ܶ�ֱ�ΪB %dԪ��C %dԪ��E %dԪ��X %dԪ��Y %dԪ\n",6*ZIA,5*ZIB,4*ZIC,3*ZID,2*ZIE,6*TAOA,5*TAOF,4*TAOI,3*TAOJ,3*TAOK,6*YUA,5*YUB,5*YUL,7*YUM,9*YUN,3*DINGD,6*DINGO,8*DINGP,8*DINGQ,6*DINGR,5*ZHIB,4*ZHIC,2*ZHIE,10*ZHIX,9*ZHIY);
	for(d=1;d<=5;d++)
	{
	printf("�Ͼ�ʳ��ÿ���˵�%d��������ܶ�Ϊ�� A %dԪ��B %dԪ��C %dԪ��D %dԪ��E %dԪ\n",d,6*ZIA[d],5*ZIB[d],4*ZIC[d],3*ZID[d],2*ZIE[d]);
	printf("����ʳ��ÿ���˵�%d��������ܶ�Ϊ�� A %dԪ��F %dԪ��I %dԪ��J %dԪ��K %dԪ\n",d,6*TAOA[d],5*TAOF[d],4*TAOI[d],3*TAOJ[d],3*TAOK[d]);
	printf("����ʳ��ÿ���˵�%d��������ܶ�Ϊ�� A %dԪ��B %dԪ��L %dԪ��M %dԪ��N %dԪ\n",d,6*YUA[d],5*YUB[d],5*YUL[d],7*YUM[d],9*YUN[d]);
	printf("����ʳ��ÿ���˵�%d��������ܶ�Ϊ�� D %dԪ��O %dԪ��P %dԪ��Q %dԪ��R %dԪ\n",d,3*DINGD[d],6*DINGO[d],8*DINGP[d],8*DINGQ[d],6*DINGR[d]);
	printf("֥��ʳ��ÿ���˵�%d��������ܶ�Ϊ�� B %dԪ��C %dԪ��E %dԪ��X %dԪ��Y %dԪ\n",d,5*ZHIB[d],4*ZHIC[d],2*ZHIE[d],10*ZHIX[d],9*ZHIY[d]);
    }
    printf("�Ͼ�ʳ��5����ÿ�ֲ��ȵ������ܶ�ֱ�ΪA %dԪ��B %dԪ��C %dԪ��D %dԪ��E %dԪ\n����ʳ��5����ÿ�ֲ��ȵ������ܶ�ֱ�ΪA %dԪ��F %dԪ��I %dԪ��J %dԪ��K %dԪ\n����ʳ��5����ÿ�ֲ��ȵ������ܶ�ֱ�ΪA %dԪ��B %dԪ��L %dԪ��M %dԪ��N %dԪ\n����ʳ��5����ÿ�ֲ��ȵ������ܶ�ֱ�ΪD %dԪ��O %dԪ��P %dԪ��Q %dԪ��R %dԪ\n֥��ʳ��5����ÿ�ֲ��ȵ������ܶ�ֱ�ΪB %dԪ��C %dԪ��E %dԪ��X %dԪ��Y %dԪ\n",6*add(ZIA),5*add(ZIB),4*add(ZIC),3*add(ZID),2*add(ZIE),6*add(TAOA),5*add(TAOF),4*add(TAOI),3*add(TAOJ),3*add(TAOK),6*add(YUA),5*add(YUB),5*add(YUL),7*add(YUM),9*add(YUN),3*add(DINGD),6*add(DINGO),8*add(DINGP),8*add(DINGQ),6*add(DINGR),5*add(ZHIB),4*add(ZHIC),2*add(ZHIE),10*add(ZHIX),9*add(ZHIY));
	//printf("�Ͼ�ʳ�õ����۶�Ϊ%d\n����ʳ�õ����۶�Ϊ%d\n����ʳ�õ����۶�Ϊ%d\n����ʳ�õ����۶�Ϊ%d\n֥��ʳ�õ����۶�Ϊ%d\n",ZIALL,TAOALL,YUALL,DINGALL,ZHIALL); 
	return(0); 
}

