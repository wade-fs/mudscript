inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","魔光之扉");
set("long",@LONG
上空浮現三輪太陽，而前方縷縷青煙閃電般來回穿梭，魔氣之盛，
前所未見，這裡，就是天底下所有魔功的源頭，亦為魔界金典的誕生地
，只見陣陣妖氣由正前方的一個寶座上散發出來...

LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 2 */
        "out"     : __DIR__"room38",
        "up"      : __DIR__"room40",
        ]));
        set("objects", ([ /* sizeof() == 1 */
        "/open/magic_palace/npc/evil_buddha.c" : 1,
      ]));
        setup();
}

int valid_leave(object me,string dir)
{
        object obj = present("Evil Buddha");
        if( dir == "up" )
        {
                if(obj)  return notify_fail(HIR + "魔也佛" + HIW + "冷笑道:『想去斷陽峰!?先打敗我吧!!』\n" + NOR);
        }

return 1;
}
