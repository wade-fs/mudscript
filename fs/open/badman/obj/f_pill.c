// s_pill.c by oda
//排版 與將函數名稱改為 eat_pill by blazakira 2011/11/6

#include "/open/open.h"
#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("藥丸", ({ "pill" }));
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "這是一顆從萬神醫那邊偷出來的藥丸，吃下去也許\有什麼神奇的功\效。\n");
    set("unit", "顆");
    set("食物", ([
//      "剩" : 4,       // 可以吃幾口
//      "供應": 40,     // 每一口填飽肚子的量
      "額外函數" : "eat_pill",
    ]) );
  }
  setup();
}

int eat_pill(object me, string arg)
{
  if( !arg || arg!="pill" )
    return 0;
  message_vision("$N拿起藥丸，不管三七二十一的就往肚子裡吞。\n", me);
  tell_object(me, "你感覺到全身突然熱血沸騰，難道是神藥的功\效讓你增加了一甲子的功\力嗎？\n");
  this_object()->move(BAD_ROOM"temp");
  call_out("eat_pill2", 3, me);
  return 1;
}

int eat_pill2(object me)
{
  int max, force;
  max = me->query("max_force");
  force = me->query("force");
  tell_object(me, "\n你感到一股雄渾的內勁在你體內流竄。\n");
  tell_object(me, HIC"你的內力恢復了！\n"NOR);
  if( force < max )
    me->set("force", max);
  destruct(this_object());
  return 1;
}
