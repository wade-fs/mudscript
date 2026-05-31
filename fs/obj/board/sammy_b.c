#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
set_name(HIW"清心寡慾板"NOR,({"board"}));
set("location","/u/s/sammy/workroom.c");
set("board_id","sammy_b");
set("long","這是無語的專用記事板\n");
    setup();
   set("capacity", 100);
 set("master",({"sammy"}));
}


