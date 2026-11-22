// daemon/rumor_d.c
// 《遺忘的世界》動態江湖情報與市井風聲守護進程 (RUMOR_D)
// 聚合六縣自主演進、商隊物流、天候異動與城邦法度，提供動態流轉情報

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

int last_broadcast;

string query_save_file() { return "/data/rumor_d"; }

void create() {
    ::create();
    last_broadcast = 0;
    if (file_size(query_save_file() + ".o") > 0) {
        restore_object(query_save_file());
    }
}

// ── 1. 取得指定縣城當前演進情報 ─────────────────────────────
string query_county_rumor(string county_id) {
    object ws_d = find_object(WORLD_STATE_D);
    if (!ws_d) ws_d = load_object(WORLD_STATE_D);
    if (!ws_d) return "近來四方寧謐，各縣官道商旅行人往來如常。";

    mapping status = ws_d->query_county_status(county_id);
    if (!status) return "此縣偏遠閉塞，近來未有確鑿音訊傳入府城。";

    int st = status["stage"];
    int pct = status["price_pct"];
    string name = status["name"];

    if (county_id == "panmu") {
        if (st == 1) return sprintf("【%s】山民在倒影澗發現煞化林獸蹤跡，紅杉原木出貨漸緊，市價微浮一成（%d%%）。", name, pct);
        if (st == 2) return sprintf("【%s】老伐木工因煞化巨熊封鎖深林，官道上原木價錢暴漲了三成（%d%%）！", name, pct);
        if (st == 3) return sprintf("【%s】南嶺林海塌方了！官道連陰雨滑坡，重車全堵在半路，木材飆至高位（%d%%）！", name, pct);
        return sprintf("【%s】林道搶通了便道，有老林戶在深澗挖出雷擊陰沉木心，據說鬼市有大金主在收！", name);
    }
    if (county_id == "zhongshi") {
        if (st == 1) return sprintf("【%s】黑石鋪礦坑塌了之後，官府的重玄條石配額全壓到重石縣穿山寨去了（%d%%）。", name, pct);
        if (st == 2) return sprintf("【%s】主採石場三號巨型絞盤被崩斷了！壓傷好幾個石工，條石出貨減半（%d%%）！", name, pct);
        if (st == 3) return sprintf("【%s】石碾坡民夫堵路抗議撫恤剋扣，南關外的條石全斷供了，鐵價飆到天上去了（%d%%）！", name, pct);
        return sprintf("【%s】百工總會派人修好了絞盤，聽說在台地深溝裡居然挖出了一座太古石槨！", name);
    }
    if (county_id == "qinghe") {
        if (st == 1) return sprintf("【%s】上游水閘放水不均，百草坪藥農和蘆花渡船伕爭水吵得不可開交（%d%%）。", name, pct);
        if (st == 2) return sprintf("【%s】洗藥坊停工了！城北採百草堂的止血草和紫蘇根價錢已經漲了四成（%d%%）！", name, pct);
        if (st == 3) return sprintf("【%s】大壩決堤啦！水匪劫了洗藥駁船，水路漕運全線停航，藥荒告急（%d%%）！", name, pct);
        return sprintf("【%s】潰壩水退之後，老河床底下沖出半截雕滿太古銘文的古石閘！", name);
    }
    if (county_id == "zhenfeng") {
        if (st == 1) return sprintf("【%s】北塞天風谷朔風轉急，邊防衛所把鷹嘴崖採石散人的石英全徵用了（%d%%）。", name, pct);
        if (st == 2) return sprintf("【%s】衛所和八方武館邊關分舵在營門口拔刀對峙，北關的硬弓和皮甲全延誤了（%d%%）。", name, pct);
        if (st == 3) return sprintf("【%s】外荒雪狼群夜襲天風谷烽燧！北塞官道已經實施戒嚴軍管（%d%%）！", name, pct);
        return sprintf("【%s】陳鎮山將軍親自出面調停，商會墊付了欠餉，北關軍管總算解除了。", name);
    }
    if (county_id == "liefan") {
        if (st == 1) return sprintf("【%s】地火堡深井地火翻騰，赤銅礦渣堵塞了官窯排煙孔（%d%%）。", name, pct);
        if (st == 2) return sprintf("【%s】商會內堂高價狂收特級耐火泥，民間銅砂被搜刮一空，工坊私爐全開（%d%%）！", name, pct);
        if (st == 3) return sprintf("【%s】地火倒灌燒毀了三座大窯！濃烈硫磺毒瘴漫入長街，耐火磚全線斷供（%d%%）！", name, pct);
        return sprintf("【%s】大火熄滅後，官窯底層被燒融的玄鐵深坑竟隱隱顯露出太古火器熔鑄痕跡！", name);
    }
    if (county_id == "zhuoshui") {
        if (st == 1) return sprintf("【%s】泥螺灘湧入大量來歷不明的生銅晶錠，淘金幫抽頭抽到三成（%d%%）。", name, pct);
        if (st == 2) return sprintf("【%s】外來亡命徒和淘金幫在水澤浮橋上火併，毒氣瘴水熏死十幾名客商（%d%%）！", name, pct);
        if (st == 3) return sprintf("【%s】當鋪分號帳房攜涉案底單逃跑，通寶體系凍結了濁水所有飛錢匯兌（%d%%）！", name, pct);
        return sprintf("【%s】失蹤帳房的半頁沾血殘帳流入了府城鬼市，牽扯出三十年前舊商盟驚天大案！", name);
    }
    if (county_id == "blackstone") {
        if (st == 1) return sprintf("【%s】阿鐵和魯大山帶礦工封了北崖毒井，改在南山採青石自救（%d%%）。", name, pct);
        if (st == 2) return sprintf("【%s】黑石關新來的暫代巡檢立了個『修路捐』，過關山貨要抽一成半的稅（%d%%）。", name, pct);
        if (st == 3) return sprintf("【%s】虎跳峽又落石封路了，巡防兵強抓村民去搬石頭，怨聲載道（%d%%）。", name, pct);
        return sprintf("【%s】莫三在後巷暗中開闢了走私小道，黑石鋪偷偷成了民間山貨中轉站。", name);
    }

    return sprintf("【%s】近來物資流轉維持在常態基準（%d%%）。", name, pct);
}

