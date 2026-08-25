#include "main.h"

int main()
{
	int active;

	active = 1;
	while (active)
	{
		char *inbuf = 0;
		int ret;

		ret = readline(&inbuf);

		if (ret >= 0)
			forkexec(inbuf);
		else
		{
			perror("error: ");
			free(inbuf);
			return (1);
		}
	}
	return (0);
}