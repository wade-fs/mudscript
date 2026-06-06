// Room: /u/g/guetenr/beggar/room/beg2/clr1.c
inherit ROOM;

void create ()
{
  set ("short", "丐幫大棧");
  set ("long", @LONG
　　　　　　　　　┌─┐　　　　　┌─┐　　　　　　　　
　　　　　　　　　　┌┴─┴─────┴─┴┐　　　　　　　　　　
　　　　　　　　　　│　  丐  幫  大  棧    │　　　　　　　　　　
　　　　　　　　　　└┬─┬─────┬─┬┘　　　　　　　　　　
　　　　　　　　　　　│　│　　　　　│　│　　　　　　　　　　　
┼┼┼┼┼┼┼┼┼┼┼┤　│　　　　　│　├┼┼┼┼┼┼┼┼┼┼┼
││││││││││││　│　　　　　│　││││││││││││
┴┴┴┴┴┴┴┴┴┴┴┴─┴─────┴─┴┴┴┴┴┴┴┴┴┴┴┴

你可以在划船回去喔(board back)
LONG);

  set("outdoors", "cs");
  set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"clr2.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "open/beggar/room/beg1/npc/guard.c" : 2,
]));

  setup();
}

void init()
{
add_action("do_board","board");
}

int do_board(string str)
{
object me;
me=this_player();
if(str!="back")
return notify_fail("你要幹麻?無聊喔??\n");
write("你慢慢的划著小舟!!\n");
  me->move("/open/beggar/room/beg1/room36.c");
  return 1;
}

int valid_leave(object me, string dir)
   {
        if(dir=="enter"&&present("guard",environment(me)))
        {
            if(me->query("family/family_name")=="丐幫")
              return 1;
            if(me->query_temp("b_enter")!=1)
              return notify_fail("丐幫門守擋著你你, 要求你說【暗號】!!\n");
         }
    return 1;
  }



