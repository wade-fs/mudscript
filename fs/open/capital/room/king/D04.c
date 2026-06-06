// Room: /open/capital/room/D04.c
#include "/open/capital/capital.h"
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "皇宮大門");
  set ("long", @LONG
這裡是皇宮的入口, 守衛森嚴, 緊閉的宮門和高大的宮牆透出一股
宮廷深深的氣氛, 皇宮裡的一切都被嚴密地守護著。門口站著兩位威武
的禁衛軍, 神風凜凜的樣子, 當你一走到這兒, 便感覺到兩道如電的眼
光向你射來。
    道路旁有塊告示版(board).

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
            「皇城重地，閒雜人等請勿在此逗留。」
            「除品級高的官員以外，其餘擅闖此地者
              皇上有令，殺無赦。」
                三品御前帶刀侍衛隊長：王彪
",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/doorsoldier" : 2,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"king/kr7-4",
  "south" : __DIR__"r08.c",
]));

  setup();
}
int valid_leave(object who,string dir){
  if(dir=="north" && present("soldier",environment(who)))
  if((dir=="north" && !wizardp(who))||(dir=="north" && who->query("class")!="officer") && who->query_temp("can_in")!=1)
  return notify_fail("皇宮守衛大聲的對你說:大內禁地，閒雜人等不得進入。\n");
return :: valid_leave(who,dir);
}
void init()
{
        add_action("do_exert","exert");
}
int do_exert(string str)
{
 object me;
 me=this_player();
 if(str=="roar"){
 message_vision(HIC + "皇宮守衛大聲的對你說:皇城禁地豈容你大聲喧嘩，還不快滾!!!\n" + NOR,me);
 return 1;
                }
 else
 {
 return 0;
 }
}
