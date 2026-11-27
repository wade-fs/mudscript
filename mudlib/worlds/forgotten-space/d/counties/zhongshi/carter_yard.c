// /d/counties/zhongshi/carter_yard.c
// 重石縣 (Zhongshi County) 擴展生活翼：條石大車棚與修軸鐵攤

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_short("重石縣・條石大車棚");
    set_long("緊靠磐石騾馬店東側院牆的寬敞石柱木棚，停放著十幾架專載萬斤城防條石的\n"
             "八輪包鐵大車。棚角擺著一座小手風箱炭爐、一桶黑亮牛油膏與幾根備用硬棗木輻條，\n"
             "老車匠正蹲在車底仔細檢驗鐵軸插銷 (axle)。\n"
             "向西穿過石拱門即回【重石縣驛・磐石騾馬店】。\n");

    set_exits(([
        "west": "/d/counties/zhongshi/post_inn.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);
    set_touch("default", WHT "生鐵車軸沾著厚滑油膩的黑牛油，棗木車輻堅硬沉實，地上積著灰白石粉。" NOR);
    set_smell("default", YEL "熱牛油膏、炭爐焦煤、牲口槽乾草與重玄條石斷口的乾冷石粉味。" NOR);
    set_listen("default", HIY "鐵錘敲進輪軸插銷的「當、當」清響，伴著棚外健騾打響鼻與鐵蹄刨地的聲音。" NOR);

    mapping grease_rule = ([
        "targets": ({ "axle", "cart", "車軸", "大車", "" }),
        "sp_cost": 10,
        "sensory_msg": YEL "你扛起千斤木槓頂起車架，把厚實牛油均勻塗滿八輪鐵軸承並敲緊插銷，車輪轉動頓時順滑無聲。" NOR,
        "train_stat": ([ "str": 8, "dex": 6 ]),
        "exp_gain": 12,
        "quest_verb": "grease",
        "quest_target": "axle"
    ]);
    add_action_rule("grease", grease_rule);
    add_action_rule("潤軸", grease_rule);

    spawn_npc("/clone/npc/folk/zhongshi_wheelwright.c");
}
