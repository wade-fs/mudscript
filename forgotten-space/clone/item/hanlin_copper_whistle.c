// /clone/item/hanlin_copper_whistle.c
// 「北線斥候・乙十七」接應銅哨（第三卷 Ch.104 黑冰斷谷，Ch.111 交還韓素）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("北線斥候乙十七銅哨", ({ "hanlin_copper_whistle", "copper_whistle", "whistle", "北線斥候乙十七銅哨", "銅哨" }));
    set_short(YEL "「北線斥候・乙十七」銅哨（遺物）" NOR);
    set_long("一枚掛在五年前八荒斥候遺骸頸間、已生出暗綠銅鏽的制式青銅哨。\n"
             "哨身側面深鑿著「北線斥候・乙十七」編號字樣，與失蹤者家屬互助會韓素\n"
             "手中所繪其兄韓林出關特徵圖分毫不差——遺骸胸口插著三支破甲鐵弩箭矢，\n"
             "足證韓林係奉命接應時遭軍弩伏殺殉職，絕非黑山檔案所稱「擅離職守」。\n");
    set_weight(80);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
