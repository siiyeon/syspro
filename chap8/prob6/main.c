#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

int main(void) {
    uid_t ruid = getuid(), euid = geteuid();
    gid_t rgid = getgid(), egid = getegid();

    struct passwd *rpw = getpwuid(ruid);
    struct passwd *epw = getpwuid(euid);
    struct group  *rg  = getgrgid(rgid);
    struct group  *eg  = getgrgid(egid);

    printf("real user ID    : %d(%s)\n",  (int)ruid, rpw ? rpw->pw_name : "unknown");
    printf("effective user ID: %d(%s)\n", (int)euid, epw ? epw->pw_name : "unknown");
    printf("real group ID   : %d(%s)\n",  (int)rgid, rg  ? rg->gr_name  : "unknown");
    printf("effective group ID: %d(%s)\n",(int)egid, eg  ? eg->gr_name  : "unknown");
    return 0;
}

