#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","花園");
  set ("long", @LONG
這裡算是絕情門的兩側的花園，你不要把心思放在賞花上，還是
先注意你自已吧，因為風火雷電四大護法常在這修練武技，最好
是不要遇上他們，否則你別想活著離開這。
LONG);
  
 
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"room2-9.c",
  "east" : __DIR__"room2-6.c",
  "south" : __DIR__"room2-1.c",
  ]));
  set("light_up", 1);

  setup();
}

