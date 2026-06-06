inherit ROOM;
#include "bonze.c"

void create ()
{
  set ("short", "營地內");
  set ("long", @LONG
與其說這座營地井然有序的模樣，不如說是從該營地的門面上就可
以看出是哪個門派駐紮在此地。

LONG);

  set("light_up", 1);
//  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"i05.c",
    "east" : __DIR__"i08.c",
    "west" : __DIR__"i10.c",
    "south" : __DIR__"pillstore.c",
	]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/b9_swordman_disciple.c" : 1,
  ]));

  setup();
}
