#include<stdio.h>  
#include<stdlib.h>  
struct stud  //��������ṹ 
{  int data;  
   struct stud *next;  
}; 

struct stud *create(struct stud *p)
{ 
	int i=0,a[5];
	FILE *fp;
	struct stud *cursor,*head;
	head=p;
	cursor=p;
    while(i<6)//����1��������
    {  
      if((fp=fopen("D:\\ѧϰ\\�������\\project\\xiaoshouzonge.txt","rb"))==NULL)
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
 printf("\n�����������\n");  //�������
 p=head;  
 while(p)  
 {   printf("%d ",p->next->data);  
       p=p->next;  
   }     
 return(head);
}

int main()
{
   struct stud *head;
   head=(struct stud *)malloc(sizeof(struct stud *));  
   head->next=NULL; 
   head=create(head);
   head=pai_xu(head,5);
   return(0);
}

