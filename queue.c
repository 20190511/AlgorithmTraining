#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define true 1
#define false 0
typedef struct node {
    struct node* next;
    int val;
}Node;

typedef struct queue {
    Node* head;
    Node* tail;
}Queue;

typedef struct radixQ {
    Queue* index[10];
}RadixQ;

RadixQ* radixQ();
Queue*  listFromRadixQ(RadixQ* rq, Queue *q);
Queue*  queue();
Queue* randList(int count);
Queue* sort(Queue* q);
Node*   node(int val);
Node*   pop(Queue* q);
int     append(Queue* q, Node* newNode);
void printQ(Queue* q);
void interface();
void freeradixq(RadixQ* rq);
void freeQueue(Queue* q);


int main(void)
{
    interface();

}
void interface()
{
    int n,m;
    Queue *q;
    printf("Input Your n,m : ");
    scanf("%d %d",&n, &m);
    getchar();
    for (int i = 0 ; i < m ; i++) {
        printf("===================[%d] random sort simulater ====================\n\n", i+1);
        q = randList(n);
        printf("prev set : \n");
        printQ(q);
        printf("sort set : \n");
        q = sort(q);
        printQ(q);
        freeQueue(q);
    }

}

void printQ(Queue* q)
{
    int sortText = 0, sortFlag = 10;
    for (Node* s = q->head->next ; s->val != -1 ; s = s->next, sortText++) {
        printf("%-5d ", s->val);
        if (sortText % sortFlag == sortFlag-1)
            printf("\n");
    }
    printf("\n");
    return;
}

void freeQueue(Queue* q)
{
    Node* checkN;
    while((checkN = pop(q)))
        free(checkN);
    free(q->head);
    free(q->tail);
    free(q);
}

void freeradixq(RadixQ* rq)
{
    Node* checkN;
    for (int i = 0 ; i < 10 ; i++) 
        freeQueue(rq->index[i]);
    free(rq);
}

Queue* randList(int count)
{
    static int upcount;
    srand((unsigned int)(time(NULL) + upcount++));
    Queue* q = queue();
    for (int i = 0 ; i < count ; i++) {
        int val = rand() % 10000;
        if(!append(q, node(val))) 
            i--;
    }
    return q;
}

Queue* sort(Queue* q)
{
    RadixQ* rq = radixQ();
    Node* popNode;
    int baseCounter = 1;
    for (int i = 0 ; i < 4 ; i++) {
        while ((popNode = pop(q))) {
            int idx = (popNode->val / baseCounter) % 10;
            append(rq->index[idx], popNode);
        }
        q = listFromRadixQ(rq, q);
        baseCounter *= 10;
    }
    freeradixq(rq);
    return q;

}

Queue*  listFromRadixQ(RadixQ* rq, Queue* q)
{
    if (rq == NULL)
        return NULL;
    if (q == NULL)
        q = queue();
    Node* tmp; 
    for (int i = 0 ; i < 10 ; i++) {
        while((tmp = pop(rq->index[i])))
            append(q, tmp);
    }
    return q;
}

RadixQ* radixQ()
{
    RadixQ* newRq = (RadixQ*)calloc(1, sizeof(RadixQ));
    for (int i = 0 ; i < 10 ; i++) 
        newRq->index[i] = queue();
    return newRq;
}

Node*   pop(Queue* q)
{
    if (!q || !q->head || q->head->next->val == -1) {
        if (q->head->next)
            q->tail = q->head->next;
        return  NULL;
    }

    Node* retNode = q->head->next;
    q->head->next = retNode->next;
    retNode->next = NULL;
    return retNode;
}

int     append(Queue* q, Node* newNode)
{
    if (!q || !q->tail || !newNode)
        return false;

    if (q->tail->val == -1) {
        q->head->next = newNode;
        newNode->next = q->tail;
        q->tail = newNode;
    }
    else  { 
        newNode->next = q->tail->next;
        q->tail->next = newNode;
        q->tail = newNode;
    }
    return true;
}

Node* node(int val)
{
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    newNode->val = val;
    return newNode;
}

Queue* queue()
{
    Queue* nq = (Queue*)calloc(1, sizeof(Queue));
    nq->head = node(-1), nq->tail = node(-1);
    nq->head->next = nq->tail;
    return nq;
}