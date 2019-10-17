typedef int ElementType;
typedef int Position;
typedef struct QNode* Queue;
struct QNode {
	ElementType *Data;
	Position Front, Rear;
	int MaxSize;
	int Size;
};
bool isFullQ(Queue Q) {
	return ((Q->Rear + 1) % Q->MaxSize == Q->Front);
}
bool isEmptyQ(Queue Q) {
	return(Q->Front == Q->Rear);
}
Queue CreateQueue(int MaxSize) {
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	Q->Size = 0;
	return Q;
}
bool AddQ(Queue Q, ElementType X) {
	if (isFullQ(Q)) {
		printf("Queue is full！！！\n");
		return false;
	}
	else {
		Q->Rear = (Q->Rear + 1) % Q->MaxSize;
		Q->Data[Q->Rear] = X;
		Q->Size++;
		return true;
	}
}
ElementType DeleteQ(Queue Q) {
	if (isEmptyQ(Q)) {
		printf("Queue is empty！！！\n");
		return ERROR;
	}
	else {
		Q->Front = (Q->Front + 1) % Q->MaxSize;
		Q->Size--;
		return Q->Data[Q->Front];
	}
}
