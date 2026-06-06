//每種pill都有藥性
//design by chan
//排版 by blazakira 2011/11/3

inherit F_MEDICINE;

void create()
{
  set_name("人靈丹", ({"human pill","pill"}) );
  set("long","此物乃傳說中的丹藥，具有起死回生的藥效。\n");
  set("unit", "盒");
  set("base_unit", "粒");
  set("no_sell",1);
  set("value",7000);
  set("base_weight", 50);
  set("cure_type","heal_kee");
  set("medicine_sick",120);
  set("eat_msg","$N將$n服下後，感覺身上傷痕都不見了。\n");
  set_amount(1);
  setup();
}
