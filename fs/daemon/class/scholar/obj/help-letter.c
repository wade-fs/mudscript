inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIR "求救信" NOR,({"help-letter"}));
        set("unit","封");
        set("value",1);
        setup();
}
void init()
{
        add_action("do_read","read");
}
int do_read( string arg )
{
        if( !arg || arg != "letter" ) return 0;
        write(@LONG
                信上寫著﹕

神算先生，因為...所以...。

                        儒門  聖賢書
LONG);
        return 1;
}

