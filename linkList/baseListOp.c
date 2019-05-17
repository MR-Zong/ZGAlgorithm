#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    int score;
    struct student *next;
}studentList;


studentList * createList(int n){
   if(n<=0){
	printf("%d",n);
	return NULL;
   }
   studentList *head,*node,*end;
   head = (studentList *)malloc(sizeof(studentList));
   end = head;
   for(int i=0;i<n;i++){
	node = (studentList *)malloc(sizeof(studentList));
	printf("请输入%d个中的第%d个数字：\n",n,i+1);
	scanf("%d",&node->score);
	end->next = node; 
	end = node;
   }
   end->next = NULL;
   return head;
}

studentList * getStudent(studentList *head,int n){
        studentList *node = head;
        int i = 0;
        while(i<n && node!=NULL){
	    node = node->next;
            i++;
        }
	return node;
} 

void addElement(studentList *head,studentList *element, int n){
    studentList *preNode, *node=head;
    int i=0;
    while(i<n && node!=NULL){
        if(i==n-1){
	    preNode = node;
	}
	i++;
	node = node->next;
    }
    preNode->next = element;
    element->next = node;
}

void deleteElement(studentList *head, int n){
    studentList *preNode, *node = head;
    int i=0;
    while(i<n && node!=NULL){
	if(i==n-1){
	    preNode = node;
	}
	i++;
	node = node->next;
    }
    if(preNode!=NULL&&node!=NULL){
        preNode->next = node->next;
        free(node);
    }
}  

void printList(studentList *head){
    studentList *node = head->next;
    printf("\n list:");
    while(node!=NULL){
	printf("score %d,",node->score);
	node = node->next;
    }
    printf("\n");
}

void exchangeElement(studentList *head, int n1, int n2){
    studentList *pre1Node, *pre2Node,  *k1Node, *k2Node=head;
    int maxN = n1>n2?n1:n2;
    int minN = n1<n2?n1:n2;
    int i=0;
    while(i<maxN && k2Node!=NULL){
	if(i==minN-1){
	    pre1Node = k2Node;
	}
	if(i==minN){
	    k1Node = k2Node;
	} 
	if(i==maxN-1){
	    pre2Node = k2Node;
	}
	i++;
	k2Node = k2Node->next;
    }
    if(k1Node->next==k2Node){
	pre1Node->next = k2Node;
        k1Node->next = k2Node->next;
	k2Node->next = k1Node;
    }else {
        pre1Node->next = k2Node;
        studentList *k1Next = k1Node->next;
        k1Node->next = k2Node->next;
        pre2Node->next = k1Node;
        k2Node->next = k1Next;
    }
}

int main()
{
    studentList *list = createList(4);
    //studentList *node = getStudent(list,3);
    //printf("score %d\n",node->score);
    printList(list);

    printf("exchange:\n");
    exchangeElement(list,1,2);
    printList(list);
    exchangeElement(list,3,4);
    printList(list);

    // delete
    printf("delete:3\n");
    deleteElement(list,3);
    printList(list);

    // add
    printf("add: 3 \n");
    studentList *element = (studentList *)malloc(sizeof(studentList));
    scanf("%d",&element->score);
    addElement(list,element,3);
    printList(list);
}
