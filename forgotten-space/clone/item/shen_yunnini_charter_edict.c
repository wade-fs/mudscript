// /clone/item/shen_yunnini_charter_edict.c
// 《九城跨界平權共治核銷書》 (Ch.163 沈泥第六階段身世終章)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("九城平權核銷書", ({ "shen_yunnini_charter_edict", "charter edict", "平權核銷書", "核銷書" }));
    set_short(HIY "九城仲裁印・跨界平權共治核銷書" NOR);
    set_long("沈泥於鋼鐵仲裁橋公開核實『沈雲妮』法理繼承名分後簽署之平權公契，\n"
             "永久廢除九城總約中的少數獨裁緊急調度條款，將資源與議事權均分予凡間總號與洞天自治議會。\n");
    set_weight(40);
    set_value(0);
    set("is_credential", 1);
}
