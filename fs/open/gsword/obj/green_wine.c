// waterskin.c
//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("竹葉青", ({"green wine","wine","green"}) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "竹葉青酒裝在一個竹筒裡，酒性極烈\n");
    set("unit", "筒");
    set("value", 200);
    set("max_liquid", 15);
  }

  // The liquid contained in the container is independent, we set a copy
  // in each cloned copy.
  set("液體", ([
    "種類": "酒",
    "名稱": "竹葉青酒",
    "剩": 20,
    "止渴" : 22,
    "酒精成份": 10,
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}
