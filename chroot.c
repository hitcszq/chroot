#include
#include
#include

int main(void)
{
    char chroot_path[] = "/tmp";
    char *pwd;
    int ret;

    /*chroot root*/
    ret = chroot(chroot_path);
    if (ret != 0) {
        perror("chroot:");
        exit(-1);
    }
    pwd = getcwd(NULL, 80);
    printf("After chroot,getcwd is [%s]\n",pwd);
    free(pwd);

    ret = chdir("/test");
    if( ret < 0 )
    {
            perror("chdir /test");
            //exit(-1);
    }
    else
         if( chdir("/") < 0 )
         {
                 perror("chdir /");
                 exit(-1);
         }

    pwd = getcwd(NULL, 80);
    printf("After chdir /,getcwd is [%s]\n",pwd);
    free(pwd);

    return 0;
}