// d/city/center/pawnshop.c
// 通寶當鋪總號 (賈半仙、模式 C 人脈情報樞紐)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石都城・通寶當鋪總號");
    set_long("高聳的黑漆典當櫃檯足有丈許高，將典當之人壓得微弱低頭。\n"
             "櫃檯上方懸著「蟲吃鼠咬、光板沒毛」八個暗金大字。\n"
             "老掌櫃賈半仙手戴玉扳指，撥弄著紫檀算盤，一雙小眼睛審視著各路貨色。\n"
             "此處連鎖全府六縣當鋪，消息極其靈通，後堂更暗藏通往地下黑市之門徑。\n"
             "北面連通通寶錢莊，向東穿過遮蔽暗簾可抵達鬼市暗巷。\n");

    set_exits(([
        "north": "/d/city/center/bank.c",
        "east":  "/d/city/center/black_alley.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", WHT "丈許高的黑漆當鋪櫃檯壓迫感十足，櫃邊銅護角摩挲得泛冷光。" NOR);
    set_smell("default", YEL "陳舊當票紙墨氣、樟腦防蛀箱櫃與各類典當舊衣雜物的混雜味道。" NOR);
    set_listen("default", HIY "紫檀算盤清脆得近乎冷漠的撥珠聲，夾著後堂布簾深處隱隱透來的陰暗微風。" NOR);

    spawn_npc("/clone/npc/center_pawn_jia.c");
}