// ── 2. 取得大荒商隊最新行蹤情報 ─────────────────────────────
string query_caravan_rumor() {
    object ws_d = find_object(WORLD_STATE_D);
    if (!ws_d) ws_d = load_object(WORLD_STATE_D);
    if (!ws_d) return "商會馱隊按期押運，各處貨棧吞吐如常。";

    string st = ws_d->query_caravan_status();
    string delay = ws_d->query_caravan_delay_reason();
    string truth = ws_d->query_caravan_truth_reason();

    if (st == "blocked") {
        return sprintf("【商隊告急】%s！但坊間暗傳真相實為：%s", delay, truth);
    }
    if (st == "arrived") {
        return "【商隊抵關】金石商會大宗馱隊已順利進抵南關車馬大院，六縣專材開庫盤點，市面流通暫緩緊俏。";
    }
    return "【商隊跋涉】金石商會重載商隊大車正自南嶺官道向府城行進，預計三日內進關。";
}

// ── 3. 取得天時與氣候警訊 ───────────────────────────────────
string query_weather_rumor() {
    object nat_d = find_object("/secure/nature_d.c");
    if (!nat_d) nat_d = load_object("/secure/nature_d.c");
    if (!nat_d) return "近來天象平緩，日月循序。";

    string w_name = nat_d->query_weather_name();
    string s_name = nat_d->query_season_name();
    string yr_name = nat_d->query_year_season_title();

    if (nat_d->query_weather() == "storm") {
        return sprintf("【天候預警】如今正值%s（%s），窗外狂風驟雨大作，各處山路恐有滑坡泥石之虞！", yr_name, s_name);
    }
    if (nat_d->query_weather() == "snowy") {
        return sprintf("【天候預警】%s寒氣逼人，北塞天風谷碎雪紛飛，重車棧道恐將結冰封關！", s_name);
    }
    return sprintf("【天時時憲】時維%s，四序輪元運轉不休，正是「%s」之景。", yr_name, w_name);
}

