// clone/npc/lao_miner.c
// 老礦工 魯大山 - 黑石斷崖古礦坑的守望者 (物修之鏈關鍵 NPC)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("魯大山");
    set_short(YEL "老礦工" NOR " 魯大山");
    set_long("一位皮膚曬得如黑鐵、滿臉皺紋沾滿石粉的老礦工。他雙手骨節粗大如生薑，\n"
             "握著一柄磨得發亮的短柄鋼鎬，目光堅毅地盯著幽深的黑石礦道。\n"
             "他長年在北崖峭壁與地下深處敲打黑石，對這片山體岩層的脈動瞭如指掌。\n");
    set_id(({ "lao miner", "miner", "lu", "魯大山", "老礦工", "礦工" }));

    set_level(15);
    set_stat("str", 26);
    set_stat("con", 25);
    set_stat("dex", 16);
    set_stat("per", 18);
    recalc_stats();

    add_response(({ "採礦", "鑿礦", "mine", "粗礦", "礦石" }), 
        "手握鐵鎬，看準石眼下鎬！別用死力氣硬砸頑石，順著地脈石理敲，才能撬出上好的北崖粗鐵礦核！");

    add_response(({ "地煞", "暗震", "黑石" }), 
        "北崖地底深處藏著太古地煞濁氣，開採過急便會引發岩層震動。若地質不穩，隨時可能大面積塌方！");

    add_response(({ "生計", "任務", "物道", "career", "job" }), 
        "咱們北崖採出來的上好粗礦，鐵匠鋪阿鐵最是稀罕！你可以拿礦去找阿鐵定胚打鐵，鍛打成柴刀再賣給商隊換粗鹽銀子，這便是咱們黑石鋪的百工之鏈！");
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    object engine = load_object(QUEST_ENGINE_D);
    if (engine && engine->check_and_handle_lost_item(me, "lu", topic)) {
        return 1;
    }
    object ws = load_object(WORLD_STATE_D);

    if (topic == "塌方" || topic == "落石" || topic == "危險" || topic == "安全") {
        if (ws && ws->is_mine_collapsed()) {
            tell_object(me, query_name() + " 焦急萬分地抹了把臉上的石粉，大聲喊道：「萬斤巨石崩落把洞口死死堵住了！快用 clear 指令幫忙搬開巨石搶修通道！」\n");
        } else if (ws) {
            tell_object(me, query_name() + sprintf(" 抬頭看了看洞頂石壁，沉聲道：「昨夜北崖暗震，目前礦道穩定度只有 %d%%（儲量 %d/30）。下坑開採千萬要留神落石！」\n",
                ws->query_mine_stability(), ws->query_mine_ore_reserve()));
        }
        return 1;
    }

    if (topic == "商隊" || topic == "封路" || topic == "黑石關") {
        if (ws) {
            tell_object(me, query_name() + " 搖頭嘆道：「" + ws->query_garrison_narrative(1) + "」\n");
            return 1;
        }
    }

    if (topic == "任務" || topic == "生計" || topic == "job" || topic == "career" || topic == "物道" || topic == "接應") {
        object career = load_object(CAREER_D);
        int st = career ? career->query_chain_stage(me, "wu") : 0;
        if (st == 0 || st == 1) {
            tell_object(me, query_name() + " 咳了兩聲，抹了把臉上的黑灰道：「阿鐵讓你來的？好小子！方才地煞震動，老夫腿腳被滾石砸傷了。這塊剛撬下來的粗礦核你先拿著，但老夫肺裡吸進了地底毒瘴，快去南谷藥廬找葛半仙配一劑解毒活絡散！」\n");
            object ore = clone_object("/clone/item/ore_chunk.c");
            if (ore) ore->move(me);
            if (st == 0) career->start_chain(me, "wu");
            career->advance_chain_stage(me, "wu"); // advance to 2
            return 1;
        } else if (st == 2) {
            tell_object(me, query_name() + " 咳喘道：「老夫肺裡毒瘴翻湧，快去南谷溪灘採晨露草，找葛半仙配藥！」\n");
            return 1;
        } else if (st == 3) {
            tell_object(me, query_name() + " 欣喜道：「藥配來了嗎？快給老夫服下 (give san to lu)！」\n");
            return 1;
        } else {
            tell_object(me, query_name() + " 笑道：「咱們北崖採出來的上好粗礦，阿鐵最是稀罕！鍛打成柴刀再賣給商隊換銀子，這便是咱們黑石鋪的百工之鏈！」\n");
            return 1;
        }
    }

    return ::do_chat(me, topic);
}

int accept_object(object who, object ob) {
    if (!who || !ob) return 0;

    if (ob->id("huoluo san") || ob->id("powder") || ob->id("san") || ob->query_name() == "葛氏活絡散") {
        tell_object(who, HIG "魯大山接過藥散服下，長舒了一口氣，大聲讚道：「好霸道的草木藥力！肺裡的悶痛散了大半！快把粗礦帶回鐵匠鋪交給阿鐵開爐！」\n" NOR);
        destruct(ob);
        object career = load_object(CAREER_D);
        if (career) {
            int st = career->query_chain_stage(who, "wu");
            if (st == 2 || st == 3) {
                while (career->query_chain_stage(who, "wu") < 4) {
                    career->advance_chain_stage(who, "wu");
                }
            }
        }
        return 1;
    }

    // 支援坑道加固：接受加固木料
    if (ob->id("timber") || ob->id("wood") || ob->id("坑木") || ob->id("加固木料")) {
        write(HIY "魯大山接過加固木料，欣喜道：「太好了！有了這批硬木支柱，礦坑上方又能多頂住一陣子！」\n" NOR);
        destruct(ob);
        object ws = load_object(WORLD_STATE_D);
        if (ws) ws->repair_mine(10);
        return 1;
    }

    return 0;
}
