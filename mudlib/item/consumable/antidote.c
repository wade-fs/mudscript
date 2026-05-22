// /item/consumable/antidote.c
#include "/include/config.h"
inherit "/std/item";

void create() {
    ::create();
    set_item_type(ITEM_CONSUMABLE);
    set_name("初級解毒劑");
    set_short("一瓶透明的解毒劑");
    set_long("這是一瓶能解除多種初級毒素的解毒藥水。\n");
    set_id(({"antidote", "potion", "解毒劑", "藥水"}));
    set_weight(150);
    set_value(50);
}

int use(object user) {
    write("你喝下了解毒劑，感覺身體輕鬆了許多。\n");
    say(user->query_name() + " 喝下了一瓶解毒劑。\n");
    destruct(this_object());
    return 1;
}
