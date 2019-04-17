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

        XMLElement* root=doc.NewElement("CodeBlocks_project_file");
        doc.InsertEndChild(root);

        XMLElement* FileVersion=doc.NewElement("FileVersion");
        FileVersion->SetAttribute("major","1");
        FileVersion->SetAttribute("minor","6");
        root->InsertEndChild(FileVersion);

        XMLElement* project=doc.NewElement("Project");
        root->InsertEndChild(project);

        XMLElement* option=doc.NewElement("option");
        option->SetAttribute("title","aproject");
        project->InsertEndChild(option);

        while(fin.getline(line, sizeof(line)))
        {
            cout << line<< std::endl;

            XMLElement* unit=doc.NewElement("Unit");
            unit->SetAttribute("filename", line);
            project->InsertEndChild(unit);
        }
        doc.SaveFile("gen_project.cbp");
        return 0;
}

int Codeblock::do_gen_file_list(const char *file_path)
{
    /* scanf file using system command */
    char cmd[1024];

    memset(cmd, 0x00, sizeof(cmd));
    sprintf(cmd, "find . -name '*.cpp' -o -name '*.c' -o -name '*.h' > %s", file_path);
    system(cmd);
}

int Codeblock::gen_codeblock_project_file(const char *file_path)
{
    if(NULL == file_path){
        do_gen_file_list("file_list.txt");
        do_gen_cbp_file("file_list.txt");
    } else {
        /* we got file name in this case */
        do_gen_cbp_file(file_path);
    }
    return 0;
}
