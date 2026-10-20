// clone/npc/zhao_si.c
// 商隊惡奴 趙四 - 狐假虎威的兵痞爪牙 (小說第6、8、10章反派)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("趙四");
    set_short(RED "商隊兵痞" NOR " 趙四");
    set_long("一名滿臉橫肉、身穿暗銅鉚釘硬皮甲的金石商會護衛。半邊臉頰高高腫起，\n"
             "帶著被二掌櫃抽打的血痕。他眼神怨毒陰鷙，腰挎一把三尺狹長解腕刀，\n"
             "正勾結城防軍暗探在鎮上尋釁滋事，隨時準備拔刀行凶。\n");
    set_id(({ "zhao si", "zhao", "guard", "趙四", "兵痞" }));

    set_level(4);
    set_stat("str", 16);
    set_stat("dex", 15);
    set_stat("con", 16);
    recalc_stats();

    set("attitude", "aggressive");
    set("combat_exp", 800);

    // 攜帶解腕刀與少量銅錢
    object blade = new("/clone/weapon/clearing_blade.c");
    if (blade) blade->move(this_object());
}

void die() {
    object me = query_temp("last_damage_from");
    if (me && userp(me)) {
        tell_object(me, HIR "趙四慘嚎一聲栽倒在地，咽喉冒血抽搐了兩下，徹底斷了氣！\n" NOR);
        // 掉落火漆密信
        object letter = new("/clone/item/secret_letter.c");
        if (letter) {
            letter->move(environment());
            tell_object(me, HIG "趙四懷裡滾落出一封【染血的火漆密信】！\n" NOR);
        }
    }
    ::die();
}
