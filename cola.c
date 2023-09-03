#include "cola.h"
#include <stdio.h>
#include <string.h>

void initQueue(Queue *queue) {
  queue->front = queue->rear = -1;
  queue->size = 0;
}

int isQueueEmpty(Queue *queue) { return queue->size == 0; }

int isQueueFull(Queue *queue) { return queue->size == maxReserves; }

int enqueue(Queue *queue, const char *student) {
  if (isQueueFull(queue)) {
    printf("Cola de reservas llena, no se pueden agregar más reservas.\n");
    return 0; // Indicar que no se agrego
  }

  if (isQueueEmpty(queue)) {
    queue->front = queue->rear = 0;
  } else {
    queue->rear = (queue->rear + 1) % maxReserves;
  }

  strcpy(queue->data[queue->rear].student, student);
  queue->size++;
  return 1; // Indicar que se agrego
}

int dequeue(Queue *queue, char *student) {
  if (isQueueEmpty(queue)) {
    printf("Cola de reservas vacía.\n");
    return 0; // Indicar que no se quito
  }

  strcpy(student, queue->data[queue->front].student);
  queue->size--;

  if (queue->front == queue->rear) {
    // Ultimo elemento en la cola
    queue->front = queue->rear = -1;
  } else {
    queue->front = (queue->front + 1) % maxReserves;
  }

  return 1;
}