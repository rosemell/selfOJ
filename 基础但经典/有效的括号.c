typedef char STDataType;
typedef struct Stack
{
	STDataType *a;
	int top;
	int capacity;
}ST;
void STInit(ST*plist)
{
	assert(plist);
	plist->a = NULL;
	plist->capacity = 0;
	plist->top = 0;
}
void STDestroy(ST* plist)
{
	assert(plist);
	free(plist->a);
	plist->a = NULL;
	plist->capacity = plist->top = 0;
}
void STPush(ST* plist,STDataType x)
{
	assert(plist);
	if(plist->capacity ==plist->top)
	{
		int newcapcity = plist->capacity == 0 ? 4 : plist->capacity*2;
		ST* tmp = NULL;
		if (NULL == (tmp = (ST*)realloc(plist->a, sizeof(ST) * newcapcity)))
		{
			perror("relloc error:");
			return;
		}
		plist->a = tmp;
		plist->capacity = newcapcity;
	}
	plist->a[plist->top] = x;
	plist->top++;
}
//¡¤???¡¤?0
bool STEmpty(ST* plist)
{
	assert(plist);
	return plist->top == 0;
}
void STPop(ST* plist)
{
	assert(plist);
	//assert(plist->top > 0);
	assert(!STEmpty(plist));
	plist->top--;
}

STDataType Top(ST* plist)
{
	assert(plist);
	assert(plist->top);
	return plist->a[plist->top - 1];
}

int STSize(ST* plist)
{
	assert(plist);
	return plist->top;
}

bool isValid(char* s) {
	ST left;
	STInit(&left);
	while (*s)
	{
		if (*s == '(' ||
			*s == '[' ||
			*s == '{')
		{
			STPush(&left, *s);
		}
		else
		{
			if (STEmpty(&left))
			{
				STDestroy(&left);
				return false;
			}
			char temp = Top(&left);
			STPop(&left);
			if (temp == '(')
			{
				if (*s != ')') {
					STDestroy(&left);
					return false;
				}
			}
			else if (temp == '[')
			{
				if (*s != ']') {
					STDestroy(&left);
					return false;
				}
			}
			else if (temp == '{')
			{
				if (*s != '}')
				{
					STDestroy(&left);
					return false;
				}
			}
		}
		s++;
	}
	if(!STEmpty(&left))
	{
			STDestroy(&left);
			return false;
	}
	STDestroy(&left);
	return true;
}
