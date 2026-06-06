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
  
   set("objects", ([ /* sizeof() == 1 */
"/open/love/npc/2.c":1,
  ]));
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"room2-14",
  "east" : __DIR__"room1-2",
  "west" : __DIR__"room2-9",
  "south" : __DIR__"room2-6",
  ]));
  set("light_up", 1);

  setup();
}

