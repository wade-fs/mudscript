//room:/open/dancer/room/start.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", HIC "月半彎的小屋" NOR );
  set ("long", @LONG
這是一間雅致的小屋，屋裡的布置雖然簡陋，但仍不失其高雅的
品味，且整理得一塵不染，可想而知其主人必是一位高尚幽雅的人！

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south"     :"/open/dancer/room/yuaroom.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/dancer/npc/master_yuaa.c" : 1,
]));

  setup();
 
}
