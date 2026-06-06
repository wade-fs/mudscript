//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("烏龍茶",({"wu-long tea","tea"}) );
  set_weight(500);
  if (clonep() )
    set_default_object(__FILE__);
  else{
    set("long","一壺烏龍茶。\n");
    set("unit","壺");
    set("value", 20);
    set("飽和", 10);
  }
  set("液體",([
    "種類" : "茶",
    "名稱" : "烏龍茶",
    "剩" : 10,
    "止渴" : 30,
    "drunk_apply" : -5,
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}
