#include<stdio.h>
#include "headersll.h"

int main()
{
	SLL *headptr=0;
	int op,c;
	while(1)
	{
	 printf("\033[32;4m\nenter your choice\n");
	 printf("\n1)add_begin\n 2)add_end\n 3)add_middle\n 4)print_node\n 5)count_nodes\n 6)save_file\n 7)read_file\n 8)reverse_print\n 9)print_rec\n 10)reverse_rec\n 11)delete_all\n 12)delete_noden\n13)search_node\n 14)sort_node\n 15)reverse_links\n 16)exit\033[0m\n");
	 scanf("%d",&op);
	 
	 switch(op)
	 {
		case 1:add_begin(&headptr);
		break;
		
		case 2:add_end(&headptr);
		break;

		case 3:add_middle(&headptr);
		break;

		case 4:print_node(headptr);
		break;
                
    		case 5:c=count_node(headptr);
		       printf("\ntotal count: %d\n",c);
		break;

		case 6:save_file(headptr);
		break;

		case 7:read_file(&headptr);
		break;

		case 8:reverse_print(headptr);
		break;

		case 9:print_rec(headptr);
		break;

		case 10:reverse_rec(headptr);
		break;

		case 11:delete_all(&headptr);
		break;
		
		case 12:delete_node(&headptr);
		break;
		
		case 13:search_node(headptr);
		break;

		case 14:sort_data(headptr);
		break;

		case 15:reverse_link(&headptr);
		break;

		case 16:exit(0);
		break;

		default:printf("\033[31;1;43m unknown choice\033[0m\n");

	 }
	}
}

//---------------------------------------------add begin----------------------------------//
void add_begin(SLL **ptr)
{
	SLL *new;
	new=malloc(sizeof(SLL));//NODE CREATED
	printf("enter rollno,name and marks\n");
	scanf("%d%s%f",&new->rollno,new->name,&new->marks);
	new->next=*ptr; //update new next addr
	*ptr=new; //update header

}

//------------------------------------------- print node---------------------------------------//
void print_node(SLL *ptr)
{
	printf("\033[34m***************************\n");
	if(ptr==0)
	{
		printf("No records found\n");
		return;
	}
	while(ptr) //till last node
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks); //visit printing
		ptr=ptr->next; //visit next node
	}
	printf("******************\033[0m\n");
}
//-----------------------------------------count nodes----------------------------------------------//
	int count_node(SLL *ptr)
	{
		printf("\033[34m***********************\n");
		int c=0;
		while(ptr) //till last node
		{
			c++;  //counting
			ptr=ptr->next; //visit next node
		}
		return c;

	}
	

//--------------------------------------------save file-------------------------------------------//
void save_file(SLL *ptr)
{
	printf("\033[34m**************************************************\n");
	if(ptr==0)
	{
		printf("no record found\n");
		return;
	}
	FILE *fp;
	fp=fopen("std.txt","w"); //open in write node
	while(ptr)   //till last node
	{     
	fprintf(fp,"%d %s %f",ptr->rollno,ptr->name,ptr->marks);//save the record in file
	fputc('\n',fp);
	ptr=ptr->next; //visit next node
	}
	
	printf("data saved in file\n");
	printf("**********************************************************\033[0m\n");
	fclose(fp); //close the file
}

//----------------------------------------------add end-------------------------------------//

void add_end(SLL **ptr)
{
	SLL *new,*last;
	new=malloc(sizeof(SLL)); //NODE CREATED
	printf("enter rollno,name,marks\n");
	scanf("%d%s%f",&new->rollno,new->name,&new->marks);
	new->next=0; //always zero
	if(*ptr==0) //if no records present
	*ptr=new; //update headptr
	else
		{
		last=*ptr; //holding first node address
		while(last->next) //find last nodes
		last=last->next; //visit next node
		last->next=new; //update last node next address
		}

}


//-----------------------------------read file--------------------------------------//

void read_file(SLL **ptr)
{
	//system("clear");
	SLL *new,*last;
	FILE *fp;
	fp=fopen("std.txt","r");
	if(fp==0)
	{
		printf("file is not present\n");
		return;
	}
	while(1)
	{
		new=malloc(sizeof(SLL)); //node created
		if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks)==-1)
		break;
		new->next=0; //always zero
		if(*ptr==0) //if no records present
			*ptr=new; //update headptr
		else
		{
			last=*ptr; //holding first node address
			while(last->next) //find last node
				last=last->next; //visit next node
			last->next=new; //update last node next address
		}
	}
	fclose(fp);
}

//--------------------------------search node-----------------------------------------//

