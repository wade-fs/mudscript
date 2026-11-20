// /clone/npc/ice_bone_dragon.c
// 冰獄骨龍・太古亞龍種荒獸王 (ice_bone_dragon) - 黑山長城西段崩塌缺口 (Ch.118-119)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("冰獄骨龍");
    set_short(HIW "太古亞龍種荒獸王・冰獄骨龍" NOR);
    set_long("體長超過六丈、二階極限至半隻腳踏入三階門檻的恐怖冰原荒獸王！通體慘白骨甲\n"
             "如萬載冰髓打造而成，長期受地底血精母脈異常噴發兼天台主陣斷流影響受驚南遷。\n"
             "牠口吐零下數百度幽藍冰煞一息便凍裂垮塌三十丈黑山長城；唯有左肋下方正帶著一道近期\n"
             "被高壓熔岩燙傷之焦黑舊創——待巨靈神機斜頂半息兼周天星力鎖定後即係《破核》唯一命門！\n");
    set_id(({ "ice_bone_dragon", "bone_dragon", "dragon", "冰獄骨龍", "骨龍" }));

    setup_archetype("K", 95);
    set("class", "beast");
    set("faction", "wastes_beast");
    set("home_room", "/d/sects/bahuang/west_wall_breach.c");

    set_exp_reward(4500);
    set_gold_reward(1200);
    set_respawn(180);
    set_aggro_msg("冰獄骨龍發出震徹雪原的淒厲龍吟，撞碎三號門樓條石帶著上千荒獸狂壓缺口！\n");
    set_special_atk("幽藍冰獄煞息", 85);
}
