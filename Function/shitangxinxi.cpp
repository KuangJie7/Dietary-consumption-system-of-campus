#include<stdio.h>
#include<stdlib.h>
int tang(int c)
{
	char name[20],dish[5][20],flavor[10],type[6];
	int number,price[5];
	FILE *fp;
	if((fp=fopen("canteen.txt","r"))==NULL)
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

int main()
{
	int c;
	tang(c);
    return(0);
 } 
