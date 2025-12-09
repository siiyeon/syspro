#include <sys/types.h>

int main()
{
 int pid, child, status;
 pid = fork();
 if (pid == 0) {
 exit(1);
 }
 child = wait(&status); 
 
}
