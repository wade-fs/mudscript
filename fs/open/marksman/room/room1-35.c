 // Room: /u/f/fire/room/room1-35.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "長沙道");
  set ("long", @LONG
熱鬧的街頭，雜亂的聲音，顯示出長沙城富裕的氣息。小販正在
為自己的東西，大聲暄叫著買東西。寧靜的氣氛，長沙城的民眾都帶
著一附微笑向你走過。
LONG);

  set("objects", ([ /* sizeof() == 2 */
C_NPC"/girl" : 1,
C_NPC"/oldman" : 1,
]));
  set("outdoors", "/u/f");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room1-36.c",
  "east" : __DIR__"room1-34.c",
]));

  setup();
}
