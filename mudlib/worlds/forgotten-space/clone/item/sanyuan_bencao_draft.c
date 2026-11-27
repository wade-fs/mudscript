// /clone/item/sanyuan_bencao_draft.c
// 《三元本草祛道錄》初稿（第三卷 Ch.121：禁忌、療效範圍與可重複溫度時間曲線）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("三元本草祛道錄", ({ "sanyuan_bencao_draft", "bencao_draft", "三元本草祛道錄", "祛道錄" }));
    set_short(HIG "顧玄手抄・《三元本草祛道錄》初稿" NOR);
    set_long("顧玄於百草谷醫療隔離區統合三十多名毒域暨低配血丹傷患脈象、廢丹崖樣本與\n"
             "白岩醫師北荒前哨寒症病例編纂而成之實證藥典初稿。明列雪線苔配伍苦參冷萃湯\n"
             "僅對皮下三寸未侵心肺之早期晶絲減緩惡化三至五成、伴手腳發涼與食慾減退副作用，\n"
             "並誠實標註逾五年老病灶無能為力，附有雜役可重複驗證之「三元互濟」溫度時間曲線。\n");
    set_weight(180);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
