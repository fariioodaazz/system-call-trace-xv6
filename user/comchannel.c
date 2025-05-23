#include "kernel/types.h"
#include "user/user.h"

int main(){
	int fds[2];
	char buf[100];
	int n;
	
	
	
	int pid=fork();
	pipe(fds);
	
	if (pid==0){
	  write(fds[1],"Child\n",6);
	}
	else{                                                              
	  write(fds[1],"parent\n",7);
	}

		n=read(fds[0],buf,sizeof(buf));
	  write(1,buf,n);
	
	exit(0);
}
