// Room: /u/d/dhk/questsfan/room14
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "晶谷外緣");
	set( "build", 1 );
  set ("long", @LONG
這裡就是傳聞中晶谷四關之一，現在由段世族人中所
擢選出最強的四天王之一"百里勇"所鎮守。只見到一位衣
衫襤褸的憔夫正運足十成時的功力施展著絕世刀法，其攻
勢之凌厲、防守之嚴密以達滴水不漏之境界。一刀一式均
讓人看的目瞪口呆。難怪此人鎮守~天下~不是、是晶谷第
一關。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room13",
  "northdown" : __DIR__"room15",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ung.c" : 1,
]));
  set("outdoors", "/u/d");
set("no_transmit", 1);
  setup();
}
int valid_leave(object who,string dir){
if(who->query("marks/fan-finger")!=1)
    if(dir=="northdown" && who->query("questsfan/quest_step")!=3)
    {
    message_vision(HIC + "百里勇大聲的對$N說道:晶谷豈是讓人隨意進入的地方?還不快滾!!\n" + NOR,who);
      return notify_fail("百里勇大聲的對你說道:晶谷豈是讓人隨意進入的地方?還不快滾!!\n");
    }
  return :: valid_leave(who,dir);
}
