#include<stdio.h>
#include <stdlib.h>
int main()
{
	char name[20],dish[5][20],flavor[10],type[6];
	int i,number,price[5];
	printf("������ʳ����Ϣ����ʽΪ������ ��� ��ζ �������(M/L/D) ��Ʒ(���) ���μ�λ \n");
	FILE *fp;
	if((fp=fopen("canteen.txt","w"))==NULL)
     {
	  puts("cannot be opened");
	  exit(0);
	 }
	 fscanf(stdin,"%s%d%s%s%s%s%s%s%s%d%d%d%d%d",name,&number,flavor,type,&dish[0],&dish[1],&dish[2],&dish[3],&dish[4],&price[0],&price[1],&price[2],&price[3],&price[4]);
	 fprintf(fp,"%s %d %s %s %s %s %s %s %s %d %d %d %d %d\n",name,number,flavor,type,dish[0],dish[1],dish[2],dish[3],dish[4],price[0],price[1],price[2],price[3],price[4]);
	 fclose(fp);
	  for(i=1;i<=4;i++)
	 {
	 	if((fp=fopen("canteen.txt","a"))==NULL)
     {
	  puts("cannot be opened");
	  exit(0);
	 }
	 fscanf(stdin,"%s%d%s%s%s%s%s%s%s%d%d%d%d%d",name,&number,flavor,type,&dish[0],&dish[1],&dish[2],&dish[3],&dish[4],&price[0],&price[1],&price[2],&price[3],&price[4]);
	 fprintf(fp,"%s %d %s %s %s %s %s %s %s %d %d %d %d %d\n",name,number,flavor,type,dish[0],dish[1],dish[2],dish[3],dish[4],price[0],price[1],price[2],price[3],price[4]);
	 fclose(fp);
	 }
	 return(0);
} 
