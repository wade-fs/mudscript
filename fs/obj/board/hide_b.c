inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
   set_name(HIC + "小熊塗鴉版" + NOR, ({"board"}));
   set("location","/u/h/hide/workroom");
   set("board_id","hide_b1");
   set("long","版子上圖被小熊塗的亂七八糟了。\n");
   setup();
   set("capacity", 200);
        set("master",({"hide"}));
}
