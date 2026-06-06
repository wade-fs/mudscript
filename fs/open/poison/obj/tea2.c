//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("鐵觀音",({"tie-guanin tea","tea"}) );
  set_weight(500);
  if ( clonep() )
    set_default_object(__FILE__);
  else{
    set("long","一壺醒酒鐵觀音茶。\n");
    set("unit","壺");
    set("value",15);
    set("飽和", 10);
  }
  set("液體", ([
    "種類" : "水",
    "名稱" : "茶水",
    "剩" :  10,
    "drunk_apply" : -3,
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}
