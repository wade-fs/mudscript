//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

#include "/open/open.h"
inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("茶壺", ({ "teapot" }) );
  set_weight(700);
  set("long", "這是一只大茶壺。\n");
  set("unit", "只");
  set("value", 50);
  set("飽和", 40);

  // The liquid contained in the container is independent, we set a copy
  // in each cloned copy.
  set("液體", ([
    "種類": "茶",
    "名稱": "邁撕萎耳紅茶",
    "剩": 35,
    "止渴" : 30,
    "drunk_apply": 8,
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}

void init()
{
  add_action("do_send", "send");
}

int do_send(string arg)
{
   object me=this_player(), day;
   string name, what;

  if (!arg) return 0;
  if ( sscanf (arg, "%s to %s", what, name) != 2) return 0;
  if (what != "teapot" && name != "day") return
  notify_fail ("你要把什麼送給誰?\n");

  if (!day=present("day", environment(me)))
    return notify_fail ("燕南天並不在這兒啊。\n");

  if (me->query_temp("quests/badman_license") >= 5 && query_temp("has_drug")) {
    me->set_temp("quests/badman_license", 6);
    message_vision ("燕南天喝了藥茶之後兩腳一撐......\n", me);
    day->die();
  }
  else
    message_vision ("燕南天喝了藥茶之後，顯得神清氣爽。\n", me);
    
  destruct(this_object());
  return 1;
}
