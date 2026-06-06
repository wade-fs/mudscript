// Room: /u/d/dhk/questsfan/room26
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", ""HIG"勝天"WHT"峰"NOR"");
	set( "build", 64 );
  set ("long", @LONG
這裡就是最後的關卡，是由全族最強的段家嫡系---
段川嶽所鎮守，他身著〝十彩皇衣〞手持〝菱骨晶扇〞
並且精通各門派武學要義。他風姿倬約、器宇軒昂的佇
立在勝天峰上的一處山洞前。此地是全谷最平凡的地方
四周的一草一木，凡映入眼簾的景象要有多普通就有多
普通，正好與全谷產生強烈的對比。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room27",
  "eastdown" : __DIR__"room25",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/muan.c" : 1,
]));
  set("outdoors", "/u/d");
set("no_transmit", 1);
  setup();
}
int valid_leave(object who,string dir)
{
if(who->query("marks/fan-finger")!=1)
   if(dir=="enter" && who->query("questsfan/quest_step")!=6)
     {
       message_vision(HIC"段川嶽神情嚴肅的對$N說道:匯靈地豈是讓人隨意進入的地方?請閣下盡快離開!!!\n"NOR,who);
       return notify_fail("段川嶽神情嚴肅的對你說道:匯靈地豈是讓人隨意進入的地方?請閣下盡快離開!!!\n");

     }
    return :: valid_leave(who,dir);
}
