#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
int do_list();
int do_trade(string);
void create()
{
  set("short","狼棚");
  set ("long",@LONG
這裡看來是村民用來給狼兒休息的地方。在棚角那有個老人站在
那，看來你可以去跟他說說話。
LONG);

  set("light_up", 1);
   set("exits", ([ /* sizeof() == 2 */
   "corner" : __DIR__"corner.c",
   "west" : __DIR__"wolf08.c",
]));
  set("objects",([ /* sizeof() == 4 */
  "/open/badman/npc/wolf.c" : 2,
   "/open/badman/npc/wolf02.c" : 2,
]));

  setup();
}