void search_node(SLL *ptr)
{
if(ptr==0)
	{
		printf("no record found\n");
		return;
	}
char name[20];
int flag=0;
printf("Enter name to search\n");
scanf("%s",name);
while(ptr)
	{
		if(strcmp(name,ptr->name)==0)
		{
			printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
			flag=1;
		}
	ptr=ptr->next;
	}
if(flag==0)
printf("name not fond\n");
}

//--------------------------------reverse print---------------------------------------//

void reverse_print(SLL *ptr)
{
	if(ptr==0)
	{
		printf("no record found\n");
		return;
	}
int i,j,c=count_node(ptr);

SLL *temp;

for(i=0;i<c;i++)
{
	temp=ptr;
	for(j=0;j<c-i-1;j++)
	temp=temp->next;
	printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);

}
}
//---------------------------------add middle----------------------------------//

void add_middle(SLL **ptr)
{
	SLL *new,*last;
	new=malloc(sizeof(SLL)); //node created
	printf("enter rollno name and marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	if((*ptr==0)||(new->rollno<(*ptr)->rollno))
	{
		new->next=*ptr;
		*ptr=new;
	}
	else
	{
		last=*ptr; //always holding 1st node address
		while((last->next!=0)&&(new->rollno>last->next->rollno))
		last=last->next;
		new->next=last->next;
		last->next=new;
	}
}

//--------------------------------print rec [print using recursion]-------------------------------//
void print_rec(SLL *ptr)
{
	if(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);	
		if(ptr->next!=0)
		print_rec(ptr->next);
	
	}
	else
		printf("no records found\n");
}
//----------------------reverse rec [reverse printing using recursion]------------------------//

void reverse_rec(SLL *ptr)
{
	if(ptr)
	{
		if(ptr->next!=0)
		reverse_rec(ptr->next);
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
	}
	else
		printf("no records found\n");
}

//--------------------------------delete all----------------------------------------------------//

void delete_all(SLL **ptr)
{
	if(*ptr==0)
	{
		printf("no records found\n");
		return;
	}
	int c=1;
	SLL *del=*ptr; //holding first node addr
	while(del)
	
	{
		*ptr=del->next; //holding next node address
		sleep(1);
		printf("\033[31m node deleted: %d\n",c++);
		free(del);
		del=*ptr;
	}
	printf("all the records are deleted\n");
}

//-----------------------------delete node--------------------------------------------//

void delete_node(SLL **ptr)
{
	if(*ptr==0)
	{
		printf("no records found\n");
		return;
	}
	int num;
	printf("enter rollno to delete\n");
	scanf("%d",&num);
	SLL *del=*ptr,*prev;
	while(del)
	{
		if(del->rollno==num) //if rollno found
		{
			if(*ptr==del) //if it is first node
			*ptr=del->next;
			else //if it is middle/last
			prev->next=del->next;
			free(del); //delete a node
			return;
	
		}

		prev=del; //follow the del one step back
		del=del->next; //visit next node
		printf("record of rollno %d is deleted\n",num);
	}
printf("rollno not found\n");

}
//------------------------------sort data----------------------------------------//

void sort_data(SLL *ptr)
{
	if(ptr==0)
	{
		printf("no record found\n");
		return;
	}
	int i,j,c=count_node(ptr); //finding count
	SLL *p1,*p2,t;
	p1=p2=ptr; //holding first node addr
	
	for(i=0;i<c-1;i++)
	{
		p2=p1->next;
		for(j=0;j<c-1-i;j++)
		{
			if(p1->rollno>p2->rollno)
			{
				t.rollno=p1->rollno;
				strcpy(t.name,p1->name);
				t.marks=p1->marks;
				p1->rollno=p2->rollno;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;

				p2->rollno=t.rollno;
				strcpy(p2->name,t.name);
				p2->marks=t.marks;
			}

		p2=p2->next;
		}
	p1=p1->next;
	}

}

//------------------------------reverse link------------------------------------//

void reverse_link(SLL **ptr)
{
	if(*ptr==0)
	{
		printf("no records found\n");
		return;
	}
	int i=0,c=count_node(*ptr);  //finding the count
	SLL **p,*t;
	if(c>1)
	{
		p=malloc(sizeof(SLL*)*c);
		t=*ptr; //holding first node address
		while(t)
		{
			p[i++]=t; //store the addr
			t=t->next; //visit next node
		}
	for(i=1;i<c;i++)
		p[i]->next=p[i-1];
		p[0]->next=0;
		*ptr=p[c-1]; //update headptr
	}
}
//----------------------------------------------------------------------------------------------//

