// /clone/npc/wenjiu.c
// 聞九・天工閣陣圖工房女陣匠 (wenjiu) - 陣圖工房 (Ch.95)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("聞九");
    set_short(CYN "陣圖工房女陣匠" NOR " 聞九");
    set_long("二十九歲的女陣匠，出身世守工藝的匠人之家，手腕束著方便作圖的藏青綁帶。\n"
             "她擅長將宏大的機括總圖拆解為分段施工圖紙，最痛恨世家弟子不看實物公差只顧搶署名。\n");
    set_id(({ "wenjiu", "wen jiu", "wen_jiu", "聞九", "女陣匠", "陣匠" }));

    setup_archetype("E", 68);
    set("class", "gong");
    set("faction", "tiangong");
    set("roles", ({ "engineer", "draftsperson", "quest" }));
    set("home_room", "/d/sects/tiangong/array_drafting_room.c");

    add_response(({ "脈衝", "圖紙", "推進錨機", "延長線" }),
        "聞九捏起細頭炭筆在羊皮紙上勾出斜樑延長線，瞳孔猛地一縮：「你竟真看出來了！\n"
        "那些世家圖紙寫作『護心甲肋』，實則所有受力角全往後下方大基座集中——這尊十丈巨靈神機根本\n"
        "不是什麼人形戰鬥傀儡，而是嵌在某座龐大船體或超巨型平台側面的『推進錨機或轉向關節』！\n"
        "（指令：trace blueprint 可複驗完整受力延長線）」");

    add_response(({ "署名", "世家", "卡尺" }),
        "聞九把算規收進木匣：「這張延長線結構草圖我們先私下留著，不入公開檔。誰出力測出來的公差，就歸誰署名！」");

    add_response(({ "盜掘", "傀儡批次", "鑽頭殘件", "千機堂" }),
        "聞九挑燈對照鑽山傀儡出廠批次冊頁與大執事密令底頁，咬牙道：「二十二至三十號高壓鑽頭正是近期經\n"
        "千機堂內庫批條撥出的！可惜那名私盟大執事伏誅前未留供狀，赤煉長老推脫『自然雪崩』，咱們必須把工坊領用簿原始副本翻出來！」");
}
