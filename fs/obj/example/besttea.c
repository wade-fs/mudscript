// besttea.c by ACKY
//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

int extra_func();
int drink_func();

void create()
{
  set_name("純喫茶", ({ "tea" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set( "long", "一壺清涼解渴的特級凍頂烏龍茶。\n" );
    set( "unit", "壺" );
    set( "value", 1000 );
    set( "飽和", 20 );
  }

  // The liquid contained in the container is independent, we set a copy
  // in each cloned copy.
  set("液體", ([
    "種類"    : "茶",
    "名稱"    : "特級凍頂烏龍茶",
    "剩"    : 20,
    "止渴"    : 100,
    "飲用訊息"  : (: drink_func :),
    "額外函數"  : (: extra_func :)
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}

int extra_func()
{
  if( !query("液體/剩") ) {
    write( "這壺茶已經被你喝光了, 你運勁於指, 將其震得粉碎。\n" );
    destruct( this_object() );
    return 1;
  }
  return 0;
}

int drink_func()
{
  object me = this_player();
  message_vision( HIC"$N拿出純喫茶, 張口輕輕運勁, 一道清涼的水柱噴進$P嘴裡, 哇, 真是透心涼啊。\n"NOR, me );
  return 1;
}
