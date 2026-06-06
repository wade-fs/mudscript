// Room: /open/capital/room/king/kr2-6
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "承德宮");
  set ("long", @LONG
這裡便是天子享福用的後宮承德宮，目前裡面大概有一百多位嬪
妃住在裡面，每天過著等待的日子，看看皇上那天心情好會去掀她們
的牌子，這裡是嚴禁男性進入的，眼前那幾位太監就是保護監督眾嬪
妃，以防止有發生有損皇室名譽的事情發生。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/capital/npc/nobird.c" : 1,
]));
  set("outdoors", "/open/capital");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kr2-6",
]));

  setup();
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
