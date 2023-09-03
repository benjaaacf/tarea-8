#ifndef COLA_H
#define COLA_H

#define maxReserves 10
#define maxString 50

typedef struct {
  char student[maxString];
} Reserve;

typedef struct {
  Reserve data[maxReserves];
  int front, rear, size;
} Queue;

void initQueue(Queue *queue);
int isQueueEmpty(Queue *queue);
int isQueueFull(Queue *queue);
int enqueue(Queue *queue, const char *student);
int dequeue(Queue *queue, char *student);

#endif