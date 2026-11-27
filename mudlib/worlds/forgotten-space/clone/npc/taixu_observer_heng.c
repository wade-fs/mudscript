// /clone/npc/taixu_observer_heng.c
// 衡真道人（太虛神宮・校星觀測院異見修士）(Ch.135-136, 148, 157-158)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("衡真道人");
    set_short(HIW "校星觀測院" NOR " 衡真道人");
    set_long("一位鬚髮微霜、道袍袖口沾滿石墨粉與銅鏽的太虛神宮外階觀測士。\n"
             "他多年來暗中核對天羅校準的衰減誤差，對主簿嚴平私挪鹽晶與玉化晶核之舉深感疑懼。\n");
    set_id(({ "taixu_observer_heng", "observer heng", "heng", "衡真道人", "衡真" }));

    setup_archetype("G", 86);
    set("class", "dao");
    set("path", "fa");
    set("faction", "taixu");
    set("roles", ({ "observer", "quest", "info" }));
    set("no_combat", 1);
    set("home_room", "/d/realm/taixu/white_jade_steps.c");

    add_response(({ "日誌", "誤差", "校準", "銅匣" }),
        "衡真壓低聲音環顧白玉階座：「每三百年天羅衰減半拍，偏殿只能靠吞噬新進修士的玉化晶核硬補！\n"
        "完整正本帶不出來，但這枚鎖死的太古讀數銅匣先交給你（copy log）；只是我欠主殿三枚無毒穩壓銅芯，\n"
        "務必請萬物外環的高明匠師替我補鍛還帳，否則下次查驗我也得被送去補塔位。」");

    add_response(({ "嚴平", "主簿", "鹽晶" }),
        "衡真神色一凜：「執律閣主簿嚴平嘴上說著零誤差，暗地裡卻扣下外階損耗鹽晶補貼自家觀星台延壽！\n"
        "校準夜偏殿裡只要攤開實測帳本，他的假面具就得當場裂開。」");
}
