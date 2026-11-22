// d/city/gate/gate_west.c
// 金石府城・西水門與西關 (青河漕運終點、駁船水閘)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石府城・西水門");
    set_long("此處是全府最重要的水陸雙關。巨大的鑄鐵千斤閘橫懸於青河入口之上，\n"
             "河面上泊滿了來自青河縣的平底駁船，滿載著洗靈草與桑竹糧油。\n"
             "西水門守舵官指揮著水關緝私吏，乘著小艇在舟楫間穿梭驗貨。\n"
             "向西出關可達城西近郊青禾田與渠首水閘，往東入關通往城內漕運碼頭，\n"
             "順生鐵懸梯向上 (up) 可登臨西城望江水樓。\n");

    set_exits(([
        "west":      "/d/city/outer/farmland_w.c",
        "northwest": "/d/city/outer/irrigation.c",
        "southwest": "/d/routes/qinghe_barge_channel.c",
        "east":      "/d/city/south/canal.c",
        "up":        "/d/city/wall/wall_path_w.c",
    ]));

    set("is_outdoor", 1);
    set("gate_id", "west");

    set_touch("default", CYN "西水門石階長期受河霧浸潤而微滑冰涼，水閘鐵鏈手搖輪上覆著一層潮鏽。" NOR);
    set_smell("default", HIG "青河濕潤水草清氣、駁船桐油味與隱約飄自暗渠閘口的微腥淤泥氣。" NOR);
    set_listen("default", CYN "活水湧過水門石拱的嘩啦浪聲與船老大喊著落帆靠岸的響亮號子。" NOR);

    spawn_npc("/clone/npc/city_gate_guard.c");
    spawn_npc("/clone/npc/gate_west_helmsman.c");
    spawn_npc("/clone/npc/gate_west_inspector.c");
}
