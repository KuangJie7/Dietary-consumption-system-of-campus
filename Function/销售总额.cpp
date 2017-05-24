#include<stdio.h>  
#include<stdlib.h>  
struct stud  //定义链表结构 
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
    while(i<6)//链表1输入数据
    {  
      if((fp=fopen("D:\\学习\\程序设计\\project\\xiaoshouzonge.txt","rb"))==NULL)
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
 printf("\n链表排完序后\n");  //输出链表
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

