// /d/yunjin/tournament_craft_arena.c
// 問道天台・東西百工丹器雙試台（Ch.113：不融黑鐵破煞火魔偶與雙盲銀針試九轉增元丹）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("問道天台・百工丹器雙試台");
    set_long("並列設於問道天台中央的兩座十丈見方高台：東側「百工器試台」青石板上鋪著厚重\n"
             "耐火生鐵板，魯長老與章百鍊分坐裁判席；台上矗立著趙烈操控的丈二「煞火魔偶」\n"
             "（可施疊震訣以三錘破其脆化主軸：smash puppet）。西側「丹鼎藥試台」則排開青銅丹鼎，\n"
             "白鶴年與孫聞露面前擺著雙盲純銀試針與雪線苔活葉（當眾銀針試毒封樣：test needle）。\n"
             "向西返回【問道天台質證高台】。\n");

    set_exits(([
        "west": "/d/yunjin/hearing_hall.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", YEL "東側耐火生鐵板隱隱發燙，西側純銀試針握在掌心冰涼細滑。" NOR);
    set_smell("default", HIG "東台煞火黑鐵焦煙與西台雪線苔、丹藥爐火的濃郁藥氣左右分庭抗禮。" NOR);
    set_listen("default", HIY "鐵錘重擊煞火魔偶的震天巨響與西台銀針試毒後全場驟然靜下的抽氣聲。" NOR);

    spawn_npc("/clone/npc/zhao_lie.c");
    spawn_npc("/clone/npc/li_qingyun.c");
}

void init() {
    ::init();
    add_action("do_smash", "smash");
    add_action("do_test", "test");
}

int do_smash(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "puppet" && arg != "shaft" && arg != "魔偶" && arg != "主軸") {
        notify_fail("你想以疊震訣擊試什麼？試試：smash puppet\n");
        return 0;
    }
    message_vision("$N運起「百工格物心眼」與「瘋魔借力疊震訣」，烏金長柄鍛錘連落三錘——震鬆虛牙、\n"
                   "貫破受血精腐蝕之暗紫脆化點、定軸停機而不傷對手！魯長老當即刮封樣本留檔。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "smash", "target": "puppet" ]));
    }
    return 1;
}

int do_test(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "needle" && arg != "pill" && arg != "銀針" && arg != "丹藥") {
        notify_fail("你想執行什麼試毒比對？試試：test needle\n");
        return 0;
    }
    message_vision("$N取出「三元生機丹」與「九轉增元丹」作雙盲比對：後者遇純銀試針僅兩息便冒灰黑煙、\n"
                   "生出暗紫鏽斑並將兩片雪線苔活葉瞬間毒枯，李青雲大驚失色並被依規封存「紅血引子」樣本。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "test", "target": "needle" ]));
    }
    return 1;
}
