// clone/item/dry_meat.c
// 風乾鹿肉乾 - 邊陲張屠戶特製，獵戶與行商常備的乾糧

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("肉乾", ({ "dry meat", "meat", "dry_meat", "rougan", "肉乾", "鹿肉乾" }));
    set_short(YEL "風乾鹿肉乾" NOR);
    set_long("一塊用大荒粗鹽與野山椒醃製風乾的深褐色鹿肉乾，質地緊實有嚼勁，\n"
             "是獵戶與行商穿行荒野的常備口糧。(可使用 eat / 吃肉 食用充飢)\n");
    set_weight(200);
    set_value(15);
}

void init() {
    ::init();
    add_action("do_eat", "eat");
    add_action("do_eat", "吃肉");
    add_action("do_eat", "食用");
}

int do_eat(string arg) {
    if (!arg || (arg != "meat" && arg != "dry meat" && arg != "肉乾" && arg != "鹿肉乾")) {
        return 0;
    }
    object me = this_player();
    write("你撕下一大塊風乾鹿肉乾塞進嘴裡用力咀嚼，鹹香濃郁的肉汁混合著椒香滑入腹中...\n");
    write(HIG "【你感到氣血回暖，飢火頓消，體力與精神恢復了！】\n" NOR);
    
    me->add(VITAL_HP, 20);
    me->add(VITAL_KEE, 20);
    me->add(VITAL_SP, 15);
    
    destruct(this_object());
    return 1;
}
