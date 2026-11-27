// clone/item/lic_broker.c
// 金石商行牙帖 - 金石府城官商聯署牙人執照

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("金石商行牙帖", ({ "broker license", "lic_broker", "yatie", "牙帖", "商行牙帖" }));
    set_short(HIY "【金石商行牙帖】" NOR);
    set_long("由金石商會牙行與府衙戶房聯名用印的行商牙人執照。\n"
             "牌面由紫竹薄片製成，詳細登載了持有人在當鋪質押、六縣物產收購與大宗合約公證的\n"
             "合法中介資格。持帖人享有全府各大商行貨棧免檢通行權，並可合法查閱三十年陳年死帳。\n");
    set_weight(150);
    set_value(300);
    set("is_legal_buffer", 1);
    set("license_career", "broker");
}
