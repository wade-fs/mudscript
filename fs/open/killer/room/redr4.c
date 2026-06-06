// open/killer/room
// 2001.11.5 修改，讓玩家如果解謎到此處search，將可以發現lu的兒子
// 此間房間會利用到  me->move("/open/killer/ninja/sonrm.c");
#include <ansi.h>
#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","紅葉組");
  set ("long", @LONG
這裡是黑牙聯總壇大廳右翼，也是黑牙聯最強的紅葉暗殺組的所在地。
江振武在此處，隨時待命出擊，並且培養自己的專屬殺手。
一身野心並不在葉秀殺之下，但是葉秀殺並不以為意。
因為江振武身上所散發出的霸氣，正是葉秀殺所需要的。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east":__DIR__"redr3",
  "north":__DIR__"redr1",
]));

  set("objects",([
        "/open/killer/npc/rednpc3.c" : 1,
        ]));  
  setup();
}

void init()
{
  add_action("do_search", "search");
}

int do_search(string arg)
{
  object me=this_player();
  int max;

  if (me->query_temp("firstpart") == 2 )
  {
    message_vision(HIY + "$N因為對此處的感到非常懷疑，居然發現了一個開關。\n" + NOR, me); 
    message_vision(HIY + "$N往這一個開關押下去...................\n" + NOR, me); 
    tell_object(me,HIY + "一陣衝撞力將你彈飛，落入陷阱之中一直墜落～～\n" + NOR);
    me->move("/open/killer/ninja/find/sonrm.c");
    return 1;
  }
  else 
    return 0;
 }
