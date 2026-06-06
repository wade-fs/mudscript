#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name(HIC + "御氣流練功版" + NOR,({"fly board","board"}));
set("location","/open/clan/fly/fly.c");
set("board_id","fly_b");
set("long","御氣流武功研討處。\n");
setup();
set("capacity",100);
}
