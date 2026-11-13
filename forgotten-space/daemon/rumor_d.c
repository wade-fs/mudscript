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
    return list;
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
