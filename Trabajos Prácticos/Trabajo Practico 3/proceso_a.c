#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	const int SIZE = 512000;
	unsigned char buffer[SIZE];
	const char *pathname = "/usr/share/doc/aufs-dkms/filesystems/aufs/design/06mmap.txt";
	const char *name = "OS";
	
	int shm_fd;
	void *ptr;
	int fd;
	int data;
	int n;
	
	fd = open(pathname,0);

	/* create the shared memory segment */

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

	/* Configure the size of the shared memory segment */
	ftruncate(shm_fd,SIZE);

	ptr = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if(ptr == MAP_FAILED) {
		printf("MAP FAILED\n");
		return -1;
	}


	while ( (n = read(fd, buffer,1)) > 0 ) {
		sprintf(ptr, "%s", buffer);

		ptr += strlen(buffer);
	}

	close(fd);

	return 0;
}
