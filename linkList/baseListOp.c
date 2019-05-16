#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    int score;
    struct student *next;
}studentList;

int * test(int n){
	printf("n %d",n);
	return NULL;
}

studentList * creatList(int n){
   if(n<=0){
	printf("%d",n);
	return NULL;
   }
   studentList *head,*node,*end;
   head = (studentList *)malloc(sizeof(studentList));
   end = head;
   for(int i=0;i<n;i++){
	node = (studentList *)malloc(sizeof(studentList));
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

int main()
{
    //test(4);
    studentList *list = createList(4);
    //studentList *node = getStudent(list,3);
    //printf("score %d",node->score);
}
