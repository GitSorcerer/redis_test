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


    //连接字符串
    sdscat(s, ",world");//len 12 free 30-12=18
    show(s);


    //copy字符串
    sdscpy(s, "nihao,gaoh");
    show(s);

    sdscatprintf(s,"%d,%d,%s,%d",7,8,"world",9); 
    show(s);

    return 0;
}

void show(char *s){
    printf("sds len: %ld\n", sdslen(s));
    printf("sds free(vail): %ld\n", sdsavail(s));
    printf("s->: %s\n",s);
    printf("========================\n" );
}