// ── 4. 取得城邦法紀告示 ─────────────────────────────────────
string query_city_law_rumor() {
    return "【城防告示】金石府四關嚴格查驗路引憑證。外縣無照者入城須於七十二小時內取得學塾、醫館或車馬大院保書，否則將列為無籍流民驅逐！內城嚴禁私鬥與未經度牒私借法印！";
}

// ── 4b. 取得民間平凡生活瑣事與市井煙火傳聞 ────────────────────
string query_slice_of_life_rumor() {
    string *folk = ({
        "【街巷閒談】黑石鋪村尾蒙館的宋秀才最近總算托貨郎胡二賒來了松煙墨，幾個山村娃兒正搶著在沙盤上描字呢。",
        "【碼頭市井】外城河埠魚市的劉三娘一早又把賣剩的小雜魚半賣半送給南關外流民矮巷，熬魚湯的香氣飄了半條街。",
        "【南市酒肆】金石城南老酒肆裡跑商陳大牙昨晚喝高了，又在吹噓盤木縣的熟革跟烈礬縣的耐火泥一轉手能翻幾成利。",
        "【雲津河畔】冰河碼頭這幾日搶在徹底封凍前加緊扛木，苦力們拿著竹籌在算帳棚核帳，就怕包頭少算兩趟工錢。",
        "【北荒寒風】聽黑山北關的戍卒說，牧戶烏蘭家有頭獨角黃羊受驚跑丟了，這大冷天的也不知找回來沒有。",
        "【青河渡口】蘆花渡的挑夫一早就為了昨日那趟藥簍少算兩文錢跟管事吵起來，柳伯邊補船底邊勸他們等午船開了再算。"
    });
    return folk[random(sizeof(folk))];
}

// ── 4c. 取得因果經濟波動解釋傳聞（讓玩家聽懂為何漲價）────────────
string query_causal_economy_rumor() {
    object ws_d = find_object(WORLD_STATE_D);
    if (!ws_d) ws_d = load_object(WORLD_STATE_D);
    if (!ws_d) return "近來六縣山貨入城平穩，米炭雜貨價碼尚稱公道。";

    mapping active_ev = ws_d->query_active_causal_events();
    if (mapp(active_ev) && sizeof(active_ev) > 0) {
        string *ev_keys = keys(active_ev);
        string pick = ev_keys[random(sizeof(ev_keys))];
        mapping ev = active_ev[pick];
        if (mapp(ev)) {
            if (pick == "landslide_rain") {
                return "【山道行情】聽南嶺腳夫說，山路連日暴雨滑坡砸斷了半幅棧道，盤木原木與符紙車隊進不了城，長街木料應聲漲價兩成半！";
            }
            if (pick == "mine_shutdown") {
                return "【礦工停工】北崖與烈礬幾口深井塌方停採，下工的礦工沒活可做全擠在粗茶棚裡喝苦茶嘆氣，條石明礬價碼立刻水漲船高！";
            }
            if (pick == "river_surge_sluice") {
                return "【水運告急】上游水閘攔水外加河水暴漲，青河平底駁船在九曲淺灘擱了兩艘，府城米糧與草藥馬上跟著緊俏！";
            }
            if (pick == "gate_tax_lockdown") {
                return "【關卡風聲】四關守軍最近又把路引稅卡收緊了！正經貨車多繳過關錢，沒路引的流民只能窩在南關外土坯巷接散活，暗渠私貨倒是旺了起來！";
            }
            if (pick == "northern_cold_snap") {
                return "【冬寒急報】北荒寒潮南壓下來了！南市鋪子裡的鎮風生羊皮襖、黑石鋪硬木炭跟濁水老薑湯三天不到就被搶貴了三四成！";
            }
            return sprintf("【因果行情】%s：%s。", ev["name"], ev["source"]);
        }
    }

    object nat_d = find_object("/secure/nature_d.c");
    if (nat_d && nat_d->query_season() == "winter") {
        return "【歲暮寒冬】如今正值玄冥冬歲，木炭、羊皮襖與老薑湯比平日俏手了兩成，大車過北關也要多備防寒草料。";
    }
    return "【市井行情】這幾日六縣水陸運道尚算通暢，粗茶糙米與柴炭價錢還守在常平線內。";
}

