#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comment.h"

comment* createComment(const char *username,const char *content){
	comment *new = (comment*)malloc(sizeof(comment));
	if(!new){
		return NULL;
	}
	new->username = strdup(username);
	new->content = strdup(content);
	new->replies=NULL;
	new->next=NULL;
	return new;
}
