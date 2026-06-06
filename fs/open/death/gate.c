// Room: /open/death/gate.c
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "鬼門關");
  set ("long", @LONG
這裡就是著名的陰間入口「鬼門關」﹐在你面前矗立著一座高大的
黑色城樓﹐眾多亡魂正哭哭啼啼地列隊前進﹐因為一進鬼門關就無法再
回陽間了。
LONG);
 set("no_auc",1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gateway",
  "south" : __DIR__"bridge3",
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wgargoyle" : 1,
]));
  set("no_magic", 1);
  set("no_transmit", 2);

  setup();
}

int valid_leave(mixed me, string dir)
{
        if (dir == "south") 
                return notify_fail("進了鬼門關就別想回去了！\n");
        else
                return 1;
}

