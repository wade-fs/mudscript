#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
int do_list();
int do_trade(string);
void create() {
set("short","狼棚角落");
set("long",@LONG
這裡是整個棚子的一角，有個老年人站在這，為毫無人煙的村子
添加了點生氣。他正在為狼群準備食物，你看到他和狼群間的關係是
如此親密，或許可以跟他要匹狼來騎騎吧。
LONG);
  set("exits",([ /* sizeof() == 1 */
  "center" : __DIR__"wolf09.c",
]));
  set("objects",([ /* sizeof() == 1 */
  "/open/badman/ride/rider.c" : 1,
]));
  set("light_up", 1);
        set("no_kill", 1);
set("no_fight", 1);
        set("no_magic", 1);
        setup();
}
void init() {
  add_action("do_trade","want");
}

int do_trade(string str) {
  int exp;
  object me,wolf;
  me=this_player();
  exp=me->query("combat_exp",1);
  if(me->query_temp("marks/have_wolf",1))
  return notify_fail("不是給你拿走一匹了嗎？\n");
  if (me->query("marks/ride_wolf")!=1)
  return notify_fail("雖然狼是我在養，但所有權是莨大爺的啊！\n");
  if (exp<350000)
  return notify_fail("你要騎？我看不太行吧？再去練練吧！\n");
  new("/open/badman/ride/r_wolf.c")->move(environment(me));
  me->set_temp("marks/have_wolf",1);
  message_vision("許\老從狼群中挑了一隻紅狼來。\n",me);
  return notify_fail("這狼就交給你啦，要好好照顧啊！\n");
}
