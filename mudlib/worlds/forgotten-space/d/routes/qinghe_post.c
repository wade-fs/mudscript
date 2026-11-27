// /d/routes/qinghe_post.c
// 青河沿河官道 (seg_city_qinghe_land, 280里) 節點 2：青河半途水驛 (對應卷二 Ch.58)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_qinghe_land");
    set_node_index(2);
    set_short("青河沿河官道・半途水驛");
    set_long("這座水陸並用的半途官驛建在青河中游的高阜上，驛站前立著刻有「西距\n"
             "青河縣百四十里、東距金石西關百四十里」的青石里程碑。空氣中已能聞到自上游\n"
             "百草坪飄來的淡淡藥草清香。向東沿柳堤回【青河柳堤官道】，往西即可踏入【青河縣・東迎水陸關門】。\n");

    set_exits(([
        "east": "/d/routes/qinghe_willow_dike.c",
        "west": "/d/counties/qinghe/east_gate.c",
    ]));

    set_coordinate(-6, 10, 0);

    mapping wheel_rule = ([
        "targets": ({ "wheel", "axle", "車輪", "修輪", "" }),
        "sp_cost": 10,
        "sensory_msg": YEL "你扛石墊穩車軸，揮錘將兩根棗木備用輻條敲進生鐵輪轂再別牢插銷，陷在水驛泥轍裡的貨車總算恢復轉動。" NOR,
        "train_stat": ([ "str": 8, "dex": 8 ]),
        "exp_gain": 12,
        "quest_verb": "mend",
        "quest_target": "wheel"
    ]);
    add_action_rule("mend", wheel_rule);
    add_action_rule("修輪", wheel_rule);
}
