// /clone/npc/ash_warden_qi.c
// 戚老頭（戚守灰・灰燼石堡守夜長老）(Ch.127-134)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("戚老頭");
    set_short(WHT "灰燼石堡守夜長老" NOR " 戚老頭");
    set_long("一位左袖空蕩別在腰帶上、臉上滿是窯灰與深皺紋的獨臂老人，右手總握著一柄烏黑短嘴鐵弩。\n"
             "他守著石堡五十餘口老弱的配給木牌，對任何招惹巡檢機隼的行為都抱持極度警惕。\n");
    set_id(({ "ash_warden_qi", "warden qi", "qi", "戚老頭", "戚守灰", "守夜長老" }));

    setup_archetype("E", 75);
    set("class", "mortal");
    set("faction", "edge_bastion");
    set("roles", ({ "warden", "quest", "info" }));
    set("no_combat", 1);
    set("home_room", "/d/realm/edge/ash_watch_post.c");

    add_response(({ "機隼", "熄燈", "巡檢" }),
        "戚老頭壓低嗓音：「別在牆外點亮火也別亂運靈氣！正東與正北那群巡檢機隼只要記上你們的帳，\n"
        "天亮前就把全堡連人帶鍋當無主料子拆走！快先將外牆油燈熄了（douse lamps）。」");

    add_response(({ "先輩", "十七批", "飛升", "祖師密錄" }),
        "戚老頭望著牆角幾截灰白廢柱冷笑：「十七批破境入界的前輩？頭三年耗死三成、騙上太虛玉化\n"
        "成晶核三成、押進戰祖獵營拼命，帶兵器的被萬物主機城拖去拆解——三百年來沒一個活著回去過！」");

    add_response(({ "配給", "木牌", "暖爐", "鹽道" }),
        "戚老頭拍了拍腰間焦黑木牌：「石堡認工不認銀兩。你們若真能拆開外環那套鎖死銅箍改出\n"
        "省料的換芯暖爐（forge stove），老朽就把這張避檢舊鹽道羊皮圖交給你們。」");
}
