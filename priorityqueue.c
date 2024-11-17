#include <stdio.h> 

#include <stdlib.h> 

struct Node { 

    int data; 

    int priority; 

    struct Node* next; 

}; 

struct Node* createNode(int data, int priority) { 

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 

    newNode->data = data; 

    newNode->priority = priority; 

    newNode->next = NULL; 

    return newNode; 

} 

int isEmpty(struct Node* head) { 

    return head == NULL; 

} 

struct Node* insert(struct Node* head, int data, int priority) { 

    struct Node* newNode = createNode(data, priority); 

    if (head == NULL || head->priority > priority) { 

        newNode->next = head; 

        head = newNode; 

    } else { 

        struct Node* temp = head; 

        while (temp->next != NULL && temp->next->priority <= priority) { 

            temp = temp->next; 

        } 

        newNode->next = temp->next; 

        temp->next = newNode; 

    } 

    return head; 

} 

struct Node* removeNode(struct Node* head) { 

    if (isEmpty(head)) { 

        printf("Priority Queue is empty\n"); 

        return NULL; 

    } 

    struct Node* temp = head; 

    head = head->next; 

    free(temp); 

    return head; 

} 

int peek(struct Node* head) { 

    if (isEmpty(head)) { 

        printf("Priority Queue is empty\n"); 

        return -1; 

    } 

    return head->data; 

} 

void display(struct Node* head) { 

    struct Node* temp = head; 

    while (temp != NULL) { 

        printf("%d \n", temp->data); 

        temp = temp->next; 

    } 

} 

int main() { 

    struct Node* pq = NULL; 

    int n, data, priority; 

    printf("Enter the number of elements in queue: "); 

    scanf("%d", &n); 

    for (int i = 0; i < n; i++) { 

        printf("Enter data and priority for element %d: ", i + 1); 

        scanf("%d %d", &data, &priority); 

        pq = insert(pq, data, priority); 

    }  

    printf("Priority Queue:\n"); 

    display(pq);  

    printf("Element at head: %d \n", peek(pq)); 

    pq = removeNode(pq); 

    printf("Queue after removing:\n"); 

    display(pq); 

    return 0; 

} 