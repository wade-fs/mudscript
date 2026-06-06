// Room: /open/capital/room/king/kr4-4-1
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "朝聖殿");
  set ("long", @LONG
這裡是朝聖殿門口,旁邊各有兩隻栩栩如生的石獅子,
使的經過的人都忍不住撫摸一下.
北邊繼續通往朝聖殿內部.
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kr4-4-2",
  "south" : __DIR__"kr5-4",
]));

        set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/ksoldier" : 3,
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
 message_vision(HIC + "皇宮守衛大聲的對你說:皇城禁地豈容你大聲喧嘩，還不快滾!!!\n" + NOR,me);
 return 1;
                }
 else
 {
 return 0;
 }
}
