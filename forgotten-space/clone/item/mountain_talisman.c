// clone/item/mountain_talisman.c
// 【太上定脈鎮山符】 (小說第14章瞎老道親筆繪製)

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("太上定脈鎮山符");
    set_short(HIC "【太上定脈鎮山符】" NOR);
    set_long("一張長達七寸、以赤陽雄雞熱血混硃砂金粉繪就的血色道符。符面上繪著\n"
             "繁複如龍蛇起伏的定脈真言，隱隱散發出一股鎮壓地脈的浩然正氣。\n"
             "可用於平息地底落石餘震 (burn talisman)。\n");
    set_id(({ "mountain talisman", "talisman", "符", "鎮山符", "定脈符" }));

    set_weight(50);
    set_value(200);
}

void init() {
    ::init();
    add_action("do_burn", "burn");
    add_action("do_burn", "焚符");
    add_action("do_burn", "用符");
}

int do_burn(string arg) {
    if (!arg || (arg != "talisman" && arg != "符" && arg != "鎮山符")) return 0;

    write(HIC "你咬破指尖點在符紙之上，真言引動，整張道符無火自燃，化作一道金光沒入岩壁！\n" NOR);
    write(HIY "只聽地脈深處傳來一聲沉悶嗡鳴，周圍震顫欲墜的碎石奇異地平息了下來。\n" NOR);
    destruct(this_object());
    return 1;
}
