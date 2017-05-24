#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ord
{
	int n;
	char ti;
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

/*int rentong(int c)
{
	struct ord a;
	FILE *sp;
	int i;
	struct ord stu[i];
	char ming[15],ming1[15];
	if((sp=fopen("buying.txt","r"))==NULL) 
		{ 
		printf("file can¡¯t be opened"); 
		exit(0); 
		}
	fscanf(sp,"%s %d %c %s %d %s %s %s %d",a.na,&a.n,a.ti,a.cna,&a.cnum,a.dish,a.ma1,a.zhu,&a.ma2);
	printf("%s",a.dish);
	fclose(sp);
	return(c);
}
*/
int load(int c)
{ 
   FILE *fp1;   
   int i; 
   struct ord a[i]; 
   if((fp1=fopen("buying.txt","rb"))==NULL)
    { 
	printf("cannot open file\n"); 
	return(0); 
	}
  for (i=0;i<3;i++)
  { 
    fread(&a[i],sizeof(struct ord),1,fp1);
    printf("%s %d %c %s %d %s %s %s %d",a[i].na,a[i].n,a[i].ti,a[i].cna,a[i].cnum,a[i].dish,a[i].ma1,a[i].zhu,a[i].ma2);
  }
  fclose(fp1);
  return(0);
}

int main()
{
	int i;
	int c;
	struct ord a[i];
	load(c);
	return(0);
}
