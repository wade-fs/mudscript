// Room: /open/snow/room/hole3.c
// 雪泉聖地中的洞穴
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "洞穴");
  set ("long", @LONG
經過狹小通道後，你來到一個巨大的洞穴之中，只見四周的壁上刻滿了
圖形，仔細一看原來壁上的圖形皆是傳說中古代的聖獸有麒麟、鳳凰、
..等，前上的壁上刻有一幅青龍追日的圖形，其彫刻的青龍栩栩如生好
像是跟真的一樣，左方的壁上(wall)似乎有東西。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "wall" : "瀧山--任正晴到此一遊!!!!
      ",
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"s_hole1.c",
]));
  set("no_auc", 1);
  set("no_transmit", 1);

  setup();
}
void init()
{
  add_action("do_search","search");
  add_action("do_put","put");
  add_action("do_use","use");
}
int do_search(string str)
{
  object ob,ob1;
  ob=this_player();
  if(ob->query("ask_god_kee") != 2)
    return notify_fail("你絲毫尋找不出任何異狀!!!\n");
  if( str!="dragon")
    return notify_fail("你絲毫尋找不出任何異狀!!!\n");
  message_vision("經過$N細心的尋找之後，$N發現壁上的青龍追日中的太陽似乎缺少了某部份。\n",ob);
  ob->set("can_use",1);
  return 1;
}
int do_use(string str)
{
  object ob,ob1;
  ob=this_player();
      if(!present("sky_lin_stone",this_player()))
    return notify_fail("你要使用什麼東西呀!!!\n");
  if(ob->query("can_use") != 1)
    return notify_fail("你要使用什麼東西呀!!!\n");
      if( str!="sky_lin_stone")
    return notify_fail("你要使用什麼東西呀!!!\n");
  if(ob->query("sec_kee") != "dragon")
    return notify_fail("只有擁有青龍之氣的人才能使用天靈珠!!!\n");
  message_vision(HIW + "$N將天靈珠放在胸前,$N全身發出光茫!!$N身上的" + HIB + "青龍之氣" + HIW + "湧出匯入了天靈珠之中了。\n" + NOR,ob);
  ob->set("can_put",1);
  return 1;
}

int do_put(string str)
{
object ob=this_player();
if(!present("sky_lin_stone",this_player()))
    return notify_fail("你要放什麼東西呀!!!\n");
  if(ob->query("can_put") != 1)
    return notify_fail("你要放什麼東西呀!!!\n");
  if( str!="sun")
    return notify_fail("你要放什麼東西呀!!!\n");
  message_vision(HIW + "$N將天靈珠放入" + HIY + "太陽" + HIW + "之中，此時壁上的青龍追日圖發出剌目的光線。\n" + NOR,ob);
  message_vision(HIY + "一道柔和的光線將$N包住，$N消失在光線之中了.....\n" + NOR,ob);
  ob->move(__DIR__"godrom1");
  return 1;
}

