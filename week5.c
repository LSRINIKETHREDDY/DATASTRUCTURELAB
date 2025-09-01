#include<stdio.h>
#define max 4

int queue[max];
int front=-1,rear=-1;

int isFull()
{
	if((front==0 && rear==max-1)||(rear+1==front))
	    return 1;
	return 0;
}

int isempty()
{
	if(front==-1)
	    return 1;
	return 0;
}

void insert()
{
	int num;
	printf("\n enter the number to be inserted in the queue:");
	scanf("%d",&num);
	
	if(isFull())
	{
		printf("\noverflow");
		return;
	}
	if(isempty())
	{
		front=rear=0;
	}
	else if(rear==max-1 && front !=0)
	{
		rear=0;
	}
	else
	{
		rear++;
	}
	queue[rear]=num;
}

int delete_element()
{
	int val;
	if(isempty())
	{
		printf("\nunderflow");
		return -1;
	}
	val=queue[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	else if(front==max-1)
	{
		front=0;
	}
	else
	{
		front++;
	}
	return val;
}

int peek()
{
	if(isempty())
	{
		printf("\n queue is empty");
		return -1;
	}
	else
	{
		return queue[front];
	}
}

void display()
{
	int i;
	
	if(isempty())
	{
		printf("\nqueue is empty");
		return;
	}
	printf("\n queue elements are: ");
	if(front<=rear)
	{
		for(i=front;i<=rear;i++)
		    printf("\t%d",queue[i]);
    }
    else
    {
    	for(i=front;i<max;i++)
    	    printf("\t%d",queue[i]);
    	for(i=0;i<=rear;i++)
		  printf("\t%d",queue[i]);  
	}
}

int main()
{
   int option,val;
   do
   {
	printf("\nMAIN MENU");
	printf("\n1.Insert an element");
	printf("\n2.Delete an element");
	printf("\n3.peek");
	printf("\n4.display the queue");
	printf("\n5.exit");
	printf("\nenter your option: ");
	scanf("%d",&option);
	
	switch(option)
	  {
	    case 1:
		  insert();
		  break;
		case 2:
		    val= delete_element();
		    if(val!=-1)
		        printf("\n the number deleted is : %d",val);
			break;
	    case 3:
			val=peek();
			if(val!=-1)
			    printf("\n the first value in queue is: %d", val);
			break;
		case 4:
			display();
			break;
	  }
   }
while(option!=5);
return 0;
}
