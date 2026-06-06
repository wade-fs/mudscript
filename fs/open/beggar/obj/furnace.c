//增加線索描述 by blazakira 2010/12/12
inherit ITEM;
#include <ansi.h>
void create()
{
  set_name("煉爐",({"temper furnace","furnace"}));
  set("unit", "座");
  set("long", "一座煉爐。爐身有著七顆人頭大的穴位，不知道可以放入(put)什麼東西。\n");
  set("no_get",1);
  set("no_sac",1);
}

