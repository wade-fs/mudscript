#include <room.h>

inherit ROOM;

void create()
{
        set("short","洞穴");
        set("long","這是一間廢棄的[2~房間,由地上的灰塵可以看出,近幾年來,很少人來過這裡了。\n");

        set("item_desc", ([ /* sizeof() == 1 */  "west" : (: look_door, "west":),
]));

        set("exits", ([
          "west":__DIR__"hole7",
          "east":__DIR__"hole4",
          "south":__DIR__"hole8",
          "north":__DIR__"hole9",
        ]) );

        create_door("west","漆黑牢門", "east",DOOR_CLOSED);

        setup();
}
