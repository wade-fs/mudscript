// Room: /u/f/fire/room/room1-12.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "楊家藥店");
	set( "build", 60 );
  set ("long", @LONG
你走進一間充滿著藥味的房子中，這裏是一間藥鋪。在這裏你可
以買到各式各樣的藥材。在房子的四周是一排的木櫃子，在櫃子上到
處寫滿了各式的藥品名稱，令你看了都覺得眼花潦亂。在櫃子前面還
有一位長滿白鬍子的老人不斷的開啟不同的抽屜拿取藥材。
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/yangming-teck" : 1,
]));
set("outdoors","/open");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room1-11",
]));

  setup();
}
