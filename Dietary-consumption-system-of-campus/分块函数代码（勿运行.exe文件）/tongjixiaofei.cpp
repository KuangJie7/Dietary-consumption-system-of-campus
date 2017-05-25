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
int pay(int c)
{
	struct ord a;
	FILE *fp;
	if((fp=fopen("buying.txt","r"))==NULL)
    {
	printf("cannot open file\n"); 
	return(0); 
	}
	while(!feof(fp))
	{
	fscanf(fp,"%d %s %s %d %s %s %s %d %s %s\n",&a.n,a.na,a.cna,&a.cnum,a.dish,a.ma1,a.zhu,&a.ma2,a.bav,a.ma3);
	fprintf(stdout,"%d %s %s %d %s %s %s %d %s %s\n",a.n,a.na,a.cna,a.cnum,a.dish,a.ma1,a.zhu,a.ma2,a.bav,a.ma3);
    }
    fclose(fp);
	return(c);
}

int main()
{
	int c;
	pay(c);
    return(0);
 } 
