// clone/npc/center_pawn_jia.c
// 通寶當鋪總號掌櫃 賈朝奉 (pawnshop_jiachaofeng) - 模式 C 跨縣人脈與地下情報樞紐

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("賈朝奉");
    set_short(HIY "通寶當鋪大朝奉" NOR " 賈朝奉 (賈富春)");
    set_long("一位頭戴瓜皮小帽、手戴碧玉扳指的老掌櫃，瞇縫著一雙精明老辣的小眼睛，人稱賈朝奉，行內送諢號「賽半仙」。\n"
             "他身後是高逾數丈的黑漆典當櫃檯。通寶當鋪在全府六縣皆有分號，\n"
             "重石採石場工頭是他子侄，宣道司外圍經生是他舊友，各路暗貨黑金無不知曉。\n");
    set_id(({ "pawnshop_jiachaofeng", "jia chaofeng", "jiachaofeng", "pawn_jia", "pawnbroker", "jia fuchun", "pawn chaofeng", "賈朝奉", "賈掌櫃", "賈富春", "當鋪朝奉", "賽半仙", "賈半仙" }));

    setup_archetype("H", 30);
    set("class", "mortal");
    set("faction", "shanghui");
    set("roles", ({ "shop", "broker", "info" }));
    set("schedule", "24h");

    add_response(({ "當鋪", "典當", "分號", "人脈", "牙印" }),
        "賈朝奉撥弄著算盤：「通寶當鋪七百年老字號，六縣分號聲息相通。客官若持有莫三老兄或蘇姑娘的信印，老朽自會以特等待之。」");

    add_response(({ "黑市", "鬼市", "暗線" }),
        "賈朝奉壓低聲音：「當鋪後巷那道暗門，需得特定腰牌方能叩開……城下那些暗渠溶洞，多的是淘金客與亡命徒銷贓的好去處。」");
}
