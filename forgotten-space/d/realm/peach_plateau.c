// /d/realm/peach_plateau.c
// Tier 3 桃花源洞天初臨地・荒蕪碎石高原 (Ch.126 第三卷大結局：非仙境而見三座太古巨構對峙)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("桃花源洞天・荒蕪碎石高原");
    set_long("預想中的十里桃花、靈泉仙鶴俱無半點蹤影——頭頂是一片詭異暗鐵青色、彷彿永遠\n"
             "停格於黎明前最壓抑時刻的巨大靜止天穹，不見熟悉日星與二十八宿，空氣冰冷稀薄。\n"
             "狂風捲著砂礫掠過腳下枯死如鐵絲般的灰白草叢與無盡灰褐碎石高原；遙望北方溝壑邊緣\n"
             "隱現數點孤零幽冷燈火與灰黑煙塵（可循玄武岩風道 north 深入探索）。地平線三個極端盡頭，\n"
             "相隔不知幾萬里巍然矗立著三座無聲對峙的太古巨構輪廓——可凝神遠眺方位（gaze horizon），\n"
             "或低首窺探高原岩基深裂隙裡隱隱閃動的歸墟古淵門縫（peer fissure）。\n"
             "（※ 單向古陣已因身後雷劫崩毀無歸途；若欲暫以神識回溯人間據點測試可輸入 vision return。）\n");

    set_exits(([
        "north": "/d/realm/edge/basalt_ridge.c",
    ]));
    set("is_outdoor", 1);

    set_bg_sensory("herbalist", CYN "【百草通玄感官】腳下灰白枯草並非凡間植物，而是半金屬化的噬靈菌絲；每一次呼吸都像吞入帶鐵鏽與苦杏仁味的冷霜。" NOR);
    set_bg_sensory("smith", YEL "【天工造物感官】高原碎石中混雜著無數太古神械崩碎後的暗紅黑鐵螺紋殘片，正東地平線傳來萬物主機城巨型齒輪的低頻共振！" NOR);
    set_bg_sensory("hunter", MAG "【荒血破障感官】風裡沒有半點凡間鳥獸的生機，西南焦土裂谷騰湧的洪荒凶煞血氣讓你的荒血本能地繃緊了弓弦。" NOR);
    set_bg_sensory("daoist", HIC "【太虛演天感官】頭頂暗鐵青色天穹沒有二十八宿天羅鐵網，但此界濃烈三倍的太古源質正試圖主動同化你的神魂經絡！" NOR);
    set_bg_sensory("beggar", WHT "【萬山共治感官】掌心【天門引】在跨界後變得滾燙，遠處荒野邊緣那幾點幽冷燈火，意味著此界仍有苟延殘喘的太古遺民聚落。" NOR);
}

string query_touch(string target) {
    return HIC "你蹲下身抓起一把高原灰褐砂礫——砂石中混著鋒利的暗紅玄鐵碎屑與灰白鹽霜，枯死如鐵絲的草莖一折即發出金石脆響；掌心【天門引】正微微發燙。" NOR;
}

string query_smell(string target) {
    return HIW "冰冷稀薄的空氣裡沒有半點桃花芬芳，只有一股濃烈的苦杏仁鹽霜味、焦土鐵鏽氣與高濃度太古源質的電離臭氧味。" NOR;
}

string query_listen(string target) {
    return HIY "狂風捲著鐵砂掠過高原的嗚咽聲中，正東萬物主機城的低頻齒輪轟鳴、西南戰祖魔殿的裂谷煞嘯與正北太虛神宮的玉石冷鳴在天地間形成三極共振。" NOR;
}

void init() {
    ::init();
    add_action("do_gaze", "gaze");
    add_action("do_vision", "vision");
    add_action("do_breathe", "breathe");
    add_action("do_breathe", "吐納");
    add_action("do_peer", "peer");
}

