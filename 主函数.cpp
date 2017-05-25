#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

struct ord	//定义消费结构体
{
	char na[30];	//人名
	int n;	//消费日期
	char ti[6];		//消费时段
	char cna[30];	//消费餐厅名称
	int cnum;		//消费餐厅编号
	char dish[10];		//消费餐厅菜品
	char ma1[10];		//消费菜品数量
	char zhu[10];		//消费主食
	int ma2;		//消费主食数量
};

int add(int a[])  //加和函数
{
	int i=1,c=0;
	for(i=1;i<=5;i++)
	c=c+a[i];
	return(c);
 }
  
int add1(int a[],int n)	   //加和函数
{
	int i,c=0;
	for(i=0;i<n;i++)
	c=c+a[i];
	return(c);
}

int scrm(int c)		//输出学生信息
{
	char sex[10],name[15];
	int age,number,i;
	printf("姓名  性别  年龄  学号\n");
	FILE *fp;
	if((fp=fopen("数据文件夹\\student.txt","r"))==NULL)
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


int zheng(int c)		//购买正餐函数
{
	struct ord a;
	FILE  *fp;
  if((fp=fopen("数据文件夹\\buying.txt","a+"))==NULL)
     {
	 puts("can’t be opened"); 
	 exit(0);
	 }
	printf("您的姓名:"); 
	scanf("%s",a.na);
	printf("消费日期(第几天):");
	scanf("%d",&a.n);
	printf("消费时段(Zao/Zhong/Wan):");
	scanf("%s",a.ti);
    printf("食堂名称:");  
	scanf("%s",a.cna);
    printf("食堂编号:");
	scanf("%d",&a.cnum);
    printf("消费全部菜品的名称:"); 
	scanf("%s",a.dish);
    printf("消费菜品的分别数量:");
	scanf("%s",a.ma1);
	printf("消费主食名称:"); 
	scanf("%s",a.zhu);
    printf("消费主食数量:");
	scanf("%d",&a.ma2);
	fprintf(fp,"%s %d %s %s %d %s %s %s %d \n",a.na,a.n,a.ti,a.cna,a.cnum,a.dish,a.ma1,a.zhu,a.ma2);
	fclose(fp);
	return(c);
}


int tuiyl(int c)		//退饮料函数
{
	int cola;
    int xuebi;
    int cheng;
	FILE *sp; 
	char a[10],d[10];
	char b[10]="yes",e[10]="no",i[10]="Kele",j[10]="Xuebi",m[10]="Chengzhi";
	printf("请问饮料是否开封(yes/no)?\n");
	scanf("%s",a);
	if((sp=fopen("数据文件夹\\project\\yinliao.txt","r"))==NULL) 
		{ 
		printf("file can’t be opened"); 
		exit(0); 
		}
	fscanf(sp,"%d %d %d",&cola,&xuebi,&cheng);
	if(strcmp(a,e)==0)
	{
	printf("请问您需要退那种饮料？(Kele/Xuebi/Chengzhi)?\n");
	scanf("%s",d);
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
    if((sp=fopen("数据文件夹\\yinliao.txt","w+"))==NULL) 
		{ 
		printf("file can’t be opened"); 
		exit(0); 
		}
		fprintf(sp,"%d %d %d",cola,xuebi,cheng);
		fclose(sp);
	return(c); 
 }		
 
int maiyl(int c)	//买饮料函数
{
	int cola;
    int xuebi;
    int cheng;
	FILE *sp; 
	char k[15],a[10];
	int leap=1;
	char i[10]="Kele",j[10]="Xuebi",m[10]="Chengzhi",n[10]="yes",l[10]="no";
	if((sp=fopen("数据文件夹\\yinliao.txt","r"))==NULL) 
	{ 
    	printf("file can’t be opened"); 
	    exit(0); 
	}
	fscanf(sp,"%d %d %d",&cola,&xuebi,&cheng);
	while(leap=1)
	{
		printf("请问需要哪种饮料(Kele,Xuebi,Chengzhi)?\n");
		scanf("%s",k);
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
		scanf("%s",a);
		if(strcmp(a,n)==0)
		leap=1;
		if(strcmp(a,l)==0)
		break;	
	}
	fclose(sp);
	if((sp=fopen("数据文件夹\\yinliao.txt","w+"))==NULL) 
		{ 
		printf("file can’t be opened"); 
		exit(0); 
		}
		fprintf(sp,"%d %d %d",cola,xuebi,cheng);
		fclose(sp);
	return(c);
}

int chayl(int c)	//查饮料库存函数
{
	int cola;
    int xuebi;
    int cheng;
	FILE *sp;
	if((sp=fopen("数据文件夹\\yinliao.txt","r"))==NULL) 
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


int cha(int c)		//查询食堂信息函数
{
	char name[20],dish[5][20],flavor[10],type[25];
	int number,price[5];
	FILE *fp;
	if((fp=fopen("数据文件夹\\canteen.txt","r"))==NULL)
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

int lu(int c)		//录入学生信息函数
{
	char sex[6],sname[15];
	int age,snumber,i;
	FILE *fp;
	printf("请输入学生信息，格式为：姓名/性别/年龄/学号\n");
	 	if((fp=fopen("数据文件夹\\student.txt","a+"))==NULL)
     {
	  puts("cannot be opened");
	  exit(0);
	 }
	 fscanf(stdin,"%s%s%d%d",sname,sex,&age,&snumber);
	 fprintf(fp,"\n%s %s %d %d",sname,sex,age,snumber);
	 fclose(fp);
	 return(c);
}

int sttjxf(int c)		//统计食堂销售额函数
{
	struct ord a;
	int i=0,d=0,ZIA[6]={0},ZIB[6]={0},ZIC[6]={0},ZID[6]={0},ZIE[6]={0},TAOA[6]={0},TAOF[6]={0},TAOI[6]={0},TAOJ[6]={0},TAOK[6]={0},YUA[6]={0},YUB[6]={0},YUL[6]={0},YUM[6]={0},YUN[6]={0},DINGD[6]={0},DINGO[6]={0},DINGP[6]={0},DINGQ[6]={0},DINGR[6]={0},ZHIB[6]={0},ZHIC[6]={0},ZHIE[6]={0},ZHIX[6]={0},ZHIY[6]={0}; 
	FILE *sp;
	if((sp=fopen("数据文件夹\\buying.txt","rb"))==NULL)
    {
	puts("can’t be opened"); 
	exit(0); 
	}
	while(feof(sp)==0)
    {
	fscanf(sp,"%s%d%s%s%d%s%s%s%d",a.na,&a.n,a.ti,a.cna,&a.cnum,a.dish,a.ma1,a.zhu,&a.ma2); //读数据
    //fprintf(stdout,"%s %d %s %s %d %s %s %s %d\n",a.na,a.n,a.ti,a.cna,a.cnum,a.dish,a.ma1,a.zhu,a.ma2);	//输出
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
	//printf("紫荆食堂5天内每种菜肴的销售总量分别为A %d份、B %d份、C %d份、D %d份、E %d份\n桃李食堂5天内每种菜肴的销售总量分别为A %d份、F %d份、I %d份、J %d份、K %d份\n玉树食堂5天内每种菜肴的销售总量分别为A %d份、B %d份、L %d份、M %d份、N %d份\n丁香食堂5天内每种菜肴的销售总量分别为D %d份、O %d份、P %d份、Q %d份、R %d份\n芝兰食堂5天内每种菜肴的销售总量分别为B %d份、C %d份、E %d份、X %d份、Y %d份\n",ZIA,ZIB,ZIC,ZID,ZIE,TAOA,TAOF,TAOI,TAOJ,TAOK,YUA,YUB,YUL,YUM,YUN,DINGD,DINGO,DINGP,DINGQ,DINGR,ZHIB,ZHIC,ZHIE,ZHIX,ZHIY);
	//printf("紫荆食堂5天内每种菜肴的销售总额分别为A %d元、B %d元、C %d元、D %d元、E %d元\n桃李食堂5天内每种菜肴的销售总额分别为A %d元、F %d元、I %d元、J %d元、K %d元\n玉树食堂5天内每种菜肴的销售总额分别为A %d元、B %d元、L %d元、M %d元、N %d元\n丁香食堂5天内每种菜肴的销售总额分别为D %d元、O %d元、P %d元、Q %d元、R %d元\n芝兰食堂5天内每种菜肴的销售总额分别为B %d元、C %d元、E %d元、X %d元、Y %d元\n",6*ZIA,5*ZIB,4*ZIC,3*ZID,2*ZIE,6*TAOA,5*TAOF,4*TAOI,3*TAOJ,3*TAOK,6*YUA,5*YUB,5*YUL,7*YUM,9*YUN,3*DINGD,6*DINGO,8*DINGP,8*DINGQ,6*DINGR,5*ZHIB,4*ZHIC,2*ZHIE,10*ZHIX,9*ZHIY);
	for(d=1;d<=5;d++)
	{
	printf("紫荆食堂每道菜第%d天的销售总额为： A %d元、B %d元、C %d元、D %d元、E %d元\n",d,6*ZIA[d],5*ZIB[d],4*ZIC[d],3*ZID[d],2*ZIE[d]);
	printf("桃李食堂每道菜第%d天的销售总额为： A %d元、F %d元、I %d元、J %d元、K %d元\n",d,6*TAOA[d],5*TAOF[d],4*TAOI[d],3*TAOJ[d],3*TAOK[d]);
	printf("玉树食堂每道菜第%d天的销售总额为： A %d元、B %d元、L %d元、M %d元、N %d元\n",d,6*YUA[d],5*YUB[d],5*YUL[d],7*YUM[d],9*YUN[d]);
	printf("丁香食堂每道菜第%d天的销售总额为： D %d元、O %d元、P %d元、Q %d元、R %d元\n",d,3*DINGD[d],6*DINGO[d],8*DINGP[d],8*DINGQ[d],6*DINGR[d]);
	printf("芝兰食堂每道菜第%d天的销售总额为： B %d元、C %d元、E %d元、X %d元、Y %d元\n",d,5*ZHIB[d],4*ZHIC[d],2*ZHIE[d],10*ZHIX[d],9*ZHIY[d]);
    }
    printf("紫荆食堂5天内每种菜肴的销售总额分别为A %d元、B %d元、C %d元、D %d元、E %d元\n桃李食堂5天内每种菜肴的销售总额分别为A %d元、F %d元、I %d元、J %d元、K %d元\n玉树食堂5天内每种菜肴的销售总额分别为A %d元、B %d元、L %d元、M %d元、N %d元\n丁香食堂5天内每种菜肴的销售总额分别为D %d元、O %d元、P %d元、Q %d元、R %d元\n芝兰食堂5天内每种菜肴的销售总额分别为B %d元、C %d元、E %d元、X %d元、Y %d元\n",6*add(ZIA),5*add(ZIB),4*add(ZIC),3*add(ZID),2*add(ZIE),6*add(TAOA),5*add(TAOF),4*add(TAOI),3*add(TAOJ),3*add(TAOK),6*add(YUA),5*add(YUB),5*add(YUL),7*add(YUM),9*add(YUN),3*add(DINGD),6*add(DINGO),8*add(DINGP),8*add(DINGQ),6*add(DINGR),5*add(ZHIB),4*add(ZHIC),2*add(ZHIE),10*add(ZHIX),9*add(ZHIY));
	//printf("紫荆食堂的销售额为%d\n桃李食堂的销售额为%d\n玉树食堂的销售额为%d\n丁香食堂的销售额为%d\n芝兰食堂的销售额为%d\n",ZIALL,TAOALL,YUALL,DINGALL,ZHIALL); 
	return(c); 
}

int xstjxf(int c)		//统计学生消费函数
{
    char name[5][20],dish[5][5][20],flavor[5][10],type[6][15],sname[10][20],sex[10][6];
	int i,j,k,n,m,tempmin,tempmax,low,number[5],price[5][5],pay[10]={0},age[10],snumber[10];
	FILE *fp;
	struct ord a;
	if((fp=fopen("数据文件夹\\canteen.txt","rb"))==NULL)
    {
	puts("can’t be opened"); 
	exit(0); 
	}
    for(i=0;i<=4;i++)
    {
	fscanf(fp,"%s%d%s%s%s%s%s%s%s%d%d%d%d%d",name[i],&number[i],flavor[i],type[i],dish[i][0],dish[i][1],dish[i][2],dish[i][3],dish[i][4],&price[i][0],&price[i][1],&price[i][2],&price[i][3],&price[i][4]); fflush;	//读数据
	}
	fclose(fp); 
	
	if((fp=fopen("数据文件夹\\student.txt","rb"))==NULL)
    {
	puts("can’t be opened"); 
	exit(0); 
	}
    for(j=0;j<10;j++)
    {
	fscanf(fp,"%s%s%d%d",sname[j],sex[j],&age[j],&snumber[j]);//读数据
	}
	fclose(fp); 

	if((fp=fopen("数据文件夹\\buying.txt","rb"))==NULL)
    {
	puts("can’t be opened"); 
	exit(0); 
	}
    while(feof(fp)==0)
    {
	i=0;
	fscanf(fp,"%s%d%s%s%d%s%s%s%d",a.na,&a.n,a.ti,a.cna,&a.cnum,a.dish,a.ma1,a.zhu,&a.ma2); 	//读数据
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
	low=0.1*(add1(pay,10)-tempmin-tempmax)/8;
	for(n=0,j=0;n<10;n++)
	{
		if(pay[n]<=low)
			{
				printf("%s可能为贫困生，请给予帮助\n",sname[n]);
				j=1;
		     }
	}
	if(j==0)
		printf("未找到贫困生\n");
	return(c);
}


int shaicai(int c)		//筛选最热门菜函数
{
	struct ord a;
	int i=0,temp=0,fen[25]={0};
	char cai[20][2]={"A","B","C","D","E","F","I","J","K","L","M","N","O","P","Q","R","X","Y"};
	FILE *sp;
	if((sp=fopen("数据文件夹\\buying.txt","rb"))==NULL)
    {
	puts("can’t be opened"); 
	exit(0); 
	}
	while(feof(sp)==0)
    {
	fscanf(sp,"%s%d%s%s%d%s%s%s%d",a.na,&a.n,a.ti,a.cna,&a.cnum,a.dish,a.ma1,a.zhu,&a.ma2); //读数据
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
		printf("从销售量来看，所有菜中最受欢迎的是%s菜\n",cai[i]);
	
	}

}

struct stud  //定义链表结构 
{  int data;  
   struct stud *next;  
}; 

struct stud *create(struct stud *p)		//创建链表函数
{ 
	int i=0,a[5];
	FILE *fp;
	struct stud *cursor,*head;
	head=p;
	cursor=p;
    while(i<6)//链表1输入数据
    {  
      if((fp=fopen("数据文件夹\\xiaoshouzonge.txt","rb"))==NULL)
    	{
		puts("can’t be opened"); 
		exit(0); 
		}
		fscanf(fp,"%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]); 	//读数据
		fclose(fp);
	  cursor->next=p;//将结点连接到链表上
      cursor=cursor->next ;//移到下一个结点
  	  p=(struct stud *)malloc(sizeof(struct stud *)); 
 	  p->next=NULL; //防止不定指针
      p->data=a[i];
	  i++;
    }
return(head);
}

struct stud *pai_xu(struct stud *head,int n)   //冒泡排序法 
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

struct stud *get_key(struct stud *head,int a[])		//打印排序后各食堂排名
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
	printf("\n依据销售额，%s食堂受欢迎程度排名为第%d名\n",c[m],6-b[m]);
	return(head);
}




int main()
{
	int x=0,y=0;		
	int c=0,p,choice=1;
	printf("欢迎来到“食为天”就餐管理系统\n");
	printf("请问您是\n1.学生\n2.管理员\n"); 
	scanf("%d",&x);		//输入选择
	if(x==1)		//学生功能
	{
		while(choice==1)		//实现回到上一层功能
		{
		printf("同学您好，请选择功能：\n1.学生身份信息录入\n2.食堂菜品查询\n3.消费\n4.食堂受欢迎度排序\n5.最受欢迎菜品\n");
		scanf("%d",&y);
		
		if(y==1)
		{
			lu(c);
			printf("身份信息录入成功！\n"); 
			printf("是否返回上一级？\n1.是\n2.否\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("指令错误\n");
				break;
			}
		}

		else if(y==2)
		{
			printf("学校食堂信息为：食堂名称 食堂编号 风味 早中晚餐情况(M/L/D) 共有菜品(五份) 依次价位\n");
			cha(c);
			printf("是否返回上一级？\n1.是\n2.否\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("指令错误\n");
				break;
			}
		}

		if(y==3)
		{
			printf("欢迎就餐,请问需要:\n1.选购正餐\n2.选购饮料\n");
			scanf("%d",&y);
			if(y==1)
			{
	        printf("欢迎选购正餐\n");
			zheng(c);
			printf("消费成功！\n"); 
			printf("是否返回上一级？\n1.是\n2.否\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("指令错误\n");
				break;
			}
	     	}

	     	else if(y==2)
			{
				printf("请问您想:\n1:购买饮料\n2.退货\n");
				scanf("%d",&y);
				if(y==1)
					{
						maiyl(c);
						printf("消费成功！\n"); 
						printf("是否返回上一级？\n1.是\n2.否\n");
						scanf("%d",&p);
						if(p==1)
						choice=1;
						else if(p==2)
						break;
						else
						{
							printf("指令错误\n");
							break;
						}
					}
				else if(y==2)
					{
						tuiyl(c);
						printf("是否返回上一级？\n1.是\n2.否\n");
						scanf("%d",&p);
						if(p==1)
						choice=1;
						else if(p==2)
						break;
						else
						{
							printf("指令错误\n");
							break;
						}
					}
			} 
		}
		if(y==4)
		{
		  printf("\n同学您好，欢迎来到食堂受欢迎度排名系统！\n");
			int a[5];
			FILE *fp;
			if((fp=fopen("数据文件夹\\xiaoshouzonge.txt","rb"))==NULL)
    			{
					puts("can’t be opened"); 
					exit(0); 
				}
			fscanf(fp,"%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]); 	//从记录表中读数据
			fclose(fp);
			struct stud *head,*head1;
			head=(struct stud *)malloc(sizeof(struct stud *));  
			head->next=NULL; 
			head1=(struct stud *)malloc(sizeof(struct stud *));  
			head1->next=NULL; 
			head=create(head);
			head1=pai_xu(head,5);
			get_key(head1,a);
			printf("是否返回上一级？\n1.是\n2.否\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("指令错误\n");
				break;
			}
		
		}
		
		if(y==5)
		{
		  printf("\n同学您好，欢迎访问最受欢迎菜品调查系统\n");
		  shaicai(c);
		  printf("是否返回上一级？\n1.是\n2.否\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("指令错误\n");
				break;
			}
		}
	}
	}
	if(x==2)		//管理员功能
   {
	while(choice==1)
	{
	   printf("管理员您好，请选择功能:\n1.学生信息查询\n2.饮料库存查询\n3.食堂菜肴销售统计\n4.学生消费统计及贫困生查询\n");
		scanf("%d",&y);
	    if(y==3)
	   {
		printf("\n欢迎访问食堂销售额统计系统！\n");
		sttjxf(c);
		printf("是否返回上一级？\n1.是\n2.否\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("指令错误\n");
				break;
			}
		}
	if(y==4)
	{
	  printf("\n欢迎访问学生消费统计系统！\n");
	  xstjxf(c);
	  printf("是否返回上一级？\n1.是\n2.否\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("指令错误\n");
				break;
			}
	} 
	if(y==2)
	{
		printf("\n欢迎访问饮料库存查询系统！\n");
		chayl(c);
		printf("是否返回上一级？\n1.是\n2.否\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("指令错误\n");
				break;
			}
	}
	if(y==1)
	{
		printf("\n欢迎访问学生信息查询系统！\n");
		scrm(c);
		printf("是否返回上一级？\n1.是\n2.否\n");
			scanf("%d",&p);
			if(p==1)
			choice=1;
			else if(p==2)
			break;
			else
			{
				printf("指令错误\n");
				break;
			}
	}
	}
   }
   	printf("感谢您使用“食为天”饮食管理系统！\n再见！\n");
	return(0);
}
