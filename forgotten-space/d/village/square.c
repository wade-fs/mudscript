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
             "東南方有獵戶搭建的防獸哨亭，西南後巷則蜿蜒通往破舊柴棚，\n"
             "東北方向延伸出通往黑石關與盤木縣的東線山道 (northeast，450 里通重車)，\n"
             "西北方向則有一條切入落龍西谷懸崖棧道的捷徑 (northwest，420 里禁重車)。\n");

    set_exits(([
        "north":     "/d/village/mine.c",
        "south":     "/d/village/stream.c",
        "east":      "/d/village/forge.c",
        "west":      "/d/village/daoist_temple.c",
        "southeast": "/d/village/hunter_cabin.c",
        "southwest": "/d/village/shed.c",
        "northeast": "/d/routes/blackstone_pass.c",
        "northwest": "/d/routes/west_gorge_entry.c",
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
        if (ws->is_caravan_arrived()) {
            res += HIY "茶棚旁正停駐著金石商會的馱獸與大車，錢大掌櫃設鋪收購粗礦良藥 (sell)！\n" NOR;
        } else if (ws->is_caravan_blocked()) {
            res += YEL "客棧門口聚著幾名憂心忡忡的行商，低聲議論著大荒商道受阻的變故。\n" NOR;
        }
    }

    res += "向北通往黑石斷崖古礦道，南邊飄來幽霧水谷的陣陣水霧，\n"
           "東面是炭火正旺的老鐵匠鋪，西面山腰坐落著一間破落道觀，\n"
           "東南方有獵戶搭建的防獸哨亭，西南後巷則蜿蜒通往破舊柴棚，\n"
           "東北方向延伸出通往黑石關與盤木縣的東線山道 (northeast，450 里通重車)，\n"
           "西北方向則有一條切入落龍西谷懸崖棧道的捷徑 (northwest，420 里禁重車)。\n";
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
    add_action("do_audit_grain", "audit");
    add_action("do_audit_grain", "盤點存糧");
    add_action("do_fortify_street", "fortify");
    add_action("do_fortify_street", "構築街防");
    add_action("do_brace_breach", "brace");
    add_action("do_brace_breach", "堵截缺口");
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

int do_audit_grain(string arg) {
    object me = this_player();
    if (arg && arg != "" && arg != "grain" && arg != "存糧" && arg != "糧倉") {
        write("你想盤點什麼？提示：audit grain（盤點陳記雜糧鋪與南谷追回之無主精糧）\n");
        return 1;
    }

    write(CYN "你在青石街市陳記雜糧鋪前壓下騷動的鄉民，當眾清點鋪內存糧與南谷覆車追回的二十四袋無主精糧。\n" NOR);
    write("你將所有糙米、燕麥麵與粗鹽逐袋過秤登冊，準備交由鐵匠鋪阿鐵、礦工頭魯大山與後巷沈泥三方共同加封，\n"
          "立下「按工發饃、傷患老弱保底配給」的戰時鐵律！\n");

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([
            "verb": "audit",
            "target": "grain"
        ]));
    }
    return 1;
}

int do_fortify_street(string arg) {
    object me = this_player();
    if (arg && arg != "" && arg != "street" && arg != "街口" && arg != "車陣") {
        write("你想加固哪裡？提示：fortify street（以鐵輪板車、房樑木與攔街鐵索構築街口防線）\n");
        return 1;
    }

    write(CYN "你號召街坊青壯與木匠老陳扛出三根百年老榆木房樑，將四輛沉重的鐵輪板車首尾交錯鎖死在北街口！\n" NOR);
    write("碗口粗的生鐵鎖鏈穿過車軸與青石拴馬樁，上風處三隻破鐵鍋悶燒著辣蓼苦艾與三分之一配比的地煞硫渣，\n"
          "街坊鄰里手持長矛與雙孔骨哨鳴鏑分班輪值，黑石鋪基層防線巍然成形！\n");

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([
            "verb": "fortify",
            "target": "street"
        ]));
    }
    return 1;
}

int do_brace_breach(string arg) {
    object me = this_player();
    if (arg && arg != "" && arg != "breach" && arg != "缺口" && arg != "木柵") {
        write("你想死守哪處缺口？提示：brace breach（以窄巷車陣與鐵索分段阻滯突破木柵的殘獸）\n");
        return 1;
    }

    write(HIR "數頭從落龍口西側洩壓缺口漏出的狂躁野豬與孤狼撞裂外圍木柵，嘶吼著衝入街口窄巷！\n" NOR);
    write(HIY "你指揮輪值青壯猛然拉緊攔街鐵索，將衝在最前的百斤野豬絆倒在鐵輪板車陣前，\n"
              "兩側屋頂竹矛與石灰包齊發，硬生生將這股殘獸死死釘在窄巷分段陷阱內，保住了後街糧倉與水井！\n" NOR);

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([
            "verb": "brace",
            "target": "breach"
        ]));
    }
    return 1;
}


