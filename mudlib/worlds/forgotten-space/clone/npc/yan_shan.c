// /clone/npc/yan_shan.c
// 燕山（燕隼失聯五年之大伯・戰祖外營獨眼老獵頭）(Ch.139-140, 150-151, 159-160, 168)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("燕山");
    set_short(HIY "獨眼老獵頭" NOR " 燕山");
    set_long("一位左眼罩著焦黑硬皮、右眉梢帶著深長舊箭疤的沉穩老獵手，指節粗大且滿是凍瘡與獸爪痕。\n"
             "五年前黑冰斷谷墜入裂隙後，他為保同批被擄獵人喘息之機，忍辱替魔殿守獵換取生存配額。\n");
    set_id(({ "yan_shan", "yanshan", "uncle yan", "燕山", "老獵頭" }));

    setup_archetype("C", 90);
    set("class", "wu");
    set("path", "li");
    set("faction", "edge_bastion");
    set("roles", ({ "ally", "quest", "lore" }));
    set("no_combat", 1);
    set("home_room", "/d/realm/zhanzu/hunting_camp.c");

    add_response(({ "暗倉", "鹽晶", "冒領", "黑冰斷谷" }),
        "燕山冷著臉壓低嗓音：「這鬼地方救不了誰的菩薩心腸！韓石與太虛管事把冒領的高純鹽晶粉\n"
        "都暗存在萬物城外三號廢鹽倉裡；這份換防血樣名錄你拿回石堡給顧大夫核對，別衝動帶我一個人逃。」");

    add_response(({ "密牌", "赤煉", "簽字" }),
        "燕山從貼身皮袋裡摸出一枚焦黑加密殘牌：「五年前送我們進來的凡間軍需轉運線，\n"
        "這塊殘牌上的古篆暗記能和雷烈那頭交叉對上——回雲津後這筆血債得當面清算。」");
}
