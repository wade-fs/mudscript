// Room: /open/su/room/jail/jail_in.c

inherit ROOM;
#include <room.h>

#include <ansi.h>

void create()
{
        set("short", "監牢入口");
        set("long", @LONG
昏暗的光線，以及噁心的臭味，都使你忍不住想快點離開這裡。除
非你是想來劫獄，否則還是快點離開吧。一座生銹的厚重鐵門(door)矗
立在這，門前站著兩個身材精練的衛士!!想劫獄?!來點會的吧～～
LONG);

        set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/hall/way1",
  "enter" : "/open/hall/jail/jail.c",
]));

         set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/j_guard" : 2,
]));
create_door("enter", HIR + "厚重銹氣的鐵門" + NOR, "out", DOOR_CLOSED);
        setup();

}

