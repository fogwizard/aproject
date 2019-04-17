#include <iostream>
#include <string.h>
#include "Codeblock.h"

using namespace std;

Codeblock codeblock;

int main(int argc, char *argv[])
{
    int ret = 0;
    if(2 == argc){
        ret = codeblock.gen_codeblock_project_file(argv[1]);
    }else{
        ret = codeblock.gen_codeblock_project_file(NULL);
    }
    if(0 == ret){
        cout << "create project file successful";
    } else {
       cout << "error found when create project file";
    }
    return 0;
}
