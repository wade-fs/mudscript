//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

int extra_func();
int drink_func();

void create()
{
  set_name(HIC"千年冰"NOR, ({ "thousand year's ice","ice" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set( "long", "一個取自於邪靈界琰揚湖最底極寒之處的冰塊，十分解渴。\n" );
    set( "unit", "個" );
    set( "value", 20000 );
    set( "飽和", 30 );
  }
  set("液體", ([
    "種類"          : "茶",
    "名稱"          : HIW"琰揚湖水"NOR,
    "剩"            : 3,
    "止渴"          : 300,
    "飲用訊息"      : (: drink_func :),
    "額外函數"      : (: extra_func :)
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}

int extra_func()
{
  if( !query("液體/剩") )
  {
    write( HIW"千年冰已經被你的內力給融化掉了。\n"NOR );
    destruct( this_object() );
    return 1;
  }
  return 0;
}

int drink_func()
{
  object me = this_player();
  message_vision( HIC"$N輕運內力，以氣力之熱溶化千年冰，並吸吮其融化之水。\n"NOR, me );
  me->add("force",-100);
  me->add("food",-300);
  return 1;
}
