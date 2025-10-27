/*
The posts on the social media platform must store the following information:
 1. Username: Username of the user posting (Always a single string)
 2. Caption: Caption to the post by the user
 3. Comments: List of comments on the post, by different users

 Function name - createPost
 Parameters - username , caption
 Return Value - Post
 Description - Creates a post using the given parameters, returning a 
 pointer to it
*/

#ifndef post_h
#define post_h
#include "comment.h"

typedef struct post{
	char *username;
	char *caption;
	comment *comments; //post can have comments
	struct post *next;
}post;

post* createPost(const char *username,const char *caption);
void free_post(post *post);

#endif
