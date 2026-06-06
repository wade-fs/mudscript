// Room: /open/capital/room/king/kr2-4
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "皇城禁地");
	set( "build", 27 );
  set ("long", @LONG
這兒就是大內皇城禁地, 在此地不得大肆喧嘩, 禁衛軍的巡邏似乎
越來越頻繁了, 你感覺到你已深入皇城禁地的內院, 在你的面前是一座
雕工精細的宮殿, 匾額上提著三個大字"永德殿", 往東走可通往鳳儀殿
往西走可通往慈禧殿, 南邊不遠處是雄偉的朝聖殿.
LONG);

        set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/ksoldier" : 3,
]));
  set("outdoors", "/open/capital");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kr3-4",
  "north" : __DIR__"kr1-2",
  "west" : __DIR__"kr2-3",
  "east" : __DIR__"kr2-5",
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
