#include <room.h>
inherit ROOM;
void create()
{
        set("short","斜坡小徑");
        set("long", @LONG
這裡距離漢水河岸已有點距離，往西北方向的山坡一直走上去可
以到達蒙古大草原，東南方的路則是通往襄陽城北門，由於地勢陡斜
，必須謹慎前進，否則相當容易摔倒。
LONG
        );
		set("outdoors", 1);
		set("no_auc", 1);
        set("no_transmit", 1);
        set("no_scale",1);
        set("no_chome",1);
        set("exits", ([
        "southdown":__DIR__"slope03",  
        "westup":__DIR__"grass19",
        ]) );
  setup();
}