// ── 5. 匯整當前全域所有傳聞清單 ─────────────────────────────
string *query_all_rumors() {
    string *list = ({});
    string *counties = ({ "panmu", "zhongshi", "qinghe", "zhenfeng", "liefan", "zhuoshui", "blackstone" });
    foreach (string cid in counties) {
        list += ({ query_county_rumor(cid) });
    }
    list += ({ query_caravan_rumor() });
    list += ({ query_weather_rumor() });
    list += ({ query_city_law_rumor() });
    list += ({ query_slice_of_life_rumor() });
    list += ({ query_causal_economy_rumor() });
    return list;
}

// ── 5b. Phase 3：深化生活語氣分層（庶民誤解絮語 vs 跑商／老匠實務判斷）──
mapping query_tiered_folk_rumor(string persona, string topic) {
    string *topics = ({ "flood_sluice", "mine_stop", "cold_wave", "road_block" });
    if (!topic || topic == "" || topic == "general") {
        topic = topics[random(sizeof(topics))];
    }
    if (!persona || (persona != "peasant_boatman" && persona != "merchant_artisan")) {
        persona = "peasant_boatman";
    }

    string msg_peasant = "";
    string msg_merchant = "";

    if (topic == "flood_sluice") {
        msg_peasant = "【渡口絮語・船婦農話】「哎呀，定是上游有人得罪了青河老龍王！好端端的太陽天，昨夜水頭竟落下去半丈，定是神明收水不準撐船哩！」";
        msg_merchant = "【商行實判・老船牙子】「別聽婦人家胡扯鬼神！是上游定神道觀私放攔水閘濾靈砂，截住六成來水；平底駁船載重減半才把過河費頂漲兩文，此刻府城洗靈草與米糧必缺！」";
    } else if (topic == "mine_stop") {
        msg_peasant = "【礦棚閒談・苦力村言】「聽說北崖與銅駝嶺三號井挖到山龍脊骨，裡頭冒出鬼火哭聲才塌的！咱們老實人不敢再下井觸霉頭啦。」";
        msg_merchant = "【匠商精算・老匠與跑商】「什麼山龍脊骨，分明是分坊貪利抽薄了鐵木支撐又亂放過量雷管！三號井一旦停工兩個月，烈礬明礬和重石生鐵在府城定要大漲三成！」";
    } else if (topic == "cold_wave") {
        msg_peasant = "【北境村謠・牧婦低語】「老輩人講，這風雪這麼早撲下來是星宿變臉要凍死牛羊了，快多燒兩柱香拜拜老天爺賞口熱飯吃。」";
        msg_merchant = "【北荒走商實務】「玄冥冬歲頭陣寒潮壓境，北塞天風谷積雪一封道，雲津與北荒最缺鎮風生羊皮襖與黑石硬木炭！此刻從黑石鋪或鎮風縣趕運過去，淨利少說四成！」";
    } else {
        msg_peasant = "【街巷猜疑・路邊攤販】「南嶺半山腰昨兒落了幾塊天雷石，聽說是有大妖在山口搶糧草，過幾天官老爺怕是要封城不許進人囉！」";
        msg_merchant = "【牙行底帳判斷】「哪有大妖搶糧，是雨後邊坡滑坡壓了半條盤木車道，加上關卡守軍趁機卡住保書路引想抽三成乾股！盤木原木進不了城，手裡有貨別急著賤賣。」";
    }

    return ([
        "topic": topic,
        "persona": persona,
        "peasant_boatman": msg_peasant,
        "merchant_artisan": msg_merchant,
        "msg": (persona == "merchant_artisan") ? msg_merchant : msg_peasant
    ]);
}

string query_persona_rumor(string persona, string topic) {
    mapping d = query_tiered_folk_rumor(persona, topic);
    return d["msg"];
}

