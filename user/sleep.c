#include "kernel/types.h"
#include "user/user.h"

int main()
{
	int seconds;
	char buf[64];
	
		int n = read(0,buf,sizeof(buf));
		if(n<=0)
			exit(1);
		seconds=atoi(buf);
		sleep(seconds);
	exit(0);
}
