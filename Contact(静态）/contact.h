
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
#define MAX 1000


typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

typedef struct Contact
{
	PeoInfo data[MAX];//存放数据
	int sz;//当前已有信息个数
}Contact, *pContact;

void InitContact(pContact pc);
void AddContact(pContact pc);
void ShowContact(pContact pc);
void DelContact(pContact pc);
void SearchContact(pContact pc);
void ModifyContact(pContact pc);
void SortContact(pContact pc);
void EmptyContact(pContact pc);

#endif //__CONTACT_H__


