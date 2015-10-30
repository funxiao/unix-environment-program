#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
using namespace std;

int main() {

	int n, fd[2];
	char line[1024];
	pid_t pid;

	if (pipe(fd) < 0) {
		printf("pipe error\n");
	}

	if ((pid = fork()) < 0) {
		printf("fork error! \n");
	} else if (pid > 0) {
		close (fd[0]);
		write (fd[1], "hello world!66666\n", 25);
	} else {
		close (fd[1]);
		n = read (fd[0], line, 1024);
		write (STDOUT_FILENO, line, n);
	}

	return 0;
}
