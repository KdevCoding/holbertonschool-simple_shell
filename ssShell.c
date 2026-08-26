#include "main.h"

int main()
{
	while (1)
	{
		char *inbuf = 0;
		int ret;

		ret = readline(&inbuf);
		inbuf[strcspn(inbuf, "\n")] = '\0';
		if (strcmp(inbuf, "exit") == 0)
		{
			free(inbuf);
			exit(1);
		}
		if (ret >= 0)
			forkexec(inbuf);
		else
		{
			perror("error");
			free(inbuf);
			return (1);
		}
	}
	return (0);
}