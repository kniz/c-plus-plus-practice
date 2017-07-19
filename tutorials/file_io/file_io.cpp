#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <string.h>

using namespace std;

class Me {
public:
    int age;
    const char* name;
    struct data {
        int a1;
        int a2;
    } data;
    string name1;
};

void binary()
{
    FILE* fd, *fd1;
    char buffer[100];

    fd=fopen("README.md","r");
    if(fd==0){
        printf("file not found.\n");
        return;
    }
    fd1=fopen("COPYIED.txt","w");
    if(fd1!=0){
        printf("file is created.\n");
    }

    ssize_t n;
    while(n=fread(buffer,sizeof(char), 100, fd)){
        fwrite(buffer,sizeof(char), n, fd1);
        printf("..writing..\n");
    }

    Me me;
    me.age = 22;
    me.name = "hello world!";
    me.data.a1 = 1;
    me.data.a2 = 2;
    me.name1 = me.name;

    //fwrite(&me.age, sizeof(me.age), 1, fd1);
    fwrite(me.name, sizeof(char), strlen(me.name), fd1);
    printf("%s", me.name);

    // when we states this, text editor will recognize COPIED file as a binary file.
    //fwrite(&me.data, sizeof(me.data), 1, fd1); 
    
    fwrite(me.name1.c_str(), sizeof(char), me.name1.size(),fd1);

    fclose(fd);
    fclose(fd1);
}

int main(int argc,char *aa[])
{
    binary();
}