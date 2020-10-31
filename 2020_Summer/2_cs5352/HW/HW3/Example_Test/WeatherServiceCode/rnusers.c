#include <stdio.h>

main(argc, argv)
int argc;
char **argv;
{
	int num;
	if (argc != 2) {
		fprintf(stderr, "usage: rnusers hostname\n");
		exit(1);
	}
	if ((num = rnusers(argv[1])) < 0) {
		fprintf(stderr, "error: rnusers\n");
		exit(-1);
	}
	printf("%d users on %s\n", num, argv[1]);
	exit(0);
}
