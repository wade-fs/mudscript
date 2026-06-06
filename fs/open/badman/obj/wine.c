// wine.c
//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("白乾", ({ "wine" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一壺香醇的白乾，聞起來烈的很。\n");
    set("unit", "壺");
    set("value", 150);
    set("飽和", 15);
  }

  // The liquid contained in the container is independent, we set a copy
  // in each cloned copy.
  set("液體", ([
    "種類": "酒",
    "名稱": "白乾",
    "剩": 15,
    "止渴" : 30,
    "drunk_apply": 9,
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}
