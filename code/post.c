#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "post.h"

post* createPost(const char *username, const char *caption){
	post *new = (post*)malloc(sizeof(post));
	if(!new){
		return NULL;
	}
	new->username = strdup(username);
	new->caption = strdup(caption);
	new->comments = NULL;
	new->next=NULL;
	return new;
}

void free_post(post *post){
	if(!post)return;
	free(post->comments);
	free(post->username);
	free(post->caption);
	free(post);
}
