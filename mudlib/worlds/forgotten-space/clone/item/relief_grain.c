// clone/item/relief_grain.c
// 官平平糶荒糧 - 金石府常平倉戰略儲糧，平抑物價之平價糧袋

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("平糶荒糧袋", ({ "relief grain", "grain", "relief_grain", "liangdai", "平糶荒糧袋", "荒糧", "糧袋" }));
    set_short(HIY "【官平平糶荒糧袋】" NOR);
    set_long("一袋由金石常平倉封印、以粗麻布緊扎的戰略儲備乾糧，內盛炒熟的稻麥碎與豆粉。\n"
             "在災荒或專材物價騰貴時由官府按平價七五折平糶供應。(可使用 eat / 吃糧 食用充飢)\n");
    set_weight(300);
    set_value(10);
}

void init() {
    ::init();
    add_action("do_eat", "eat");
    add_action("do_eat", "吃糧");
}

int do_eat(string arg) {
    if (!arg || (arg != "grain" && arg != "relief grain" && arg != "荒糧" && arg != "吃糧")) {
        return 0;
    }
    object me = this_player();
    if (!me->consume_food(40)) return 1;

    write("你解開麻布糧袋，捧出一把焦香乾脆的炒麥豆粉倒入口中，混著唾沫吞下...\n");
    write(HIG "【你感到腹中充實溫熱，氣血與精力迅速恢復！】\n" NOR);

    me->add(VITAL_KEE, 30);
    me->add(VITAL_SP, 25);

    destruct(this_object());
    return 1;
}
