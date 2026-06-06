//增加前往東瀛島的相關密道 by blazakira 2011/8/21

#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "莫塔湖瀑布");
  set ("long", @LONG
	
	高山上，銀龍直洩，在你眼前的是萬丈飛瀑，奔騰而下！！
	有如千軍萬馬之勢，隆隆之聲，震盪澎湃，只聽的令人心神舒暢，
	豪氣千里，爽朗異常，舒服已極，令你不禁想放聲狂嘯！！！！
	如此巨大的瀑布，自然不可能縱身而下，必定粉身碎骨。
	所以一旁有高人依山壁所築的立足點，你可以踏那些立足點往下而去。

LONG);

  set("exits", ([ /* sizeof() == 3   */
    "north" : __DIR__"hr19.c",
    "down" : __DIR__"lk1.c",
  ]));
  setup();
}

void init()
{
  add_action("do_search","search");
  add_action("do_pass","pass");
}

int do_search(string str)
{
  if(!str) {
    tell_object(this_player(),"似乎瀑布(waterfall)深處有些微光。\n");
    return 1;
  }
  if(str!="waterfall") return 0;
  this_player()->set_temp("search",1);
  message_vision("$N覺得瀑布裡面似乎有通道可以進入。\n",this_player());
  return 1;
}

int do_pass(string str)
{
  object me=this_player();
  if(str!="waterfall") return 0;
  if(me->query_temp("search")==0) return 0;
  message_vision("$N往瀑布裡走了進去。\n",me);
  me->delete_temp("search");
  me->move("/open/japan/room/s1.c");
  return 1;
}