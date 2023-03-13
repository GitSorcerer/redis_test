#include <stdio.h>
#include "../redis/sds.c"
#include "../redis/zmalloc.c"


void show(char *s);

int main(){
    sds s;
    s = sdsnew("hello");
    show(s);

    sdsMakeRoomFor(s,10);//（5+10）* 2 申请30个字节
    show(s);


    sdscat(s, ",world");
    show(s);

    sdscpy(s, "nihao,gaoh");
    show(s);

    return 0;
}

void show(char *s){
    printf("sds len: %ld\n", sdslen(s));
    printf("sds free(vail): %ld\n", sdsavail(s));
    printf("s->: %s\n",s);
    printf("========================\n" );
}