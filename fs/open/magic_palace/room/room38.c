inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","聖光之扉");
	set( "build", 28 );
set("long",@LONG
最終決戰終於要來臨了，四週異像再現，彩虹般的極光浮現在
四周冰柱之上，將整個魔宮映照得輝煌燦爛，前面雖然充斥著前所
未見、空前強大的邪惡魔氣，但有英雄和尚的支持，你已不再懼怕
魔界金典，

LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 2 */
        "enter"     : __DIR__"room39",
        "south"     : __DIR__"room37",
      ]));
        setup();
}
