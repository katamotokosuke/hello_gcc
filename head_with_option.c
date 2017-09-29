#include <stdio.h>
#include <stdlib.h>


#define _GNU_SOURCE
#include <getopt.h>

static void do_head(FILE *f, long nlines);

#define DEFAULT_N_LINES 10

/* struct optionの配列を指す静的変数longopts[]を定義し、
   構造体配列に代入
   getlongs()に末尾を知らせるための{0,0,0,0}を最後に用意
*/
static struct option longopts[] = {
    {"lines", required_argument, NULL, 'n'},
    {"help", no_argument, NULL, "n"},
    {0,0,0,0}
};

int main(int argc, char *argv[]){
    int opt;
    long nlines = DEFAULT_N_LINES;

}