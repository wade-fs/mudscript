inherit ROOM;

#include "room.msg"
string query_long1();
void create ()
{
set ("short", "殭屍洞");
set("no_clean_up",1);
set("exits/west",__DIR__"/room11.c");
set("long",@LONG
這裡矗立著一位殭屍王，身上散發出金光，旁邊還有紅色的棺木，除
了這些之外，還有一些奇怪的陪葬品，這些好像是殭屍王生前所使用的物
品。
LONG
);
set("objects",([ /* sizeof() == 3 */
      __DIR__"/npc/zombie_king.c" : 1,
      ]));

  set("no_transmit", 1);
  set("no_scale",1);
setup();
}
void init()
{
	add_action("do_throw","throw");
}
int do_throw(string arg)
{
  object obj,king;
object me = this_player();
if(!arg) return notify_fail("你要丟什麼？\n");
if(arg != "blood" && arg != "line" && arg != "rice")
	return notify_fail("你要丟什麼？\n");
if(!obj = present(arg,me))
  return notify_fail("你身上沒有這些東西。\n");
if(!king = present("zk",environment(this_player())))
  return notify_fail("這裡沒有人可以給你丟哦。\n");
message_vision(RED + "$N把手上的$n" + RED + "丟出去，鬼王覺得身上的金身露出了一些破綻。\n" + NOR,me,obj);
king->set_temp("break",1);
destruct(obj);
return 1;
}

