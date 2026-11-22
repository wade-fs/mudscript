// d/city/outer/farmland_w.c
// 金石府外・城西近郊青禾田

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城西近郊・青禾田");
    set_long("金石府城西郊外一片平曠肥沃的農耕田畝。\n"
             "引自青河上游的清冽活水順著條石水渠潺潺流經禾田，禾穗隨風翻起碧綠波浪。\n"
             "農民肩挑菜蔬正欲入城，不時有人駐足擦汗。\n"
             "東面通往西水門關口，向北沿渠堤可抵達青河水閘樞紐。\n");

    set_exits(([
        "east":      "/d/city/gate/gate_west.c",
        "north":     "/d/city/outer/irrigation.c",
        "west":      "/d/city/wall/moat.c",
        "southwest": "/d/routes/qinghe_willow_dike.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIG "田埂濕潤黑土鬆軟沾鞋，田間稻葉邊緣帶著割手的細微鋸齒與晨露。" NOR);
    set_smell("default", HIG "清新泥土芬芳、田間農家施肥氣味與青河灌渠飄來的濕潤草氣。" NOR);
    set_listen("default", CYN "蛙鳴蟲唧、水車吱呀轉動與農夫吆喝老牛耕作的純樸田園聲響。" NOR);

    spawn_npc("/clone/npc/outer_farmland_w_zhaodingtian.c");
}
