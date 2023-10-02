#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 30

//��̬�汾�����һЩ��
#define DEFAULT_SZ 3
#define INC_SZ 2



typedef struct people
{
	char name[MAX_NAME];
	int age;
	char sex[5];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}people;
//��̬�汾
//typedef struct contact
//{
//	people data[MAX];
//	int sz;//��¼�ж�������Ϣ
//}contact;


//��̬�汾
typedef struct contact
{
	people* data;//ָ���˴�����ݵĿռ�
	int sz;//��¼�ж�������Ϣ
	int capacity;//ͨѶ¼��ǰ������
}contact;

void initcontact(contact* pc);
void Addcontact(contact* pc);
void Showcontact(const contact* pc);
void Delcontact(contact* pc);
void Searchcontact(const contact* pc);
void Modifycontact(contact* pc);
void Sortcontact(contact* pc);
void Deleteontact(contact* pc);
void Savecontact(contact* pc);