int do_peer(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "fissure" && arg != "歸墟" && arg != "門縫") {
        notify_fail("你要窺探什麼？試試：peer fissure\n");
        return 0;
    }

    object t3 = load_object(TIER3_D);
    mapping gate = t3 ? t3->evaluate_tier4_unlock_eligibility(me) : ([ "eligible": 0, "missing_requirements": ({ "enc_map_fusion", "three_yuan_resonance", "personal_event/pierced_false_heaven" }) ]);

    tell_object(me, HIC
        "【歸墟古淵門縫召喚與第四卷終章見證（Ch.170）】\n"
        "碎石高原萬丈地底突然傳來一聲彷彿跨越萬古的沉重石門輕顫——禁忌深淵【歸墟古淵】亮起一線微光門縫！\n" NOR);
    if (!gate["eligible"]) {
        string missing_txt = arrayp(gate["missing_requirements"]) ? implode(gate["missing_requirements"], "、") : "三要件未齊";
        tell_object(me, YEL
            "（門檻檢定阻斷：你已取得三階洞天實戰見證並見識門縫召喚，但入內仍須獨立集齊 §4.2 三大要件：" + missing_txt + "，絕無自動捷徑。）\n" NOR);
    } else {
        tell_object(me, HIY "（三大要件俱備：你已感應通往深層歸墟古淵的微弱門縫座標。）\n" NOR);
    }
    say(me->query_name() + " 俯身檢視高原地底傳來沉悶石響的玄武岩裂隙。\n");

    if (!present("guixu_threshold_record", me)) {
        object rec = clone_object("/clone/item/guixu_threshold_record.c");
        if (rec) rec->move(me);
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) qe->trigger_event(me, "action", ([ "verb": "peer", "target": "fissure" ]));
    return 1;
}

int do_breathe(string arg) {
    object me = this_player();
    if (!me) return 0;
    tell_object(me, HIR
        "【異界源質吐納警兆（第四卷法則）】\n"
        "你試圖依凡間吐納法門吸納一口洞天靈氣——比凡間濃烈三倍的太古源質如滾燙鉛水般湧入經脈！\n"
        "此界源質毫無假天濾網稀釋，兼具『玉石結晶化（法）』、『血肉狂暴畸變（力）』與『金屬電路同化（物）』三重侵蝕性，\n"
        "你連忙以三元互濟之法強行鎖住氣海，方才將那股同化排異感壓下！\n" NOR);
    return 1;
}

int do_gaze(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (!arg || arg == "") arg = "horizon";
    tell_object(me, HIY
        "【異界洞天地平線初窺（第四卷前瞻）】\n"
        "・正北雲霧高空——【太虛神宮】：懸浮於高天、通體純白星輝玉石築成，散發令神魂幾乎自行跪拜臣服的冰冷秩序威壓。\n"
        "・西南焦土裂谷——【戰祖魔殿】：巨獸白骨與暗紅玄鐵堆疊而成，時刻似有洪荒凶煞血氣自焦黑裂谷騰湧翻滾。\n"
        "・正東無邊荒漠——【萬物主機城】：閃爍億萬道青金幾何電路與無數巨型轉動齒輪，發出大地亦為之震顫的低頻轟鳴。\n"
        "握緊百斤鐵胎弓、小鍛錘、藥囊與微溫的【天門引】，無論門後是避難所抑或更深囚籠，這筆帳正要從第一頁算起。\n" NOR);
    return 1;
}

int do_vision(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "return" && arg != "mortal") {
        notify_fail("單向古陣已無實體歸途；若以測試神識返回雲津總號請用：vision return\n");
        return 0;
    }
    object dst = load_object("/d/yunjin/mudway_store.c");
    if (dst) {
        tell_object(me, CYN "你以一縷神識記憶暫返雲津【萬山泥途總號】查閱人間留守帳冊……\n" NOR);
        me->move(dst);
    }
    return 1;
}
