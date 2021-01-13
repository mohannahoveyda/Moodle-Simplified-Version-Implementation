#include "Header.h"
void showwaitlist(teacher** allt, char* user) {
	if (*allt == NULL) {
		printf("no teachers signed up!\n");
		return;
	}
	bool exist = false;
	teacher* t;
	teacher* ret;
	t = (struct teacher*) malloc(sizeof(struct teacher));
	t = *allt;
	bool contin = true;
	while (contin) {
		if (streql(t->username, user)) {
			ret = t;
			exist = true;
		}
		if (t->nextteacher != NULL)
		{
			t = t->nextteacher;
		}
		else {
			contin = false;
		}
	}
	if (!exist) {
		printf("no such teacher existed. \n");
		return;
	}
	printf("\n  -------------%s WAITING LIST------------- \n", user);
	if (*(ret->pendingstudentptr) == NULL) {
		printf("your pending list is empty \n-------------------------------\n");
		return;
	}
	student* s;
	s = (struct student*) malloc(sizeof(struct student));
	s = *(ret->pendingstudentptr);
	contin = true;
	while (contin) {
		printf("user:%s \n", s->username);
		if (s->next != NULL)
		{
			s = s->next;
		}
		else {
			contin = false;
		}
	}
	printf("--------------------------------------------\n \n");
}