// Room: /open/capital/room/king/kr5-6
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "皇城禁地");
  set ("long", @LONG
這兒就是大內皇城禁地, 在此地不得大肆喧嘩, 附近時常有禁衛軍
在巡邏, 往西走可通往朝聖殿, 往北走可以通往明和園, 往南則是皇城
的廣場
LONG);

  set("outdoors", "/open/capital");
  set("no_transmit", 1);
        set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/ksoldier" : 3,
]));
  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/capital/room/king/kr4-6",
  "south" : "/open/capital/room/king/kr6-6",
  "west" : "/open/capital/room/king/kr5-5",
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
