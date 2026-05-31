//roger's board
inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
   set_name(HIY"\n  艦橋主銀幕"NOR, ({"board"}));
   set("location","/u/r/roger/workroom");
   set("board_id","roger_b1");
   set("long","高科技的橢圓形乳白銀幕,顯示魔界一切的狀態。\n");
   setup();
   set("capacity", 100);
        set("master",({"roger"}));
}
