// /clone/item/wanbao_black_iron_box.c
// 萬寶閣後庫「三宗暗標」黑鐵帳箱暨異常匯兌總冊（第三卷 Ch.115-116）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("萬寶後庫三宗暗標帳箱", ({ "wanbao_black_iron_box", "black_iron_box", "三宗暗標帳箱", "異常匯兌冊" }));
    set_short(HIY "雲津公所火漆・萬寶閣暗標帳箱摘要" NOR);
    set_long("依《商埠危機處置律》查封萬寶閣西街後庫起獲之七口黑鐵帳箱摘要暨雲海票號近兩月異常匯兌總冊：\n"
             "明載萬寶閣偽造「越冬燃料預付款」倉單，私挪託管三宗外門五百萬靈石準備金套走\n"
             "一百八十萬靈石票炒作「無標記南境特殊礦藥期貨」，暗標直指「太清雷律／丹鼎丙柒／天工赤火」。\n");
    set_weight(800);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "conclusive");
}
