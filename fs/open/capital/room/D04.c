// Room: /open/capital/room/D04.c
#include "/open/capital/capital.h"
#include <ansi.h>
inherit ROOM;
int flag=0;
void create ()
{
  set ("short", "皇宮大門");
	set( "build", 453 );
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
   {
    if(dir=="north" && who->query("class")=="officer" && who->query_temp("can_in")!=1)
        return notify_fail(HIY + "皇宮守衛說道:大人要進攻的話,點個頭就好了阿!!!\n" + NOR);
if(dir=="north" && who->query("class")!="officer" && who->query_temp("can_in")!=1)
  return notify_fail("皇宮守衛大聲的對你說:大內禁地，閒雜人等不得進入。\n");

     if(dir=="north" && !present("soldier",environment(who)))
{
           if(who->query("class")=="officer")
       {
        message_vision(HIC + "hmm,你還不能進去喔,等到皇門守衛換班回來你才能進去!!!\n" + NOR,who);
      return 0;
       }
        if(!flag)
{
     tell_object(users(),HIR + "
轟隆一聲~~~~~~~~~

  皇城的大門竟然被"+who->query("name")+"給打開了

  皇城禁衛軍頃巢而出,務要致"+who->query("name")+"於死地!!!
\n" + NOR); 
       flag=1;
    }
  }
}
return :: valid_leave(who,dir);
}
void init()
{
          object me=this_player();
        add_action("do_exert","exert");
         if(me->query("class")!="officer")
         if( present("soldier", environment(me)) ) 
        flag=0;
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
