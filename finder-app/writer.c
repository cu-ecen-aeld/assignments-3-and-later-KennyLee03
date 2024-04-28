#include <stdio.h>
#include <syslog.h>

int write_file(char *dir, char *content)
{
    syslog(LOG_DEBUG, "Writing %s to %s", content, dir);
    int ret = 0;
    // if (opendir(dir) == NULL) {
    //     syslog(LOG_DEBUG, "Directory not exist.");
    //     ret = mkdir(dir, 0x0755);
    //     if (ret)
    //         return ret;
    // }
    FILE *wf = fopen(dir, "wb");
    if (wf == NULL)
        syslog(LOG_ERR, "Cannot open file");
    ret = fputs(content, wf);
    if (ret) {
        syslog(LOG_ERR, "Cannot write to file");
        return 1;
    }
    fclose(wf);

    return  0;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    if (argc != 3)
        return 1;
    write_file(argv[1], argv[2]);
    closelog();

    return 0;
}