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

    set_touch("default", WHT "病案封存櫃冰涼乾爽，舊藥單紙頁邊緣脆黃，案上純銀試毒針擦得纖塵不染。" NOR);
    set_smell("default", HIG "乾燥藏書竹紙味、甘草艾葉幽香與淡淡的陳舊醋洗藥水味。" NOR);
    set_listen("default", WHT "室極靜，唯聽見孫聞露輕手翻動病案的紙頁聲與屋外藥谷偶爾傳來的風聲。" NOR);

    spawn_npc("/clone/npc/sun_wenlu.c");
    spawn_npc("/clone/npc/zhou_shishu.c");
}

void init() {
    ::init();
    add_action("do_crosscheck", "crosscheck");
    add_action("do_publish", "publish");
}

int do_publish(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "bencao" && arg != "draft" && arg != "三元本草" && arg != "祛道錄") {
        notify_fail("你想公開整理什麼醫典？試試：publish bencao\n");
        return 0;
    }
    message_vision(HIG "$N將百草谷醫療隔離區三十餘傷患脈象、廢丹崖樣本與白岩北荒寒症病例逐條寫清：\n"
                       "公開《三元本草祛道錄》禁忌單與『三元互濟』可重複溫度曲線，嚴守病人拒絕權與醫理邊界！\n"
                       "太清周執事讀罷默默赴醫理院領藥，上游藥渠湧出清冽無酸泉水，醫道實證歸返本心。\n" NOR, me);
    if (!present("sanyuan_bencao_draft", me)) {
        object ob = clone_object("/clone/item/sanyuan_bencao_draft.c");
        if (ob) {
            ob->move(me);
            tell_object(me, HIG "你整理完畢並領存《三元本草祛道錄》初稿。\n" NOR);
        }
    }
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "publish", "target": "bencao" ]));
    }
    return 1;
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
