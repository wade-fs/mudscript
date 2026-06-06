#include <room.h>

 inherit ROOM;

 void create()
{

        set("short", "小徑");
        set("long", @LONG
這是一條滿佈青苔的小路，由地上的痕跡看來，這似乎鮮少有人經過
，兩旁的巨石足足有十尺高，看的你不禁連連咋舌，小徑往西北方向爬升
，通往仙劍後山及思過崖。
 
LONG
        );

        set("exits", ([
		"eastdown":__DIR__"g6-1.c",
		"westup":__DIR__"g6-3.c",
        ]) );
	set("outdoors" ,"/open/gsword/room");
setup();

}
