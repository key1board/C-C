/*�汾1.0*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct Node
{
	char name[20];  //����
	int num;	 //ѧ��
	int CH;      //����
	int MA;      //��ѧ
	int EN;      //Ӣ��
	struct Node *next;
}Node;

Node * NewLink(int n) //β�巨�����±�
{
	Node *p, *L, *h;
	int i;
	if ((L = (Node *)malloc(sizeof(Node))) == NULL)
	{
		printf("���ܷ���ռ�!");
		exit(0);
	}
	L->next = NULL;
	h = L;
	for (i = 0; i < n; i++)
	{
		if ((p = (Node *)malloc(sizeof(Node))) == NULL)
		{
			printf("���ܷ���ռ䣡");
			exit(0);
		}
		h->next = p;
		printf("\n�������%dλѧ������:", i + 1);
		scanf("%s",p->name);
		printf("\n������ѧ��:");
		scanf("%d", &p->num);
		printf("\n���������ĳɼ�:");
		scanf("%d", &p->CH);
		printf("\n��������ѧ�ɼ�:");
		scanf("%d", &p->MA);
		printf("\n������Ӣ��ɼ�:");
		scanf("%d", &p->EN);
		p->next = NULL;
		h = p;
	}
	if (L != NULL)
		printf("����ɹ���");
	return (L);
}

Node * search(Node * head, char *name) //�Ե���Ԫ�ؽ��в���
{
	Node *p;
	char *y;
	p = head->next;
	while (p != NULL)
	{
		y = p->name;
		if (strcmp(y, name) == 0)
		{
			printf("������%s\n", p->name);
			printf("\nѧ��: %d\n", p->num);
			printf("\n ����:%d  ��ѧ:%d  Ӣ��:%d\n",p->CH,p->MA,p->EN);
			return (p);
		}
		else p = p->next;
	}
	if (p == NULL)
		printf("û�в��ҵ������ݣ�");
	return 0;
}

void insert(Node *head)  //β�巨��������Ϣ
{
	Node *p,*s;
	char x[20];
	char *y;
	p = head->next;        //p=head��ͷ���
	while (p != NULL)
	{
		printf("���֣�%sѧ�ţ�%d���ģ�%d��ѧ��%dӢ�%d\n", p->name, p->num, p->CH, p->MA, p->EN);
		p = p->next;     //ָ����һ�����
	}
	printf("\n��������λѧ���ĺ��������Ϣ��");
	scanf("%s",x);
	s = (Node *)malloc(sizeof(Node));
	while (p != NULL)
	{
		y = p->name;
		if (strcmp(y,x)==0)        //��xͬѧ�ĺ��������Ϣ
		{
			printf("\n��������Ҫ�������Ϣ!");
			printf("\n������ѧ������:");
			scanf("%s", &p->name);
			printf("\n������ѧ��ѧ��:");
			scanf("%d", &p->num);
			printf("\n���������ĳɼ�:");
			scanf("%d", &p->CH);
			printf("\n��������ѧ�ɼ�:");
			scanf("%d", &p->MA);
			printf("\n������Ӣ��ɼ�:");
			s->next = p->next;
			p->next = s;
		}
		else p = p->next;
	}
}

Node * search2(Node *h,char  *x)   //�����ǰ����ǰ�����
{
	Node *p, *s;
	char *y;
	p = h->next;
	s = h;
	while (p != NULL)
	{
		y = p->name;
		if (strcmp(y,x) == 0)
			return(s);
		else
		{
			p = p->next;
			s = s->next;
		}
	}
	if (p == NULL)
		printf("û�в��ҵ�����!");
	return 0;
}

void del(Node *x, Node *y)  //ɾ�����
{
	Node *s;
	s = y;
	x->next = y->next;
	free(s);
}

void change(Node * head,char *x)
{
	Node *p = head->next;
	char *y;
	while (p != NULL)
	{
		y = p->name;
		if (strcmp(y, x) == 0)
		{
			printf("\n��������Ҫ�޸ĵ���Ϣ!");
			printf("\n������ѧ������:");
			scanf("%s", &p->name);
			printf("\n������ѧ��ѧ��:");
			scanf("%d", &p->num);
			printf("\n���������ĳɼ�:");
			scanf("%d", &p->CH);
			printf("\n��������ѧ�ɼ�:");
			scanf("%d", &p->MA);
			printf("\n������Ӣ��ɼ�:");
		}
		else p = p->next;
	}
}

int main()
{
	int n;
	Node *head, *searchpoint,*forepoint;  //searchpointΪǰ����㣬forepointΪ��ǰ���
	char name[20];

	printf("��Ҫ¼�����λͬѧ����Ϣ��");
	scanf("%d", &n);
	head = NewLink(n);  //������ʼ������
	system("cls");
	while (1)
	{

		printf("\t\t\t1)������Ϣ\n\n");
		printf("\t\t\t2)�޸���Ϣ\n\n");
		printf("\t\t\t3)ɾ����Ϣ\n\n");
		printf("\t\t\t4)������Ϣ\n\n");
		printf("\n������ҪҪִ�е�����: ");
		scanf("%d", &n);
		if (n == 1)
		{
			printf("\n��������Ҫ���ҵ��˵�������");
			scanf("%s", &name);
			search(head, name);
			system("cls");
		}
		else if (n == 2)
		{
			printf("\n������Ҫ���ĵ�ѧ����Ϣ��");
			scanf("%s", &name);
			change(head, name);
			system("cls");
		}
		else if (n == 3)
		{
			printf("\n��������Ҫɾ�����˵���Ϣ��");
			scanf("%s", &name);
			forepoint = search(head, name);
			searchpoint = search2(head, name);
			del(searchpoint, forepoint);
			system("cls");
		}
		else if (n == 4)
		{
			printf("\n������Ҫ���ӵ���Ϣ��\n");
			insert(head);
			system("cls");
		}
	}
}
