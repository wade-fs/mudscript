// d/village/stream.c
// 黑石鋪・南面幽霧水谷與碎石古溪 (自然採藥、瀑布淬體與史前斷碑)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit RUIN_ROOM_OB;

void create() {
    ::create();
    set_short("幽霧水谷・碎石溪灘");
    set_long("山澗自崖頂轟鳴墜落，在此匯聚成一汪清冽深潭。長年不散的濕冷水霧如白\n"
             "紗般籠罩著兩岸茂密的荊棘灌木。溪灘邊遍佈著被水流沖刷圓潤的大小卵石，\n"
             "幾塊平整的巨大石板斜臥在水邊，上面放著婦人搥洗衣物用的木槌與皂角，\n"
             "屠夫與老獵戶也常把柴刀在石邊擦磨。\n"
             "其中一塊半浸在水中的深青色石板 (stone)，表面生滿了厚厚青苔。\n"
             "瀑布深潭水氣澎湃，是聚落漢子跳入水中鍛鍊肉身耐力的天然之所。\n"
             "崖壁凹槽處垂著幾根粗壯麻藤，順著藤蔓向下可攀入一間隱蔽的採藥草廬 (down)。\n");

    set_exits(([
        "north": "/d/village/square.c",
        "down":  "/d/village/herb_hut.c",
    ]));

    set("is_outdoor", 1);
    set("can_gather_herb", 1);

    // 史前斷碑物象設定
    set_relic_target("stone");
    set_required_fate(1);
    set_required_int(2);
    set_inscription("太古天曆：逆行九宿，星軌反震，大清洗紀元始...");
}

string query_long() {
    object ws = load_object(WORLD_STATE_D);
    string res = "山澗自崖頂轟鳴墜落，在此匯聚成一汪深潭。長年不散的濕冷水霧如白\n"
                 "紗般籠罩著兩岸茂密的荊棘灌木。溪灘邊遍佈著被水流沖刷圓潤的大小卵石。\n";

    if (ws) {
        int wl = ws->query_stream_water_level();
        if (wl >= 85) {
            res += HIR "此刻正逢山洪暴發！濁黃滔天的狂暴巨浪轟鳴席捲，幾乎淹沒了整片淺灘，\n"
                       "原本斜臥水邊的大石板已被滔滔濁流徹底沒過頂部，難辨痕跡！\n" NOR;
        } else if (wl >= 70) {
            res += HIB "此刻正處豐水期，潭水深邃碧綠，雪白浪花激烈拍打著岸邊大石，水流十分湍急。\n" NOR;
        } else if (wl <= 30) {
            res += CYN "此刻正值枯水清淺期，潭水清澈見底，幾塊巨大的平整青石完全露出水面。\n" NOR;
        } else {
            res += "幾塊平整的巨大石板斜臥在水邊，上面放著婦人搥洗衣物用的木槌與皂角。\n";
        }

        if (ws->is_moss_cleared() && wl < 85) {
            res += HIY "其中一塊深青色石板 (stone) 表面的厚重青苔已被洪水急流沖淨，露出了古怪凹凸的古老紋理。\n" NOR;
        } else if (wl < 85) {
            res += "其中一塊半浸在水中的深青色石板 (stone)，表面生滿了厚厚青苔。\n";
        }

        int herbs = ws->query_herb_stock();
        if (herbs > 5) {
            res += HIG "兩岸濕潤的灌木草叢間，幾叢青翠藥草生機勃勃，正散發著淡淡草木香氣 (gather)。\n" NOR;
        } else if (herbs > 0) {
            res += "石縫草叢裡零星生長著幾株尚可入藥的野生草苗 (gather)。\n";
        } else {
            res += WHT "兩岸泥濘中留有前人剛採擷過的痕跡，成熟草藥已被採空，只餘幼苗破土。\n" NOR;
        }
    }

    res += "瀑布深潭水氣澎湃，是聚落漢子跳入水中鍛鍊肉身耐力的天然之所 (waterfall)。\n"
           "崖壁凹槽處垂著幾根粗壯麻藤，順著藤蔓向下可攀入一間隱蔽的採藥草廬 (down)。\n";
    return res;
}

void init() {
    ::init();
    add_action("do_waterfall", "waterfall");
    add_action("do_waterfall", "沖瀑布");
    add_action("do_waterfall", "淬體");
    add_action("do_gather", "gather");
    add_action("do_gather", "採藥");
    add_action("do_gather", "採集");
}

int do_gather(string arg) {
    return load_object(WORLD_STATE_D)->gather_herb(this_player());
}

int do_waterfall(string arg) {
    object me = this_player();
    object ws = load_object(WORLD_STATE_D);
    int wl = ws ? ws->query_stream_water_level() : 50;

    int cost = 20;
    int gain = 1;

    if (wl >= 85) {
        cost = 35;
        gain = 2; // 洪水暴漲期硬扛，根骨收益翻倍！
    } else if (wl <= 30) {
        cost = 10;
        gain = 1;
    }

    if (me->query(VITAL_KEE) < cost + 10) {
        write(HIR "此刻水勢洶湧，你氣血虛弱、面無血色，若貿然跳入千鈞水流，恐有性命之憂！\n" NOR);
        return 1;
    }

    if (wl >= 85) {
        write(HIR "暴雨山洪化作一條狂暴黃龍，千鈞重力瘋狂轟在你的脊背與胸膛上！\n" NOR);
        write("你眼前發黑，骨骼咯咯作響，憑藉驚人意志硬生生在狂暴激流中站穩腳跟！\n");
    } else {
        write(HIB "你褪去上衣，毅然縱身躍入深潭巨石之上，任由千鈞瀑布狠狠砸在脊背上！\n" NOR);
        write("冰冷刺骨的水流如同無數鐵錘重擊，你咬緊牙關，體內氣血劇烈奔湧抗衡！\n");
    }

    me->add(VITAL_KEE, -cost);
    me->add(STAT_CON, gain);

    write(HIG "【在極端水壓的沖刷淬鍊下，你的筋骨發出沉悶雷音，根骨提升了 " + gain + " 點！】\n" NOR);
    return 1;
}

// 覆寫 study，增加水位阻擋與青苔沖刷檢定
int do_study_ruin(string arg) {
    object ws = load_object(WORLD_STATE_D);
    if (ws && ws->is_stele_submerged()) {
        write(HIR "此刻正值山洪暴發，滔滔濁浪早已沒過溪石，看不清原本的石板蹤跡，強行涉水恐被急流捲走！\n" NOR);
        return 1;
    }
    return ::do_study_ruin(arg);
}

int do_tuoyin(string arg) {
    object ws = load_object(WORLD_STATE_D);
    if (ws && ws->is_stele_submerged()) {
        write(HIR "石板完全沉沒在洶湧濁流之中，無法進行拓印！\n" NOR);
        return 1;
    }
    return ::do_tuoyin(arg);
}
