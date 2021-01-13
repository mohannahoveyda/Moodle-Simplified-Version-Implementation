#include "Header.h"
bool LoginStudent(student** alls, char* user, char* pass) {
	if (*alls == NULL) {
		printf("no students signed up!\n");
		return false;
	}
	bool exist = false;
	student* s;
	s = (struct student*) malloc(sizeof(struct student));
	s = *alls;
	bool contin = true;
	while (contin) {
		if (streql(s->username, user) && streql(s->password, pass)) {
			exist = true;
		}
		if (s->next != NULL)
		{
			s = s->next;
		}
		else {
			contin = false;
		}
	}
	return exist;
}