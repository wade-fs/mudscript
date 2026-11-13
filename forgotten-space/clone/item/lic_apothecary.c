// clone/item/lic_apothecary.c
// 杏林初階醫籍 - 金石府城杏林百草堂職業憑證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("杏林初階醫籍", ({ "apothecary license", "lic_apothecary", "yiji", "醫籍", "杏林醫籍" }));
    set_short(HIG "【杏林初階醫籍】" NOR);
    set_long("由杏林醫館白先生與宣道司百藥門孫先生聯署簽發的初階丹醫執照。\n"
             "青色竹簡以絲線編綴，標註了認證醫師姓名與本草針灸造詣。持牌者享有府城永久行醫資格，\n"
             "自由出入藥市、採買列管丹毒藥材，並不受府衙巡丁盤查。\n");
    set_weight(150);
    set_value(300);
    set("is_legal_buffer", 1);
    set("license_career", "apothecary");
}
