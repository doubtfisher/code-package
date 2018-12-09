//设计一个循环队列
typedef struct {
	int* queue;
	int front;
	int rear;
	int k;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* pcq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	pcq->queue = (int*)malloc(sizeof(int)*(k + 1));
	pcq->front = 0;
	pcq->rear = 0;
	pcq->k = k;
	return pcq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)//当头和尾是紧挨着的时候就不能入数据了
	{
		return false;
	}
	obj->queue[obj->rear] = value;
	obj->rear++;
	if (obj->rear == obj->k + 1)
	{
		obj->rear = 0;
	}
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {

	if (obj->front == obj->rear)//为空时
	{
		return false;
	}
	obj->front++;//删除
	if (obj->front == obj->k + 1)//当front走到k时，把front置为0，让它构成环形
	{
		obj->front = 0;
	}
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
	{
		return -1;
	}
	else
	{
		return obj->queue[obj->front];
	}
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
	{
		return -1;
	}
	if (obj->rear == 0)
	{
		return obj->queue[obj->k];
	}
	else
	{
		return obj->queue[obj->rear - 1];
	}

}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->queue);
	obj->queue = NULL;
	free(obj);
}
