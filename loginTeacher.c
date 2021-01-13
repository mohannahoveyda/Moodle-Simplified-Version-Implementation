#include "Header.h"
bool LoginTeacher(teacher** allt, char* user, char* pass) {
	if (*allt == NULL) {
		printf("no teachers signed up!\n");
		return false;
	}
	bool exist = false;
	teacher* t;
	teacher* ret;
	t = (struct teacher*) malloc(sizeof(struct teacher));
	t = *allt;
	bool contin = true;
	while (contin) {
		if (streql(t->username, user) && streql(t->password, pass)) {
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
	return exist;
}