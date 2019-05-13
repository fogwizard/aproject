#include <iostream>
#include <string.h>
#include "Codeblock.h"
#include "Seg7.h"

using namespace std;

Codeblock codeblock;
Seg7      seg7;

int main(int argc, char *argv[])
{
    int ret = 0;
    if(2 == argc) {
        if(0 == strcmp(argv[1], "--gen-seg")) {
            return seg7.do_seg7();
        }
        ret = codeblock.gen_codeblock_project_file(argv[1]);
    } else {
        ret = codeblock.gen_codeblock_project_file(NULL);
    }
    if(0 == ret) {
        cout << "create project file successful" << endl;
    } else {
        cout << "error found when create project file" << endl;
    }
    return 0;
}
