// Room: /u/d/dhk/questsfan/room18
inherit ROOM;
#include <ansi.h>
#include <room.h>
#include "/open/open.h"

void create ()
{
  set ("short", "晶谷間層");
  set ("long", @LONG
此地就是傳聞中的晶谷第二關，其地處晶谷中段。由
一位虯髯大漢所鎮守。你四下觀望發現東北角的山壁上插
滿各式各樣的名劍利器，想必守關人必是一位劍癡吧！又
在那片山壁下有一名大漢在舞弄著名劍〝紫虹〞。只見他
一手捏劍訣、雙腳展開〝飄風急步〞劍勢、劍光化成一張
劍網，真是嘆為觀止。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"room19",
  "eastup" : __DIR__"room17",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shing.c" : 1,
]));
  set("outdoors", "/u/d");
set("no_transmit", 1);
  setup();
}
int valid_leave(object who,string dir){
if(who->query("marks/fan-finger")!=1)
   if(dir=="westdown" && who->query("questsfan/quest_step")!=4)
     {
     message_vision(HIC + "南宮勳正聲的對$N說道: 晶谷不是讓人隨意進入的地方?請尊駕快快離去!!\n" + NOR,who);
       return notify_fail("南宮勳正聲的對你說道:晶谷不是讓人隨意進入的地方?請尊駕快快離去!!\n");
     }
   return :: valid_leave(who,dir);
}
