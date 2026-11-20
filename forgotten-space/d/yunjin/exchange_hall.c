// /d/yunjin/exchange_hall.c
// 雲津仙集・三宗交割廳暨雲海票號 (Ch.84, Ch.90：顧蘭舟核驗實物倉單與準備金)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・三宗交割廳暨雲海票號");
    set_long("堂內不見浮誇的沉香氣，唯有一股淡淡的油墨與冷鐵味道。高大的紅木櫃檯上\n"
             "陳列著三宗物資交割回執木架與信用準備金核驗板，雲海票號女掌櫃顧蘭舟在此專司\n"
             "跨州匯兌、實物倉單抵押保書與延誤違約劃扣清算（十會會武核驗準備金暨擠兌稽核：audit wanbao）。\n"
             "向西退回【萬山商埠公所】。\n");

    set_exits(([
        "west": "/d/yunjin/public_office.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/gu_lanzhou.c");
}

void init() {
    ::init();
    add_action("do_audit", "audit");
}

int do_audit(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "wanbao" && arg != "reserves" && arg != "萬寶閣" && arg != "準備金") {
        notify_fail("你想稽核哪項帳冊？試試：audit wanbao\n");
        return 0;
    }
    message_vision("$N聯手羅九秤與顧蘭舟攤開近兩月異常匯兌總冊，揭破萬寶閣假造『越冬燃料預付款』\n"
                   "倉單私挪準備金一百八十萬靈石票炒作南境礦藥期貨，依法觸發《商埠危機處置律》\n"
                   "查封萬寶閣後庫七口「太清、丹鼎、天工」暗標黑鐵帳箱，並自賠退約保住泥途商棧！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "audit", "target": "wanbao" ]));
    }
    return 1;
}
