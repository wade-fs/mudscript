// made by ccat
// refix by onion
// refix by chan
// 加上藥性
//排版 by blazakira 2011/11/2

inherit F_MEDICINE;

void create()
{
  set_name("靈芝仙丹", ({"super pill","pill"}) );
  set("long",
    "此物乃蜀中將軍自蜀山神峰採來之神藥，專克血氣失調。為藥丸可食用(eat pill)。\n");
  set("unit", "盒");
  set("base_unit", "粒");
  set("no_sell",1);
  set("value",20000);
  set("base_weight", 50);
  set("cure_type","poison");
  set("cure_poison_type","ff_poison");
  set("medicine_sick",120);
  set_amount(1);
  set("medicine_power",5);
  setup();
}
