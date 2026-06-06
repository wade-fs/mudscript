//room:/u/e/eva/village/room/room-17.c    made by eva
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create()
{
    set("short","魔界村東村口");
    set("long","
    這裡是魔界村的東村口, 魔界村位於魔界的正中央, 由於在村中
自古以來, 有高人在此設下了五行之陣, 憑藉著五行相生相剋的力量
, 巧妙的運用使魔物無法進入, 使這裡變成魔界中唯一的樂土, 僅有
人類以及低等魔物可以進入.\n\n");
    set ("exits",([
        "west" : __DIR__"room-16",
       "east" : "/open/mogi/castle/h",
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("outdoors",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);  
    setup();
}

int valid_leave(object me,string dir)
{
    if ( me==this_player() && dir=="east" )
        {
        tell_object(me,HIM + "你輕輕巧巧的穿過力場, 出了魔界村!\n" + NOR);
        }
    return ::valid_leave(me,dir);
}
