// Room: /u/f/fire/room/room1-13.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short",GRN"長沙道"NOR);
  set ("long", @LONG
走這個長沙道之中而到處充滿著鳥語花香的小路上，路旁的那些
花正飄來那濃郁的花香，聞著令人清爽的花香，耳邊傳來鳥兒們似乎
在嬉戲的叫聲。
LONG);

  set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"room1-14",
"south" : __DIR__"room1-9",
"west" : "/open/trans/room/room7.c",
]));
set("outdoors","/open/marksman");

  setup();
}
