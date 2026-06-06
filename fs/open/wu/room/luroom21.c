// Room: /open/wu/room/luroom21.c
// 瀧山武館休息室
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "藏寶庫");
    set("long", @LONG
這是瀧山派的EQ存放及休息處,放眼望去滿地的寶物及藥膏,看到
怎麼多的東西,你不禁要感謝前輩的努力,才有現在的收獲。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
//   "north" : __DIR__"luroom18",
   "north" : "/open/wu/room/luroom18",
]));
        set("light_up", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        if( !me->query("lungshan_test") ) {
		tell_object(me, HIY + "在你離開的時候，忽然發現一旁的牆壁似乎寫著四個字：【瀧…山…拳…法】。\n\n" + NOR);
		}
        return 1;
}
