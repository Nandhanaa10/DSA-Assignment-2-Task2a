/*
The replies to the comments on a post must store the following information:
 1. Username: Username of the user replying
 2. Content: Content of the reply

 Function Name - createReply
 Parameters - username , content
 return Value - reply 
 Description - creates a reply using the given parameters, returning a pointer to it
*/
#ifndef reply_h
#define reply_h

typedef struct reply{
	char *username;
	char *content;
	struct reply *next;
}reply;

reply* createReply(const char *username, const char *content);

#endif
