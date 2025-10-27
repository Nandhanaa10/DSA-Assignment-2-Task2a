#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reply.h"

reply* createReply(const char *username, const char *content){
	reply *new = (reply*)malloc(sizeof(reply));
	if(!new){
		return NULL;
	}
	new->username = strdup(username);
	new->content = strdup(content);
	new->next = NULL;
	return new;
}
