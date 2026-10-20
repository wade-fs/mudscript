// d/city/center/academy.c
// 金石學塾 (地方文教、三日通牒緩衝路徑 A)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石都城・學塾講堂");
    set_long("學塾講堂內窗明几淨，墨香繚繞。\n"
             "正中懸掛著至聖先師與前朝文治圖軸，兩排整齊的烏木書案前擺放著筆墨紙硯。\n"
             "陸夫子正襟危坐於講席之上，手持戒尺講述道藏政典。\n"
             "初入府城的無依流民可在陸夫子處簽訂謄抄契約 (ask lu about 抄書)，\n"
             "領取【學塾白鹿青衿】取得十四天合法居留資格。\n"
             "東北出門返回中央青石廣場，往西穿過小夾道直通杏林醫館。\n");

    set_exits(([
        "northeast": "/d/city/center/square.c",
        "west":      "/d/city/center/clinic.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/center_teacher_lu.c");
}
