#include "Header.h"
float getgrade(teacher** allt, char* teacheruser, char* name) {
	if (*allt == NULL) {
		printf("no teachers signed up!\n");
		return -1;
	}
	bool exist = false;
	teacher* t;
	teacher* ret;
	t = (struct teacher*) malloc(sizeof(struct teacher));
	t = *allt;
	bool contin = true;
	while (contin) {
		if (streql(t->username, teacheruser)) {
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
		return -1;
	}
	if (*(ret->firststudentptr) == NULL) {
		printf("there is no student in his class!\n");
		return -1;
	}
	student* s;
	s = (struct student*) malloc(sizeof(struct student));
	s = *(ret->firststudentptr);
	contin = true;
	exist = false;
	while (contin) {
		if (streql(s->username, name)) {
			exist = true;
			return s->grade_score;
		}
		if (s->next != NULL)
		{
			s = s->next;
		}
		else {
			contin = false;
		}
	}
	if (!exist) {
		printf("this student is not in the class! \n");
		return -1;
	}
}