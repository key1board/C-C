#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;     //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
#define MAXSIZE 100

typedef struct
{
    char name[20];//����
    char no[10];//ѧ��
    double score;//�ɼ�
}Student;
typedef Student ElemType;

typedef struct
{
    ElemType *elem; //�洢�ռ�Ļ���ַ
    int length;//��ǰ����
}SqList;

void input(ElemType *e)//����ѧ����Ϣ
{
    printf("����ѧ��");
    scanf("%s",e->no);
    printf("��������\n");
    scanf("%s",e->name);
    printf("����ɼ�\n");
    scanf("%lf",&e->score);
}

void output(ElemType *e)//���ѧ����Ϣ
{
    printf("ѧ��: %-10s, ����: %-20s,  �ɼ�: %-10.2lf\n\n", e->no, e->name, e->score);
}

Status InitList(SqList *L)//����˳���
{
    L->elem=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);//Ϊ˳������һ����СΪMAXSIZE�Ŀռ�
    if(!L->elem)                         //�洢�ռ����ʧ��
    exit(OVERFLOW);
    L->length=0;                         //�ձ���Ϊ0
    return OK;
}

int LocateElem(SqList *L,ElemType e)//�����ֲ�ѯѧ����Ϣ
{
    int i;
    for(i=0;i<L->length;i++)
        if(!strcmp(L->elem[i].name,e.name))
        {
            return i+1;
        }
    return 0;
}

Status ListInsert(SqList *L,int i,ElemType e) //����ѧ����Ϣ
{
    int j;
    system("cls");
    if(i<1||i>L->length+1)//����λ�ò��Ϸ�
    {
        return ERROR;
    }
    if(L->length==MAXSIZE)//����ռ�����
    {
        return ERROR;
    }
    for(j=L->length-1;j>=i-1;j--)
        L->elem[j+1]=L->elem[j];
    L->elem[i-1]=e;
    ++L->length;//���ȼ�һ
    return OK;
}

Status ListDelete(SqList *L,int j,char *e)//ɾ��ָ��λ�õ�ѧ����Ϣ
{
    if(j!=L->length&&j>0)
    {
        strcpy(e,L->elem[j].name);
        for(;j<=L->length;j++)
        L->elem[j-1]=L->elem[j];
    }
    else//λ�ò��Ϸ�
    return ERROR;
    --L->length;//���ȼ�һ
    return OK;
}
int main()
{
    int i,j,len,m,temp,a;
    char res[20];
    ElemType e,b;
    SqList L;
    int n;
    printf("******��ӭ����ѧ����Ϣ����ϵͳ******\n");//����ѡ��
    printf("1.����˳���\n");
    printf("2.�������ݡ�\n");
    printf("3.������������ɼ���\n");
    printf("4.����������ѯ�����ɼ���\n");
    printf("5.��ʾָ��λ��ѧ����Ϣ��\n");
    printf("6.�����������ݡ�\n");
    printf("7.ɾ���������ݡ�\n");
    printf("8.ͳ����Ϣ����ѧ��������\n");
    printf("0.�˳���\n");

    n=-1;
    while(n!=0)
    {
        printf("��ѡ���ܱ��:\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:           //����˳���
                    if(InitList(&L))
                       printf("�ɹ�����˳���\n\n");
                    else
                       printf("����˳���ʧ��\n\n");
                    break;
            case 2:        //����ѧ����Ϣ
                    printf("������ѧ��������(<100)\n");
                    scanf("%d",&len);
                    for(i=0;i<len;i++)
                    {
                        printf("��%d����:\n",i+1);
                        input(&L.elem[i]);
                    }
                    L.length=len;
                    putchar('\n');
                    break;
            case 3:     //�������ѧ����Ϣ
                   for(i=0;i<L.length;i++)
                   {
                        output(&L.elem[i]);
                   }
                   putchar('\n');
                   break;
            case 4:    //�����ֲ�ѯ
                    printf("��������Ҫ��ѯ��������������\n");
                    scanf("%s",e.name);
                    temp=LocateElem(&L,e);
                    if(temp!=0)
                       output(&L.elem[temp-1]);
                    else
                        printf("��ѯʧ�ܣ�û�д�ѧ����Ϣ\n\n");
                    break;
            case 5:   //��λ�ò�ѯ
                    printf("��������Ҫ��ѯ���ݵ�λ�á�\n");
                    scanf("%d",&i);
                    output(&L.elem[i-1]);
                    break;
            case 6:  //����ѧ����Ϣ
                    printf("������һ��������������λ��:\n");
                    scanf("%d",&a);
                    printf("��������Ҫ����ѧ������Ϣ:\n");
                    printf("ѧ��:");
                    scanf("%s",b.no);
                    printf("����:");
                    scanf("%s",b.name);
                    printf("�ɼ�:");
                    scanf("%lf",&b.score);
                    if(ListInsert(&L,a,b))
                        printf("����ɹ�.\n\n");
                    else
                        printf("����ʧ��.\n\n");
                    break;
            case 7:   //ɾ��ѧ����Ϣ
                    printf("��������Ҫɾ����ѧ��λ��:");
                    scanf("%d",&m);
                    if(ListDelete(&L,m,res))
                        printf("ɾ���ɹ�.\n��ɾ����ѧ������Ϊ:%s\n\n",res);
                    else
                        printf("ɾ��ʧ��.\n\n");
                    break;
            case 8:  //ͳ��ѧ��������
                    printf("ѧ��������Ϊ %d\n",L.length);
                    break;
            case 0:exit(0); //�˳�ϵͳ
        }
    }
    return 0;
}
/*
#define MAXSIZE 20        //�洢�ռ��ʼ������
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int Status;  //Statusʱ���������ͣ���ֵ�Ǻ������״̬�룬��ok��
typedef int ElemType;     //ElemType,���͸���ʵ������������������Ϊint

typedef struct
{
	ElemType data[MAXSIZE];
	int length;                 //���Ա���
}SqList;
Status GetElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i<1 || i>L.length)        //�ж��б��Ƿ�Ϊ��
		return ERROR;
	*e = L.data[i - 1];
	return OK;
}
Status ListInsert(SqList *L, int i, ElemType e)         //�б����
{
	int k;
	if (L->length == MAXSIZE)    //˳�������
		return ERROR;
	if (i<1 || i>L->length + 1)   //��i����ʹ�÷�Χ��
		return ERROR;
	if (i <= L->length)     //����������λ�ò��ڱ�β
	{
		for (i <= L->length - 1; k >= i - 1; k--)   //��Ҫ����λ�ú�����Ԫ������ƶ�һλ
			L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;          //����Ԫ�ز���
	L->length++;
	return OK;
}
Status ListDelet(SqList *L, int i, ElemType *e)         //�б�ɾ��
{
	int k;
	if (L->length == 0)           //���Ա�Ϊ��
		return ERROR;
	if (i<1 || i>L->length)         //ɾ��λ�ò���ȷ
		return ERROR;
	*e = L->data[i - 1];
	if (i < L->length)        //���ɾ���������λ��
	{
		for (k = i; k < L->length; k++) //��ɾ��λ�ú��Ԫ��ǰ��
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}
int main()
{

}
*/
