#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    struct node *next;
};

struct node *newNode()
{
    return (struct node *)malloc(sizeof(struct node *));
}

void setLink(struct node *current,struct node *nextNode)
{
    current->next = nextNode;
}

void setValue(struct node *current,int value)
{
    current->value=value;
}

void insertBack(struct node **start,struct node *newNode)
{
    struct node *temp=*start;
    if(temp==NULL)
        *start=newNode;
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void insertFront(struct node **start,struct node *newNode)
{
    struct node *temp=*start;
    if(temp==NULL)
    {
        *start=newNode;
    }
    else
    {
        setLink(newNode,*start);
        *start=newNode;
    }
}
int sizeOfLinkedList(struct node *start)
{
    int temp=0;
    while(start!=NULL)
    {
        start=start->next;
        temp++;
    }
    return temp;
}
void insertAt(struct node **start,struct node *newNode,int pos)
{
    if(sizeOfLinkedList(*start)<pos)
    {
        insertBack(start,newNode);
    }
    else
    {
        int count=0;
        if(pos==0)
        {
            insertFront(start,newNode);
        }
        else
        {
            struct node *temp1=*start,*temp2=*start;
            while(count<pos)
            {
                temp1=temp1->next;
                if(count!=0)
                    temp2=temp2->next;
                count++;
            }
            temp2->next=newNode;
            newNode->next = temp1;
        }
    }
}

void printLinkedList(struct node *start)
{
    while(start!=NULL)
    {
        cout<<"->"<<start->value<<" ";
        start=start->next;
    }
    cout<<endl;
}

struct node *valuAt(struct node *start,int index)
{
    int count=0;
    if(sizeOfLinkedList(start)<index)
        return NULL;
    else
    {
        while(count<index)
        {
            start=start->next;
            count++;
        }
        return start;
    }
}

void deleteFront(struct node **start)
{
    if(*start==NULL)
        return;
    struct node *temp=*start;
    *start=temp->next;
}
void deleteBack(struct node **start)
{
    struct node *temp=*start;
    if(temp->next==NULL)
    {
        *start=NULL;
        return;
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}

void deleteAt(struct node **start,int index)
{
    struct node *temp1=*start,*temp2=*start;
    int count=0;
    if(sizeOfLinkedList(*start)<index)
        return;
    else
    {
        while(count<index)
        {
            temp1=temp1->next;
            if(count!=0)
                temp2=temp2->next;
            count++;
        }
        temp2->next=temp1->next;
    }
}
int main()
{
    int n,val;
    cin>>n;
    struct node *temp,*start=NULL,*start2=NULL;
    while(n--)
    {
        cin>>val;
        temp=newNode();
        setLink(temp,NULL);
        setValue(temp,val);
        insertBack(&start,temp);
        temp=newNode();
        setLink(temp,NULL);
        setValue(temp,val);
        insertFront(&start2,temp);
    }
    cout<<sizeOfLinkedList(start)<<endl;
    temp=newNode();
    setLink(temp,NULL);
    setValue(temp,1000);
    insertAt(&start,temp,3);
    deleteAt(&start2,3);
    deleteFront(&start);
    deleteBack(&start);
    cout<<sizeOfLinkedList(start)<<endl;
    printLinkedList(start);
    printLinkedList(start2);
    return 0;
}