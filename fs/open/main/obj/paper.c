#include "/open/open.h"

inherit ITEM;

void create()
{
        set_name("紙包", ({ "paper" }) );
        set("unit", "包");
        set("long", "一包紙包，似乎可以打開看看。\n");
        set("no_sell", 1);
	setup();
}

void init()
{
  add_action("do_open", "open");
}

int do_open (string arg)
{
  object	me=this_player();
  int		query;

  if (!arg || arg != "paper")
	return 0;
  
  query = me->query_temp("quests/badman_license");

  message_vision("$N把手中的紙打開。\n", me);
  if (query >= 3) {
    me->set_temp("quests/badman_license", 4);
    tell_object(me, "你發現紙裡面包著一堆藥粉，也許\是蒙漢藥吧。\n");

    new(MAIN_OBJ"drug")->move(me);
    destruct (this_object());
  }
  else set ("name", "打開的紙包");
  return 1;
}
