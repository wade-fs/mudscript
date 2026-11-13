// clone/item/cross_state_trade_tally.c
// 金石商會與通寶跨州特等通行信印 - 沈泥專屬自由縱橫天下信印

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("跨州特等通行信印", ({ "cross state trade tally", "trade_tally", "cross_state_tally", "信印", "特等信印", "通行信印" }));
    set_short(HIW "【金石商會與通寶跨州特等通行信印】" NOR);
    set_long("由金石商會大掌櫃蘇凝霜與通寶當鋪總號賈朝奉聯署簽發的玄鐵金邊特等信印。\n"
             "牌面精雕金蓮環刀暗紋與通寶跨州飛錢金印，在全天下七十二州各府各縣商路暢通無阻。\n"
             "凡金石商會分舵與通寶錢莊字號，見印如見大掌櫃親臨，享有最高等級帳目調閱與資源借調特權，\n"
             "象徵沈泥不入封閉宗門、以自由身行走人間查訪太古舊約之崇高信用身份。\n");
    set_weight(120);
    set_value(8000);
    set("is_legal_tally", 1);
    set("tally_type", "cross_state_special");
}
