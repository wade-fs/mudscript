#include <room.h>

 inherit ROOM;

 void create()
{
        set("short", "船上");
        set("long", @LONG
        
鐵船之上僅能容納數人，船身皆以烏鋼所造，雖處在陽光下，船上卻
為黑氣籠罩，就好似六月雪，雖然豔陽高掛，船上倒是涼的令人不禁直
打哆唆.... 


LONG
        );

        set("exits", ([
		"out": "/open/gsword/room/road3.c",
        ]) );
setup();

}
