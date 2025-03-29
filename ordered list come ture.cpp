#include<stdio.h>
//struct information
//{
//	int number;
//	int last;
//};
//单列表的初始化
#define maxsize 100
typedef struct information
{
	int a[maxsize];
	int last = -1;
	int standard;
}SeqList;
//单列表的输入
SeqList scanf_(SeqList x,int quantity)
{
	for (int i = 1; i <= quantity; i++)
	{
		scanf_s("%d", &(x.a[x.last + 1]));
		x.last++;
	}
	return x;
	
}
//单列表的输出
void print_(SeqList x)
{
	int i;
	for (i = 0; i <= x.last; i++)
	{
		printf("%d\n",x.a[i]);
	}
}
//单列表的插入
SeqList insert_(SeqList x,int number,int opsition)
{
	int i;
	if (opsition<1 || opsition>x.last + 2)
	{
		printf("表满");
	}
	else if (x.last==-1)
	{
		printf("为空表，请先声明数据");
	}
	else
	{
		for (i = x.last; i >= opsition - 1; i--)
		{
			x.a[i + 1] = x.a[i];
		}
		x.a[opsition - 1] = number;
		x.last++;
	}
	return x;
}
//单列表的删除
SeqList deplete(SeqList x, int number)
{
	int i;
	int j;
	int n=0;
	int getsum=0;
	if (x.last == -1)
	{
		printf("为空表");
	}
	else
	{
		for (i = 0; i < x.last + 1; i++)
		{
			if (x.a[i] != number)
			{
				getsum++;
				if (getsum > 50)
				{
					break;
				}
			}
			else
			{
				for (j = i; j < x.last; j++)
				{
					x.a[j] = x.a[j + 1];
				}
				x.last--;
				n++;
				printf("已删除%d,%d次\n",number,n);
				i = 0;
			}
		}
		
	}
	return x;
}
//元素的查找
int find(SeqList x,int number)
{
	int i=0;
	while(i<=x.last&&x.a[i]!=number)
	{
		i++;
	}
	if (i > x.last)
	{
		return -1;
	}
	else
	{
		return i+1;
	}

}
//元素的划分
SeqList separete(SeqList x)
{
	int i,j;//循环变量
	int m = 0;//标准表的位置
	int numberstore;//存储标准表的值
	if (x.last == -1)
	{
		printf("为空表");
	}
	else
	{
		 x.standard = x.a[0];
		
		for (i = 1; i <= x.last; i++)
		{
			if (x.a[i] <= x.standard)//不可写x.a[0],因为在变化，标准不可变
			{
				numberstore = x.a[i];
				for (j = i-1; j >= 0; j--)
				{
					x.a[j+1 ] = x.a[j];
				}
				x.a[m] = numberstore;
				m++;
			}
		}

	}
	return x;
}
//两个元素从小到大的顺序表的合并
SeqList combine(SeqList a, SeqList b)//
{
	SeqList c;
	int i = 0,j=0,k=0;
	while (i <= a.last && j <= b.last)
	{
		if (a.a[i] > b.a[j])
		{
			c.a[k++] = b.a[j++];
			
		}
		else
		{
			c.a[k++] = a.a[i++];
			
		}
	}
			while (j <= b.last)
			{
				c.a[k++] = b.a[j++];
				
			}
			while (i <=a.last)
			{
				c.a[k++] = a.a[i++];
				
			}
			c.last = k - 1;
		
		
		return c;
	
}


int main()
{
	SeqList q;
	q = scanf_(q, 5);//验证输入
	SeqList p;
	p = scanf_(p, 5);
	SeqList c = combine(q, p);
	printf("\n");
	print_(c);
	printf("%d",c.last);
	//q = insert_(q, 66, 4);//验证插入
	//printf("\n");
	//print_(q);//验证输出

	//q = deplete(q, 66);//验证删除	
	//print_(q);

	//int e = 0;
	//e= find(q, 3);//验证查找
	//printf("%d\n", e);

	//q = separete(q);//验证划分
	//printf("划分是%d\n",q.standard);
	
	return 0;

}
