inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
   set_name(HIG"不理不理板"NOR, ({"board"}));
   set("location","/u/h/houng/room/workroom");
   set("board_id","houng_b");
   set("long","顧名思義 ,你在上面潑什麼都不會有人理你。\n");
   setup();
   set("capacity", 100);
        set("master",({"houng"}));
}

