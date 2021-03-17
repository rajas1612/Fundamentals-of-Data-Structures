
#include<stdio.h>  
#include<stdlib.h>  
struct node{  
    int data;  
    struct node *next;   
};  
struct node *head;  
  
void beginInsert ();   
void lastInsert ();  
void randomInsert();  
void display();
int getsize();
void beginDelete();
void lastDelete();
void randomDelete();
void main (){  
    int choice =0;  
    while(choice != 8){   
        printf("\n1.Insert in begining\n2.Insert at the last\n3.Insert at any random location\n4.Show\n5.Delete first node\n6.Delete last node\n7.Delete node at any random location\n8.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice){  
            case 1:  
            beginInsert();      
            break;  
            case 2:  
            lastInsert();         
            break;  
            case 3:  
            randomInsert();       
            break;  
            case 4:  
            display();        
            break;  
            case 5:
            beginDelete();
            break; 
            case 6:
            lastDelete();
            break; 
            case 7:
            randomDelete();
            break; 
            case 8:  
            exit(0);  
            break;
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
void beginInsert()  {  
    struct node *ptr;  
    int item;  
    ptr = (struct node *) malloc(sizeof(struct node *));  
    if(ptr == NULL){  
        printf("\nOVERFLOW");  
    }  
    else{  
        printf("\nEnter value\n");    
        scanf("%d",&item);    
        ptr->data = item;  
        ptr->next = head;  
        head = ptr;  
        printf("\nNode inserted");  
    }     
}  
void lastInsert(){  
    struct node *ptr,*temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL){  
        printf("\nOVERFLOW");     
    }  
    else{  
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL){  
            ptr -> next = NULL;  
            head = ptr;  
            printf("\nNode inserted");  
        }  
        else{  
            temp = head;  
            while (temp -> next != NULL){  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            printf("\nNode inserted");  
        }  
    }  
}  
void randomInsert(){  
    int i,loc,item;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));
    int count=getsize();
    printf("\nEnter the location after which you want to insert ");  
    scanf("\n%d",&loc);
    temp=head; 
    if(ptr == NULL){  
        printf("\nOVERFLOW");  
    }  
    else{  
        if(head == NULL || loc==0){
            beginInsert();
        }
        else if(loc==count){
            lastInsert();
        }
        else{
            printf("\nEnter element value");  
            scanf("%d",&item);  
            ptr->data = item;  

            for(i=1;i<loc;i++){  
                temp = temp->next;  
                if(temp == NULL){  
                    printf("\ncan't insert\n");  
                    return;  
                } 
            }
            ptr ->next = temp ->next;   
            temp ->next = ptr;   
            printf("\nNode inserted");
        }
    }  
}  
void display(){  
    struct node *ptr;  
    ptr = head;
    if(ptr == NULL){  
        printf("Nothing to print");  
    }  
    else{  
        printf("\nprinting values . . . . .\n");   
        while (ptr!=NULL){  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
} 

int getsize(){
    int count=0;
    struct node *ptr;
    ptr=head;
    while(ptr != NULL){
        count++;
        ptr=ptr->next;
    }
    return count;
}


void beginDelete(){  
    struct node *ptr;  
    if(head == NULL){  
        printf("\nList is empty\n");  
    }  
    else{  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("\nNode deleted from the begining\n");  
    }  
}  
void lastDelete(){  
    struct node *ptr,*ptr1;  
    if(head == NULL){  
        printf("\nlist is empty");  
    }  
    else if(head -> next == NULL){  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted\n");  
    }        
    else{  
        ptr = head;   
        while(ptr->next != NULL){  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("\nDeleted Node from the last\n");  
    }     
}  
void randomDelete(){  
    struct node *ptr,*ptr1;  
    int loc,i,count;
    count=getsize();
    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&loc);  
    ptr=head;  
    if(ptr == NULL||loc<1||loc>count){  
        printf("\nCan't delete");  
        return;  
    }
    else{
        if(loc==1){
            beginDelete();
        }
        else if(loc==count){
            lastDelete();
        }
        else{
            for(i=1;i<loc;i++){  
                ptr1 = ptr;       
                ptr = ptr->next; 
            }
        ptr1 ->next = ptr ->next;  
        free(ptr);  
        printf("\nDeleted node %d ",loc+1);
        }
    }  
  
}

  