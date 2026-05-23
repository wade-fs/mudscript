#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name(([ "en": "Guild Master Edmund", "zh-TW": "公會會長 艾德蒙", "zh-CN": "公会会长 艾德蒙" ]));
    set_short(([ "en": HIW("Adventurer Guild Master") + " Edmund", "zh-TW": HIW("冒險者公會會長") + " 艾德蒙", "zh-CN": HIW("冒险者公会会长") + " 艾德蒙" ]));
    set_long(([
        "en": "An experienced human warrior who is the head of this guild.\nHe wears a polished silver armor, and his eyes show authority.\n",
        "zh-TW": "一位看起來經驗豐富的人類戰士，他是這間公會的負責人。\n他穿著一套擦得發亮的銀色鎧甲，眼神中透著威嚴。\n",
        "zh-CN": "一位看起来经验丰富的人类战士，他是这间公会的负责人。\n他穿着一套擦得发亮的银色铠甲，眼神中透着威严。\n"
    ]));
    set_id(({"edmund", "guild master", "master", "會長"}));
    set_race("human");
    set_level(30);
    set_stat(STAT_STR, 25);
    set_stat(STAT_CON, 25);
    recalc_stats();
	set_move_range(2);
	set_wander_chance(2); // 調低機率，免得老是不在公會
	set_respawn(60);
	set_behaviour(BEHAV_PASSIVE|BEHAV_WANDER);

    // 🚀 新增：傳授技能
    set_skill_to_teach("unarmed", 20);
    set_skill_to_teach("magic", 20);

	set_flee_hp_pct(15);
	set_flee_chance(80);

    hp = max_hp;

    add_response("job", ({ 
        "最近東邊的草原有狼群出沒，你可以去看看。",
        "聽說北方的山腳下出現了一些奇怪的洞穴，或許你可以去調查一下。",
        "公會現在正缺少一些藥草，如果你能去採些回來就太好了。"
    }));
    add_response("工作", ({ 
        "最近東邊的草原有狼群出沒，你可以去看看。",
        "聽說北方的山腳下出現了一些奇怪的洞穴，或許你可以去調查一下。",
        "公會現在正缺少一些藥草，如果你能去採些回來就太好了。"
    }));
    add_response("guild", ({
        "這裡提供冒險者休息與交流的場所。",
        "公會是你最強大的後盾，不論你遇到什麼困難，都可以回來尋求協助。",
        "想加入公會嗎？只要你有顆勇敢的心！"
    }));
    add_response("公會", ({
        "這裡提供冒險者休息與交流的場所。",
        "公會是你最強大的後盾，不論你遇到什麼困難，都可以回來尋求協助。",
        "想加入公會嗎？只要你有顆勇敢的心！"
    }));
    add_response("help", ({
        "新手的話，可以先去[鐵匠鋪|go west]找索林買把武器，或者去[藥劑店|go south]備些藥水。",
        "記住，適時的撤退也是冒險的一部分。",
        "多和其他人交談，你會收穫意想不到的情報。"
    }));
    add_response("幫助", ({
        "新手的話，可以先去[鐵匠鋪|go west]找索林買把武器，或者去[藥劑店|go south]備些藥水。",
        "記住，適時的撤退也是冒險的一部分。",
        "多和其他人交談，你會收穫意想不到的情報。"
    }));
    add_response("newbie", ({
        "這裡是新手村，是所有偉大冒險的起點。",
        "別擔心，每個人都是從新手開始的。",
        "好好利用這裡的資源提升自己吧！"
    }));
    add_response("新手", ({
        "這裡是新手村，是所有偉大冒險的起點。",
        "別擔心，每個人都是從新手開始的。",
        "好好利用這裡的資源提升自己吧！"
    }));
    add_response("adventure", ({
        "冒險總是充滿驚喜與危險，記得隨時準備好你的裝備。",
        "真正的冒險家從不畏懼未知的挑戰！",
        "想當初，我也曾經在巨龍的巢穴裡打過滾..."
    }));
    add_response("冒險", ({
        "冒險總是充滿驚喜與危險，記得隨時準備好你的裝備。",
        "真正的冒險家從不畏懼未知的挑戰！",
        "想當初，我也曾經在巨龍的巢穴裡打過滾..."
    }));
    add_response("news", ({
        "聽說最近有批厲害的冒險者剛從北方回來，帶回了不少好東西。",
        "聽說新手村附近的森林裡出現了前所未見的巨大史萊姆。",
        "最近酒館裡的人特別多，大概是因為新運來的麥酒很好喝吧。"
    }));
    add_response("消息", ({
        "聽說最近有批厲害的冒險者剛從北方回來，帶回了不少好東西。",
        "聽說新手村附近的森林裡出現了前所未見的巨大史萊姆。",
        "最近酒館裡的人特別多，大概是因為新運來的麥酒很好喝吧。"
    }));
    add_response("skill", ({
        "技能是你在荒野中生存的關鍵。",
        "多加練習，你的技巧會越來越純熟的。",
        "雖然我主要教授戰鬥技巧，但其他領域的知識也同樣重要。"
    }));
    add_response("技能", ({
        "技能是你在荒野中生存的關鍵。",
        "多加練習，你的技巧會越來越純熟的。",
        "雖然我主要教授戰鬥技巧，但其他領域的知識也同樣重要。"
    }));
    add_response("地圖", "新手村由 8x8 的區域組成。我們現在在 (4,5)。中央廣場在正南方 (4,4)。");

    // 任務互動：改用外部方法避免 closure 內宣告型別變數
    add_response(({ "quest", "任務" }),   (: this_object()->resp_quest() :));
    add_response(({ "report", "回報" }),  (: this_object()->resp_report() :));
    add_response(({ "hunt", "打獵", "獵狼" }), (: this_object()->resp_hunt() :));
    add_response(({ "join", "加入" }),    (: this_object()->resp_join() :));
    add_response(({ "wolf", "野狼" }), "最近東邊的草原野狼氾濫，如果你想練手，可以找我承接『獵狼』任務。");
}


