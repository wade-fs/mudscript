// /clone/npc/zhou_shishu.c
// 周師叔・太清外門中年執事 (zhou_shishu) - 丹鼎宗醫療隔離區暨醫理院 (Ch.121)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("周師叔");
    set_short(CYN "太清外門中年執事" NOR " 周師叔");
    set_long("三十多歲的太清外門執事，左腕關節已微結一層淡青硬殼，當年因長期服用執法堂所發\n"
             "『九轉延命散』落得一身爛肺暗傷。初時在醫療隔離區憤怒打翻孫聞露藥碗拒當試藥白老鼠，\n"
             "直至讀完顧玄交來不隱瞞半句禁忌與副作用之《三元本草祛道錄》初稿方主動前來領藥。\n");
    set_id(({ "zhou_shishu", "zhou shishu", "zhou", "周師叔", "周執事" }));

    setup_archetype("G", 58);
    set("class", "dao");
    set("faction", "taiqing");
    set("roles", ({ "patient", "survivor" }));
    set("home_room", "/d/sects/danding/medical_archive.c");

    add_response(({ "三元本草", "禁忌", "九轉延命散", "試藥" }),
        "周師叔沙啞地咳了兩聲，低頭看了一眼那紙把毒性下限、療效範圍與副作用寫得清清楚楚的《三元本草祛道錄》：\n"
        "「以前執法堂老爺給『九轉延命散』只吹仙家靈丹，吃出爛肺卻沒人敢寫進單子。\n"
        "你們連停藥半年可能復發、手腳發涼、逾五年老病灶救不了都敢寫上去，還明言我拒喝亦照供熱粥熱敷——\n"
        "這回算我周某信你們一回，把那碗冷萃苦參湯拿來吧！」");

    add_response(({ "拒絕權", "隔離區", "熱粥" }),
        "周師叔望著手腕淡青硬殼輕嘆：「人怕的不是藥苦，是連怎麼死的都被瞞在黑箱裡。\n"
        "只要醫者不拿病人當白老鼠、實話實說能治幾成，我們這些廢人自會替這條生路守規矩。」");
}
