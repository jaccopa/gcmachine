#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_fn(int sig)
{
	printf("alarm!\n");
	alarm(1);
	return;
}

int main(void)
{
	signal(SIGALRM,signal_fn);
	alarm(1);
	while(1)pause();
}
