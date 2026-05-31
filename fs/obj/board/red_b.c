 

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
set_name(HIC"囊囊記事簿"NOR,({"board"}));
    set("location","/u/r/red/workroom");
   set("board_id","red_b");
        set("long","這是一本用來記事的留言簿。\n");
        setup();
    set("capacity",100);
    set("master",({"red"}));
}
