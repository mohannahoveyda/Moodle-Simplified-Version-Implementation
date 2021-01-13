#include "Header.h"
void showteachersandgrades(teacher** allt, char* studentname) {
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
	int numberofcourses = 0;
	float sum = 0;
	printf("--------your grades list-----------\n");
	while (contin) {

		s = (struct student*) malloc(sizeof(struct student));
		s = *(t->firststudentptr);
		con = true;
		while (con) {
			if (streql(s->username, studentname)) {
				if (s->grade_score>0) {
					printf("teacher:%s    your grade:%f \n", t->username, s->grade_score);
					numberofcourses++;
					sum += s->grade_score;
				}
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
		s->grade_score;
		return;
	}
	if (numberofcourses>0) {
		printf("         average:%f \n", sum / numberofcourses);
	}
	printf("----------------------------------- \n");
}