// ── 5c. Phase 3B：六維結構化資訊品質與五方交叉查證（thinking.md 規範）──
// 每則傳聞皆具備：source, event_id, credibility(0~100), region, timestamp, is_stale(0/1)
mapping *query_cross_check_rumors(string event_id) {
    if (!event_id || event_id == "") event_id = "mine_shutdown";
    object ws = find_object(WORLD_STATE_D);
    if (!ws) ws = load_object(WORLD_STATE_D);
    object nat = find_object("/secure/nature_d.c");
    int now_gt = nat ? nat->query_game_time() : 300;

    int ev_active = 1;
    if (ws) {
        if (event_id == "mine_shutdown") ev_active = ws->is_mine_economy_halted();
        else if (event_id == "cold_wave" || event_id == "northern_cold_snap") ev_active = ws->is_causal_event_active("northern_cold_snap");
        else if (event_id == "river_surge_sluice") ev_active = ws->is_causal_event_active("river_surge_sluice");
    }
    int stale_flag = ev_active ? 0 : 1;

    if (event_id == "cold_wave" || event_id == "northern_cold_snap") {
        return ({
            ([
                "source": "鎮風牧戶", "event_id": "northern_cold_snap",
                "credibility": 60, "region": "zhenfeng", "timestamp": now_gt - 15,
                "is_stale": stale_flag,
                "text": "聽說北山風神發威，這批羊毛還沒剪下來就凍硬了，老牧主也不肯賤賣皮子。"
            ]),
            ([
                "source": "金石茶館跑商", "event_id": "northern_cold_snap",
                "credibility": 88, "region": "city", "timestamp": now_gt - 5,
                "is_stale": stale_flag,
                "text": "北荒寒潮南壓造成鎮風生羊皮襖與黑石木炭雙雙緊缺！金石與雲津商棧已調高收購價，有貨趕緊運進來。"
            ]),
            ([
                "source": "雲津把頭", "event_id": "northern_cold_snap",
                "credibility": 82, "region": "yunjin", "timestamp": now_gt - 10,
                "is_stale": stale_flag,
                "text": "冰河渡船快結死冰了，城裡羊皮襖跟硬木炭庫存見底，過兩天價錢只會再高。"
            ]),
            ([
                "source": "邊關防卒", "event_id": "northern_cold_snap",
                "credibility": 70, "region": "zhenfeng", "timestamp": now_gt - 20,
                "is_stale": stale_flag,
                "text": "天風谷積雪壓壞半截棧道，無正式路引的私貨車隊過關口多半會被補抽兩成寒冬路稅。"
            ]),
            ([
                "source": "街巷閒婦", "event_id": "northern_cold_snap",
                "credibility": 35, "region": "city", "timestamp": now_gt - 30,
                "is_stale": stale_flag,
                "text": "聽說是雲津有人挖出冰棺才惹來大雪，明天所有皮衣都要封市不賣啦！"
            ])
        });
    }

    if (event_id == "river_surge_sluice") {
        return ({
            ([
                "source": "青河藥婦", "event_id": "river_surge_sluice",
                "credibility": 55, "region": "qinghe", "timestamp": now_gt - 12,
                "is_stale": stale_flag,
                "text": "洗靈草晒場進了水，大家都傳是龍王生氣把上游水路封住了。"
            ]),
            ([
                "source": "老船工柳伯", "event_id": "river_surge_sluice",
                "credibility": 85, "region": "qinghe", "timestamp": now_gt - 6,
                "is_stale": stale_flag,
                "text": "不是龍王，是定神道觀上頭水閘放水太急沖淺了九曲灘，平底藥船載重減半、運費自然翻倍。"
            ]),
            ([
                "source": "丹鼎採辦執事", "event_id": "river_surge_sluice",
                "credibility": 90, "region": "danding", "timestamp": now_gt - 4,
                "is_stale": stale_flag,
                "text": "青河洗靈草庫存不足，我們丹鼎堂已改發急單向盤木與雲津高價收購替代靈草。"
            ])
        });
    }

    // 預設：mine_shutdown（精確對齊 thinking.md 烈礬礦場停工五方口徑）
    return ({
        ([
            "source": "礦工家屬", "event_id": "mine_shutdown",
            "credibility": 45, "region": "liefan", "timestamp": now_gt - 25,
            "is_stale": stale_flag,
            "text": "聽說礦場大掌櫃發不出工錢偷偷躲起來了，這個月家裡的米缸都要見底！"
        ]),
        ([
            "source": "茶棚老闆", "event_id": "mine_shutdown",
            "credibility": 65, "region": "liefan", "timestamp": now_gt - 15,
            "is_stale": stale_flag,
            "text": "最近來買炭喝湯的人少了一大半，礦工兜裡沒錢連兩文甘草茶都捨不得多點。"
        ]),
        ([
            "source": "井下礦工", "event_id": "mine_shutdown",
            "credibility": 90, "region": "liefan", "timestamp": now_gt - 8,
            "is_stale": stale_flag,
            "text": "不是單純欠餉！是深井岩壁裂開又竄毒煙，礦坑出了實打實的結構問題才被迫停工。"
        ]),
        ([
            "source": "跨區跑商", "event_id": "mine_shutdown",
            "credibility": 85, "region": "city", "timestamp": now_gt - 5,
            "is_stale": stale_flag,
            "text": "烈礬礬貨與重石鐵料供應一斷，其他地方庫存很快吃緊，十天內府城收購價必漲三成！"
        ]),
        ([
            "source": "縣衙官差", "event_id": "mine_shutdown",
            "credibility": 55, "region": "liefan", "timestamp": now_gt - 18,
            "is_stale": stale_flag,
            "text": "奉官府諭令礦場暫停作業等候勘驗，一切井然有序，閑雜人等切莫聽信謠言。"
        ])
    });
}

