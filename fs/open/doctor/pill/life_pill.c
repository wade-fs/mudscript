//排版 by blazakira 2011/11/3

inherit F_MEDICINE;

void create()
{
  set_name("保命丹", ({"life pill","pill"}) );
  set("long","一粒保命丹，可用來補血及療傷，你可以吞下它(eat pill)。\n"+
    "(此藥由銀針門大夫所製，因華陀醫術之精愖，故孳性甚低。\n");
  set("unit", "盒");
  set("base_unit", "粒");
  set("value", 300);
  set("base_weight", 100);
  set_amount(1);
  set("cure_type","heal");
  set("cure_heal_type","kee");
  set("medicine_power",50);
  set("medicine_sick",108);
  setup();
}
