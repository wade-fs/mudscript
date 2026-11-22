// d/city/east/wu_arena.c
// 斷魂生死擂台 (鐵臂趙猛、斷魂刀裁判)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("軍鎮・斷魂生死擂台");
    set_long("這座高出地面半丈的四方巨石擂台通體由厚重的重玄石條砌就，四角立著粗麻擂繩。\n"
             "台面泛著洗刷不掉的斑駁暗黑血漬，空氣中瀰漫著濃烈的雄渾氣血與鐵砂氣息。\n"
             "裁判斷魂刀抱刀立於台角，冷眼注視著挑戰者。\n"
             "教頭鐵臂趙猛雙臂交叉站在中央，專試天下好漢氣血筋骨 (ask zhaomeng about 比試)。\n"
             "西面跳下擂台可回到軍鎮大校場。\n");

    set_exits(([
        "west": "/d/city/east/wu_plaza.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", WHT "重玄巨石擂台磨得粗糙防滑，粗麻擂繩沾著乾涸血漬與掌心老繭汗鹽。" NOR);
    set_smell("default", HIR "濃烈陽剛的血汗味、抹手滑石粉與熱血激盪後的鐵砂腥氣。" NOR);
    set_listen("default", HIY "拳肉相搏的沉悶「嘭嘭」聲、擂台外圍武卒齊聲助威的喝采震天。" NOR);

    spawn_npc("/clone/npc/wu_zhaomeng.c");
    spawn_npc("/clone/npc/wu_referee.c");
}
