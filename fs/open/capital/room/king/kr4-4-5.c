// Room: /open/capital/room/king/kr4-4-5.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "御書房");
	set( "build", 131 );
  set ("long", @LONG
這裡便是天子平常時間辦公的地方，同時也會在這裡召見朝中大
臣商討國家大事，也因為天子平常都在此地，所以這裡的門禁相當的
森嚴，不得皇上召見，是不得隨便進入的。
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kr4-4-4.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/room/king/npc/king" :1,
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
