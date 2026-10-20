// clone/npc/wild_bear.c - 黑嶺狂暴巨熊（高階菁英怪，Lv6）
#include "/include/ansi.h"
#include "/include/config.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name(([ "en": "Wild Bear", "zh-TW": "黑嶺暴熊", "zh-CN": "黑岭暴熊" ]));
    set_short(([ "en": "a ferocious black ridge bear", "zh-TW": "一頭狂暴的黑嶺巨熊", "zh-CN": "一头狂暴的黑岭巨熊" ]));
    set_long(([
        "en": "This is a gigantic black bear with thick fur like iron plates and blood-red eyes, reeking of violent煞气.\n",
        "zh-TW": "這是一頭直立起來足有一丈高的太古大荒暴熊！周身毛皮如鐵氈般板結油亮，肩背肌肉高高隆起，\n一對泛著幽暗濁血紅芒的凶目死死盯著四周，沉重的喘息聲震得地面落葉簌簌發抖。\n",
        "zh-CN": "这是一头直立起来足有一丈高的太古大荒暴熊！周身毛皮如铁毡般板结油亮，肩背肌肉高高隆起，\n一对泛著幽暗浊血红芒的凶目死死盯著四周，沉重的喘息声震得地面落叶簌簌发抖。\n"
    ]));
    set_id(({ "wild bear", "bear", "暴熊", "黑嶺暴熊", "黑嶺巨熊", "巨熊" }));

    level    = 6;
    stat_str = 28;
    stat_dex = 10;
    stat_con = 24;
    stat_int = 3;
    recalc_stats();
    hp = max_hp;

    set_exp_reward(280);
    set_gold_reward(60);
    set_drop_list(({ "/clone/item/dry_meat.c", "/item/material/wolf_fur.c" }));
    set_respawn(60);
    set_aggro_msg("黑嶺暴熊仰天發出一聲撕裂林莽的狂暴熊咆，人立而起，重逾千斤的巨掌帶起狂風拍下！\n");
    set_special_atk("巨熊裂石掌", 30);
}
