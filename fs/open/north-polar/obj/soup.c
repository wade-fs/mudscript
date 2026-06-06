//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

int extra_func();
int drink_func();

void create()
{
  set_name("薑湯", ({ "soup" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set( "long", "冰寒天氣中最適合飲用的飲品。\n" );
    set( "unit", "碗" );
    set( "value", 1000 );
    set( "no_auc",1);
    set( "飽和", 18 );
  }

  // The liquid contained in the container is independent, we set a copy
  // in each cloned copy.
  set("液體", ([
    "種類"          : "茶",
    "名稱"          : "特級凍頂烏龍茶",
    "剩"            : 20,
    "止渴"          : 100,
    "飲用訊息"      : (: drink_func :),
    "額外函數"      : (: extra_func :)
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}

int extra_func()
{
  if( !query("液體/剩") ) {
    write( "這碗薑湯已經被你喝光了，你舔了舔嘴，似乎還意猶未盡。\n" );
    destruct( this_object() );
    return 1;
  }
  return 0;
}

int drink_func()
{
  object me = this_player();
  message_vision( YEL + "$N取出薑湯，大口大口的嚥下，肚子裡升起一股暖意。\n" + NOR, me );
  return 1;
}
