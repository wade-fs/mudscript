// beck.c
//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set("no_get", 1);
  set_name("水缸",({"beck"}));
  set("long","一個用來裝清水的水缸。\n");
  set("飽和",50);
  set("液體", ([
    "種類": "水",
    "名稱": "清水",
    "剩": 50,
    "止渴": 30,
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}
