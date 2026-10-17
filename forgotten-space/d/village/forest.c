// d/village/forest.c
// 黑石鋪・東面荊棘荒林與獸道 (身法敏捷、陷阱與追蹤狩獵區)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

int totem_discovered;

void create() {
    ::create();
    set_short("大荒外緣・荊棘林口");
    set_long("穿過聚落東邊的粗木鹿角柵欄，便是遮蔽天日的原始荒林。老藤如同巨蟒盤\n"
             "踞在粗壯古木之上，地面堆積著厚厚腐葉，散發著泥土與松脂的潮味。泥濘\n"
             "小徑上有幾道新鮮的野獸蹄印與抓痕，路旁倒伏的斷木下暗藏著獵戶布下的\n"
             "竹刺吊套陷阱 (trap)。循著泥濘獸道似乎可深入追蹤獸跡 (track)。\n"
             "遠處林海深處不時傳來沉悶的狼嚎與飛鳥驚起之聲。\n");

    set_exits(([
        "north":     "/d/village/hunter_cabin.c",
        "west":      "/d/village/hunter_cabin.c",
        "northwest": "/d/village/square.c",
    ]));

    set("is_outdoor", 1);
    totem_discovered = 0;

    spawn_item("/clone/item/tainted_pelt.c");
}

string query_long() {
    object ws = load_object(WORLD_STATE_D);
    string res = "穿過聚落東邊的粗木鹿角柵欄，便是遮蔽天日的原始荒林。老藤如同巨蟒盤\n"
                 "踞在粗壯古木之上，地面堆積著厚厚腐葉，散發著泥土與松脂的潮味。泥濘\n"
                 "小徑上有幾道新鮮的野獸蹄印與抓痕，路旁倒伏的斷木下暗藏著獵戶布下的\n"
                 "竹刺吊套陷阱 (trap)。循著泥濘獸道似乎可深入追蹤獸跡 (track)。\n";
    if (ws) {
        res += sprintf(MAG "【東林氣機】%s\n" NOR, ws->query_beast_movement_narrative(0));
    } else {
        res += "遠處林海深處不時傳來沉悶的狼嚎與飛鳥驚起之聲。\n";
    }
    return res;
}

void init() {
    ::init();
    add_action("do_inspect_trap", "trap");
    add_action("do_inspect_trap", "檢視陷阱");
    add_action("do_track", "track");
    add_action("do_track", "追蹤");
    add_action("do_commune_totem", "totem");
    add_action("do_commune_totem", "圖騰");
    add_action("do_commune_totem", "感應圖騰");
    add_action("do_chop", "chop");
    add_action("do_chop", "伐木");
    add_action("do_chop", "砍木");
}

int do_chop(string arg) {
    object me = this_player();
    if (me->query(VITAL_SP) < 15) {
        write(HIR "你精疲力竭，雙臂酸軟，連柴刀都掄不動了。\n" NOR);
        return 1;
    }

    object weapon = me->query_temp("weapon");
    if (!weapon) {
        object *inv = all_inventory(me);
        foreach (object ob in inv) {
            if (ob->query("weapon_type") == "blade" || ob->query("weapon_type") == "axe" || ob->query("weapon_type") == "hammer" || ob->id("blade") || ob->id("axe") || ob->id("柴刀") || ob->id("hammer") || ob->id("鐵錘") || ob->id("鎬") || ob->id("pickaxe")) {
                weapon = ob;
                break;
            }
        }
    }

    if (!weapon) {
        write("伐木需手持砍刀、斧頭或重錘工具！（例如：wield blade 或 wield hammer）\n");
        return 1;
    }

    me->add(VITAL_SP, -15);
    write("你手持" + weapon->query_short() + "，看準路旁一株倒伏的陳年硬木，沉腰落刃，奮力劈砍！\n");
    write(HIW "「喀嚓！」木屑紛飛，經過一番費力砍鋸，你砍下了一根結實沉重的【加固硬木料】！\n" NOR);
    object timber = clone_object("/clone/item/timber.c");
    if (timber) {
        if (!timber->move(me)) timber->move(this_object());
    }
    me->train_stat(STAT_STR, 15);
    me->gain_exp(10);
    return 1;
}

int do_inspect_trap(string arg) {
    object me = this_player();

    if (me->query(VITAL_SP) < 10) {
        write(HIR "你精力耗盡、手腕顫抖，無法專心進行精密機關調試。\n" NOR);
        return 1;
    }

    me->add(VITAL_SP, -10);
    write("你蹲下身，手掌在荊棘叢中精巧地撥開落葉，重新調校竹刺彈簧與吊繩套鎖...\n");

    object ws = load_object(WORLD_STATE_D);
    if (ws) {
        ws->calm_forest_beasts(10);
        write(sprintf(CYN "隨著外圍防獸陷阱加固，東林獸群躁動度降至 %d%%。\n" NOR, ws->query_forest_beast_alert()));
    }

    // 鍛鍊靈巧 dex 與 感知 per
    write(HIG "【在穿針引線般的機巧微調中，你的指節愈發靈敏，靈巧與感知提升！】\n" NOR);
    me->train_stat(STAT_DEX, 15);
    me->train_stat(STAT_PER, 15);
    me->gain_exp(10);

    object career = load_object(CAREER_D);
    if (career && career->query_chain_stage(me, "li") == 2) {
        career->advance_chain_stage(me, "li");
    }
    return 1;
}

