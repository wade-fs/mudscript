// d/city/west/dao_gate.c
// 宣道司外門牌樓 (法道世俗門戶)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石宣道司・外門牌樓");
    set_long("此處高聳著一座以漢白玉巨石雕琢的三間四柱沖天牌樓。\n"
             "牌樓橫額鐫刻「周虛微茫」四個古篆金字，散發著淡淡清冷道意。\n"
             "空氣中的紅塵喧囂濁氣在此驟減，隱約有玄鶴清唳與鐘磬長鳴之音相聞。\n"
             "向東走出牌樓直通中央青石廣場，往西穿過雲階大道進入宣道司正堂。\n");

    set_exits(([
        "east": "/d/city/center/square.c",
        "west": "/d/city/west/dao_hall.c",
    ]));

    set("is_outdoor", 1);
}
