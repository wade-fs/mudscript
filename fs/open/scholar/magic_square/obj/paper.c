//因為有倉庫的形式 避免玩家存入 因而造成quest不順利完成 故而增加 no save的設定 by blazakira 2011/9/28

inherit ITEM;

void create()
{
  set_name("寫滿文字的竹簡", ({ "boombo" }) );
  set("unit", "張");
  set("long", "上面寫滿著各式各樣軍隊移動的方式，感覺就像是一種極為機秘的兵書。\n");
  set("stone",1);
  set("no_get",1);
  set("no_drop",1);
  set("no_sac",1);
  set("no_save",1);
  setup();
}

int query_autoload()
{
  return 0;
}
