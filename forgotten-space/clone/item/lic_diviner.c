// clone/item/lic_diviner.c
// 宣道司觀象牒 - 金石宣道司觀象生法定資質憑證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("宣道司觀象牒", ({ "diviner license", "lic_diviner", "guanxiangdie", "觀象牒", "宣道司觀象牒" }));
    set_short(HIC "【宣道司觀象牒】" NOR);
    set_long("由金石宣道司玄機真人與觀星師星淵共同頒發的觀象生職牒。\n"
             "赤銅雲紋外框包裹著一面微型水銀羅盤，持牒者享有登臨摘星觀測台推演周天星宿、\n"
             "勘測府城地脈煞氣之法定資格，受宣道司直接庇護，享有官方最高等級文書借閱權限。\n");
    set_weight(150);
    set_value(300);
    set("is_legal_buffer", 1);
    set("license_career", "dao");
}
