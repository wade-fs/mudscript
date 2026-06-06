// waterskin.c
//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("女兒紅", ({"girl red wine","wine","red"}) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "女兒紅美酒裝在一個葫蘆裡，酒性極烈\n");
    set("unit", "罈");
    set("value", 200);
    set("max_liquid", 15);
  }

  // The liquid contained in the container is independent, we set a copy
  // in each cloned copy.
  set("液體", ([
    "種類": "酒",
    "名稱": "女兒紅酒",
    "剩": 15,
    "止渴" : 20,
    "酒精成份": 12,
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}
