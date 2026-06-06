// Room: /open/capital/room/king/kr4-1-A
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "東廠通道");
  set ("long", @LONG
從此處往西可以走到東廠，這裡是東廠的太監通往皇宮的必經之路
，此處正有兩名東廠守衛看守著。
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kr4-2",
//  "west" : "/open/capital/room/sroom/room21",
]));


  setup();
}
int valid_leave(object who,string dir)
{
  if(dir && present("soldier",environment(who)))
  {
        if((who->query("class")=="officer" && who->query_temp("can_in")==1) || (who->query("class")=="taigan"))
        {
        return :: valid_leave(who,dir);
        }
        else
        {
  return notify_fail("皇城禁衛軍說道:你想跑?!跑得掉嗎?\n");
        }
  }
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
 message_vision(HIC"皇宮守衛大聲的對你說:皇城禁地豈容你大聲喧嘩，還不快滾!!!\n"NOR,me);
 return 1;
                }
 else
 {
 return 0;
 }
}
