//與recall區域清除生活物資的npc搭配的房間 禁止離開該npc離開 by blazakira 2010/10/25
//修正上述裡的bug by blazakira 2013/10/2

#include <ansi.h>
#include "/open/open.h"

inherit TRANS_ROOM;

void create ()
{
  set ("short", "中央驛站");
  set( "build", 238 );
  set ( "long", @long
這兒就是最最出名的驛站, 鑣局的車隊, 來往於沙漠的駱駝隊, 甚
至是牛馬騾車, 幾乎只要你叫得出名字的交通工具這兒都有。
long);

  set("objects", ([ /* sizeof() == 1 */
    "/open/center/npc/sale_girl" : 1,
    "/open/center/npc/info-spy" : 1,
    "/open/center/npc/braid_girl" : 1, //放在此處是因為玩家經常經過 因此該npc消失後 方便重生
  ]));
  set("no_kill",1);
  set("no_magic",1);
  set("no_fight",1);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
    "west" : "/open/center/room/road2",
    "south" : "/open/center/room/road3",
    "north" : "/open/center/room/road1",
    "east" : "/open/center/room/road4",
//    "present" : "/u/n/neverend/present/present_room",
    "up"	: "/open/common/room/inn",
    // "down" : "/open/wiz/donate",
  ]));

  setup();
  call_other("/obj/board/start_b", "???");
}
//old message //
//如果你是這裡的新朋友，虔誠的祈禱(pray), 天神會將你傳送到新手練功區喔。
//新手區域拿掉 by Chan
/*void init()
{
  ::init();
  add_action ("do_pray","pray");
}

int do_pray()
{
  if(this_player()->query("combat_exp")>20000)
    return notify_fail("你還是新手嗎，去去去，到別的地方練功\去!\n");
  message_vision(HIY"天神感應到$N虔誠的心意從天空射出一道光芒將就$N帶走。\n\n"NOR, this_player());
  this_player()->move("/open/start/room/newhand5.c");
  return 1;
}*/

int valid_leave(object me, string dir)
{
//阻擋有"mark/leave_ng"離開recall區域
  if ( me->query_temp("mark/leave_ng") ==1 ) {
    switch (dir)
    {
      case "east" :
      case "west" :
      case "north" :
      case "south" :
        break;
      default : //往上沒問題
        return 1;
        break;
    }
    return notify_fail("STOP!\n");
  }
  else if ( me->query_temp("mark/up_ng") == 1 && dir =="up" ) //禁止鎖妖塔的npc 往上走
    return notify_fail("STOP!\n");
  return ::valid_leave(me,dir); //為valid_leave(me,dir)函數的結尾
}
