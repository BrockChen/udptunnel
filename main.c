#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <utun/conf.h>
/*
char g_password[20];
char g_remoteip[20];
char g_tunname[20];
char g_net[20];
char g_remoteport[8];
char g_others[100];
*/
int g_servermode=1;

#define BZERO(var) bzero(var, sizeof(var))

static void usage(void)
{
    (void)fprintf(stderr,
        "usage: server [-p password] [-c remote_ip] [-P port] [-i tunx] [-n 10.1.1] [-I dev]\n");
    exit(2);
}

int main(int argc, char *argv[]) {
    //char *opt;
    int i;

    int cnt = 0;

    if (argc < 2)
        usage();
    BZERO(g_password);
    BZERO(g_remoteip);
    BZERO(g_tunname);
    BZERO(g_net);
    BZERO(g_remoteport);
    BZERO(g_dev);
    //BZERO(g_others);    
    while((i = getopt(argc, argv, "hP:p:c:i:n:d:")) != -1) {
        switch(i) {
            case 'h': usage();
            case 'p': strcpy(g_password, optarg); cnt = cnt+2; break;
            case 'P': strcpy(g_remoteport, optarg); cnt = cnt+2; break;
            case 'I': strcpy(g_dev, optarg); cnt = cnt+2; break;
            case 'c': {
                //strcpy(g_remoteip, optarg);
                g_servermode = 0;
                strcpy(g_remoteip, optarg);
                cnt = cnt+2; break;
            }
            case 'i': strcpy(g_tunname, optarg); cnt = cnt+2; break;
            case 'n': strcpy(g_net, optarg); cnt = cnt+2; break;
            default: usage();
        }
    }
	/*
    if (cnt < argc - 1){

        strcpy(g_others, argv[++cnt]);
    }*/

    printf("g_password: %s\ng_remoteip: %s\ng_tunname: %s\ng_net: %s\n", g_password, g_remoteip, g_tunname, g_net);
    
    printf("port: %s\n", g_remoteport);
    //printf("anyargs: %s\n", g_others);
    if(g_servermode==1) server();
    else client();
}
