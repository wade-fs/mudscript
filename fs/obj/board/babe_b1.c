#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
set_name(HIC"玄天冰晶"NOR, ({"mysterious crystal","board"}));
  set("location","/u/b/babe/workroom.c");
set("board_id","babe_b2");
  set("long","
    要唸完書, 做完功\課, 才能玩 mud 喔!\n
    做個乖寶寶...\n
    不管有事沒事都歡迎POST..");
    setup();
set("capacity", 100);
  set("master",({"babe"}));
}
