// d/city/center/bank.c
// 通寶錢莊總號

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石都城・通寶錢莊總號");
    set_long("這座高大氣派的石砌錢莊總號門檻極高，兩尊鎮煞石獅威風凜凜。\n"
             "青銅櫃檯後大朝奉正熟練撥動算盤，身後陳列著全府六縣通兌的銀票存根與高聳銀冬瓜。\n"
             "需持有一階合法度牒或商會腰牌方能在總號開立戶頭。\n"
             "西北出門回到中央青石廣場，向南可進入通寶當鋪總號。\n");

    set_exits(([
        "northwest": "/d/city/center/square.c",
        "south":     "/d/city/center/pawnshop.c",
    ]));

    set("is_outdoor", 0);
    set("has_bank", 1);

    set_touch("default", HIY "青銅櫃檯擦拭得冰涼鋥亮，櫃邊壓單的黃銅鎮紙沉甸甸得令人心生敬畏。" NOR);
    set_smell("default", YEL "乾燥防潮庫房飄來的松木箱香、新銀錠淡淡金屬味與官印朱砂印泥氣息。" NOR);
    set_listen("default", HIY "高大廳堂裡只有大朝奉珠算如飛的清脆啪嗒聲，連呼吸都不自覺放輕了幾分。" NOR);

    spawn_npc("/clone/npc/bank_chief.c");
}
