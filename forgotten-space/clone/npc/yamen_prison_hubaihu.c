// clone/npc/yamen_prison_hubaihu.c
// 胡百戶・前黑石關百戶（階下囚，yamen_prison_hubaihu） - 府衙死牢

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("胡百戶");
    set_short(RED "死牢階下囚" NOR " 胡百戶 (前黑石關守將)");
    set_long("一位被扒去號坎甲冑、全身烙著鞭痕的落魄軍官，被單獨鎖在死牢最深處的重鐵籠內。\n"
             "他曾任黑石關巡檢司百戶，因私自挪用軍器局制式開山雷管並誣指礦工暴亂，在關前勘驗時被隨軍監軍與主帥陳鎮山當場革職收押。\n");
    set_id(({ "yamen_prison_hubaihu", "hu baihu", "hubaihu", "baihu", "胡百戶" }));

    setup_archetype("C", 22);
    set("class", "wu_initiate");
    set("faction", "yamen");
    set("roles", ({ "quest_target", "info" }));
    set("schedule", "24h");

    add_response(({ "雷管", "軍火", "黑石關", "陳鎮山", "幕後" }),
        "胡百戶咬牙切齒地捶著鐵籠：「要不是你們這群黑石鋪的小崽子拿著雷管拓印找上隨軍監軍，老子怎會落到這步田地！那些軍火批文都是府城裡的大人物授意的，憑我一個小小百戶哪敢私調軍器局火藥！」");
}
