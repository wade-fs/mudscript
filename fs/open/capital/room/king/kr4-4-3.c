// Room: /open/capital/room/king/kr4-4-3.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "朝聖殿大殿");
  set ("long", @LONG
這裏就是朝聖殿最重要的地方--朝聖大殿,皇帝正坐在龍椅上,你看到皇帝的
目光向你掃來,不禁打了一個寒顫,大殿的兩旁有許多火把正燃燒著,大殿的後
方通往內殿,但內殿不是普通人可以隨便進去的,樹立的牌子(sign)寫得非常
清楚明白!!
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kr4-4-2",
  "north" : __DIR__"kr4-4-4",
]));
        set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/ksoldier" : 3,
]));
  set("light_up", 1);

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
