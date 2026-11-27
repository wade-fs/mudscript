// /clone/npc/zhang_bailian.c
// 章百鍊・天工閣地火鍛兵台總匠 (zhang_bailian) - 千鍛地火廊暨千機院 (Ch.88)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("章百鍊");
    set_short(RED "地火鍛兵台總匠" NOR " 章百鍊");
    set_long("四十六歲的精壯匠師，左臉頰留有一道醒目的舊火灼疤，腰間掛滿擦拭鋥亮的測溫銅棒與卡尺。\n"
             "他痛恨世家匠徒只顧往外觀糊貴重秘銀與符文卻忽視結構應力，最看重標準化與工匠安全。\n");
    set_id(({ "zhang_bailian", "zhang bailian", "bailian", "章百鍊", "總匠" }));

    setup_archetype("E", 76);
    set("class", "gong");
    set("faction", "tiangong");
    set("roles", ({ "examiner", "smith", "quest" }));
    set("home_room", "/d/sects/tiangong/thousand_mechanisms_hall.c");

    add_response(({ "搬山傀儡", "考核", "修復", "熟鐵" }),
        "章百鍊冷眼看著一旁炸膛的世家爐台，哼聲道：「連內腔受力方向和半厘偏角都沒量清楚，\n"
        "光往外殼糊流銀與貼鎮壓符紙，負重起落三十次必炸！先拿卡尺測清右肘軸套公差，再以雙契榫楔重鍛（指令：repair puppet）。」");

    add_response(({ "卡尺", "熱處理", "淬火" }),
        "章百鍊點頭贊許：「退火去脆、溫油慢淬保留韌性，連兩塊十文錢的熟鐵都能咬出天工級公差。\n"
        "去把測量前後的應力紀錄工單交給魯長老驗收吧。」");
}
