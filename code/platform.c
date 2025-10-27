#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "platform.h"
#include "post.h"

platform* createPlatform(){
	platform *pf= (platform*)malloc(sizeof(platform));
	if(!pf){
		return NULL;
	}
	pf->posts = NULL;
	pf->lastviewedpost=NULL;
	return pf;
}

bool addPost(platform *platform,const char *username,const char *caption){
	if(!platform){
		return false;
	}
	post *new = createPost(username,caption);
	if(!new){
		return false;
	}
	new->next=platform->posts;
	platform->posts=new;
	if(!platform->lastviewedpost){
		platform->lastviewedpost = new;	
	}
	return true;
}

bool deletePost(platform *platform, int n){
	if(!platform || !platform->posts || n<=0){
		return false;
	}
	post *curr = platform->posts;
	post *prev = NULL ;
	for (int i=1; curr && i<n ; i++){
		prev=curr;
		curr=curr->next;
	}
	if(!curr){
		return false;
	}
	if(prev){
		prev->next = curr->next;
	}
	else{
		platform->posts = curr->next;
	}
	if(platform->lastviewedpost == curr){
		platform->lastviewedpost = platform->posts;
	}
	free_post(curr);
	return true;
}	
post* viewPost(platform *platform, int n){
		if(!platform || !platform->posts || n<=0){
			return NULL;
		}
		post *curr = platform->posts;
		for(int i=1;curr && i<n;i++){
			curr=curr->next;
		}
		if(!curr){
			return NULL;
		}
		platform->lastviewedpost = curr;
		return curr;
}
	
post* currPost(platform *platform){
		if(!platform || !platform->posts){
			return NULL;
		}
		if(!platform->lastviewedpost){
			platform->lastviewedpost = platform->posts;
		}
		return platform->lastviewedpost;
}
	
post* nextPost(platform *platform){
		if(!platform || !platform->posts || !platform->lastviewedpost){
			return NULL;
		}
		post *curr = platform->posts;
		post *prev = NULL;
		
		while(curr && curr!=platform->lastviewedpost){
			prev=curr;
			curr=curr->next;
		}
		if(!curr){
			return NULL;
		}
		if(curr->next){
			platform->lastviewedpost = curr->next;
			return curr->next;
		}
		printf("Next post doesn't exist.\n");
		return curr;
}
	
post* previousPost(platform * platform){
		if(!platform || !platform->posts || !platform->lastviewedpost){
			return NULL;
		}
		if(platform->lastviewedpost == platform->posts){
			printf("Previous post doesn't exist.\n");
			return platform->lastviewedpost;
		}
		post *curr = platform->posts;
		post *prev = NULL;
		
		while(curr && curr->next!=platform->lastviewedpost){
			curr=curr->next;
		}
		if(!curr){
			return NULL;
		}
		platform->lastviewedpost = curr;
		return curr;
}
	
bool addComment(platform *platform,const char *username,const char *content){
		if(!platform || !platform->lastviewedpost){
			return false;
		}
		comment *new = createComment(username,content);
		if(!new){
			return false;
		}
		if(!platform->lastviewedpost->comments){
			platform->lastviewedpost->comments=new;
		}
		else{
			comment *temp = platform->lastviewedpost->comments;
			while(temp->next){
				temp=temp->next;
			}
			temp->next=new;
		}
		return true;
}
	
bool deleteComment(platform *platform,int n){
		if(!platform || !platform->lastviewedpost || !platform->lastviewedpost->comments){
			return false;
		}
		comment *prev = NULL;
		comment *curr = platform->lastviewedpost->comments;
		int count=1;
		while(curr && count<n){
			prev=curr;
			curr=curr->next;
			count++;
		}
		if(!curr){
			return false;
		}
		if(prev==NULL){
			platform->lastviewedpost->comments=curr->next;
		}
		else{
			prev->next = curr->next;
		}
		
		reply *rep = curr->replies;
		while(rep){
			reply *temprep = rep;
			rep = rep->next;
			free(temprep->username);
			free(temprep->content);
			free(temprep);
		}
		free(curr->username);
		free(curr->content);
		free(curr);
		return true;
}

comment* viewComments(platform *platform){
	if(!platform || !platform->lastviewedpost){
		return NULL;
	}
	return platform->lastviewedpost->comments;
}

bool addReply(platform *platform,const char *username , const char *content , int n){
	if(!platform || !platform->lastviewedpost){
		return false;
	}
	comment *com = platform->lastviewedpost->comments;
	int count=1;
	while(com && count<n){
		com=com->next;
		count++;
	}
	if(!com){
		return false;
	}
	reply *newrep = createReply(username,content);
	if(!newrep){
		return false;
	}
	if(!com->replies){
		com->replies = newrep;
	}
	else{
		reply *temp = com->replies;
		while(temp->next){
			temp=temp->next;
		}
		temp->next = newrep;
	}
	
	return true;
}

bool deleteReply(platform *platform,int n, int m){
	if(!platform || !platform->lastviewedpost){
		return false;
	}
	comment *c = platform->lastviewedpost->comments;
	int count=1;
	while(c && count<n){
		c=c->next;
		count++;
	}
	if(!c || !c->replies){
		return false;
	}
	reply *prev= NULL;
	reply *curr=c->replies;
	int replycount=1;
	while(curr && replycount<m){
		prev=curr;
		curr=curr->next;
		replycount++;
	}
	if (!curr){
		return false;
	}
	if (prev == NULL){
        	c->replies = curr->next;
        }
        else{
        	prev->next = curr->next;
	}
    	free(curr->username);
    	free(curr->content);
    	free(curr);
    	return true;
}
