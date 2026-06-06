// Room: /u/f/fire/room/room1-4.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "長沙道");
  set ("long", @LONG
零零散散的行人，也許這正是顯示出長沙城的平靜安寧的氣象。
這麼大的一條街，似乎成了遊民的居所。在北邊你可以看到一家鐵鋪
，南邊則是一家商店。
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/man" : 1,
]));
set("outdoors","/open/marksman");
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room1-3.c",
  "south" : __DIR__"room1-6.c",
  "north" : __DIR__"room1-5.c",
  "east" : __DIR__"room1-7.c",
]));

  setup();
}
