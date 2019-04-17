#ifndef CODEBLOCK_H
#define CODEBLOCK_H


class Codeblock
{
    public:
        Codeblock();
        int gen_codeblock_project_file(const char *file_path);
        int do_gen_file_list(const char *file_path);
        int do_gen_cbp_file(const char *file_path);
        virtual ~Codeblock();

    protected:

    private:
};

#endif // CODEBLOCK_H
