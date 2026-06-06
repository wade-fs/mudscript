// Room: /u/f/fire/room/room1-10.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "長沙道");
  set ("long", @LONG
這是一個熱鬧的街口，到處都是長沙的民眾。車馬雜沓，人語喧
騰。你在混亂之中，似乎很難認出出方向。你看到這裏似乎都一些豪
門的住宅。
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/boy" : 1,
]));
set("outdoors","/open/marksman");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room1-7",
  "north" : __DIR__"room1-32.c",
]));

  setup();
}
