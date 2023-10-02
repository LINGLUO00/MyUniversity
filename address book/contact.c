#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//��̬�汾
//void initcontact(contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

int CheckCapacity(contact* pc);
void Loadcontact(contact* pc)
{
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		perror("Loadcontact::fopen");
		return;
	}
	people tmp = { 0 };
	while (fread(&tmp,sizeof(people),1,pf))
	{
		CheckCapacity(pc);

		pc->data[pc->sz] = tmp;
		pc->sz++;
	}


	fclose(pf);
	pf = NULL;
}
//��̬
void initcontact(contact* pc)
{
	pc->sz = 0;
	pc->data = malloc(DEFAULT_SZ * sizeof(people));
	if (pc->data == NULL)
	{
		perror("ͨѶ¼��ʼ��ʧ��");
	}
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	//�������е���Ϣ
	Loadcontact(pc);
}

static int Findbyname(const contact* pc,char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
//��̬
//void Addcontact(contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("ͨѶ¼�������޷�����\n");
//		return;
//	}
//	printf("����������:>");
//	scanf("%s", (pc->data[pc->sz]).name);
//	printf("����:>");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("�Ա�:>");
//	scanf("%s", (pc->data[pc->sz]).sex);
//	printf("�绰:>");
//	scanf("%s", (pc->data[pc->sz]).tele);
//	printf("��ַ:>");
//	scanf("%s", (pc->data[pc->sz]).addr);
//	(pc->sz)++;
//	printf("��ӳɹ�");
//}

//��̬
int CheckCapacity(contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		people *ptr = (people*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(people));
		if (ptr == NULL) 
		{
			perror("CheckCapacity");
			return 0;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ�������Ϊ: %d\n", pc->capacity);
			return 1;
		}
	}
	return 1;
}
//��̬
void Addcontact(contact* pc)
{
	if (0 == CheckCapacity(pc))//�������
	{
		printf("����ʧ��");
		return;
	}
	else
	{
		printf("����������:>");
		scanf("%s", (pc->data[pc->sz]).name);
		printf("����:>");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("�Ա�:>");
		scanf("%s", (pc->data[pc->sz]).sex);
		printf("�绰:>");
		scanf("%s", (pc->data[pc->sz]).tele);
		printf("��ַ:>");
		scanf("%s", (pc->data[pc->sz]).addr);
		(pc->sz)++;
		printf("��ӳɹ�\n");
	}
}

void Showcontact(const contact* pc)
{
	int i = 0;
	printf("%-8s %-4s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-8s %-4d %-5s %-12s %-30s\n", 
			pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}

void Delcontact(contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	printf("ɾ���˵�����:>");
	scanf("%s", name);
	int i = 0;
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("ɾ�����˲�����\n");
		return;
	}
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

void Searchcontact(const contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("����������:>");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("���ҵ��˲�����\n");
		return;
	}
	
	printf("%-8s %-4s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-8s %-4d %-5s %-12s %-30s\n",
		pc->data[pos].name, 
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);
}


void Modifycontact(contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("����������:>");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("�޸ĵ��˲�����\n");
		return;
	}
	printf("����������:>");
	scanf("%s", (pc->data[pc->sz]).name);
	printf("����:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�Ա�:>");
	scanf("%s", (pc->data[pc->sz]).sex);
	printf("�绰:>");
	scanf("%s", (pc->data[pc->sz]).tele);
	printf("��ַ:>");
	scanf("%s", (pc->data[pc->sz]).addr);
	printf("�޸ĳɹ�\n");

}
static int Cmpbyname(const void* p1, const void* p2)
{
	return strcmp(((people*)p1)->name, ((people*)p2)->name);
}
void Sortcontact(contact* pc)
{

	qsort(pc->data, pc->sz, sizeof(people), Cmpbyname);
	printf("����ɹ�");
}

void Deleteontact(contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}


//����
void Savecontact(contact* pc)
{
	FILE* pf = fopen("contact.dat", "wb");
	if (pf == NULL)
	{
		perror("Savecontact::fopen");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(people), 1, pf);
	}




	fclose(pf);
	pf = NULL;
	printf("�ѱ���");
}