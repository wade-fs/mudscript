#include "/open/open.h"
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW+"天鼓『" + HIC + "雷音"HIW + "』"+NOR, ({ "drum" }) );
        set_weight(700);
        set("long", "傳聞跟四大神獸的龜有關 ,然而沒用過誰也不知道... 
用法是use drum at xxx。\n");
        set("unit", "只");
        set("value", 5000);
       set("no_put", 1);
       set("no_sell", 1);
       set("no_drop", 1);
       set("no_give", 1);
        setup();
}

void init()
{
  add_action("do_use", "use");
}

int do_use(string arg)
{
   object me=this_player(), turtle;
   string name, what;

  if (!arg) return 0;
  if ( sscanf (arg, "%s at %s", what, name) != 2) return 0;
  if (what != "drum" && name != "turtle") return
        notify_fail ("你在做什麼??\n");

  if (!turtle=present("turtle", environment(me)))
    return notify_fail ("一道閃電劈下來 ,但什麼事都沒發生。\n");

 
    message_vision (HIW + "一道天雷直劈下來 ,將盤古真龜的龜殼粉碎了\n" + NOR, me);
   destruct(turtle);
   
 new("/open/island/npc/turtle2.c")->move("/open/island/room/cold.c");   
message_vision (HIC + "天鼓『雷音』也隨後化成飛灰...\n" + NOR, me);
destruct(this_object());

  return 1;
}

