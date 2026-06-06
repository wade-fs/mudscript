// Room: /open/main/room/r26.c
//新增link 3/18/2004 Firedancer
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "道路");
	set( "build", 12 );
  set ("long", @LONG
南北兩邊是十分濃密的森林, 如果不是這邊人來人往, 恐怕會
遭歹徒暗算哩.
                < 木屋 >
LONG);

  set("item_desc",([
"木屋":"
一作木造的屋子，門開著，應該可以進去(enter)\n",
]));
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"F12",
  "west" : __DIR__"r25",
  "east" : CENTER_ROOM"road2",
  "enter" : __DIR__"sp/room",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/magic-manor/npc/steal-man" : 1,
]));


  set("outdoors", "/open/main");

  setup();
}

