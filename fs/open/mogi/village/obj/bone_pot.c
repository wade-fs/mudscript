//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("骷髏\酒壺", ({ "bone pot", "pot" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "用人類頭骨刻出來酒壺, 感覺有點陰森恐怖.\n");
    set("unit", "個");
    set("value", 40);
    set("max_liquid", 20);
  }

  set("液體", ([
    "種類": "酒",
    "名稱": "血酒",
    "剩": 20,
    "止渴" : 50,
    "酒精成份": 7,
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}
