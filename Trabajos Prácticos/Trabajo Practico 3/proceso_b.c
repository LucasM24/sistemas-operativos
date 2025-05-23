#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	const char *name = "OS";
	const int SIZE = 512000;
	
	int shm_fd;
	void *ptr;
	int i;
	
	/* open the shared memory segment */
	shm_fd = shm_open(name, O_RDONLY, 0666); 
	if(shm_fd == -1) {
		printf("shared memory failed\n");
		exit(-1);
	}

	/* now map the shared memory segment in the address space of the process */
	ptr = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if(ptr == MAP_FAILED) {
		printf("MAP FAILED\n");
		exit(-1);
	}

	/* now read from memory segment */
	printf("%s", (char *)ptr);


	/* now read from memory segment */
	if(shm_unlink(name) == -1) {
		printf("Error removing %s\n", name);
		exit(1);
	}

	return 0;
}
