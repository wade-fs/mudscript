// clone/npc/folk/liefan_old_miner.c
// 老礦工羅七・烈礬縣礦工粗茶棚（礦工下工日常與銅駝嶺早年記憶）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("老礦工羅七");
    set_short(HIR "烈礬老礦工" NOR " 羅七");
    set_long("一位背微駝、臉頰與指甲縫永遠洗不淨赤銅礦灰與煤煙的乾瘦老礦工。\n"
             "他二十年前在銅駝嶺老坑道裡吸進太多硫磺煙，如今下不了深井，只每天坐在縣驛旁的粗茶棚幫忙劈柴添水，跟收工的年輕礦工說些井下避險規矩。\n");
    set_id(({ "liefan_old_miner", "luo qi", "old miner", "老礦工羅七", "羅七", "礦工" }));

    setup_archetype("B", 9);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "miner", "info" }));
    set("no_combat", 1);

    add_response(({ "礦洞", "銅駝嶺", "井下", "規矩" }),
        "羅七灌了半碗解毒粗茶沙啞道：「下深井最怕的不是塌方，是地火突然竄出來的無色毒氣！看見礦燈火苗發藍發紫就得立刻閉氣往回爬，千萬別貪那兩塊紅銅原礦。」");
    add_response(({ "粗茶", "礦工", "生計" }),
        "羅七苦笑著拍拍膝蓋：「有錢的去客舍喝甘泉綠豆湯，我們這些苦力只能蹲在棚裡灌兩文一碗的明礬甘草茶，圖個潤喉壓咳嗽罷了。」");
}
