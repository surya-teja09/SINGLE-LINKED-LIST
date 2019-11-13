#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;
void add_at_beg(int);
void add_at_last(int);
void display();
int list_count();
int position_list(int);
void delete_at_beg();
void delete_list();
void delete_at_last();
void add_after_node(int,int);
void add_before_node(int,int);
void delete_par_node(int);
void create_list_at_end(int *,int);
void create_list_at_beg(int *,int);
void reverse_list();
void add_node_at_mid(int);
//struct node *start=NULL;
#define A_ELE 4
int count=0;
void main()
{
	int opt,num,pos,val;
	int arr[A_ELE],i;
	while(1)
	{
		printf("1.create list at end\n2.add at beginning\n3.add at last\n4.count\n5.search\n6.add after a node\n7.delete particular node\n8.delete first node\n9.delete last node\n10.delete entire list\n11.reverse the list\n12.display\n13.add before a node\n14.create list at beginning\n15.add node at the middle of the list\n16.exit\n");
		printf("select the option\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: //int arr[4];
				//int i;
				//int n;
				//printf("enter number of elements to be inserted\n");
				//scanf("%d",&n);
				//int arr[n];
				printf("enter array elements\n");
				for(i=0;i<A_ELE;i++)
					scanf("%d",&arr[i]);
				create_list_at_end(arr,A_ELE);
				//count=count+4;
				break;

			case 2: printf("enter the input\n");
				scanf("%d",&num);
				add_at_beg(num);
				//count++;
				break;

			case 3: printf("enter the input\n");
				scanf("%d",&num);
				add_at_last(num);
				//count++;
				break;

			case 4: count=list_count();
				printf("number of nodes -%d\n",count);
				break;

			case 5: printf("enter the input\n");
				scanf("%d",&num);
				pos=position_list(num);
				printf("%d\n",pos);
				break;

			case 6: printf("enter the number \n");
				scanf("%d%d",&num,&val);
				add_after_node(num,val);
				//count++;
				break;

			case 7: printf("enter the number \n");
				scanf("%d",&num);
				delete_par_node(num);
				//count--;
				break;

			case 8: delete_at_beg();
				//count--;
				break;

			case 9: delete_at_last();
				//count--;
				break;

			case 10: delete_list();
				 //count=0;
			 	 break;

			case 11: reverse_list();
				 break;

			case 12: printf("displaying the elements in the list\n");
				 display();
				 break;

			case 13: printf("enter the number\n");
				 scanf("%d%d",&num,&val);
				 add_before_node(num,val);
				 //count++;
				 break;

			case 14: printf("enter array elements\n");
				 for(i=0;i<A_ELE;i++)
					 scanf("%d",&arr[i]);
				 create_list_at_beg(arr,A_ELE);
				 //count=count+4;
				 break;


			case 15: printf("enter a number\n");
				 scanf("%d",&val);
				 add_node_at_mid(val);
				 break;

			case 16: exit(0);

			default: printf("enter the valid input\n");
				 break;
		}
	}
}
		

				//add at beginning function

void add_at_beg(int num)
{
	struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->link=start;
	start=ptr;
	//printf("total number of nodes:-%d\n",count);
	count=list_count();
}
                                 
                                //add at last function

void add_at_last(int num)
{
	struct node *temp;
	struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=num;
	//ptr->link=NULL;
	if(start==NULL)
	{
		start=ptr;
		return;
	}
	temp=start;
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=ptr;
	//printf("total numbeer of nodes:-%d\n",count);
	count=list_count();
}

			      //display function


void display()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=start;
	while(temp!=NULL)
	{
		printf("%d \n",temp->data);
		temp=temp->link;
	}
}

			     //count the number of nodes in given list


int list_count()
{
	int count=0;
	struct node *temp;
	if(start==NULL)
	{
		printf("list is empty\n");
		return count;
	}
	temp=start;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
}

				// search for a particular element 

int position_list(int num)
{
	int pos=0;
	struct node *temp;
	temp=start;
	if(temp==NULL)
	{
		printf("list is empty\n");
		return 0;
	}
	while(temp!=NULL)
	{
		pos++;
		if(temp->data==num)
			return pos;
		temp=temp->link;
	}
	return 0;
}
						
			         //delete at beginning


void delete_at_beg()
{
	struct node *temp;
	temp=start;
	if(temp==NULL)
	{
		printf("list is empty \n");
		return;
	}
	start=start->link;
	free(temp);
	count=list_count();
}

				//delete entire list


