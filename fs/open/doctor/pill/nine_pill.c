//每種pill都有藥性
//design by chan
//排版 by blazakira 2011/11/3

inherit F_MEDICINE;

void create()
{
  set_name("九節法神丸", ({"nine pill","pill"}) );
  set("long","此物乃由九節昌蒲所煉製，可以恢復大量法力。\n");
  set("unit", "盒");
  set("base_unit", "粒");
  set("no_sell",1);
  set("value",7000);
  set("base_weight", 50);
  set("cure_type","mana");
  set("medicine_sick",120);
  set("eat_msg","$N將$n服下後，感覺身上充滿了法力。\n");
  set_amount(1);
  setup();
}
