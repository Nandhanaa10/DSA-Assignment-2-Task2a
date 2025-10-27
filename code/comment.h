/*
The comments on the posts must store the following information:
 1. Username: Username of the user commenting
 2. Content: Content of the comment
 3. Replies: List of replies to the comment by different users

 Function Name - createComment
 Parameters - username , content
 return value - comment 
 description - Creates a comment using the given parameters, returning a pointer to it
*/

#ifndef comment_h
#define comment_h
#include "reply.h"

typedef struct comment{
	char *username;
	char *content;
	reply *replies; // each comment can have replies
	struct comment *next; //each comment points to the next comment also
}comment;
comment* createComment(const char *username, const char *content);
#endif
