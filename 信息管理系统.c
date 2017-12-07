#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

//���еĺ���
void save(char *name, int n);
int readout(char *name, char *type);
void insert(char *name);
void deletedata(char *name);
void rankout(char *name);
void deletefile(char *name);
void fileinitialize(char *name);
void update(char *name);
void cleanscreen();
void makechoice(char *name);
int main();

typedef struct student_info           //ѧ����Ϣ�ṹ��
{
    char name[10];      //����
    int num;            //ѧ��
    int Chinese;        //����
    int math;           //��ѧ
    int English;        //Ӣ��
    int sum;
} info[100], insertinfo[100];
//info:�洢100��ѧ������Ϣ
//ȫ�ֱ���
char filename[50] = "D:\\programdata.txt";        //·���ļ���
char type[10];
char *p;

void save(char *name, int n)         //������д��info[100]�ṹ��
{
    //����д���ļ��ķ��������ڴ��е�����д�뵽ָ�����ļ���
    FILE *fp;
    int i;
    if ((fp = fopen(name, "w")) == NULL)       //�ж��ļ��Ƿ�Ϊ��
    {
        printf("�ļ��򿪴���\n");
        printf("��鲢ȷ����̨��������Ĭ��·����ָ����̷���E��������\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
        if (fwrite(&info[i], sizeof (struct student_info), 1, fp) != 1)     //�Զ�������ʽд���ļ�
            /*fwrite(����,�������ʹ�С(�ֽ���),ÿ��д�����ݵ��������,�ļ�ָ��)
            ÿ��������ֽ���Ϊsizeof��struct student_info)    ��info[i]�����ݷ�1��д��fp�ļ���*/
            printf("�ļ�д�����");


    fclose(fp);          //�ر��ļ�
}

int readout(char *name, char *type)  //����Ϣ����
{
    /*������ļ��ж�ȡ���ݵĺ������˺�����ָ���ļ��е����ݶ�ȡ���ڴ���
    ��׼���������Ĳ���*/
    int i;
    FILE *fp;
    if ((fp = fopen(name, type)) == NULL)
    {
        printf("�ļ��򿪴���\n");
        system("pause");
        makechoice(filename);
    }
    printf("\n=========================================\n");
    printf("����\t���\t����\t��ѧ\tӢ�� *\n");
    for (i = 0; fread(&info[i], sizeof (struct student_info), 1, fp) != 0; i++) //���ض�ȡ���ݵĸ���������0
    {
        printf("%s\t%d\t%d\t%d\t%d\t*\n", info[i].name, info[i].num,
                info[i].Chinese, info[i].math, info[i].english);
    }
    printf("=========================================\n");
    printf("���� %d ����¼\n\n", i);
    fclose(fp);
    return i;
}

void insert(char *name)
{
    /*����������ݵ��ļ��еķ���
        �˷�����˼�����Ƚ��ļ��е����ݶ�ȡ���ڴ�����
        �ڴ��еĽ���һϵ�е����ݲ���֮���ڽ�����������������
        ���ô����ݺ����浽�ļ���*/
    FILE *fp;
    int i, j, k, n, choice, flag, number;
    char insertname[10];


    p = "r";
    strcpy(type, p);
    readout(filename, type);

    printf("��ѡ����뷽ʽ\n");
    printf("1  �����м�¼��ĩβ���룻\t2  ָ��λ�ò���\n����ѡ��1,2����");
    scanf("%d", &choice);
    switch (choice) {
        case 1:/*����ֱ��ĩδ����ķ���������������ݽ�ֱ�ӱ����뵽�ļ���ĩβ*/
            printf("��������Ҫ����ļ�¼��\nnumber=");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {//get infomation from keybord to memory
                printf(">NO_%d ", i + 1);
                scanf("%s%d%d%d%d", info[i].name, &info[i].num, &info[i].Chinese,
                        &info[i].math, &info[i].english);
            }

            if ((fp = fopen(name, "a+")) == NULL) {//try open the file and ready to write
                printf("cannot open file\n");
                system("pause");
                makechoice(filename);
            }
            for (i = 0; i < n; i++) {//write the data to the file
                if (fwrite(&info[i], sizeof (struct student_info), 1, fp) != 1)
                    printf("�ļ�д�����");
            }
            fclose(fp);
            break;
        case 2:/*�����������ķ��� ����������û�Ҫ����������ݽ�������뵽ĳ������֮ǰ*/
            if ((fp = fopen(name, "r")) == NULL) {
                /*�Ƚ�ԭ�������ݶ����ڴ����������ݲ���ǰ��׼������*/
                printf("�ļ��򿪴���\n");
                system("pause");
                makechoice(filename);
            }
            for (i = 0; fread(&info[i], sizeof (struct student_info), 1, fp) != 0; i++) {
                number = i;
            }
            fclose(fp);

            printf("�����㽫�¼�¼���뵽�ĸ���¼��ǰ��\nname=");
            scanf("%s", insertname);

            printf("������Ҫ����ļ�¼��\nnumber=");
            scanf("%d", &n);

            for (i = 0; i < n; i++) {//get infomation from keybord to memory
                printf(">NO_%d ", i + 1);
                scanf("%s%d%d%d%d", insertinfo[i].name, &insertinfo[i].num, &insertinfo[i].Chinese,
                        &insertinfo[i].math, &insertinfo[i].english);
            }

            for (flag = 1, i = 0; flag && i <= number; i++) {//handle(delete) the data in the memory
                /*���õ�һ��forѭ�����ҳ�����������λ�ã�λ��Ӧ��Ϊ��������������λ�õ������±�Ϊi�����i���ڵ�
                ��number+n+1��-��i+1��������Ҫ������n��λ�õ�λ*/
                if (strcmp(insertname, info[i].name) == 0 && i <= number) {
                    /*����if������λ ׼�������ݵ�д��
                     */
                    for (j = number; j > i - 1; j--) {
                        /*���õڶ���forѭ����Ŀ��λ���Ժ�����ݺ���
                                                number+1��ԭ�е����ݸ���number���±�*/
                        info[j + n] = info[j];
                        if (j == i) {
                            //�жϵ������ʺϵ�ʱ����������滻
                            for (k = 0; k < n; k++, j++) {
                                info[j] = insertinfo[k];
                            }

                            /*�����ݺ��ƹ����Լ������ݲ��빤�����֮���ٴ�д���ļ�*/
                            if ((fp = fopen(name, "w")) == NULL) {
                                /*�Ƚ�ԭ�������ݶ����ڴ����������ݲ���ǰ��׼������*/
                                printf("�ļ��򿪴���\n");
                                system("pause");
                                makechoice(filename);
                            }
                            for (i = 0; i <= number + n; i++) {//write the data to the file
                                if (fwrite(&info[i], sizeof (struct student_info), 1, fp) != 1)
                                    printf("file write error");
                            }
                            fclose(fp);
                            j = i;
                            flag = 0;
                        }
                    }
                    puts(info[1].name);
                }
            }
            break;

    }

    printf("���������ݺ��ѧ����Ϣ����:\n");
    p = "r";
    strcpy(type, p);
    readout(filename, type);
    system("pause");
    makechoice(filename);
}

void deletedata(char *name)          //ɾ������
{
    /*����ɾ�����ݵķ���*/
    FILE *fp;
    int i, number;

    p = "r";
    strcpy(type, p);
    number = readout(filename, type) - 1;

    int j, flag;
    char delname[10];
    printf("��������Ҫɾ����ѧ��������:");
    scanf("%s", delname);
    for (flag = 1, i = 0; flag && i <= number; i++) {//handle(delete) the data in the memory
        if (strcmp(delname, info[i].name) == 0) {
            for (j = i; j <= number; j++) {
                /*���ø��ǵ�˼�뽫����֮�������ͳͳǰ���Ը��ǵ�ʵ�ʴﵽɾ����Ч��*/
                strcpy(info[j].name, info[j + 1].name);
                info[j].num = info[j + 1].num;
                info[j].Chinese = info[j + 1].Chinese;
                info[j].math = info[j + 1].math;
                info[j].english = info[j + 1].english;
                flag = 0;
            }
            printf("����ѡ����Ϣ�Ա��ɹ�ɾ��!\n");
        }
    }
    if (flag) {
        printf("û����Ҫɾ������Ϣ ������!\n");
        deletedata(filename);
    }
    if ((fp = fopen(name, "w")) == NULL) {//try to open the file
        printf("�ļ��򿪴���\n");
        exit(0);
    }
    for (i = 0; i < number; i++) {//rewrite the data after the delete handle
        if (fwrite(&info[i], sizeof (struct student_info), 1, fp) != 1)
            printf("�ļ�д�����");
    }
    fclose(fp);

    printf("ɾ��֮����Ϣ����:\n");
    p = "r";
    strcpy(type, p);
    readout(filename, type);
    system("pause");

    makechoice(filename);
}

void rankout(char *name)
{
    /*�����ܷ������ķ���*/
    FILE *fp;
    int i, j, number, choice;
    if ((fp = fopen(name, "r")) == NULL) {//try to open the file
        printf("�ļ��򿪴���\n");
        exit(0);
    }
    printf("׼����...\n��ǰѧ����Ϣ����\n\n");
    printf("=================================================\n");
    printf("name\tid\tchinese\tmath\tenglish\tsum\t*\n");
    for (i = 0; fread(&info[i], sizeof (struct student_info), 1, fp) != 0; i++) {
        info[i].sum = info[i].Chinese + info[i].math + info[i].english;
        printf("%s\t%d\t%d\t%d\t%d\t%d\t*\n", info[i].name, info[i].num,
                info[i].Chinese, info[i].math, info[i].english, info[i].sum);
        number = i + 1;
    }
    printf("=================================================\n");
    printf("���� %d ����¼\n\n", i);
    fclose(fp);
    printf("�� 1 ��������:�� 2 ˳������!\n����ѡ��1,2����");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            if ((fp = fopen(name, "r")) == NULL) {//try to open the file
                printf("cannot open file\n");
                exit(0);
            }
            for (i = 0; fread(&info[i], sizeof (struct student_info), 1, fp) != 0; i++) {
                info[i].sum = info[i].Chinese + info[i].math + info[i].english;

            }
            fclose(fp);
            //printf("%d",number);
            for (j = 0; j < number; j++) {//sort by the sum backformation
                //printf("%d",number);
                /*�����ĺ����㷨 ��ð������*/
                for (i = 0; i < number - 1; i++) {
                    if (info[i].sum < info[i + 1].sum) {
                        info[number] = info[i];
                        info[i] = info[i + 1];
                        info[i + 1] = info[number];
                    }
                }
            }
            if ((fp = fopen(name, "w")) == NULL) {//try to open the file
                printf("�ļ��򿪴���\n");
                exit(0);
            }
            for (i = 0; i < number; i++) {//rewrite the data after the delete handle
                if (fwrite(&info[i], sizeof (struct student_info), 1, fp) != 1)
                    printf("�ļ�д�����");
            }
            fclose(fp);

            if ((fp = fopen(name, "r")) == NULL) {//try to open the file
                printf("cannot open file\n");
                exit(0);
            }
            printf("׼����...\n��ǰѧ����Ϣ����\n\n");
            printf("=================================================\n");
            printf("����\t���\t����\t��ѧ\tӢ��\tsum\t*\n");
            for (i = 0; fread(&info[i], sizeof (struct student_info), 1, fp) != 0; i++) {
                info[i].sum = info[i].Chinese + info[i].math + info[i].english;
                printf("%s\t%d\t%d\t%d\t%d\t%d\t*\n", info[i].name, info[i].num,
                        info[i].Chinese, info[i].math, info[i].english, info[i].sum);
                number = i + 1;
            }
            printf("=================================================\n");
            printf("���� %d ����¼\n\n", i);
            fclose(fp);
            system("pause");
            break;
        case 2:
            p = "r";
            strcpy(type, p);
            number = readout(filename, type);

            for (j = 0; j < number; j++) {//sort by the sum orderly
                for (i = 0; i < number - 1; i++) {
                    if (info[i].sum > info[i + 1].sum) {
                        info[number] = info[i];
                        info[i] = info[i + 1];
                        info[i + 1] = info[number];
                    }
                }
            }
            if ((fp = fopen(name, "w")) == NULL) {//try to open the file
                printf("�ļ��򿪴���\n");
                exit(0);
            }
            for (i = 0; i < number; i++) {//rewrite the data after the delete handle
                if (fwrite(&info[i], sizeof (struct student_info), 1, fp) != 1)
                    printf("�ļ��򿪴���");
            }
            fclose(fp);

            if ((fp = fopen(name, "r")) == NULL) {//try to open the file
                printf("cannot open file\n");
                exit(0);
            }
            printf("׼����...\n��ǰѧ����Ϣ����\n\n");
            printf("=================================================\n");
            printf("n����\t���\t����\t��ѧ\tӢ��\t�ܷ�\t*\n");
            for (i = 0; fread(&info[i], sizeof (struct student_info), 1, fp) != 0; i++) {
                info[i].sum = info[i].Chinese + info[i].math + info[i].english;
                printf("%s\t%d\t%d\t%d\t%d\t%d\t*\n", info[i].name, info[i].num,
                        info[i].Chinese, info[i].math, info[i].english, info[i].sum);
                number = i + 1;
            }
            printf("=================================================\n");
            printf("���� %d ����¼\n\n", i);
            fclose(fp);
            system("pause");
            break;
        default:
            printf("����ѡ�� ������!\n");
            makechoice(filename);
    }
    makechoice(filename);

}

void deletefile(char *name)           //ɾ���ļ�
{
    FILE *fp;
    int choice;
    char delfilename[50];
    printf("ѡ��ɾ����ʽ?\n");
    printf("1 ɾ����ǰ�ļ�: 2 ɾ�������ļ�\n����ѡ��0-9����");
    scanf("%d", &choice);
    switch (choice) {
        case 2:
            printf("������Ҫɾ�����ļ���·��\npath=");
            scanf("%s", delfilename);
            if (remove(filename) == 0)
                printf("�ļ�ɾ���ɹ�!\n");
            else
                printf("�ļ�ɾ��ʧ��!\n");
            break;
        case 1:
            if (remove(filename) == 0)
                printf("�ļ�ɾ���ɹ�!\n");
            else
                printf("�ļ�ɾ��ʧ��!\n");
            break;
        default:
            printf("ѡ����� !\n");
            break;
    }
    makechoice(filename);
}

void fileinitialize(char *name)       //�ļ����ݳ�ʼ��
{
    int i, n;

    printf("������༶������?\n>Number=");
    scanf("%d", &n);

    printf("\n�����Ὣ %d ��Ϣ��¼�洢�� %s �ļ���\n\n", n, filename);

    printf("����������ѧ����������ѧ���Լ����ġ���ѧ��Ӣ���ѧ�Ƴɼ�:\n");
    for (i = 0; i < n; i++)
    {
        printf(">NO_%d ", i + 1);
        scanf("%s%d%d%d%d", info[i].name, &info[i].num, &info[i].Chinese,
                &info[i].math, &info[i].English);//�Ƿ�info[i]����.name .num .....��
        save(filename, n);
    }
    p = "r";
    strcpy(type, p);
    readout(filename, type);
    makechoice(filename);
}

void update(char *name)
{
    puts("��ǰ�ļ�������\n");
    p = "r";
    strcpy(type, p);
    readout(filename, type);
    printf("Update successfully!");
    system("pause");
    makechoice(filename);
}

void makechoice(char *name)          //��Ŀ¼
{
    time_t now;
    time(&now);
    int choice;

    printf("\n          �� <1> ��ʼ���ļ�����----------------1\n");
    printf("          �� <2> �����¼���ļ���--------------2\n");
    printf("          �� <3> ɾ����¼----------------------3\n");
    printf("          �� <4> ���������--------------------4\n");
    printf("          �� <5> ɾ���ļ�----------------------5\n");
    printf("          �� <6> �ļ�����----------------------6\n");
    printf("          �� <7> �������иĳ���----------------7\n");
    printf("          �� <8> ����--------------------------8\n");
    printf("          �� <9> ��ʾ��������------------------9\n");
    printf("          �� <0> �˳�--------------------------0\n");
    printf("          �� Ctrl+C ��ϼ������жϳ���!\n");
    printf("\n                                        ��ǰʱ��:%s\n", ctime(&now));
    printf("����ѡ��0-9����");
    scanf("%d", &choice);
    switch (choice) {
        case 1:printf("����ִ�г�ʼ������$\n");
            fileinitialize(filename);
            break;
        case 2:printf("����ִ�в������$\n");
            insert(filename);
            break;
        case 3:printf("����ִ��ɾ�����ݲ���$\n");
            deletedata(filename);
            break;
        case 4:printf("����ִ�������������$\n");
            rankout(filename);
            break;
        case 5:printf("����ִ��ɾ���ļ�����$\n");
            deletefile(filename);
            break;
        case 6:printf("����ִ���ļ����²���$\n");
            update(filename);
            break;
        case 7:system("cls");
            main();
            break;
        case 8:system("cls");
            makechoice(filename);
            break;
        case 9:printf("������ʾ$\n");
            p = "r";
            strcpy(type, p);
            readout(filename, type);
            system("pause");
            makechoice(filename);
            break;
        case 0:printf("�˳�$\n");
            exit(0);
            break;
        default:printf("����ѡ�� ������!\n");
            system("pause");
            makechoice(filename);
            break;
    }
}

int main() {
    int i, choice;
    printf("=========================================================================\n");
    printf("\t\t\t��ӭ����ѧ���ɼ�����ϵͳ\n");
    printf("=========================================================================\n");
    printf("�������ݽ��洢���ļ��У���������·�����õ����ѡ����ȷ���ļ���·��\n");
    printf("           1--------------------ʹ��Ĭ��·��\n");
    printf("           2--------------------�����Զ���·��\n");
    printf("           3--------------------��������Ĭ��·��\n");
    printf("           0--------------------�˳�\n");
    printf("����ѡ��0-3����");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            makechoice(filename);
            break;
        case 2:
            printf("Enter new path=");
            scanf("%s", filename);
            printf("\nӦΪ·�������£��ļ�����Ϊ�գ�Ҫ�������ȳ�ʼ�����ݣ�����ִ�� 1ѡ�� ����!\n");
            makechoice(filename);
            break;
        case 3:
            printf("��ǰĬ��·��:%s\n��������·��:", filename);
            scanf("%s", filename);
            printf("·������ɹ�\t��ǰ·�� :%s\n", filename);
            system("pause");
            makechoice(filename);
            break;
        case 0:
            exit(0);
        default:
            printf("����ѡ�� ������!\n");
            system("pause");
            main();
    }
}
