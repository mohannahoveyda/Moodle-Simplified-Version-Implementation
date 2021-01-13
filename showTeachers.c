#include "Header.h"
void showteachers(teacher** allt, char* studentname) {
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
	bool con = true;
	student* s;
	printf("--------your teachers list-----------\n");
	while (contin) {

		s = (struct student*) malloc(sizeof(struct student));
		s = *(t->firststudentptr);
		con = true;
		while (con) {
			if (streql(s->username, studentname)) {
				printf("teacher:  %s     grade:%f\n", t->username, s->grade_score);
				exist = true;
				con = false;
			}
			if (s->next != NULL)
			{
				s = s->next;
			}
			else {
				con = false;
			}
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
		printf("you have no teachers. \n");
		return;
	}
	printf("----------------------------------- \n");
}