#include "Header.h"
void gradestudent(teacher** allt, char* user, char* name, float grade) {

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
		printf("no such teacher exist! \n");
		return;
	}
	if (*(ret->firststudentptr) == NULL) {
		printf("class list is empty! \n");
		return;
	}
	//////////////search for student
	student* s;
	student* returnendstudent;
	s = (struct student*) malloc(sizeof(struct student));
	s = *(ret->firststudentptr);
	contin = true;
	exist = false;
	while (contin) {
		if (streql(s->username, name)) {
			exist = true;
			returnendstudent = s;
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
		printf("no such student exist in your pending list! \n");
		return;
	}
	returnendstudent->grade_score = grade;
}
