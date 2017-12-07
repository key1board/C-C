#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int DataType;

//---------���Ա�ľ�̬������洢�ṹ--------
#define MAXSIZE 100
typedef struct
{
    ElemType data;
    int cur;
}SLinkList[MAXSIZE];

//���±�Ϊk�Ŀ��н����յ���������
void Free_SL(SLinkList space, int k)
{
    space[k].cur = space[0].cur;    //��������������k֮��
    space[0].cur = k;               //��k������������ͷ֮��
}

//���䱸�������һ�����,�����±�
//��Ϊ0����˵��������������
int Malloc_SL(SLinkList space)
{
    int i = space[0].cur;
    if(space[0].cur)                 //�жϱ��������Ƿ�ǿ�
        space[0].cur = space[i].cur; //��������ͷָ��ָ��ڶ����ս��
    return i;                        //���ص�һ���ս��
}

void SListInit(SLinkList space)
{
    int i;
    for(i = 0; i < MAXSIZE; i++)
        space[i].cur = i+1;         //�����н�����뱸������

    space[0].cur = space[1].cur;    //��������ͷָ������ڶ������
    space[1].cur = 0;               //��һ�������Ϊ�����ͷ���
}

//��ȡ����ĳ���
int SListLength(SLinkList space)
{
    int len = 0;
    int i = space[1].cur;           //��ͷָ���һ�������±�
    while(i)
    {
        ++len;
        i = space[i].cur;
    }
    return len;
}

//������ĵ�i��λ�ò���Ԫ��e
void SlistInsert(SLinkList space, int i, ElemType e)
{
    if(i < 1 || i > SListLength(space)+1) //������Χ
        return;

    int k = 1, j;
    for(j = 0; j <i-1; j++)         //ʹkָʾҪɾ���Ľ���ǰһ�����
        k = space[k].cur;

    int v = Malloc_SL(space);
    if(v)                           //����пռ�
    {
        space[v].data = e;
        space[v].cur = space[k].cur;
        space[k].cur = v;           //��������
    }
}

//ɾ����i��λ�õ�Ԫ��
void SListDelete(SLinkList space, int i)
{
    if(i < 1 || i > SListLength(space))  //������Χ�˳�
        return ;
    int k = 1, j;
    for(j = 0; j <i-1; j++)         //ʹkָʾҪɾ���Ľ���ǰһ�����
        k = space[k].cur;

    int temp = space[k].cur;
    space[k].cur = space[temp].cur;
    Free_SL(space, temp);
}

void SListTraverse(SLinkList space)
{
    int i = space[1].cur;
    while(i)
    {
        printf("%d\n", space[i].data);
        i = space[i].cur;
    }
}
int main()
{
    SLinkList space;
    SListInit(space);   //��ʼ��
    int i;
    for(i = 1; i <= 10; i ++)
        SlistInsert(space, 1, i);
    SListDelete(space, 10);

    SListTraverse(space);
    return 0;
}
