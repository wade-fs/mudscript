// clone/item/yunji_roster.c
// 舊商盟雲記名冊手抄底單 - 卷二第三幕核心物證與沈泥身世確證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("舊商盟雲記名冊手抄底單", ({ "yunji roster", "yunji_roster", "mingce", "雲記名冊", "名冊底單" }));
    set_short(HIY "【舊商盟雲記名冊手抄底單】" NOR);
    set_long("前朝舊商盟度支老帳房柯九算自貼身秘藏名冊中親筆抄錄並加蓋度支副印之關鍵底單。\n"
             "詳細載明天興十三年商盟分序第十一行金石府分號【雲記行】之少東沈懷安與長女「沈雲妮」之嫡脈傳承，\n"
             "並詳述天興十五年黑石嶺大火滅門除籍慘案。\n"
             "與第44章府衙案卷庫刑部舊卷、第51章通寶當鋪死當陳帳形成三方獨立互鎖，\n"
             "正式達成沈泥身世六階段之階段三「關係證實」（conclusive on identity），\n"
             "亦揭示前朝古暗渠密室子母玄鐵門之開合機括。\n");
    set_weight(40);
    set_value(1200);
    set("is_evidence", 1);
    set("evidence_type", "yunji_roster");
    set("evidence_level", "conclusive_identity");
}
