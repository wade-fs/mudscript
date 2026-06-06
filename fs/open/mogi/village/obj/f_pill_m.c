// made by ccat
//改寫原來的pill....加上藥性....     adapt by eva
// 重新改寫.加上藥性..bye chan
inherit F_MEDICINE;
void create()
{
        set_name("魔血丹", ({"force pill","pill"}) );
        set("long","魔界特殊草藥煉製而成的丹藥, 因其顏色如血而得名.
聽說服用後對內力大有助益.\n");
        set("unit", "盒");
        set("base_unit", "粒");
        set("value",50000);
        set("base_weight", 50);
        set("cure_type","force");
        set("medicine_sick",125);
        set("eat_msg","$N將$n服下後, 感覺身上湧出源源不斷的內力,瞬時內力大增。\n");
        set_amount(1);
        setup();
}
