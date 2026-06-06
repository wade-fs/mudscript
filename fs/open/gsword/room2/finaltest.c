#include <ansi.h>
inherit ROOM;
void create()
{
   set("short", HIW"仙劍最終試煉谷"NOR);
   set("long", @LONG
傳說中仙劍的練劍室..室中處處都是駭人的劍痕.你眼前有一個模糊的影子
難道他就是傳說中的...!?
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
 "south":"/open/gsword/room2/shab1",
 "back":"/open/gsword/room/g5-1.c",
      ]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/npc2/t4" : 1,
]));
        set("light_up",1);
        set("no_transmit", 1);
        set("no_die_room",1);
        set("die_room","open/gsword/room/eqroom");
        setup();
}
