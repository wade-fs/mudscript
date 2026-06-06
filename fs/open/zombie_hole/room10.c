inherit ROOM;

#include "room.msg"
string query_long1();
void create ()
{
set ("short", "殭屍洞");
set ("long", (: query_long1 :) );
set("no_clean_up",1);

  set("no_transmit", 1);
  set("no_scale",1);
set("search_desc/hole","你覺得這個洞好像可以鑽(enter)進去。");
setup();
}
string query_long1()
{
return query_long()  + HIW"\t這裡好像有一個神奇的洞(hole)。\n" + NOR;
}
void init()
{
	add_action("do_enter","enter");
}
int do_enter(string arg)
{
object me = this_player();
if(!arg) return notify_fail("你要去哪裡？");
if(arg != "hole")
	return notify_fail("你要去哪裡？");
message_vision(HIB + "$N努力的往洞裡鑽啊鑽的，終於進去了。\n" + NOR,me);
me->move(resolve_path(__DIR__,"room11.c"));
return 1;
}
