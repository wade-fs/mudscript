// Room: /u/f/fire/room/room1-30.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "強者之道");
  set ("long", @LONG
眼前一片耀眼的閃光襲來，你勉強睜開眼睛一看，眼前聳立著一
座鑲滿寶石，流露許多七彩鮮豔的光芒。這裡飄著淡淡的花香，你不
禁大大的吸了口氣，突然飄來了各種花的香味，有清香的桂花味，讓
人神清氣爽。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room1-28.c",
  "east" : __DIR__"room1-31",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/chang-yang.c" : 1,
]));

set("light_up",1);
  setup();
}
