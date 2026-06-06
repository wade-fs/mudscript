// Room: /u/d/dhk/questsfan/room22
inherit ROOM;
#include <ansi.h>
#include <room.h>
#include "/open/open.h"

void create ()
{
  set ("short", "晶谷谷底");
	set( "build", 12 );
  set ("long", @LONG
此地就是傳聞中的晶谷第三關，地處晶谷谷底。你望
眼所及，在右手方約十步之遙有一處涼亭，亭內有一絕色
女子雙眼微合，似在思索什麼。忽然你的腳陷入一條凹溝
中，差點把你拌倒。你仔細一瞧，嚇然發現此地縱橫交錯
數條凹溝。忽然你心念一動施展上成輕功往上一躍。差點
沒把你嚇死。原然來你所站之處，竟是一幅超大的棋盤，
難到那美人是在下棋，那和誰下呢？又如何推動上百斤的
巨棋呢？

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room23",
  "westup" : __DIR__"room21",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yun.c" : 1,
]));
  set("outdoors", "/u/d");
set("no_transmit", 1);
  setup();
}
int valid_leave(object who,string dir){
if(who->query("marks/fan-finger")!=1)
   if(dir=="east" && who->query("questsfan/quest_step")!=5)
     {
     message_vision(HIC"寒芸柔聲的對$N說道:晶谷不是讓人隨意進入的地方?請閣下快快離去!!\n"NOR,who);
       return notify_fail("寒芸柔聲的對你說道:晶谷不是讓人隨意進入的地方?請閣下快快離去!!\n");
     }
   return :: valid_leave(who,dir);
}
