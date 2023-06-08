httpsleetcode.cnproblemsimplement-stack-using-queuesdescription
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	unsigned int size;
}Queue;
void QueueInit(Queue* pq)
{
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* next;
	while (pq->phead)
	{
		next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->ptail = NULL;
	pq->size = 0;
	printf("内存销毁成功！\n");
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (NULL == newnode)
	{
		perror("malloc error:\n");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (NULL == pq->ptail)
	{
		assert(NULL==pq->phead);
		pq->phead = newnode;
		pq->ptail = newnode;
	}
	else {
		pq->ptail->next = newnode;
		pq->ptail= newnode;
	}
	pq->size++;
}
bool QueueEmpty(Queue* pq)
{
	return pq->size==0;
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	
	QNode* tmp = pq->phead;
	pq->phead = pq->phead->next;
	if (tmp == pq->ptail)
	{
		pq->ptail = NULL;
	}
	free(tmp);
	
	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->phead->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->ptail->data;
}
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
typedef struct {
    Queue data1;
    Queue data2;
    Queue *top;
    Queue *store;
} MyStack;

MyStack* myStackCreate() {
    MyStack*new=(MyStack*)malloc(sizeof(MyStack));
		QueueInit(&new->data1);
		QueueInit(&new->data2);
		new->top=&new->data1;
		new->store=&new->data2;
    return new;
}
void myStackPush(MyStack* obj, int x) {
	
	while(QueueSize(obj->top))//把top所有的数据全压入store
 	{
 		QueuePush(obj->store,QueueFront(obj->top));
 		QueuePop(obj->top);
 	}
 	QueuePush(obj->top,x);
}
int myStackTop(MyStack* obj) {
return QueueFront(obj->top);
}
int myStackPop(MyStack* obj) {
	QDataType ret=myStackTop(obj);//保存一下要pop的数据到时候返回
	QueuePop(obj->top);//总之先把top弹掉再说（
	//把store里的数据压到只剩一个，或没有，再把store当top
	while(QueueSize(obj->store)>1)
	{
		QueuePush(obj->top,QueueFront(obj->store));
		QueuePop(obj->store);
	}
	Queue*temp=obj->top;
	obj->top=obj->store;
	obj->store=temp;
return ret;
}
//非空返非0
bool myStackEmpty(MyStack* obj) {
return !QueueSize(obj->top)||QueueSize(obj->store);
}
void myStackFree(MyStack* obj) {
	QueueDestroy(obj->top);
	QueueDestroy(obj->store);
	free(obj);
}



/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/