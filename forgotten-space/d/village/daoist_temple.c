// d/village/daoist_temple.c
// 黑石鋪・破落道觀・三清偏殿 (破落道童出生地)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("破落道觀・三清偏殿");
    set_long("這座高踞於西面孤岩山腰的古老道觀早已破落不堪。殿頂青瓦大半剝落，\n"
             "光線透過孔隙灑在泥塑的三清尊像上，神像肩背早已斑駁殘缺，覆著一層青苔。\n"
             "案几上積著厚厚冷灰，散落著幾張抄錄著殘缺符篆的泛黃紙頁與乾裂硯台。\n"
             "你自幼在此枯坐抄經，懷中那卷邊角被鼠齧殘缺的《引氣訣》已泛黃受潮。\n"
             "穿過偏殿後方的狹窄石階向上，便能登上直面萬丈罡風的迎風殘壇。\n");

    set_exits(([
        "east": "/d/village/square.c",
        "up":   "/d/village/altar.c",
    ]));

    set("is_outdoor", 0);

    spawn_npc("/clone/npc/kumu_daoist.c");
    spawn_item("/clone/item/rubbing_kit.c");
}

void init() {
    ::init();
    add_action("do_temple_meditate", "meditate");
    add_action("do_temple_meditate", "打坐");
    add_action("do_temple_meditate", "靜坐");
}

int do_temple_meditate(string arg) {
    object me = this_player();
    write("你在三清尊像前的破舊蒲團上盤膝靜坐，伴隨著殘存的檀香餘韻，眼觀鼻、鼻觀心，徐徐調息...\n");
    write(HIC "偏殿內古井無波，你的神識在寧靜中迅速凝聚，周身氣機流轉圓融。\n" NOR);
    me->add(VITAL_KEE, 15);
    me->add(VITAL_SEN, 30);
    me->add(VITAL_SP, 20);
    write(HIG "【蒲團靜坐，你的氣血 +15、神識 +30、精力 +20！】\n" NOR);
    return 1;
}

