// Room: /u/m/moner/tree/room19.c
inherit ROOM;
#include <ansi.h>
#include "/open/open.h"

void create ()
{
  set ("short", "囚室");
  set ("long", @LONG

這裡是天邪峰囚禁犯人的牢房，兒臂粗細的鐵桿內一對對陰森的眼
睛，滿怖殺意的凝視著你，你每踏出一步，心裡便寒寒的發毛著，牢籠內
並沒有哀嚎聲，反而是一片的寧靜才令人越害怕。牢房內來來回回的走動
著獄卒。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room22.c",
"east":__DIR__"room25.c",
]));
  set("light_up", 1);
set("no_transmit", 1);
  setup();
}
void init()
{
 object me = this_player();
   if(present("skykey",me))
   tell_object(me,HIW + "南面的鐵門鎖有感於你身上的鑰匙而發出聲響。\n" + NOR);
 add_action("do_go","go");
 add_action("do_press","press");
}
int do_go(string str)
{
  object me = this_player();
  object ob = this_object();
    if(str == "south" )
         if(present("skykey",me))
            {
        tell_room(ob,"鐵門感應鑰匙的魔力，開起了一道門。\n");
             message_vision("$N不慌不忙地走了進去。\n",me);
             tell_room(ob,"隨著磁石離去，石門自動關上。\n");
me->move("/open/gblade/room/mrm1/r13.c");
             return 1;
            }
}