// ── 任務回應方法（從 closure 拆出，避免 closure 內宣告型別限制）────────────
string resp_quest() {
    mapping qdata = this_player()->query_quest("newbie_badge");
    if (qdata) {
        if (qdata["status"] == "active")
            return "你已經在進行『新手證明』任務了，快去證明你的勇氣吧！";
        return "你已經獲得了冒險者的認可。現在可以去[教官|go west]那裡看看有沒有什麼新兵任務。";
    }
    load_object("/secure/quest_d.c")->accept_quest(this_player(), "newbie_badge");
    return "很好，有志氣！只要你大聲喊出『我有勇氣』，我就把這枚徽章送給你。";
}

string resp_report() {
    mapping qwolf = this_player()->query_quest("wolf_hunter");
    if (qwolf && qwolf["status"] == "active") {
        mapping info = load_object("/secure/quest_d.c")->query_quest_info("wolf_hunter");
        if (qwolf["progress"]["count"] >= info["goal"]["count"]) {
            load_object("/secure/quest_d.c")->complete_quest(this_player(), "wolf_hunter");
            return "做得好！那些討厭的野狼終於被制伏了。這是你的獎勵。";
        }
        return "野狼還在草原上出沒呢，快去完成任務吧！";
    }
    return "你目前沒有什麼可以向我回報的。";
}

string resp_hunt() {
    if (this_player()->query_quest("wolf_hunter")) return "你已經領過獵狼任務了。";
    load_object("/secure/quest_d.c")->accept_quest(this_player(), "wolf_hunter");
    return "很好，去消滅 3 隻飢餓的野狼，回來向我『回報』。";
}

string resp_join() {
    if (this_player()->query_guild())
        return "你已經是 " + load_object("/secure/guild_d.c")->query_guild_info(this_player()->query_guild())["name"] + " 的成員了。";
    load_object("/secure/guild_d.c")->join_guild(this_player(), "adventurer");
    return "很好！從今天起，你就是我們冒險者公會的一員了。";
}

// 攔截玩家大喊「我有勇氣」
void catch_tell(string msg) {
    ::catch_tell(msg);

    object tp = this_player();
    if (!tp || !userp(tp)) return;

    if (strsrch(msg, "我有勇氣") != -1) {
        mapping qdata = tp->query_quest("newbie_badge");
        if (qdata && qdata["status"] == "active") {
            load_object("/secure/quest_d.c")->complete_quest(tp, "newbie_badge");
            say(query_name() + " 欣慰地點點頭，將一枚徽章遞給了 " + tp->query_name() + "。\n");
        }
    }
}

