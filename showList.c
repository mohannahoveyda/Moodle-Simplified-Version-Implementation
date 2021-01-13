#include "Header.h"
void showlist(teacher** allt, char* user) {
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
			exist = true;
			ret = t;
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
		printf("no such teacher existed.\n");
		return;
	}
	printf("\n----------------%s CLASS LIST------------------\n", user);
	if (*(ret->firststudentptr) == NULL) {
		printf("no students enrolled in your class.\n");
		printf("\n---------------------------------\n");
		return;
	}
	student* s;
	s = (struct student*) malloc(sizeof(struct student));
	s = *(ret->firststudentptr);
	contin = true;
	while (contin) {
		printf("user:%s \t", s->username);
		printf("grade:%f \n", s->grade_score);
		if (s->next != NULL)
		{
			s = s->next;
		}
		else {
			contin = false;
		}
	}
	printf("\n---------------------------------\n");
}