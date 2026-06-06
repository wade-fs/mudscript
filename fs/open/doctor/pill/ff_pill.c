// made by ccat
// refix by chan
// 加上藥性
//排版 by blazakira 2011/11/3

inherit F_MEDICINE;

void create()
{
  set_name("雪蓮丹", ({"force pill","pill"}) );
  set("long",
    "此物乃蜀中將軍自天山絕頂採來之神藥，可以恢復大量內力。可食用(eat pill)。\n");
  set("unit", "盒");
  set("base_unit", "粒");
  set("no_sell",1);
  set("value",30000);
  set("base_weight", 50);
  set("cure_type","force");
  set("medicine_sick",125);
  set("eat_msg","$N將$n服下後，感覺身上湧出源源不斷的內力，瞬時內力大增。\n");
  set_amount(1);
  setup();
}
