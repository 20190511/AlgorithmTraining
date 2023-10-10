#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define true 1
#define false 0

typedef struct node {
    int val; 
    struct node *next;
    struct node *prev;
}Node;

typedef struct Queue {
    Node *tail[10];
    Node *head[10]; 
    int total_count;
}Queue;


Queue* queue();
Node* sort(Node* list);

Node* node(int val);
Node* pop(Queue* q, int idx);
Node* allpop(Queue* q);
int append (Queue* q, int idx, Node* newNode);

Node* randSet(int n);
void printNode(Node* n);
void printNode2(Node* n);

int interface();

void freeList(Node* n);
void freeQueue(Queue* q);
int main(void)
{
    while(interface());
    return 0;
}

void freeList(Node* n)
{
    Node *del;
    for (Node* s = n ; n != NULL ;) {
        del = n;
        n = n->next;
        free(del);
    }
}

void freeQueue(Queue* q)
{
    if (q == NULL)
        return;

    for (int i = 0 ; i < 10 ; i++) {
        if (q->head[i])
            free(q->head[i]);
        if (q->tail[i])
            free(q->tail[i]);
    }
}

int interface()
{
    int d = 0;
    printf(" your n size (Want Quit enter -1) : ");
    scanf("%d", &d);
    getchar();
    if (d == -1) {
        printf("Quit!!\n");
        return false;
    }
    else if (d < 0) {
        printf("Retry your number (%d)\n", d);
        return true;
    }
    Node* n = randSet(d);
    printf("Prev Set : \n");
    printNode(n);
    n = sort(n);
    printf("\n");
    printf("Sorted Set : \n");
    printNode(n);
    freeList(n);
    printf("===============================\n\n");
    return true;
}
void printNode(Node* n)
{
    if (n == NULL)
        return;
    int count = 0;
    int printFlag = 10;
    for (Node* p = n ; p != NULL && p->val != -1; p = p->next, count++) {
        printf("%-5d ", p->val);
        if (count % printFlag == printFlag-1)
            printf("\n");
    }
    printf("\n");
}

void printNode2(Node* n)
{
    if (n == NULL)
        return;
    for (Node* p = n->next ; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    printf("\n");

}

Node* sort(Node* list)
{
    Queue* q = queue();
    Node* s=list, *delNode;
    int baseCounter = 1;
    for (int i = 0 ; i < 4 ; i++) {
        while (s != NULL && s->val != -1) {
            Node* tmp = s->next;
            int iidx = (s->val / baseCounter) % 10;
            append(q, iidx, s);
            s = tmp;
        }
        s = allpop(q);
        delNode = s;
        s = s->next;
        free(delNode);
        baseCounter *= 10;
    }
    freeQueue(q);
    return s;

}

Node* randSet(int n)
{
    srand((unsigned int)time(NULL));
    int val;
    Node* head = node(-1); //dummy head
    Node* ptr = head;
    for (int i = 0 ; i < n ; i++) {
        val = rand() % 10000;
        Node* newNode = node(val);
        newNode->next = ptr;
        ptr = newNode;
    }
    return ptr;
}


Node* pop(Queue* q, int idx)
{
    if (!q || !q->head[idx] || q->head[idx]->next == q->tail[idx])
        return NULL;
    
    Node* retNode = q->head[idx]->next;
    q->head[idx]->next = retNode->next;
    retNode->next->prev = q->head[idx];
    retNode->next = retNode->prev = NULL;
    q->total_count--;
    return retNode;
}

// list->a1, a2 ... -> NULL
Node* allpop(Queue* q)
{
    if (!q)
        return NULL;

    Node* list = node(-1), *ptr = list, *pNode;
    for (int idx = 0 ; idx < 10 ; idx++)  {
        while ((pNode = pop(q, idx))) {
            ptr->next = pNode; 
            ptr = pNode;
        } 
    }
    return list;
}
int append (Queue* q, int idx, Node* newNode) {
    if (!q || !q->head[idx])
        return false;

    newNode->prev = q->tail[idx]->prev;
    newNode->next = q->tail[idx];
    newNode->prev->next = newNode;
    q->tail[idx]->prev = newNode;
    q->total_count++;
    return true;
}

Node* node(int val) {
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    newNode->val = val;
    return newNode; 
}
/** head <-> data, data, data <-> tail*/
Queue* queue()
{
    Queue *nq = (Queue*)calloc(1, sizeof(Queue));
    for (int i = 0 ; i < 10 ; i++) {
        Node* head = node(-1), *tail = node(-1);
        head->next = tail;
        tail->prev = head;
        nq->head[i] = head;
        nq->tail[i] = tail;
    }
    return nq;
}