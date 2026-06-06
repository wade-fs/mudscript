// Room: /u/d/dhk/questsfan/rm17
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "雲霧松林");
  set ("long", @LONG
松林蔽日、雲霧迷濛、松果滿地，這兒最奇怪的是一片大松林
竟沒看到半株莖幹，格外特別。不時有幾隻罕見的六尾松鼠狂奔而
過，不然就是昆蟲的鳴叫聲，特別的是牠們的一起突然的大鳴，然
後再一起的安靜，那一起突發的鳴叫聲真是相當令人震撼的。

LONG);

  set("exits", ([ /* sizeof() == 6 */
  "westup" : __DIR__"rm20",
  "westdown" : __DIR__"rm16",
  "southdown" : __DIR__"rm9",
  "northup" : __DIR__"rm19",
  "eastdown" : __DIR__"rm10",
  "eastup" : __DIR__"rm18",
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
  if(who->query_temp("run")!=4 && who->query_temp("run")==3)
  {
tell_object(who,"" + WHT + "這道黑色的人影又快速往西邊山上奔去，好像有意要與你玩捉迷藏。" + NOR + "\n");
   who->set_temp("run",4);
   remove_call_out("dhk");
  }
}

