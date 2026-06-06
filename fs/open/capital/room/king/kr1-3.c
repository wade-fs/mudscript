#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "鳳儀殿");
	set( "build", 73 );
  set ("long", @LONG
這兒就是當今皇后的寢宮，你一進來就被滿室的香氣所迷倒，眼
前的太后正在繡一方手巾，看她文靜的樣子，使你對皇后產生了無上
的敬意，不過皇后似乎因為你無緣無故進來而嚇了一跳。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/kingwife" : 1,
  "/open/capital/npc/kingirl" : 2,
]));
  //set("outdoors", "/open/capital");
  set( "light_up", 1 );
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kr2-5",
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









