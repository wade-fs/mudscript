//無名屍體------by dhk 2000.5.18
#include "/open/open.h"
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("無名屍體", ({ "noname corpse","corpse" }) );
    set_weight(1000000);
 if( clonep() )
    set_default_object(__FILE__);
 else {
       set("long", "這是一具不知名的屍體，怎麼會橫屍後山，真是奇怪？\n");
       set("unit", "棵");
       set("value", 150);
       set("no_sell",1);
       set("no_auc",1);
       set("no_give",1);
       set("no_get",1);
      }
    setup();
}
void init()
{
  add_action("do_corpse","search");
  add_action("do_yes","get_all_from_corpse");
}
int do_corpse()
{
  object me = this_player();

  if(me->query("family/family_name") != "段家")
  {
  tell_object(this_player(),"啥也沒找到....\n");
  }
  if(me->query("family/family_name") == "段家")
  {
  tell_object(this_player(),"好像它的手上拿著一樣東西，不知道是什麼?拿起來﹝get_all_from_corpse﹞看一下吧！\n");
    me->set_temp("search_ok",1);
  }
  return 1;
}
int do_yes()
{
  object me = this_player();
  object letter=new("/open/ping/questsfan/obj/posthumous.c");
    if(me->query_temp("search_ok")==1)
  {
  letter->move(me);
  tell_object(this_player(),"找到一封" + HIR + "沾血的遺書" + NOR + "\n");
    me->set_temp("search_ok",0);
}
  return 1;
}

