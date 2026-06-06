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
    "east" : __DIR__"i01.c",
    "west" : __DIR__"i03.c",
    "south" : __DIR__"i05.c",
	]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/b9_duan_savant.c" : 1,
  ]));

  setup();
}