mapping query_structured_rumor(string event_id, string source_filter) {
    mapping *all = query_cross_check_rumors(event_id);
    if (!sizeof(all)) return ([]);
    if (source_filter && source_filter != "") {
        foreach (mapping r in all) {
            if (r["source"] == source_filter) return r;
        }
    }
    return all[random(sizeof(all))];
}

// ── 6. 隨機取得一條傳聞（支援主題關鍵字篩選）─────────────────
string query_random_rumor(string topic) {
    if (topic && topic != "") {
        if (topic == "盤木" || topic == "panmu") return query_county_rumor("panmu");
        if (topic == "重石" || topic == "zhongshi") return query_county_rumor("zhongshi");
        if (topic == "青河" || topic == "qinghe") return query_county_rumor("qinghe");
        if (topic == "鎮風" || topic == "zhenfeng") return query_county_rumor("zhenfeng");
        if (topic == "烈礬" || topic == "liefan") return query_county_rumor("liefan");
        if (topic == "濁水" || topic == "zhuoshui") return query_county_rumor("zhuoshui");
        if (topic == "黑石鋪" || topic == "blackstone") return query_county_rumor("blackstone");
        if (strsrch(topic, "商隊") != -1 || strsrch(topic, "馱隊") != -1) return query_caravan_rumor();
        if (strsrch(topic, "天氣") != -1 || strsrch(topic, "天候") != -1) return query_weather_rumor();
        if (strsrch(topic, "法令") != -1 || strsrch(topic, "居留") != -1) return query_city_law_rumor();
    }

    string *all = query_all_rumors();
    if (!sizeof(all)) return "市井喧騰，各方客商交頭接耳，尚未有定論。";
    return all[random(sizeof(all))];
}

// ── 7. 定時廣播市井絮語與更夫報時 ─────────────────────────────
void tick(int game_time) {
    // 每 60 遊戲分鐘 (現實 15 分鐘) 在主要公共通衢廣播一次市井氣息
    if (game_time - last_broadcast < 60) return;
    last_broadcast = game_time;

    object nat_d = find_object("/secure/nature_d.c");
    if (!nat_d) nat_d = load_object("/secure/nature_d.c");
    string shichen = nat_d ? nat_d->query_shichen_full() : "辰時";

    string *broadcast_rooms = ({
        "/d/city/center/square.c",
        "/d/city/center/inn_main.c",
        "/d/city/south/market_special.c",
        "/d/city/gate/gate_south.c",
        "/d/village/square.c"
    });

    string rumor = query_random_rumor(0);
    string pulse_msg = sprintf(
        "\n" WHT "【更夫報曉・市井風聲】更夫敲著梆子高聲唱道：「天乾物燥，當心火燭！如今正是 %s 哩——」" NOR "\n"
        CYN "茶攤客商附和私語道：「你可聽說了？%s」" NOR "\n",
        shichen, rumor
    );

    foreach (string r_path in broadcast_rooms) {
        object r = find_object(r_path);
        if (r) {
            tell_room(r, pulse_msg);
        }
    }
}

