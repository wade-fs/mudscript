// Room: /u/d/dhk/questsfan/rm15
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "石林");
  set ("long", @LONG
這兒是一處寸草不生，堅石林立的地方。而且這兒淨是一些奇
形怪狀的巨石四處林立。但是卻又不是人造而成的，所以此地得名
〝石林〞也。在仔細看看這些巨石，有些質地鬆散、有些質地堅硬
各式各樣的石形都有，有一點像石頭大觀園一般。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/woman" : 2,
]));
  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"rm20",
  "eastup" : __DIR__"rm14",
  "eastdown" : __DIR__"rm16",
  "west" : __DIR__"rm26",
]));

  setup();
}
void init()
{
    call_out("dhk",1,this_player());
}
void dhk(object who)
{
  if(who->query_temp("run")!=6 && who->query_temp("run")==5)
  {
   tell_object(who,"" + WHT + "這道黑色的人影這次又朝東邊山上奔去，儘管你努力提氣奔馳，還是追趕不及。" + NOR + "\n");
   who->set_temp("run",6);
   remove_call_out("dhk");
  }
}

