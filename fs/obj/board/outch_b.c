#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
set_name(HIW + "悲歡離合板" + NOR,({"board"}));
set("location","/u/o/outch/workroom.c");
set("board_id","outch_b");
    setup();
set("master",({"outch"}));
}


