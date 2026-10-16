// clone/item/huoluo_dan.c
// 葛氏活絡散 - 瘋郎中葛半仙獨家熬製的拔毒活絡藥散

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("活絡散", ({ "huoluo san", "powder", "san", "活絡散", "葛氏活絡散" }));
    set_short(HIG "葛氏活絡散" NOR);
    set_long("由瘋郎中葛半仙以清晨帶露晨露草與水谷地陰苔調配而成的草藥散劑，\n"
             "氣味微苦甘辛。服下後氣血充盈，能迅速驅散體內寒濕與勞損。(可使用 eat / 服藥 服用)\n");
    set_weight(80);
    set_value(100);
}

void init() {
    ::init();
    add_action("do_eat", "eat");
    add_action("do_eat", "服藥");
    add_action("do_eat", "吞服");
}

int do_eat(string arg) {
    if (!arg || (arg != "san" && arg != "powder" && arg != "huoluo san" && arg != "活絡散" && arg != "葛氏活絡散")) {
        return 0;
    }
    object me = this_player();
    if (!me->consume_food(25)) return 1;

    write(HIG "你仰頭將一包葛氏活絡散倒入口中，微苦回甘的藥力如一線溫熱清泉直透四肢百骸...\n" NOR);
    write(HIY "【體內寒氣消散，筋骨活絡舒暢，你的氣血、神識與精力大幅回升！】\n" NOR);
    
    me->add(VITAL_KEE, 40);
    me->add(VITAL_SEN, 25);
    me->add(VITAL_SP, 30);
    
    destruct(this_object());
    return 1;
}
