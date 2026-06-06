// Room: /u/d/dhk/questsfan/rm15
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", ""WHT"石林"NOR"");
  set ("long", @LONG
這兒是一處寸草不生，堅石林立的地方。而且這兒淨是一些奇
形怪狀的巨石四處林立。但是卻又不是人造而成的，所以此地得名
〝石林〞也。在仔細看看這些巨石，有些質地鬆散、有些質地堅硬
各式各樣的石形都有，有一點像石頭大觀園一般。

LONG);

  set("exits", ([ /* sizeof() == 5 */
  "southdown" : __DIR__"rm16",
  "northup" : __DIR__"rm14",
  "west" : __DIR__"rm15",
  "eastup" : __DIR__"rm19",
  "eastdown" : __DIR__"rm17",
]));
  set("outdoors", "/u/d");

  setup();
}
void init()
{
    call_out("dhk",1,this_player());
}
void dhk(object who)
{
  if(who->query_temp("run")!=5 && who->query_temp("run")==4)
  {
   tell_object(who,""WHT"這道黑色的人影又快速朝西邊奔去，還是追趕不及。"NOR"\n");
   who->set_temp("run",5);
   remove_call_out("dhk");
  }
}

