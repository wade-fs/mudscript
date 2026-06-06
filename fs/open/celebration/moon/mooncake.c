#include <ansi.h>
#include "moon.h"

inherit ITEM;

void create()
{
        set_name(HIY + "月餅" + NOR, ({ "mooncake", }) );
        set("long","可以吃的月餅。\n");
        set("unit", "顆");
       set("value", 100);
			 set("no_get",1);
			 set("no_give",1);
			 set("no_put",1);
			 set("no_auc",1);
       set("no_save",1);
	setup();
}
void init()
{
  add_action("do_eat","eat");
}
int do_eat(string arg)
{
  int rand ;
  string str;
  object me = this_player();
  object money;
  if(arg != "mooncake") return 0;
  rand = random(100);
  switch(rand)
  {
    case 0..35:
    money = new("/obj/money/gold");
    str = "哈哈哈，我得到一百兩黃金啦。\n";
    money->set_amount(100);
    money->move(me);
    break;
    case 36..60:
    str = "哈哈哈，我得到一顆鑽石啦。\n";
    money = new("/obj/money/diamond");
    money->move(me);
    break;
    case 61..85:
    str = "超爽的，得到一個替身！\n";
    me->add("standby",1);
    break;
    case 86..90:
    str = "超爽的，基本內功\昇高一級！\n";
    me->set_skill("force",me->query_skill("force",1) +1);
    break;
    case 91..95:
    str = "超爽的，跳躍閃躲之術昇高一級！\n";
    me->set_skill("dodge",me->query_skill("dodge",1) +1);

    break;
    case 96..99:
    str = "超爽的，基本輕功\昇高一級！\n";
    me->set_skill("move",me->query_skill("move",1) +1);


    break;

    default:
    str = "幹，見鬼了！\n";

  }
  me->delete_temp("last_channel_msg");
    CHANNEL_D->do_channel(this_player(),CHANNEL,str);
  destruct(this_object());
  return 1;
}
