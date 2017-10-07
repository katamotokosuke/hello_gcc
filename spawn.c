//1 forkする
//2 子プロセスで新しいプログラムをexecする
//3 親プロセスは子プロセスをwaitする

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//  ./spawn program pass, 1arg option
int main(int argc, char *argv[])
{
    pid_t pid;
    if (argc != 3){ //引数エラー
        fprintf(stderr, "Usage: %s <command> <arg>\n", argv[0]);
        exit(0);
    }

    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork(2) failed\n");
        exit(1);
    }

    if (pid == 0){ //子プロセス
       execl(argv[1], argv[1], argv[2], NULL);
       //execl()が呼び出しから戻れば失敗
       perror(argv[1]);
       exit(99);
    } else {//親プロセス
        int status;

        waitpid(pid, &status, 0);

        printf("child (PID=%d) finished", pid);
        if (WIFEXITED(status)){
            printf("exit status=%d\n", WEXITSTATUS(status));
        } else if ( WIFSIGNALED(status)){
            printf(" signal, sig=%d\n", WTERMSIG(status));
        } else {
            printf("abnormal exit\n");
            exit(0);
        }
    }
}
