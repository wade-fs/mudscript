// /d/counties/zhenfeng/yamen.c
// 鎮風縣 (Zhenfeng County) 房間 3/14：鎮風縣衛所・邊防軍政廳 (對應卷二 Ch.61-62 & 30天時間線核心現場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_short("鎮風縣衛所・邊防軍政廳");
    set_long("鎮風縣實行軍民合治，縣衙即為邊防衛所正堂。堂內火盆炭火熊熊，正面\n"
             "牆上懸掛著巨幅《極北雪原與天風谷防禦圖》。衛所守將近日以北荒煞潮將至為由，\n"
             "強徵散人採獲的八成風蝕石英充作軍備，引得民間與武館分舵怨聲載道。向東出廳回\n"
             "【皮甲硬弓邊集】，往北登階通往【鎮風測風祭壇】，順西側石階向下 (down) 可入【衛所地下案卷室】。\n");

    set_stage_desc(1, "衛所剛頒布入谷管制令，強徵散人八成風蝕石英充作軍資，僅給微薄粟米補償。");
    set_stage_desc(2, "衛所巡邏隊抓捕私售石英散人，八方武館分舵教頭率眾在衛所營門外對峙抗議！");
    set_stage_desc(3, "外圍烽燧遭雪狼夜襲受損，衛所宣布北塞馳道實施半月全面軍管，石英與皮甲暴漲！");
    set_stage_desc(4, "都城軍鎮副將雷震派快馬送達調停令，改為五五官買並由商會墊付欠餉，對峙暫歇。");

    set_exits(([
        "east":  "/d/counties/zhenfeng/market.c",
        "north": "/d/counties/zhenfeng/wind_altar.c",
        "down":  "/d/counties/zhenfeng/yamen_vault.c",
    ]));

    set_is_outdoor(0);
    set_coordinate(-1, 17, 0);
}
