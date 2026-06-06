#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "內院走道");
  set ("long", @LONG

這裡是金刀門王宅的內院，內院呈一個口字型，中間是一個花園，花園四
周是王元霸家眷的住處，你看看四周房間，門欄窗隔俱是細雕時新花樣，
並無朱粉塗飾。
西方是王大小姐的香閨。


LONG);

   set("light_up", 1);
   set("exits", ([ /* sizeof() == 3 */
   "east" :__DIR__"g3-6.c",
   "north" : __DIR__"g3-4.c",
   "west" : __DIR__"g3-5-1.c",
]));

create_door("west", "雕花紫檀木門", "east", DOOR_CLOSED);
  setup();
}

 int valid_leave(object me, string dir)
  {
	if(dir=="west" && (doors["west"]["status"]==DOOR_CLOSED) )
	return notify_fail("你必須先把雕花紫檀木門打開﹗\n");

    if(dir=="west"&&me->query("gender")=="男性")
	if(!me->query_temp("can-enter") && me->query("lotch")<1 && me->query("quests/lotch") <1 )
	{
	if(me->query_temp("know_leing") )
	me->set_temp("cant-enter",1);
	return notify_fail("一個大男人 , 擅闖女孩子的閨房 ?\n");
	}
   return 1;
  }
