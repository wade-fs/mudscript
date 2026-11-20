// /d/sects/danding/medical_archive.c
// 丹鼎宗・醫理院暨病案封存室 (Ch.96-97：白鶴年贈《地火中毒救護手記》與孫聞露匿名病案對照)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("丹鼎宗・醫理院暨病案封存室");
    set_long("整齊靜謐的石築藥房與病案長廊，門廊長案疊放著浸過甘草冷水的厚棉口罩與\n"
             "《地火中毒救護手記》。靠牆一排上鎖的檀木病案櫃背後格外幽靜，年輕女掌記孫聞露\n"
             "在最底層保管著「甲一、乙三」等十七份去名化加密病案統計（指令：crosscheck cases）。\n"
             "向南走出醫理院回返【百毒試藥谷暨百草谷】，往西沿後山雪道通往【廢丹崖】。\n");

    set_exits(([
        "south": "/d/sects/danding/herb_garden.c",
        "west":  "/d/sects/danding/discarded_pill_cliff.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/sun_wenlu.c");
}

void init() {
    ::init();
    add_action("do_crosscheck", "crosscheck");
}

int do_crosscheck(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "cases" && arg != "records" && arg != "病案" && arg != "病例") {
        notify_fail("你想交叉核對什麼？試試：crosscheck cases\n");
        return 0;
    }
    message_vision("$N躲在無人病案櫃後，按「甲一、乙三」匿名編碼逐一比對白猿解剖圖與十七份病案：\n"
                   "服用「逆道延命血丹」前三月確實壓低道化指標，第四月卻轉為不可逆「血煞癌變」，\n"
                   "且停藥逾七日後雙股力量互搏反撲，病患將在三日內劇烈晶化破裂暴斃！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "crosscheck", "target": "cases" ]));
    }
    return 1;
}
