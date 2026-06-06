// Room: /open/hoom/hall/jail.c

inherit ROOM;
#include <room.h>

#include <ansi.h>

void create()

{

        set("short", "牢頭休息區");
        set("long", @LONG
這ㄦ是牢頭的休席區，一個臘蹋的壯漢正翹著二郎腿，哼著淫穢的
小調..桌上擺著幾碟小菜和一壺白乾，這傢伙似乎還蠻會享受的......
牢頭的身上掛著一串鑰匙，但是你最好不要有劫獄的念頭，除非你很強
壯..嘿嘿....
LONG);

        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"jail1",
  "north" :__DIR__"jail2",

  ]));

        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/j_head" : 1,
]));
create_door("out", HIR + "厚重銹氣的鐵門" + NOR ,"enter",DOOR_CLOSED);
        setup();

}

