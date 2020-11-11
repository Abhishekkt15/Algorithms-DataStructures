#include <assert.h>
#include "dlist.h"

int main()
{

//10.Create double linked list with methods to add, remove, to check the existence of element.


	Slist s = slist_new();
	Slist *list = &s;

	list=slist_add_tail(list,10);
	list=slist_add_tail(list,20);
	list=slist_add_tail(list,30);
	list=slist_add_tail(list,40);

	list=slist_delete_tail(list);
	list=slist_delete_tail(list);

	assert(slist_lookup(list,20)==1);
	assert(slist_lookup(list,80)==0);

	slist_add_head(list,30);
	slist_add_head(list,40);

	slist_delete_head(list);
	assert(slist_length(list)!=2);
	slist_delete_head(list);
	slist_delete_head(list);

	slist_delete_head(list);

	assert(slist_length(list)==0);
	slist_add_head(list,30);

	assert(slist_length(list)==1);
	return 0;
}
