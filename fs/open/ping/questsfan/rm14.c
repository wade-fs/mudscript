// Room: /u/d/dhk/questsfan/rm14
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

  set("exits", ([ /* sizeof() == 4 */
  "westdown" : __DIR__"rm15",
  "southdown" : __DIR__"rm20",
  "eastdown" : __DIR__"rm19",
  "eastup" : __DIR__"rm13",
]));
  set("outdoors", "/u/d");
  set("objects", ([ /* sizeof() == 1 */
  "/open/beggar/npc/leader" : 1,
  ]));


  setup();
}
void init()
{
    call_out("dhk",1,this_player());
}
void dhk(object who)
{
  if(who->query_temp("run")!=7 && who->query_temp("run")==6)
  {
   tell_object(who,"" + WHT + "追了這麼久終於認出此人身法竟是" + HIY + "凌波微步"NOR+WHT"，這道黑色的人影這次又朝東邊山上奔去，還是追吧。" + NOR + "\n");
   who->set_temp("run",7);
   remove_call_out("dhk");
  }
}

