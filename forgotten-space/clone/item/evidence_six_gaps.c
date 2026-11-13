// clone/item/evidence_six_gaps.c
// 六缺口物證案卷 - 金石府城底層黑幕調查核心卷宗

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("六缺口物證案卷", ({ "six evidence gaps", "evidence_six_gaps", "anjuan", "案卷", "物證案卷", "六缺口案卷" }));
    set_short(HIR "【六缺口物證案卷】" NOR);
    set_long("五子在南關老劉客棧連夜推演、閉環交叉比對所編纂的機密卷宗。\n"
             "嚴格依循五欄物證鐵律（編號、名稱、型態、來源鏈、證明力限制）記錄六大斷裂物證：\n"
             "1. 濁水毒源批單：鎖定死牢毒物來源\n"
             "2. 烈礬灰陶票根：關聯紫銅坩堝燒製底帳\n"
             "3. 鎮風關轉運通牒：揭發黑石關物資被扣真正路線\n"
             "4. 重石採石場底帳：對照地煞精錠失竊空帳\n"
             "5. 一號庫總勘提單：撕開商會地下走私大庫偽裝\n"
             "6. 趙德貴親供口供：直指錢百川與城防軍中飽私囊鐵證。\n");
    set_weight(300);
    set_value(1000);
    set("is_evidence_file", 1);
}
