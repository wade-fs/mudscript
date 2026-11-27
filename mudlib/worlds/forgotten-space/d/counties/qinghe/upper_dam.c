// /d/counties/qinghe/upper_dam.c
// 青河縣 (Qinghe County) 房間 10/14：青河上游・攔水濾沙石閘 (對應卷二 Ch.58-59 & 30天時間線核心現場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_short("青河上游・攔水濾沙石閘");
    set_long("青河出西嶺山口的第一道咽喉要衝，橫亙著一座以巨型條石砌築的分水攔沙\n"
             "大壩。壩頂設有絞盤控制的銅包木水閘，北側清渠專供山上【定神靈植道觀】引水\n"
             "育靈，南側主槽則向下游萬畝稻田與蘆花渡漕運放水。上游截水與下游爭水的結構性\n"
             "矛盾全繫於此閘高低。往北拾級而上可登【定神靈植道觀】，向東南沿堤回【青河縣衙】。\n");

    set_stage_desc(1, "道觀為保靈圃水質私自下放攔水石閘兩尺，主槽下洩水量銳減。");
    set_stage_desc(2, "壩前聚集了大批抗議截水的百草坪藥農與蘆花渡船工，與道觀護院劍拔弩張！");
    set_stage_desc(3, "連陰雨導致攔水壩上游淤沙積聚潰漫，定神道觀三畝外圃被濁水倒灌淹沒！");
    set_stage_desc(4, "商會雇工炸開南側副渠洩洪，壩體雖穩，但洶湧急流將下游古河床沖刷得溝壑縱橫。");

    set_exits(([
        "north":     "/d/counties/qinghe/herb_shrine.c",
        "southeast": "/d/counties/qinghe/yamen.c",
    ]));

    set_coordinate(-10, 11, 0);
}
