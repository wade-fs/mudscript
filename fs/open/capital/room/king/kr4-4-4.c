// Room: /open/capital/room/king/kr4-4-4.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走道");
	set( "build", 26 );
  set ("long", @LONG
這是通往永德殿的及其它殿的走道,看到天花板是用黃金做的,心想著
不虧是皇宮內苑,有那麼大的財力來建造這些殿,走道的右方通往御書房
LONG);

  set("no_transmit", 1);
    set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kr4-4-3.c",
  "east" : __DIR__"kr4-4-5.c",
    "enter" : __DIR__"tomb1.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/taigan1" : 2,
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
