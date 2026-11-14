// /d/counties/liefan/hongsha_slag.c
// 烈礬縣 (Liefan County) 房間 10/14：紅砂坳・廢礬渣堆與私銅暗窖 (30天時間線 Stage 1 & 4 現場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_short("紅砂坳・廢礬渣堆與私銅暗窖");
    set_long("紅砂坳東側山谷堆滿了小山般的灰紅廢礬渣與爐渣。自從黑石鋪血精停產、\n"
             "百工分舵又強壓官定銅價後，本地小礦主便在渣堆深處挖設暗窖，將優質無印赤銅\n"
             "與私硝藏匿於此，伺機經東麓私梟道偷運出境。向西可退回【紅砂坳・洗礬篩砂聚落】。\n");

    set_stage_desc(1, "因黑石鋪血精停產導致熔煉助劑滯銷，礦主正暗中在官交赤銅裡摻入三成廢礬渣。");
    set_stage_desc(4, "百工分舵管事與礦主達成『明罰暗補』默契，每十車官銅默許夾帶兩車無印私銅由此出境！");

    set_exits(([
        "west": "/d/counties/liefan/hongsha_hollow.c",
    ]));

    set_coordinate(7, 12, 0);
}
