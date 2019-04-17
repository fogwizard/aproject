#include "Codeblock.h"
#include "tinyxml2.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;
using namespace tinyxml2;

Codeblock::Codeblock()
{
    //ctor
}

Codeblock::~Codeblock()
{
    //dtor
}

int Codeblock::do_gen_cbp_file(const char *file_path)
{
        char line[1024]={0};
        fstream fin;

        fin.open(file_path,ios::in);
        if(!fin){
            cout << "file not exist";
            return -1;
        }
        const char* declaration ="<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
        XMLDocument doc;
        doc.Parse(declaration);
        XMLElement* root=doc.NewElement("DBUSER");
        doc.InsertEndChild(root);
        doc.SaveFile("gen_project.cbp");

        while(fin.getline(line, sizeof(line)))
        {
            cout << line<< std::endl;
        }
        return 0;
}

int Codeblock::gen_codeblock_project_file(const char *file_path)
{
    if(NULL == file_path){
        do_gen_cbp_file("file_list.txt");
    } else {
        /* we got file name in this case */
        do_gen_cbp_file(file_path);
    }
    return 0;
}
