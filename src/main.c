#include <los/filesystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    if (argc != 2 && argc != 3) {
        printf("Usage: %s file [length]\n", argv[0]);
        return 1;
    }

    int64_t fd = open_file(argv[1], OPEN_WRITE | OPEN_CREATE);
    if (fd < 0) {
        printf("Error while opening %s: %s\n", argv[1], strerror(fd));
        return 1;
    }

    uint64_t length = 0;
    if (argc == 3)
        length = strtoul(argv[2], NULL, 10);

    int64_t status = truncate_file(fd, length);
    if (status < 0) {
        printf("Error while truncating %s: %s\n", argv[1], strerror(status));
        return 1;
    }

    close_file(fd);
}
