// beck.c
//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set("no_get", 1);
  set_name("水井",({"well"}) );
  set("long","一口樣式古樸的水井。\n");
  set("飽和",50);
  set("液體", ([
    "種類": "水",
    "名稱": "清水",
    "剩": 300,
    "止渴" : 30,
    "drink_func":0,
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}
