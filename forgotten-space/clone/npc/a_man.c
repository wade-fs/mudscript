// /clone/npc/a_man.c
// 阿滿・黑山北線軍寨炊事與家屬聯絡人 (a_man) - 北線軍寨炊事後勤區 (Ch.94)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("阿滿");
    set_short(YEL "北線軍寨炊事" NOR " 阿滿");
    set_long("三十多歲、雙手生滿凍瘡卻收拾得極為利落的軍寨炊事婦人。丈夫三年前在裂谷外圍巡哨\n"
             "失蹤後，她帶著兩個孩子留在後勤伙房洗菜煮飯，暗中保管著歷年失蹤卒伍的名冊與未寄家書。\n");
    set_id(({ "a_man", "a man", "aman", "阿滿", "阿滿姐", "炊事婦人" }));

    setup_archetype("D", 32);
    set("class", "mortal");
    set("faction", "bahuang");
    set("roles", ({ "cook", "archivist", "civilian" }));
    set("home_room", "/d/sects/bahuang/north_garrison_kitchen.c");

    add_response(({ "失蹤者", "名冊", "天興十九年", "走山隊" }),
        "阿滿擦乾手上的水漬，從碗櫃最底層摸出一本畫著兩道黑槓的《天興十九年失蹤者與未寄家書簿》：\n"
        "「五年前大雪封山那晚，金石府來的民間走山隊領隊叫『燕山』，黑山營原本派了兩名熟路斥候在東口外接應；\n"
        "可三天後上面一張字條下來，硬生生全改成『擅離職守、改道失聯除名』，連撫恤銀子都沒發！\n"
        "名冊上的字是會被人改的，可等不到人回家的女人和老娘，是不會記錯日子的。」");

    add_response(({ "韓素", "互助棚", "家屬" }),
        "阿滿紅了眼眶指指北荒南沿入口外：「當年失聯那對接應斥候兄弟有個親妹子叫韓素，一直沒走，\n"
        "就住在關外的失蹤者家屬互助棚裡，屋裡還留著兄長的舊銅哨呢。」");
}
