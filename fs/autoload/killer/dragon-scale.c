#include <armor.h>
#include <ansi.h>
inherit FINGER;
object me=this_player();
int cor,kar,intt,spi,cps;
void create()
{
  set_name(HIR + "火龍之鱗" + NOR,({"fire-dragon ring","fring", "ring"}) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
        else {
    set("unit","件");
    set("value", 0);
    set("material","gem");
    set("long","火龍之王身上的環狀鱗片, 可用(wear fire-dragon ring)來裝備。或用(identify fire)來鑑定此火龍麟的防火等級。\n");
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
  }
  setup();
  set("armor_prop/dodge", 5);
  set("armor_prop/parry", 5);
  set("armor_prop/force", 10);
  set("armor_prop/magic", 10);
  set("armor_prop/armor", 10);
  set("wear_msg",HIR + "戴上了$n" + HIR + "後，一股強烈的焰氣籠罩了$N" + HIR + "。\n" + NOR);
  set("unequip_msg",HIR + "$N" + HIR + "脫下了$n" + HIR + "週遭的火焰立刻消散。\n" + NOR);
}

int query_autoload()
{
  return 1;
}

void init()
{
  if(this_player()==environment()){
    add_action("do_identify","identify");
  }
}

int wear()
{
  object me;
  int result = ::wear();
  if( query("equipped"))
  {
    me=environment();
//    message_vision(HIR + "戴上了火龍之鱗後，一股強烈的焰氣隴罩了$N。\n" + NOR,me);
    me->set_temp("def_fire1",1);
  }
  return result;
}

int unequip()
{
  object me=environment();
  int result = ::unequip();
  if( !query("equipped") )
  {
//    message_vision(HIR + "$N脫下了火龍之鱗週遭的火焰立刻消散。\n" + NOR,me);
    me->delete_temp("def_fire1");
  }
  return result;
}

int do_identify(string str)
{
   int ringlev=this_player()->query("ring_type");
   if(str=="fire")
   message_vision(HIR + "$N鑑定身上的火龍之麟等級為第"+ringlev+"級。\n" + NOR,this_player());
   return 1;

}