void delete_list()
{
	struct node *temp;
	while(start!=NULL)
	{
		temp=start;
		start=start->link;
		free(temp);
	}
	count=list_count();
}


			//delete at last


void delete_at_last()
{
	struct node *ptr,*temp;
	//ptr=start;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	ptr=start;
	if(start->link==NULL)
	{
		free(ptr);
		start=NULL;
		count=list_count();
		return;
	}
	//ptr=start;
	while(ptr->link!=NULL)
	{
		temp=ptr;
		ptr=ptr->link;
		//free(ptr);
		//temp->link=NULL;
	}
	free(ptr);
	temp->link=NULL;
	count=list_count();
}


				// add after a particular node


void add_after_node(int num,int val)
{
	struct node *temp,*ptr;
	temp=start;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			ptr=(struct node *)malloc(1*sizeof(struct node));
			ptr->data=val;
			ptr->link=temp->link;
			temp->link=ptr;
			count=list_count();
			return;
		}
		temp=temp->link;
	}
	printf("element not found\n");
}


				//delete particular node


void delete_par_node(int num)
{
	struct node *ptr,*prev;
	ptr=start;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	while(ptr!=NULL)
	{
		if(start->data==num)
		{
			start=start->link;
			free(ptr);
			count=list_count();
			return;
		}
		if(ptr->data==num)
		{
			if(ptr->link==NULL)
			{
				prev->link=NULL;
				free(ptr);
				count=list_count();
				return;
			}
			prev->link=ptr->link;
			free(ptr);
			count=list_count();
			return;
		}
		prev=ptr;
		ptr=ptr->link;
	}
	count=list_count();
	printf("element not found\n");
}


				//create list


void create_list_at_end(int *iptr,int n)
{
	int i;
	struct node *l_start,*temp;
	struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=iptr[0];
	ptr->link=NULL;
	l_start=temp=ptr;
	for(i=1;i<n;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		ptr->data=iptr[i];
		ptr->link=temp->link;
		temp->link=ptr;
		temp=ptr;
	}
	if(start==NULL)
	{
		start=l_start;
		count=list_count();
		return;
	}
	temp=start;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=l_start;
	count=list_count();
}



			//reverse of a the list


void reverse_list()
{
	int i,j,k,temp,len;
	struct node *p,*q;
	len=list_count();
	p=q=start;
	i=0;
	j=len-1;
	while(i<j)
	{
		k=0;
		while(k<j)
		{
			q=q->link;
			k++;
		}
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		i++;
		j--;
		p=p->link;
		q=start;
	}
	count=list_count();
}


				// add before a node


void add_before_node(int num,int val)
{
	struct node *temp,*ptr,*temp1;
	temp1=temp=start;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			ptr=(struct node *)malloc(1*sizeof(struct node));
			ptr->data=val;
			ptr->link=temp;
			temp1->link=ptr;
			count=list_count();
			return;
		}
		temp1=temp;
		temp=temp->link;
	}
	count=list_count();
	printf("element not found\n");
}


     				//create list at beginning



void create_list_at_beg(int *iptr,int n)
{
	int i;
	struct node *l_start,*temp;
	struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=iptr[0];
	ptr->link=NULL;
	l_start=temp=ptr;
	for(i=1;i<n;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		ptr->data=iptr[i];
		ptr->link=temp->link;
		temp->link=ptr;
		temp=ptr;
	}
	if(start==NULL)
	{
		start=l_start;
		count=list_count();
		return;
	}
	temp->link=start;
	start=l_start;
	count=list_count();
}


				
				//add node at the middle of the list

void add_node_at_mid(int val)
{
	int i,j;
	struct node *temp,*ptr,*prev;
	j=count/2;
	prev=temp=start;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(start->link==NULL)
	{
		printf("list contains only single node\n");
		return;
	}
	if(count%2==0)
	{
	for(i=0;i<j;i++)
	{
		prev=temp;
		temp=temp->link;
	}
	ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=val;
	ptr->link=prev->link;
	prev->link=ptr;
	count=list_count();
	}
	else
	{
		j++;
	for(i=0;i<j;i++)
	{
		prev=temp;
		temp=temp->link;
	}
	ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=val;
	ptr->link=prev->link;
	prev->link=ptr;
	count=list_count();
	}

}

