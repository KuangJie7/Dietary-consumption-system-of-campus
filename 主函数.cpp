#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

struct ord	//�������ѽṹ��
{
	char na[30];	//����
	int n;	//��������
	char ti[6];		//����ʱ��
	char cna[30];	//���Ѳ�������
	int cnum;		//���Ѳ������
	char dish[10];		//���Ѳ�����Ʒ
	char ma1[10];		//���Ѳ�Ʒ����
	char zhu[10];		//������ʳ
	int ma2;		//������ʳ����
};

int add(int a[])  //�Ӻͺ���
{
	int i=1,c=0;
	for(i=1;i<=5;i++)
	c=c+a[i];
	return(c);
 }
  
int add1(int a[],int n)	   //�Ӻͺ���
{
	int i,c=0;
	for(i=0;i<n;i++)
	c=c+a[i];
	return(c);
}

int scrm(int c)		//���ѧ����Ϣ
{
	char sex[10],name[15];
	int age,number,i;
	printf("����  �Ա�  ����  ѧ��\n");
	FILE *fp;
	if((fp=fopen("D:\\2015011921\\�����ļ���\\student.txt","r"))==NULL)
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


int zheng(int c)		//�������ͺ���
{
	struct ord a;
	FILE  *fp;
  if((fp=fopen("D:\\2015011921\\�����ļ���\\buying.txt","a+"))==NULL)
     {
	 puts("can��t be opened"); 
	 exit(0);
	 }
	printf("��������:"); 
	scanf("%s",a.na);
	printf("��������(�ڼ���):");
	scanf("%d",&a.n);
	printf("����ʱ��(Zao/Zhong/Wan):");
	scanf("%s",a.ti);
    printf("ʳ������:");  
	scanf("%s",a.cna);
    printf("ʳ�ñ��:");
	scanf("%d",&a.cnum);
    printf("����ȫ����Ʒ������:"); 
	scanf("%s",a.dish);
    printf("���Ѳ�Ʒ�ķֱ�����:");
	scanf("%s",a.ma1);
	printf("������ʳ����:"); 
	scanf("%s",a.zhu);
    printf("������ʳ����:");
	scanf("%d",&a.ma2);
	fprintf(fp,"%s %d %s %s %d %s %s %s %d \n",a.na,a.n,a.ti,a.cna,a.cnum,a.dish,a.ma1,a.zhu,a.ma2);
	fclose(fp);
	return(c);
}


int tuiyl(int c)		//�����Ϻ���
{
	int cola;
    int xuebi;
    int cheng;
	FILE *sp; 
	char a[10],d[10];
	char b[10]="yes",e[10]="no",i[10]="Kele",j[10]="Xuebi",m[10]="Chengzhi";
	printf("���������Ƿ񿪷�(yes/no)?\n");
	scanf("%s",a);
	if((sp=fopen("D:\\2015011921\\�����ļ���\\project\\yinliao.txt","r"))==NULL) 
		{ 
		printf("file can��t be opened"); 
		exit(0); 
		}
	fscanf(sp,"%d %d %d",&cola,&xuebi,&cheng);
	if(strcmp(a,e)==0)
	{
	printf("��������Ҫ���������ϣ�(Kele/Xuebi/Chengzhi)?\n");
	scanf("%s",d);
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
    if((sp=fopen("D:\\2015011921\\�����ļ���\\yinliao.txt","w+"))==NULL) 
		{ 
		printf("file can��t be opened"); 
		exit(0); 
		}
		fprintf(sp,"%d %d %d",cola,xuebi,cheng);
		fclose(sp);
	return(c); 
 }		
 
int maiyl(int c)	//�����Ϻ���
{
	int cola;
    int xuebi;
    int cheng;
	FILE *sp; 
	char k[15],a[10];
	int leap=1;
	char i[10]="Kele",j[10]="Xuebi",m[10]="Chengzhi",n[10]="yes",l[10]="no";
	if((sp=fopen("D:\\2015011921\\�����ļ���\\yinliao.txt","r"))==NULL) 
	{ 
    	printf("file can��t be opened"); 
	    exit(0); 
	}
	fscanf(sp,"%d %d %d",&cola,&xuebi,&cheng);
	while(leap=1)
	{
		printf("������Ҫ��������(Kele,Xuebi,Chengzhi)?\n");
		scanf("%s",k);
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
		scanf("%s",a);
		if(strcmp(a,n)==0)
		leap=1;
		if(strcmp(a,l)==0)
		break;	
	}
	fclose(sp);
	if((sp=fopen("D:\\2015011921\\�����ļ���\\yinliao.txt","w+"))==NULL) 
		{ 
		printf("file can��t be opened"); 
		exit(0); 
		}
		fprintf(sp,"%d %d %d",cola,xuebi,cheng);
		fclose(sp);
	return(c);
}

int chayl(int c)	//�����Ͽ�溯��
{
	int cola;
    int xuebi;
    int cheng;
	FILE *sp;
	if((sp=fopen("D:\\2015011921\\�����ļ���\\yinliao.txt","r"))==NULL) 
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


int cha(int c)		//��ѯʳ����Ϣ����
{
	char name[20],dish[5][20],flavor[10],type[25];
	int number,price[5];
	FILE *fp;
	if((fp=fopen("D:\\2015011921\\�����ļ���\\canteen.txt","r"))==NULL)
    {
	printf("cannot open file\n"); 
	return(0); 
	}
	while(!feof(fp))
	{
	fscanf(fp,"%s %d %s %s %s %s %s %s %s %d %d %d %d %d\n",name,&number,flavor,type,dish[0],dish[1],dish[2],dish[3],dish[4],&price[0],&price[1],&price[2],&price[3],&price[4]);
	fprintf(stdout,"%s %d %s %s %s %s %s %s %s %d %d %d %d %d\n",name,number,flavor,type,dish[0],dish[1],dish[2],dish[3],dish[4],price[0],price[1],price[2],price[3],price[4]);
    }
    fclose(fp);
	return(c);
}

int lu(int c)		//¼��ѧ����Ϣ����
{
	char sex[6],sname[15];
	int age,snumber,i;
	FILE *fp;
	printf("������ѧ����Ϣ����ʽΪ������/�Ա�/����/ѧ��\n");
	 	if((fp=fopen("D:\\2015011921\\�����ļ���\\student.txt","a+"))==NULL)
     {
	  puts("cannot be opened");
	  exit(0);
	 }
	 fscanf(stdin,"%s%s%d%d",sname,sex,&age,&snumber);
	 fprintf(fp,"\n%s %s %d %d",sname,sex,age,snumber);
	 fclose(fp);
	 return(c);
}

int sttjxf(int c)		//ͳ��ʳ�����۶��
{
	struct ord a;
	int i=0,d=0,ZIA[6]={0},ZIB[6]={0},ZIC[6]={0},ZID[6]={0},ZIE[6]={0},TAOA[6]={0},TAOF[6]={0},TAOI[6]={0},TAOJ[6]={0},TAOK[6]={0},YUA[6]={0},YUB[6]={0},YUL[6]={0},YUM[6]={0},YUN[6]={0},DINGD[6]={0},DINGO[6]={0},DINGP[6]={0},DINGQ[6]={0},DINGR[6]={0},ZHIB[6]={0},ZHIC[6]={0},ZHIE[6]={0},ZHIX[6]={0},ZHIY[6]={0}; 
	FILE *sp;
	if((sp=fopen("D:\\2015011921\\�����ļ���\\buying.txt","rb"))==NULL)
    {
	puts("can��t be opened"); 
	exit(0); 
	}
	while(feof(sp)==0)
    {
	fscanf(sp,"%s%d%s%s%d%s%s%s%d",a.na,&a.n,a.ti,a.cna,&a.cnum,a.dish,a.ma1,a.zhu,&a.ma2); //������
    //fprintf(stdout,"%s %d %s %s %d %s %s %s %d\n",a.na,a.n,a.ti,a.cna,a.cnum,a.dish,a.ma1,a.zhu,a.ma2);	//���
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
	fclose(sp); 
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
	return(c); 
}

int xstjxf(int c)		//ͳ��ѧ�����Ѻ���
{
    char name[5][20],dish[5][5][20],flavor[5][10],type[6][15],sname[10][20],sex[10][6];
	int i,j,k,n,m,tempmin,tempmax,low,number[5],price[5][5],pay[10]={0},age[10],snumber[10];
	FILE *fp;
	struct ord a;
	if((fp=fopen("D:\\2015011921\\�����ļ���\\canteen.txt","rb"))==NULL)
    {
	puts("can��t be opened"); 
	exit(0); 
	}
    for(i=0;i<=4;i++)
    {
	fscanf(fp,"%s%d%s%s%s%s%s%s%s%d%d%d%d%d",name[i],&number[i],flavor[i],type[i],dish[i][0],dish[i][1],dish[i][2],dish[i][3],dish[i][4],&price[i][0],&price[i][1],&price[i][2],&price[i][3],&price[i][4]); fflush;	//������
	}
	fclose(fp); 
	
	if((fp=fopen("D:\\2015011921\\�����ļ���\\student.txt","rb"))==NULL)
    {
	puts("can��t be opened"); 
	exit(0); 
	}
    for(j=0;j<10;j++)
    {
	fscanf(fp,"%s%s%d%d",sname[j],sex[j],&age[j],&snumber[j]);//������
	}
	fclose(fp); 

	if((fp=fopen("D:\\2015011921\\�����ļ���\\buying.txt","rb"))==NULL)
    {
	puts("can��t be opened"); 
	exit(0); 
	}
    while(feof(fp)==0)
    {
	i=0;
	fscanf(fp,"%s%d%s%s%d%s%s%s%d",a.na,&a.n,a.ti,a.cna,&a.cnum,a.dish,a.ma1,a.zhu,&a.ma2); 	//������
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
	printf("%s������%dԪ\n",sname[k],pay[k]);
	fclose(fp);	//���
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
	low=0.1*(add1(pay,10)-tempmin-tempmax)/8;
	for(n=0,j=0;n<10;n++)
	{
		if(pay[n]<=low)
			{
				printf("%s����Ϊƶ��������������\n",sname[n]);
				j=1;
		     }
	}
	if(j==0)
		printf("δ�ҵ�ƶ����\n");
	return(c);
}


int shaicai(int c)		//ɸѡ�����Ų˺���
{
	struct ord a;
	int i=0,temp=0,fen[25]={0};
	char cai[20][2]={"A","B","C","D","E","F","I","J","K","L","M","N","O","P","Q","R","X","Y"};
	FILE *sp;
	if((sp=fopen("D:\\2015011921\\�����ļ���\\buying.txt","rb"))==NULL)
    {
	puts("can��t be opened"); 
	exit(0); 
	}
	while(feof(sp)==0)
    {
	fscanf(sp,"%s%d%s%s%d%s%s%s%d",a.na,&a.n,a.ti,a.cna,&a.cnum,a.dish,a.ma1,a.zhu,&a.ma2); //������
	for(i=0;a.dish[i]!=0;i++)
	{
		if(a.dish[i]==65)
		 fen[0]=fen[0]+a.ma1[i]-48;
		if(a.dish[i]==66)
		 fen[1]=fen[1]+a.ma1[i]-48;
		if(a.dish[i]==67)
		 fen[2]=fen[2]+a.ma1[i]-48;
		if(a.dish[i]==68)
		 fen[3]=fen[3]+a.ma1[i]-48;
		if(a.dish[i]==69)
		 fen[4]=fen[4]+a.ma1[i]-48;
		if(a.dish[i]==70)
		 fen[5]=fen[5]+a.ma1[i]-48;
		if(a.dish[i]==73)
		 fen[6]=fen[6]+a.ma1[i]-48;
		if(a.dish[i]==74)
		 fen[7]=fen[7]+a.ma1[i]-48;
		if(a.dish[i]==75)
		 fen[8]=fen[8]+a.ma1[i]-48;
		if(a.dish[i]==76)
		 fen[9]=fen[9]+a.ma1[i]-48;
		if(a.dish[i]==77)
		 fen[10]=fen[10]+a.ma1[i]-48;
		if(a.dish[i]==78)
		 fen[11]=fen[11]+a.ma1[i]-48;
		if(a.dish[i]==79)
		 fen[12]=fen[12]+a.ma1[i]-48;
		if(a.dish[i]==80)
		 fen[13]=fen[13]+a.ma1[i]-48;
		if(a.dish[i]==81)
		 fen[14]=fen[14]+a.ma1[i]-48;
		if(a.dish[i]==82)
	     fen[15]=fen[15]+a.ma1[i]-48;
		if(a.dish[i]==88)
		 fen[16]=fen[16]+a.ma1[i]-48;;
		if(a.dish[i]==89)
		 fen[17]=fen[17]+a.ma1[i]-48;;
		}
	}
	//printf("%d%d%d",fen[0],fen[1],fen[2]);
	fclose(sp);
	for(i=0,temp=fen[0];i<=16;i++)
	{
		if(temp<fen[i+1])
		   temp=fen[i+1];
	}
	for(i=0;i<=16;i++)
	{
		if(fen[i]==temp)
		printf("�����������������в������ܻ�ӭ����%s��\n",cai[i]);
	
	}

}

struct stud  //��������ṹ 
{  int data;  
   struct stud *next;  
}; 

struct stud *create(struct stud *p)		//����������
{ 
	int i=0,a[5];
	FILE *fp;
	struct stud *cursor,*head;
	head=p;
	cursor=p;
    while(i<6)//����1��������
    {  
      if((fp=fopen("D:\\2015011921\\�����ļ���\\xiaoshouzonge.txt","rb"))==NULL)
    	{
		puts("can��t be opened"); 
		exit(0); 
		}
		fscanf(fp,"%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]); 	//������
		fclose(fp);
	  cursor->next=p;//��������ӵ�������
      cursor=cursor->next ;//�Ƶ���һ�����
  	  p=(struct stud *)malloc(sizeof(struct stud *)); 
 	  p->next=NULL; //��ֹ����ָ��
      p->data=a[i];
	  i++;
    }
return(head);
}

struct stud *pai_xu(struct stud *head,int n)   //ð������ 
{int i,temp=0;  
 struct stud *p;  
 for(i=0;i<n-1;++i)  
   for(p=head;p->next!=NULL;p=p->next)
     if(p->data > p->next->data)  
      {    temp=p->data;  
           p->data=p->next->data;  
           p->next->data=temp;  
      }  
 p=head;  
 while(p->next)  
 {   ;  
     p=p->next;  
   }     
 return(head);
}

struct stud *get_key(struct stud *head,int a[])		//��ӡ������ʳ������
{
	int n,i,m,b[5];
	char c[5][15]={"Zijing","Taoli","Yushu","Dingxiang","Zhilan"};
	struct stud *p;
	for(i=0;i<5;i++)
	{
	   p=head->next;
	   n=0;
	   while(p!=NULL)
		{
			if(p->data!=a[i])
			{
				p=p->next;
				n++;
		     }
		else 
		    {
				b[i]=n+1;
				break;
			 }
	     }
	}
	for(m=0;m<5;m++)
	printf("\n�������۶%sʳ���ܻ�ӭ�̶�����Ϊ��%d��\n",c[m],6-b[m]);
	return(head);
}




int main()
{
	int x=0,y=0;		
	int c=0,p,choice=1;
	printf("��ӭ������ʳΪ�족�Ͳ͹���ϵͳ\n");
	printf("��������\n1.ѧ��\n2.����Ա\n"); 
	scanf("%d",&x);		//����ѡ��
	if(x==1)		//ѧ������
	{
		while(choice==1)		//ʵ�ֻص���һ�㹦��
		{
		printf("ͬѧ���ã���ѡ���ܣ�\n1.ѧ�������Ϣ¼��\n2.ʳ�ò�Ʒ��ѯ\n3.����\n4.ʳ���ܻ�ӭ������\n5.���ܻ�ӭ��Ʒ\n");
		scanf("%d",&y);
		
		if(y==1)
		{
			lu(c);
			printf("�����Ϣ¼��ɹ���\n"); 
			printf("�Ƿ񷵻���һ����\n1.��\n2.��\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("ָ�����\n");
				break;
			}
		}

		else if(y==2)
		{
			printf("ѧУʳ����ϢΪ��ʳ������ ʳ�ñ�� ��ζ ����������(M/L/D) ���в�Ʒ(���) ���μ�λ\n");
			cha(c);
			printf("�Ƿ񷵻���һ����\n1.��\n2.��\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("ָ�����\n");
				break;
			}
		}

		if(y==3)
		{
			printf("��ӭ�Ͳ�,������Ҫ:\n1.ѡ������\n2.ѡ������\n");
			scanf("%d",&y);
			if(y==1)
			{
	        printf("��ӭѡ������\n");
			zheng(c);
			printf("���ѳɹ���\n"); 
			printf("�Ƿ񷵻���һ����\n1.��\n2.��\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("ָ�����\n");
				break;
			}
	     	}

	     	else if(y==2)
			{
				printf("��������:\n1:��������\n2.�˻�\n");
				scanf("%d",&y);
				if(y==1)
					{
						maiyl(c);
						printf("���ѳɹ���\n"); 
						printf("�Ƿ񷵻���һ����\n1.��\n2.��\n");
						scanf("%d",&p);
						if(p==1)
						choice=1;
						else if(p==2)
						break;
						else
						{
							printf("ָ�����\n");
							break;
						}
					}
				else if(y==2)
					{
						tuiyl(c);
						printf("�Ƿ񷵻���һ����\n1.��\n2.��\n");
						scanf("%d",&p);
						if(p==1)
						choice=1;
						else if(p==2)
						break;
						else
						{
							printf("ָ�����\n");
							break;
						}
					}
			} 
		}
		if(y==4)
		{
		  printf("\nͬѧ���ã���ӭ����ʳ���ܻ�ӭ������ϵͳ��\n");
			int a[5];
			FILE *fp;
			if((fp=fopen("D:\\2015011921\\�����ļ���\\xiaoshouzonge.txt","rb"))==NULL)
    			{
					puts("can��t be opened"); 
					exit(0); 
				}
			fscanf(fp,"%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]); 	//�Ӽ�¼���ж�����
			fclose(fp);
			struct stud *head,*head1;
			head=(struct stud *)malloc(sizeof(struct stud *));  
			head->next=NULL; 
			head1=(struct stud *)malloc(sizeof(struct stud *));  
			head1->next=NULL; 
			head=create(head);
			head1=pai_xu(head,5);
			get_key(head1,a);
			printf("�Ƿ񷵻���һ����\n1.��\n2.��\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("ָ�����\n");
				break;
			}
		
		}
		
		if(y==5)
		{
		  printf("\nͬѧ���ã���ӭ�������ܻ�ӭ��Ʒ����ϵͳ\n");
		  shaicai(c);
		  printf("�Ƿ񷵻���һ����\n1.��\n2.��\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("ָ�����\n");
				break;
			}
		}
	}
	}
	if(x==2)		//����Ա����
   {
	while(choice==1)
	{
	   printf("����Ա���ã���ѡ����:\n1.ѧ����Ϣ��ѯ\n2.���Ͽ���ѯ\n3.ʳ�ò�������ͳ��\n4.ѧ������ͳ�Ƽ�ƶ������ѯ\n");
		scanf("%d",&y);
	    if(y==3)
	   {
		printf("\n��ӭ����ʳ�����۶�ͳ��ϵͳ��\n");
		sttjxf(c);
		printf("�Ƿ񷵻���һ����\n1.��\n2.��\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("ָ�����\n");
				break;
			}
		}
	if(y==4)
	{
	  printf("\n��ӭ����ѧ������ͳ��ϵͳ��\n");
	  xstjxf(c);
	  printf("�Ƿ񷵻���һ����\n1.��\n2.��\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("ָ�����\n");
				break;
			}
	} 
	if(y==2)
	{
		printf("\n��ӭ�������Ͽ���ѯϵͳ��\n");
		chayl(c);
		printf("�Ƿ񷵻���һ����\n1.��\n2.��\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("ָ�����\n");
				break;
			}
	}
	if(y==1)
	{
		printf("\n��ӭ����ѧ����Ϣ��ѯϵͳ��\n");
		scrm(c);
		printf("�Ƿ񷵻���һ����\n1.��\n2.��\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("ָ�����\n");
				break;
			}
	}
	}
   }
   	printf("��л��ʹ�á�ʳΪ�족��ʳ����ϵͳ��\n�ټ���\n");
	return(0);
}