#include "Header.h"
bool istherestudent(student** alls, char* user) {
	if (*alls == NULL) {
		return false;
	}
	bool exist = false;
	student* s;
	s = (struct student*) malloc(sizeof(struct student));
	s = *alls;
	bool contin = true;
	while (contin) {
		if (streql(s->username, user)) {
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