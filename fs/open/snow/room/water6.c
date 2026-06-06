#include <room.h>
#include <ansi.h>
#include "/open/open.h"
inherit ROOM;
void do_west();
void create()
{
          set("short","雪泉洞內");
        set("long",@LONG
這裡是雪泉洞的盡頭﹐神聖泉水就在眼前﹐但是卻有
三聖獸最強的白髮狼魔在此把守。
LONG);
        set("exits", ([
		"east":__DIR__"water5",
      ]));
	set("objects",([SNOW_NPC"sec_anm3":1]));
        setup();
}
void init()
{
      add_action("do_drink","drink");
     add_action("do_search","search");
    add_action("do_enter","enter");
}
int do_drink(string str)
{
    if(str!="water")
       return 0;
	if(this_player()->query("quests/get_tiger")!=1)
     {
        message_vision(
       HIW + "$N喝了雪泉聖水﹐得到了一道靈氣。\n" + NOR,this_player());
	this_player()->set("quests/get_tiger",1);
	this_player()->set("sec_kee","tiger");
        return 1;
     }
          tell_object(this_player(),"你已經喝過聖水﹐再喝也沒用。\n");
      return 1;
}
int do_search()
{
	write("你發現石壁的邊邊有一個小洞(hole)。\n");
    this_player()->set_temp("search",1);
   return 1;
}
int do_enter(string str)
{
    if(this_player()->query_temp("search")!=1)
        return 0;
   if(str!="hole")
      return 0;
    tell_object(this_player(),"你走進了小洞。\n");
     this_player()->move(__DIR__"s_hole");
    return 1;
}
