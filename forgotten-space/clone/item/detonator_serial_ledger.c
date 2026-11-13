// clone/item/detonator_serial_ledger.c
// 軍需雷管雙聯火印存根 - 卷二第四幕核心定罪鐵證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("軍需雷管雙聯火印存根", ({ "detonator serial ledger", "detonator_serial_ledger", "cungen", "火印存根", "雷管存根" }));
    set_short(HIY "【軍需雷管雙聯火印存根】" NOR);
    set_long("自城防司披甲兵器庫與百工官禁硝火作當面對質起獲的特種軍需雙聯底冊存根。\n"
             "兩張厚羊皮紙邊緣由特殊鋼齒裁斷的鋸齒紋路物理咬合分毫不差，\n"
             "正中央烙印著百工總會特殊硃砂與城防司兵備道精鋼大印的「雙聯騎縫火印」。\n"
             "簽領人直指錢百川之妻弟錢百貴，調撥編號與黑石鋪北崖炸毀古礦之雷管完全連號，為關鍵定罪鐵證（conclusive）。\n");
    set_weight(50);
    set_value(1800);
    set("is_evidence", 1);
    set("evidence_type", "detonator_ledger");
    set("evidence_level", "conclusive");
}
