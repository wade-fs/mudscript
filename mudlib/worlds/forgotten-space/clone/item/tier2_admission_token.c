// clone/item/tier2_admission_token.c
// Tier 2 名山外門考核令 - 卷二第五幕四維分離名山資格憑證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("Tier 2 名山外門考核令", ({ "tier2 admission token", "admission_token", "token_tier2", "考核令", "名山考核令" }));
    set_short(HIY "【Tier 2 名山外門考核令】" NOR);
    set_long("由金石府宣道司、八方武館、百工總會與杏林醫館四大道統聯署簽發的古拙令牌。\n"
             "牌身非金非木，流轉著青紫雲霞雷紋與名山靈氣防偽印記。\n"
             "強調：拿到此令僅代表取得前往北方二階名山參試「登天梯」與「問心谷」大考的資格，\n"
             "絕非自動成為真傳弟子，為凡俗邁向仙山宗門的法定通行憑證（admission token）。\n");
    set_weight(80);
    set_value(5000);
    set("is_token", 1);
    set("token_tier", 2);
    set("token_type", "admission_token");
}
