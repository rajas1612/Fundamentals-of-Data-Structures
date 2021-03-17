#include<stdio.h>  
#include<stdlib.h>  
struct node{  
    int data;  
    struct node *left;
    struct node *right;    
};  
struct node *root;  
struct node *temp; 
void create();
void insert();
void search(struct node *a);   
void inorder(struct node *a);  
void preorder(struct node *a);  
void postorder(struct node *a);
void main (){  
    int choice =0;  
    while(choice != 5){   
        printf("\n1.Insert\n2.inorder\n3.preorder\n4.postorder\n5.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice){  
            case 1:  
            insert();      
            break;  
            case 2:  
            inorder(root);         
            break;  
            case 3:  
            preorder(root);       
            break;  
            case 4:  
            postorder(root);        
            break;
            case 5:  
            exit(0);  
            break;
            default:  
            printf("Please enter valid choice");  
        }  
    }  
}  

void create(){
    int data;
    printf("Enter the value to be inserted: ");
    scanf("%d",&data);
    temp=(struct node *) malloc(sizeof(struct node *));
    temp->data=data;
    temp->left=temp->right=NULL;
}

void insert(){
    create();
    if(root==NULL){
        root=temp;
    }
    else{
        search(root);
    }
}

void search(struct node *a){
    if ((temp->data > a->data)&&(a->right != NULL)){
        search(a->right);
    }
    else if ((temp->data > a->data) && (a->right == NULL)){
        a->right = temp;
    }
    else if ((temp->data < a->data) && (a->left != NULL)){    
        search(a->left);
    }
    else if ((temp->data < a->data) && (a->left == NULL)){
        a->left = temp;
    }
}

void inorder(struct node *a){
    if(root==NULL){
        printf("No data in the BST");
        return;
    }
    if(a->left !=NULL){
        inorder(a->left);
    }
    printf("%d -> ",a->data);
    if(a->right !=NULL){
        inorder(a->right);
    }
}
void preorder(struct node *a){
    if(root==NULL){
        printf("No data in the BST");
        return;
    }
    printf("%d -> ",a->data);
    if(a->left !=NULL){
        preorder(a->left);
    }
    if(a->right !=NULL){
        preorder(a->right);
    }
}
void postorder(struct node *a){
    if(root==NULL){
        printf("No data in the BST");
        return;
    }
    if(a->left !=NULL){
        postorder(a->left);
    }
    if(a->right !=NULL){
        postorder(a->right);
    }
    printf("%d -> ",a->data);
}