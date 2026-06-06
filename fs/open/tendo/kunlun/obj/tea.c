// waterskin.c
//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

inherit ITEM;
inherit F_LIQUID;

int extra_func();
            
void create()
{
  set_name("茶", ({ "tea" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一壺香味撲鼻的茶。\n");
    set("unit", "壺");
    set("value", 50);
    set("飽和", 5);
  }

  // The liquid contained in the container is independent, we set a copy
  // in each cloned copy.
  set("液體", ([
    "種類": "茶",
    "名稱": "烏龍茶",
    "剩": 5,
    "止渴" : 30,
    "額外函數" : (: extra_func :)
  ]) );
  setup();
  set("liquid_name",query("液體/名稱"));
}

int extra_func()
{
  if (!query("液體/剩")) {
    write ("這壺茶已經被你喝光了, 你順手丟到隱密之處.\n");
    destruct(this_object());
    return 1;
  }
  return 0;
}
