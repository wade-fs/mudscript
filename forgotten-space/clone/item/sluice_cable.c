// clone/item/sluice_cable.c
// 截流精鋼索 - 水門搶險特製高韌鋼纜

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("截流精鋼索", ({ "sluice cable", "cable", "gangsuo", "鋼索", "精鋼索", "截流精鋼索" }));
    set_short(CYN "【截流精鋼索】" NOR);
    set_long("由城防軍與百工匠坊聯合調發的七股生鐵合絞高韌鋼纜，長達百丈，沉重冰涼。\n"
             "在西水門狂暴洪峰與水流衝擊下，唯有具備深厚盤石身法的武者才能將其負入深潭，\n"
             "錨定水底地牛，為封堵決口提供唯一的受力支點。\n");
    set_weight(500);
    set_value(150);
    set("is_cable", 1);
}
