// /d/counties/qinghe/ferry_dock.c
// 青河縣 (Qinghe County) 房間 2/14：漕運平底駁船碼頭 (對應卷二 Ch.58-59)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_short("青河縣・漕運駁船碼頭");
    set_long("寬闊的青石碼頭階梯一直延伸入碧綠的青河水中，數十艘特製的寬體平底\n"
             "漕船正排隊裝載烘乾裝箱的洗靈草、苦參與今年新收的秋稻。碼頭立著一根刻有紅白\n"
             "水尺的量水石柱，水行船夫們正焦急地盯著水尺刻度議論上游水勢。往北登岸回\n"
             "【東迎水陸關門】，向東順流駛入【九曲淺灘】（300 里水路），往西南沿河岸可抵【蘆花渡】。\n");

    set_stage_desc(1, "上游定神道觀私自下放攔水石閘兩尺，碼頭水位明顯下降，重載糧船吃水吃緊。");
    set_stage_desc(2, "碼頭水行船夫與道觀護院發生爭執，平底漕船因淺灘擱淺被迫延誤船期！");
    set_stage_desc(3, "上游攔水壩淤沙潰漫，渾濁泥水湧入碼頭，靈草外銷全面封鎖，藥價飆漲！");
    set_stage_desc(4, "商會青河分號出資炸開副渠洩水，水位雖已恢復，但四成靈草已被商會預先壟斷。");

    set_exits(([
        "north":     "/d/counties/qinghe/east_gate.c",
        "east":      "/d/routes/qinghe_shallow_bend.c",
        "southwest": "/d/counties/qinghe/luhuadu_dock.c",
    ]));

    set_coordinate(-7, 9, 0);
}
