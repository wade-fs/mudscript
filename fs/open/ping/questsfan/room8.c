// Room: /u/d/dhk/questsfan/room8
inherit ROOM;

#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short", "絕崖的彼端");
  set ("long", @LONG
這裡的北面有一座大型的木柵，只有木柵的角邊留有
一道小門而且還上了鎖。這裡人煙罕至，難道此嶺有人居
住。不會是逃命到此的將軍吧？…
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room9",
  "goup" : __DIR__"room30",
  "enter" : __DIR__"room10",
]));
  set("outdoors", "/u/d");

set("need_key/out",1);
create_door("enter",HIY + "大木柵柵門" + NOR,"out",DOOR_LOCKED);
  setup();
}
