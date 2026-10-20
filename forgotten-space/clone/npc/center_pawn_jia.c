// clone/npc/center_pawn_jia.c
// 通寶當鋪總號掌櫃 賈半仙 - 模式 C 跨縣人脈與地下情報樞紐

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("賈半仙");
    set_short(HIY "通寶當鋪大朝奉" NOR " 賈半仙");
    set_long("一位頭戴瓜皮小帽、手戴碧玉扳指的老掌櫃，瞇縫著一雙精明老辣的小眼睛。\n"
             "他身後是高逾數丈的黑漆典當櫃檯。通寶當鋪在全府六縣皆有分號，\n"
             "重石採石場工頭是他子侄，宣道司外圍經生是他舊友，各路暗貨黑金無不知曉。\n");
    set_id(({ "pawn_jia", "jia", "pawnbroker", "賈半仙", "掌櫃", "朝奉" }));

    set_level(30);
    set_stat("int", 36);
    set_stat("per", 40);
    recalc_stats();

    add_response(({ "當鋪", "典當", "分號", "人脈" }),
        "賈半仙撥弄著算盤：「通寶當鋪七百年老字號，六縣分號聲息相通。客官若持有莫三老兄或蘇姑娘的信印，老朽自會以特等待之。」");

    add_response(({ "黑市", "鬼市", "暗線" }),
        "賈半仙壓低聲音：「當鋪後巷那道暗門，需得特定腰牌方能叩開……城下那些暗渠溶洞，多的是淘金客與亡命徒銷贓的好去處。」");
}
