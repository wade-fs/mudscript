// /d/counties/panmu/fir_logging_line.c
// 盤木縣 (Panmu County) 房間 14/14：古冷杉伐木線・集材滑道 (30天時間線核心現場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_short("古冷杉伐木線・集材滑道");
    set_long("陡峭的山坡上開闢出一條長達數十丈的滾木集材滑道，空氣中充滿了新鮮\n"
             "鋸末與刺鼻的冷杉松脂味。數十名赤膊伐木夫正喊著號子拉動粗麻絞索，將合抱粗\n"
             "的鐵木與冷杉原木順著滑道放往山下。山坡土層因過度砍伐而顯得鬆動裸露。\n"
             "向南下坡可退回【倒影澗・古林界碑】。\n");

    set_stage_desc(1, "商會大木林班正越過倒影澗界碑日夜搶伐百年冷杉，滑道木屑紛飛。");
    set_stage_desc(2, "青松塢獵戶封鎖了下山滑道，集材絞盤被迫停擺，木料堆積如山。");
    set_stage_desc(3, "秋雨引發山坡土石崩塌，數十根巨木連同泥漿衝毀滑道，原木行情暴漲！");
    set_stage_desc(4, "林班退回南坡合法林區，並按三七分帳補種樹苗、加固護坡木樁。");

    set_exits(([
        "south": "/d/counties/panmu/daoying_stream.c",
    ]));

    set_coordinate(5, 8, 0);
}
