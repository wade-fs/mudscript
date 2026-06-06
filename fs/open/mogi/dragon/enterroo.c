// Room: /u/p/poloer/dragon/enterroom
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "炎龍谷入口");
	set( "build", 33 );
  set ("long", @LONG
一個位於山腳下的地方，也就是傳說中兇惡炎龍躲藏的地方
。從這裡往山上看去隱約在山頂上有一間寬大的宮殿，一條小路
從宮殿一直延伸到山腰，但山腰被霧遮蓋住了，看不出有什麼東
西。四周看來死氣沉沉，毫無生氣，怪恐怖的。旁邊有一塊石碑
(stone)擋在路中央。
      這裡一片霧茫茫看不到任何出路。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
   武功\未熟，死路一條
         
         
   ",
]));
  set("no_transmit", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fire-dra.c" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"a2",
  "east" : __DIR__"dr10",
]));

  setup();
}
int valid_leave(object me, string dir)

{
        if(dir=="enter"&&present("fire-dragon guard",environment(me)))
  {
if(me->query("combat_exp") < 299999 ||
me->query("max_force") <999)
{
message_vision("炎龍武士對$N怒喝 : 這裡豈能讓你自由進出！？\n",me);
return 0;
}
}
return 1;
}
