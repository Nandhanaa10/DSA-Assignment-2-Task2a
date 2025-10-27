/*
 The social media platform ADT, must store the following information:
 1. Posts: Lists of posts stored in some order of the time they were posted at
 2. lastViewedPost: The last viewed post on the terminal. By view, it means the
 one of which the details were shown latestly. If this does not hold for any post, it
 is the most recently added post till now.

 Function name - createPlatform 
 Parameters - no parameters
 return value - platform
 description -  Create an instance of the platform datatype. Only one such instance
 should be made throughout the code

 Function name - addPost
 Parameters - username , caption
 Return Value - bool posted 
 Description - create a post of the given parameter(by calling the previous implemented function)
 and adds it to the existing list of posts, returning whether the process is successful or not

 Function name - deletePost
 Parameters - int n
 Return Value - bool deleted
 Description - deletes the nth recent post, returnging whether the deletion is successful or not
 also it should clear the comments and replies as well to the post

 Function name - viewPost
 Parameters - int n
 Return Value - post
 Description - Returns the nth recent post, if existing.if it does not exist, a null pointer 
 must be returned

 Function name - currPost
 Parameters - 
 Return Value - post
 Description -  Returns the viewed post. as described earlier this post will be the most recent
 post, if no other post has been viewed. if no post has been done , a null pointer must be returned

 Function name - nextPost
 Parameters - 
 Return Value - post
 Description -  Returns post which was posted just before posting the lastViewedPost.
 If the lastViewedPost is the first posttobeadded, then return it. In caseof any 
 error, a NULL pointer must be returned. Doing this operation, will change the lastViewed
 Post, by it’s definition

 Function name - previousPost
 Parameters - 
 Return Value - post
 Description -  Returns post which was posted just after posting the lastViewedPost. If
 the lastViewedPost is the most recent to be added,then return it. In case of 
 any error, a NULL pointer must be returned. Doing this operation , will change
 the lastViewedPost , by it’s definition

 Function name - addComment
 Parameter - username , content
 Return Value - bool commented
 Description -  Adds a comment to the lastViewedPost, returning whether the addition
 is successful or not

 Function name - deleteComment
 Parameter - int n
 Return Value - bool deleted
 Description - Deletes the nth recent comment to the lastViewedPost, returning
 whether the deletion is successful or not. Also, it should clear the replies
 to the comment as well

 Function name - viewComments
 Parameter -
 Return value - comments
 description -  Returns a list of all comments to the lastViewedPost. The order of the
 comments in the list must be in order of the time of commenting, the
 latest being at last. The order of
 replies should be the same as well

 Function name - addReply 
 Parameter - username , content , n
 Return Value - bool replied
 Description -  Adds a reply to the nth recent comment of the lastViewedPost, returning whether
 the addition is successful or not

 Function name - deleteReply
 Parameter - int n , int m
 Return Value - bool deleted
 Description - Deletes the mth recent reply to the nth recent comment of the
 lastViewedPost, returning whether the deletion is successful or not
*/

#ifndef platform_h
#define platform_h
#include <stdbool.h>
#include "post.h"

typedef struct platform{
	post *posts;
	post *lastviewedpost;
}platform;

platform* createPlatform();
bool addPost(platform *platform,const char *username, const char *caption);
bool deletePost(platform *platform,int n);
post *viewPost(platform *platform,int n);
post* currPost(platform *platform);
post* nextPost(platform *platform);
post* previousPost(platform *platform);
bool addComment(platform *platform,const char *username, const char *content);
bool deleteComment(platform *platform,int n);
comment* viewComments(platform *platform);
bool addReply (platform *platform , const char *username,char const *content,int n);
bool deleteReply (platform *platform,int n , int m);
#endif

