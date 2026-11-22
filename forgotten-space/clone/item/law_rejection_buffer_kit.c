// /clone/item/law_rejection_buffer_kit.c
// 【律令排異症】三元緩衝針藥組 (Ch.141 顧玄配合三極樣本所製)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("三元緩衝針藥組", ({ "law_rejection_buffer_kit", "buffer kit", "緩衝針藥", "針藥組" }));
    set_short(HIG "顧玄親配・律令排異緩衝針藥組" NOR);
    set_long("一隻雙層木匣，內盛以苦苔冷萃汁、礦灰糊劑與數枚隔絕晶塵用的導流溫氣骨針；\n"
             "能替早期律令排異症患者護住臟腑與四肢觸覺，但對徹底石化骨骼無力回天。\n");
    set_weight(220);
    set_value(40);
    set("is_medical_kit", 1);
}