// ── 8. 傳聞衰減與市井扭曲機制 (Rumor Decay & Distortion vs Truth) ──
// 俗民經三次轉述後的傳聞往往將制度性腐敗扭曲為「山鬼作祟」或「流寇劫道」；
// 唯有乞兒身世 (beggar)、高感知 (per >= 25) 或已掌握實證者，能從市井雜訊中聽出幕後真相。
mapping query_distorted_rumor(string topic, object listener) {
    object ws_d = find_object(WORLD_STATE_D);
    if (!ws_d) ws_d = load_object(WORLD_STATE_D);

    string surface_hearsay = "";
    string hidden_truth = "";
    int distortion_hops = 3;

    if (!topic || topic == "" || topic == "caravan" || topic == "商隊") {
        string delay = ws_d ? ws_d->query_caravan_delay_reason() : "虎跳峽落石封路";
        string truth = ws_d ? ws_d->query_caravan_truth_reason() : "金石商會與黑石關巡防營暗中扣留物資哄抬市價";
        surface_hearsay = sprintf("【三手市井傳聞（失真度 70%%）】茶客繪聲繪影地說：「聽說南嶺山神發怒降下天雷巨石（%s），連山魈野鬼都出來吃人啦，大家快去搶購高價米糧！」", delay);
        hidden_truth = sprintf("【聽風破妄・幕後實情】你從茶客誇大其詞的傳聞裡剔除鬼神噱頭，精準捕捉到車夫隨口漏出的車轍印深淺——所謂天災封路純屬幌子，真相實為：%s！", truth);
    } else if (topic == "mine" || topic == "礦難" || topic == "blackstone") {
        surface_hearsay = "【三手市井傳聞（失真度 65%）】街頭巷尾都在傳：「黑石鋪北崖礦工挖斷了山龍地脈，惹怒了地底火煞才遭了天譴塌方！」";
        hidden_truth = "【聽風破妄・幕後實情】你冷笑一聲，從傳言裡的『悶雷三響』與『黃煙刺鼻』判斷：那絕非天然地脈塌方，而是城防司官禁連號雷管定向爆破封井！";
    } else if (topic == "credit" || topic == "通寶" || topic == "銀票") {
        surface_hearsay = "【三手市井傳聞（失真度 80%）】外城百姓慌亂傳言：「通寶當鋪的運銀大車在濁水澤被水鬼連人帶車拖進無底洞了，手裡的飛錢銀票全要變廢紙啦！」";
        hidden_truth = "【聽風破妄・幕後實情】你留意到南關重車入城時青石板被壓出的兩寸深印——十二萬兩現銀分明早已運入南城商會暗庫，所謂水鬼劫銀不過是錢百川凍結跨縣清算的苦肉計！";
    } else {
        string raw = query_random_rumor(topic);
        surface_hearsay = "【市井流言】" + raw;
        hidden_truth = "【底層脈絡】" + raw;
    }

    int can_discern = 0;
    if (listener) {
        if (listener->query("background") == "beggar") can_discern = 1;
        else if (listener->query_stat("per") >= 20 || listener->query("per") >= 20) can_discern = 1;
        else if (arrayp(listener->query_temp("presented_evidence_list")) && sizeof(listener->query_temp("presented_evidence_list")) > 0) can_discern = 1;
    }

    return ([
        "topic": topic ? topic : "caravan",
        "distortion_hops": distortion_hops,
        "surface_hearsay": surface_hearsay,
        "hidden_truth": hidden_truth,
        "can_discern_truth": can_discern,
        "display_msg": can_discern ? (surface_hearsay + "\n" + HIY + hidden_truth + NOR) : surface_hearsay
    ]);
}
