// Room: /u/f/fire/room/room1-16.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "長沙道");
  set ("long", @LONG
此地兩旁種植了高大的樹木，和許許多多美麗的花草，徐風樹蔭
，鳥語花香，讓你迫不及待地想走進去逛一逛。北邊一間長沙城裏最
有名名的客棧天龍客棧。
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/boy" : 1,
]));
set("outdoors","/open");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room1-15.c",
  "north" : __DIR__"room1-17.c",
  "east" : __DIR__"room1-19.c",
]));

  setup();
}
