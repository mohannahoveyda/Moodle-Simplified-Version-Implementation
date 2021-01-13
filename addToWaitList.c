#include "Header.h"
void addtowaitlist(teacher** allt, char* user, char* name) {
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
		printf("no such teacher exist\n");
		return;
	}

	//make the student
	student* s;
	s = (struct student*) malloc(sizeof(struct student));
	s->username = name;
	s->grade_score = -1;
	//adding him to the wait list
	s->next = *(ret->pendingstudentptr);
	*(ret->pendingstudentptr) = s;
}