// d/village/square.c
// 黑石鋪・中央青石街市 (Tier 0 核心樞紐)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑石鋪・青石街市");
    set_long("這是一座依山勢而建的邊陲粗獷聚落。腳下的青石板路被往來商隊的鐵蹄\n"
             "磨得凹凸斑駁，泛著深沉的黑青色。街市中央搭著幾間避風的破舊茶棚，\n"
             "旁邊的鐵匠鋪內炭火熊熊，傳出節奏分明的叮噹打鐵聲。幾塊告示牌斜插\n"
             "在老客棧門口，貼滿了鄉民求助與商隊招募的泛黃布告。\n"
             "向北通往黑石斷崖古礦道，南邊飄來幽霧水谷的陣陣水霧，\n"
             "東面是炭火正旺的老鐵匠鋪，西面山腰坐落著一間破落道觀，\n"
             "東南方有獵戶搭建的防獸哨亭，西南後巷則蜿蜒通往破舊柴棚。\n");

    set_exits(([
        "north":     "/d/village/mine.c",
        "south":     "/d/village/stream.c",
        "east":      "/d/village/forge.c",
        "west":      "/d/village/daoist_temple.c",
        "southeast": "/d/village/hunter_cabin.c",
        "southwest": "/d/village/shed.c",
    ]));

    set("no_combat", 1);
    set("is_outdoor", 1);
    set("has_shop", 1);
    set("has_forge", 1);

    add_item("board", "一張告示牌");
}

string query_long() {
    object ws = load_object(WORLD_STATE_D);
    string res = "這是一座依山勢而建的邊陲粗獷聚落。腳下的青石板路被往來商隊的鐵蹄\n"
                 "磨得凹凸斑駁，泛著深沉的黑青色。街市中央搭著幾間避風的破舊茶棚，\n"
                 "旁邊的鐵匠鋪內炭火熊熊，傳出節奏分明的叮噹打鐵聲。幾塊告示牌 (board)\n"
                 "斜插在老客棧門口，貼滿了鄉民求助與商隊招募的泛黃布告。\n";

    if (ws) {
        if (ws->query_caravan_status() == "arrived") {
            res += HIY "茶棚旁正停駐著金石商會的馱獸與大車，錢大掌櫃設鋪收購粗礦良藥 (sell)！\n" NOR;
        } else if (ws->query_caravan_status() == "blocked") {
            res += YEL "客棧門口聚著幾名憂心忡忡的行商，低聲議論著大荒商道受阻的變故。\n" NOR;
        }
    }

    res += "向北通往黑石斷崖古礦道，南邊飄來幽霧水谷的陣陣水霧，\n"
           "東面是炭火正旺的老鐵匠鋪，西面山腰坐落著一間破落道觀，\n"
           "東南方有獵戶搭建的防獸哨亭，西南後巷則蜿蜒通往破舊柴棚。\n";
    return res;
}

string look_at_item(string id) {
    if (id == "board" || id == "告示牌" || id == "布告" || id == "告示") {
        object ws = load_object(WORLD_STATE_D);
        string msg = "\n" + HIY "【黑石鋪・聚落官驛布告欄】" + NOR + "\n" +
                     WHT "────────────────────────────────────────\n" + NOR;

        if (ws) {
            // 1. 商道與商隊動態 (由 WORLD_STATE_D 官軍封關與商隊狀態驅動)
            msg += HIW "【大荒商道・金石商會】\n" + NOR;
            string c_stat = ws->query_caravan_status();
            if (c_stat == "arrived") {
                msg += HIG "  ● 商隊已抵達青石街市！大掌櫃錢富貴設鋪開市，高價收購粗礦、良藥與大荒柴刀 (sell)。\n" + NOR;
            } else if (c_stat == "blocked") {
                msg += HIR "  ● 【特急警告】" + ws->query_garrison_narrative(0) + "\n" + NOR;
            } else {
                msg += YEL "  ● " + ws->query_garrison_narrative(0) + "\n" + NOR;
            }

            // 2. 礦坑安全與儲量
            msg += "\n" + HIW "【黑石斷崖・古礦道】\n" + NOR;
            if (ws->is_mine_collapsed()) {
                msg += HIR "  ● 【緊急通告】北崖礦洞發生嚴重塌方！巨石封洞，懸賞青壯前往搬石搶修 (clear)！\n" + NOR;
            } else {
                int res = ws->query_mine_ore_reserve();
                int stab = ws->query_mine_stability();
                msg += sprintf("  ● 礦脈運作正常 (粗礦儲量: %d/30，地質穩定度: %d%%)。\n", res, stab);
            }

            // 3. 水谷水情
            msg += "\n" + HIW "【幽霧水谷・碎石溪灘】\n" + NOR;
            string w_desc = ws->query_water_level_desc();
            if (ws->is_stele_submerged()) {
                msg += HIR "  ● 【山洪警報】水谷深潭山洪狂暴注入，淺灘巨石盡沒，切勿涉水！\n" + NOR;
            } else {
                int herbs = ws->query_herb_stock();
                msg += sprintf("  ● 當前水情：%s，兩岸草藥存量：%d/12 (gather)。\n", w_desc, herbs);
            }

            // 4. 東林獵場與地煞獸情 (由 WORLD_STATE_D 獸群異動狀態驅動)
            msg += "\n" + HIW "【東林獵場・地煞獸情】\n" + NOR;
            int alert = ws->query_forest_beast_alert();
            if (alert >= 60) {
                msg += HIR "  ● 【獸潮警戒】" + ws->query_beast_movement_narrative(0) + "\n" + NOR;
            } else {
                msg += "  ● " + ws->query_beast_movement_narrative(0) + "\n";
            }
        }
        msg += WHT "────────────────────────────────────────\n" + NOR;
        return msg;
    }
    return ::look_at_item(id);
}

void init() {
    ::init();
    add_action("do_tea", "tea");
    add_action("do_tea", "drink");
    add_action("do_tea", "喝茶");
    add_action("do_tea", "歇腳");
}

int do_tea(string arg) {
    object me = this_player();
    if (!me->consume_drink(30)) return 1;

    write("你在街市中央的避風破舊茶棚長條凳上坐下，從大陶缸裡盛了一碗溫熱的荒山粗葉茶一飲而盡。\n");
    write(YEL "微苦回甘的熱茶順喉而下，暖流傳遍全身，行路的風霜與困乏一掃而空。\n" NOR);
    me->add(VITAL_KEE, 20);
    me->add(VITAL_SEN, 20);
    me->add(VITAL_SP, 25);
    write(HIG "【茶棚歇腳，你的氣血 +20、神識 +20、精力 +25！】\n" NOR);
    return 1;
}

