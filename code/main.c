#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "platform.h"
#include "post.h"
#include "comment.h"
#include "reply.h"

void printPostDetails(post *p){
	if(!p){
		return;
	}
	printf("\n Post by: %s\n",p->username);
	printf("Caption: %s\n", p->caption);
	comment *c = p->comments;
	int cnum=1;
	while(c){
		printf(" comment %d by %s: %s\n",cnum,c->username,c->content);
		reply *r = c->replies;
		int rnum=1;
		while(r){
			printf("reply %d by %s: %s\n",rnum,r->username,r->content);
			r=r->next;
			rnum++;
		}
		c=c->next;
		cnum++;
	}
}

void showMenu(){
	printf("WELCOME TO THE PLATFORM!");
	printf("1.add post \n2.View post by number \n3.Add comment to current post \n4.Add reply to comment \n5.Delete post \n6.delete comment \n7.delete reply \n8.view current post details \n9.next post \n10.Previous post \n0.exit \n");
	printf("enter choice: ");
}

int main(){
	platform *platform = createPlatform();
	if(!platform){
		return 0;
	}
	int choice;
	char username[100],caption[500],content[500];
	int n,m;
	while(1){
		printf("\n");
		showMenu();
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1:
				printf("enter username: ");
				fgets(username,100,stdin);
				username[strcspn(username,"\n")]=0;
				printf("enter caption: ");
				fgets(caption,500,stdin);
				caption[strcspn(caption,"\n")]=0;
				if(addPost(platform, username, caption)){
					printf("post added");
				}
				else{
					printf("failed to add post");
				}
				break;
			case 2:
				printf("enter post number to view: ");
				scanf("%d",&n);
				getchar();
				post *p = viewPost(platform,n);
				if(p){
					printPostDetails(p);
				}
				else{
					printf("post not found");
				}
				break;
			case 3:
				printf("enter username ");
				fgets(username,100,stdin);
				username[strcspn(username,"\n")]=0;
				printf("enter comment content: ");
				fgets(content,500,stdin);
				content[strcspn(content,"\n")]=0;
				if(addComment(platform,username,content)){
					printf("comment added");
				}
				else{
					printf("failed to add comment");
				}
				break;
			case 4:
				printf("enter comment number to reply to: ");
				scanf("%d",&n);
				getchar();
				printf("enter username: ");
				fgets(username,100,stdin);
				username[strcspn(username,"\n")]=0;
				printf("enter reply content:");
				fgets(content,500,stdin);
				content[strcspn(content,"\n")]=0;
				if(addReply(platform,username,content,n)){
					printf("reply added");
				}
				else{
					printf("failed to add reply");
				}
				break;
				
			case 5:
				printf("enter post number to delete: ");
				scanf("%d",&n);
				getchar();
				if(deletePost(platform,n)){
				printf("post deleted");
				}
				else{
					printf("failed to delete post");
				}
				break;
			case 6:
				printf("enter comment number to delete:");
				scanf("%d",&n);
				getchar();
				if(deleteComment(platform,n)){
					printf("comment deleted");
				}
				else{
					printf("failed to delete comment");
				}
				break;
			case 7:
				printf("Enter comment number: ");
                		scanf("%d", &n);
                		printf("Enter reply number: ");
                		scanf("%d", &m);
                		getchar();
                		if (deleteReply(platform, n, m)){
                    			printf("Reply deleted.\n");
                    		}
                		else{
                    			printf("1Could not delete reply.\n");
                    		}
                		break;
                	case 8:
                		printPostDetails(currPost(platform));
                		break;
                	case 9:
                		printPostDetails(nextPost(platform));
                		break;
                	case 10:
                		printPostDetails(previousPost(platform));
                		break;
                	case 0:
                		printf("Exiting\n");
                		exit(0);
                	default:
                		printf("Invalid choice.\n");
		}
	}
}
