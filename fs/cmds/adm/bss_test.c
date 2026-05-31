#include <ansi.h>
inherit F_DBASE;
void create()
{
        seteuid(getuid());
}
int main(object me, string arg)
{
    object bk;

    bk=find_object("/open/magic_palace/obj/book.c");
    bk=environment(bk);
    printf("%O\n", bk);
    return 1;
}

