//每種pill都有藥性
//design by chan
//排版 by blazakira 2011/11/3

inherit F_MEDICINE;

void create()
{
  set_name("太乙靈神丹", ({"taii pill","pill"}) );
  set("long","此物乃由太乙山青草煉製，可以恢復大量靈力。\n");
  set("unit", "盒");
  set("base_unit", "粒");
  set("no_sell",1);
  set("value",7000);
  set("base_weight", 50);
  set("cure_type","atman");
  set("medicine_sick",120);
  set("eat_msg","$N將$n服下後，感覺身上充滿了靈氣。\n");
  set_amount(1);
  setup();
}
