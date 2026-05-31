#include <ansi.h>
inherit BULLETIN_BOARD;

#include <ansi.h>
void create()
{
  set_name(HIC"風雷幫的幫派討論區"NOR, ({"board"}));
  set("location","/open/clam/wind.c");
   set("board_id","clam_1");
  set("long","
   風雷幫 幫眾 , 大家集合囉~~~~~\n
  有事大家一起幫忙吧");
    setup();
    set("capacity", 50);
}
