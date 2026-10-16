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
    if (me->query("background") == "daoist" && me->query_skill("still_heart") <= 0) {
        write(HIC "盲眼老道枯木輕叩木魚，淡淡道：「凡心不止，外邪自生。且依老道所授之法，止念存神、不引外氣。」\n" NOR);
        load_object("/secure/skill_d.c")->grant_starter_force(me, "still_heart");
    }
    write("你在三清尊像前的破舊蒲團上盤膝靜坐，伴隨著殘存的檀香餘韻，眼觀鼻、鼻觀心...\n");
    object rec_cmd = load_object("/cmds/cmd_recover.c");
    if (rec_cmd) {
        rec_cmd->main(me, "meditate", arg);
    }
    me->add(VITAL_SEN, 10);
    write(HIC "【三清偏殿檀香餘韻加持，神識額外 +10】\n" NOR);
    return 1;
}

