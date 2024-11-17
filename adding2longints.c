#include <stdio.h> 

#include <stdlib.h> 

struct node { 

    int data; 

    struct node* next; 

}; 

struct node* createNode(int data) { 

    struct node* newNode = (struct node*)malloc(sizeof(struct node)); 

    newNode->data = data; 

    newNode->next = NULL; 

    return newNode; 

} 

struct node* insertEnd(struct node* head, int data) { 

    struct node* newNode = createNode(data); 

    if (head == NULL) { 

        return newNode; 

    } 

    struct node* temp = head; 

    while (temp->next != NULL) { 

        temp = temp->next; 

    } 

    temp->next = newNode; 

    return head; 

} 

struct node* insertBeginning(struct node* head, int data) { 

    struct node* newNode = createNode(data); 

    newNode->next = head; 

    head = newNode; 

    return head; 

} 

void printList(struct node* head) { 

    struct node* temp = head; 

    while (temp != NULL) { 

        printf("%d", temp->data); 

        temp = temp->next; 

    } 

    printf("\n"); 

} 

struct node* addNumbers(struct node* list1, struct node* list2) { 

    struct node* result = NULL; 

    int carry = 0; 

 

    while (list1 != NULL || list2 != NULL || carry != 0) { 

        int digit1 = 0, digit2 = 0, sum = 0; 

         

        if (list1 != NULL) { 

            digit1 = list1->data; 

            list1 = list1->next; 

        } 

         

        if (list2 != NULL) { 

            digit2 = list2->data; 

            list2 = list2->next; 

        } 

         

        sum = digit1 + digit2 + carry; 

        carry = sum / 10; 

        sum = sum % 10; 

         

        result = insertBeginning(result, sum); 

    } 

     

    return result; 

} 

struct node* convertToList(int number) { 

    struct node* head = NULL; 

     

    if (number == 0) { 

        return createNode(0); 

    } 

     

    while (number > 0) { 

        int digit = number % 10; 

        head = insertEnd(head, digit); 

        number /= 10; 

    } 

     

    return head; 

} 

int main() { 

    int number1, number2; 

   struct node* list1 = NULL; 

    struct node* list2 = NULL; 

    struct node* result = NULL; 

    printf("Enter number 1: "); 

    scanf("%d", &number1); 

    printf("Enter number 2: "); 
    

    scanf("%d", &number2); 

    list1 = convertToList(number1); 

    list2 = convertToList(number2); 

    result = addNumbers(list1, list2); 

    printf("Sum of given numbers: "); 

    printList(result); 

     

    return 0; 

}