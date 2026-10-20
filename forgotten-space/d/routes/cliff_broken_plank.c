// /d/routes/cliff_broken_plank.c
// 西線第一段 (seg_blackstone_zhongshi, 180里) 節點 2：落龍西谷・懸崖飛棧

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_blackstone_zhongshi");
    set_node_index(2);
    set_short("落龍西谷・懸崖飛棧");
    set_long("腳下是深不見底的落龍西谷暗澗，湍急水聲在狹窄岩縫間轟鳴回盪。整段飛棧\n"
             "全憑楔入青黑花崗岩壁的千斤鐵钎與厚木板凌空架設，陣陣山谷陰風吹過，木板發出\n"
             "令人牙酸的嘎吱聲響。岩壁裂隙中偶爾滲出淡淡的地煞硫氣，唯獨輕車快馬或身手矯健\n"
             "的行者方敢由此捷徑疾行。向南退回【西谷棧道口】，往北穿出崖口即抵【重石縣西南門】。\n");

    set_exits(([
        "south": "/d/routes/west_gorge_entry.c",
        "north": "/d/counties/zhongshi/southwest_gate.c",
    ]));

    set_coordinate(-3, 4, 0);
}
