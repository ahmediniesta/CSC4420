#include <sys/types.h>
#include"stdio.h"
#include <unistd.h>
int globalVariable = 2;
int main()
{
	char parentStr[] = "Parent Process";
	char childStr[] = "Child Process";
	char *string = NULL;
	int functionVariable = 20;

	// Create a child process.
	pid_t processID; //pid_t is like int, double, etc.

	if ((processID = fork()) == -1) // Failed to fork
	{
		perror("Unable to create child process");
		return 1;
	}

	else if (processID == 0) // child
	{
		// Code only executed by child process
		string = &childStr[0];
		globalVariable++;
		functionVariable++;
	}

	if (processID > 0)		// parent
	{
		// Code only executed by parent process
		string = &parentStr[0];
		globalVariable += 2;
		functionVariable += 2;
	}

	// Code executed by both parent and child.
	printf("%s\n", string);
	printf(" Global Variable: %d\n",globalVariable);
	printf(" Function Variable: %d\n", functionVariable);
}
