#import <stdio.h>
#import <stdlib.h>
#import <string.h>

struct node{
    char data;
    struct node * left;
    struct node * right;
};

struct node * createNode(char data);
struct node * plantTree(char * preOrder, char * inOrder, int start, int endnd); 
void printPost(struct node* node);

int main(){
    int caseNumber;
    scanf("%d", &caseNumber);

    for (int i = 0; i < caseNumber; ++i){
        int inputSize;
        char * preOrder = (char *)malloc(sizeof(char)*53);
        char * inOrder = (char *)malloc(sizeof(char)*53);

        scanf("%d %s %s", &inputSize, preOrder, inOrder);
        struct node * root = plantTree(preOrder, inOrder, 0, inputSize - 1);
        printPost(root);
        printf("\n");
    }
    
}

void printPost(struct node* node){ 
    if (node == NULL){
        return;
    }
  
    printPost(node->left);
    printPost(node->right);
    printf("%c", node->data);
} 

struct node * createnode(char data) { 
    struct node * node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 


struct node * plantTree(char * preOrder, char * inOrder, int start, int end) { 
    static int preIndex = 0; 
  
    if (start > end){ 
        return NULL; 
    }
    struct node* node = createnode(preOrder[preIndex++]); 
  
    if (start == end){
        return node; 
    }
    int inIndex;
    for (int i = start; i <= end; i++) { 
        if (inOrder[i] == node->data) 
            inIndex = i; 
    }
  
    node->left = plantTree(preOrder, inOrder, start, inIndex - 1); 
    node->right = plantTree(preOrder, inOrder, inIndex + 1, end); 
  
    return node; 
} 
