#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (argc != 1) {
		fprintf(stderr, "Usage: %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("$ ");
	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		if (strcmp(line, "exit\n") == 0){
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(line, "\n") == 0)
		{
			printf("$ ");
			continue;
		}
		fwrite(line, 1, nread, stdout);
		printf("$ ");
	}
	free(line);
	putchar(10);
	exit(EXIT_SUCCESS);
}
