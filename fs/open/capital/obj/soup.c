// by onion
//補上inherit F_LIQUID專用的液體名稱 by blazakira 2011/7/22

inherit ITEM;
inherit F_LIQUID;

int extra_func();

void create()
{
  set_name("傳家雞湯", ({ "chicken soup", "soup" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "這是王家食堂祖傳的秘方, 也是王家食堂的招牌, 雞湯中還加了不少補藥, 據說可恢復少許/體力。\n");
    set("unit", "罐");
    set("value", 1000);
    set("飽和", 5);
  }

  // The liquid contained in the container is independent, we set a copy
  // in each cloned copy.
  set("液體", ([
    "種類": "湯",
    "名稱": "雞湯",
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
    write ("這罐雞湯已經被你喝光了, 你順手將它丟到隱密之處.\n");
    destruct(this_object());
    return 1;
  }
  this_player()->receive_heal("kee",10);
  return 0;
}