int do_track(string arg) {
    object me = this_player();
    if (me->query(VITAL_SP) < 5) {
        write(HIR "你精疲力竭，雙眼昏花，難以分辨林間細微的獸跡。\n" NOR);
        return 1;
    }

    object ws = load_object(WORLD_STATE_D);
    int disha = ws ? ws->query_disha_activity() : 60;
    if (disha < 20 && me->query_stat(STAT_PER) < 3) {
        write("此時林間地煞平息，腐葉掩蓋了舊痕，憑你目前的感知難以尋得異獸留下的深層蹤跡。\n");
        return 1;
    }

    me->add(VITAL_SP, -5);
    write("你壓低身形，指尖拂過濕潤的泥土與斷裂的草莖，目光如夜隼般搜尋獸道痕跡...\n");
    write(MAG "你在落葉掩蓋的泥坑邊發現了幾滴暗紫色的焦灼濁血，散發著令人心悸的地煞凶腥（地煞濃度 " + disha + "%）！\n" NOR);
    write(HIR "\n【警兆驟臨・反向伏擊】\n" NOR);
    write(YEL "頭頂枯樹頂端猛然刮起一陣腥臭狂風！一頭背生森白骨甲、足有兩丈高的狂暴骨魔黑熊悍然暴起撲殺！\n"
              "你不及多想，借力凌空翻滾避開拍碎古木的千鈞巨掌，手中柴刀順勢狠狠鑿入黑熊眼眶！\n" NOR);
    write(RED "一人一獸在慘烈嘶吼中翻滾失控，雙雙砸穿化骨泥沼邊緣脆弱的腐泥斷層，直墜百丈地陷死穴！\n" NOR);
    write(WHT "狂暴撞擊中黑熊當場斃命，而在坑底被砸碎的萬年石衣深處，\n"
              "赫然露出一尊通體倒插於地心死穴、散發著蒼茫蠻荒神威的【太古戰神獵獸圖騰玄柱】(totem)！\n" NOR);
    totem_discovered = 1;
    me->set_temp("tracked_totem", 1);
    me->train_stat(STAT_PER, 15);
    me->gain_exp(10);

    object career2 = load_object(CAREER_D);
    if (career2 && career2->query_chain_stage(me, "li") == 2) {
        career2->advance_chain_stage(me, "li");
    }
    return 1;
}

int do_commune_totem(string arg) {
    object me = this_player();
    if (!totem_discovered && !me->query_temp("tracked_totem")) {
        write("密林遮蔽，你尚未發現深處的古老圖騰所在。（請先在林中仔細追蹤獸跡 track）\n");
        return 1;
    }

    if (me->query(VITAL_KEE) < 15) {
        write(HIR "你傷勢過重、氣血衰竭，無法逼出心頭精血承受太古戰神圖騰的狂暴蠻荒意志！\n" NOR);
        return 1;
    }

    object ws = load_object(WORLD_STATE_D);
    object pelt = present("tainted pelt", me);
    if (!pelt) pelt = present("tainted pelt", this_object());
    int disha = ws ? ws->query_disha_activity() : 60;

    object md = load_object(MYSTERY_D);
    if (md && !md->can_discover_relic(me, "commune_forest_totem")) {
        write(HIR "你伸手欲割血抹向圖騰柱，石柱非但毫無回應，反被石雕上積累的萬古凶煞直接震退，\n"
                  "整條右臂冰冷刺痛、氣血逆亂！（身世非大荒蠻荒神魔血脈，肉身無法承載戰祖煞氣）\n" NOR);
        me->add(VITAL_KEE, -5);
        return 1;
    }

    // 檢定：需有獸血/煞獸殘皮為引或地煞翻湧，且肉身氣血根骨足以承受
    if (!pelt && disha < 40) {
        write(YEL "圖騰柱上的石紋冰冷死寂。缺乏沾染地煞的暗紫濁血或煞獸殘皮作為媒介，無法引動太古血脈共鳴。\n" NOR);
        return 1;
    }
    if (me->query_stat(STAT_STR) + me->query_stat(STAT_CON) < 2) {
        write(HIR "你刚將手指按上圖騰，一股蠻荒凶威便震得你手臂發麻，肉身根骨尚不足以承受共鳴！\n" NOR);
        return 1;
    }

    me->add(VITAL_KEE, -10);
    write(YEL "你強行壓下胸腹重傷，眼神狠厲如狼，屈指狠狠割破掌心，逼出一大口滾燙純陽的【心頭精血】！\n" NOR);
    write(HIR "殷紅熾烈的人族精血如決堤烈火，狂暴潑灑在圖騰柱中央那尊手撕萬丈神魔的荒古戰祖石雕上！\n" NOR);
    write(MAG "柱身殘存的萬年青苔石衣如雪崩般轟然震飛，石雕雙目驟然爆發出兩道撕裂九幽的赤金血芒！\n" NOR);
    write(HIR "「吼————！！」\n" NOR);
    write(HIR "一聲源自遠古蠻荒的凶獸咆哮在你的靈魂深處炸裂，浩瀚神魔血氣如狂暴火龍逆流倒灌入體！\n" NOR);
    write(HIW "【太古戰祖蠻荒血脈共鳴！斷骨續接、經絡重鑄，戰鬥敏捷與肉身力道得到了極致淬鍊！】\n" NOR);

    me->train_stat(STAT_STR, 20);
    me->train_stat(STAT_DEX, 30);
    me->gain_exp(15);

    object md = load_object(MYSTERY_D);
    if (md && !md->is_relic_discovered(me, "commune_forest_totem")) {
        md->trigger_relic_discovery(me, "commune_forest_totem", me);
        write(HIG "【你首度以心頭精血引動太古戰祖圖騰共鳴，體內荒血覺醒（天命+1），額外獲得 40 點經驗！】\n" NOR);
    }
    return 1;
}
