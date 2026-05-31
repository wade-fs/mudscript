// waterskin.c
//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("牛皮酒袋", ({ "wineskin", "skin" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一個牛皮縫的大酒袋﹐大概裝得八、九升的酒。\n");
    set("unit", "個");
    set("value", 20);
    set("max_liquid", 15);
  }

  // The liquid contained in the container is independent, we set a copy
  // in each cloned copy.
  set("液體", ([
    "種類": "酒",
    "名稱": "紅酒",
    "剩": 15,
    "止渴" : 40,
    "酒精成份": 6,
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}
