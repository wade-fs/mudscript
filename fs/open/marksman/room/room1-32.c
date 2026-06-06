// Room: /u/f/fire/room/room1-32.c
#include <ansi.h>
#include "marksman.h"
inherit ROOM;

void create ()
{
  set ("short", "民房");
  set ("long", @LONG
這是一間長沙城裏的民眾所居住的民房，你看到一個簡陋的小床
，一張木工造成的小椅子，四四方方的桌子。桌子上放著一些小茶壺
，你似乎看到民眾正在做東西。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room1-10",
]));
  set("objects", ([ /* sizeof() == 2 */
C_NPC"/woman" : 1,
C_NPC"/man" : 1,
]));

  setup();
}
