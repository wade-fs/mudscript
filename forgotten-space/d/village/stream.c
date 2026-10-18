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
        "south": "/d/village/falls.c",
        "down":  "/d/village/herb_hut.c",
    ]));

    set("is_outdoor", 1);
    set("can_gather_herb", 1);

    // 史前斷碑物象設定 (需天命覺醒 >= 2，或先以 sharpen 磨刀/山洪去除青苔石垢方能勘破)
    set_relic_target("stone");
    set_required_fate(2);
    set_required_int(2);
    set_inscription("太古天曆：逆行九宿，星軌反震，大清洗紀元始...");

    spawn_npc("/clone/npc/zhang_butcher.c");
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
            object nd = load_object("/secure/nature_d.c");
            int hour = nd ? nd->query_hour() : 7;
            string weather = nd ? nd->query_weather() : "clear";
            if ((hour >= 6 && hour <= 8) && weather == "clear") {
                res += HIY "其中一塊深青色石板 (stone) 表面的厚苔已被洗淨，朝陽正以極低角度斜射在微凹邊緣，投下淡淡的神秘光影 (look stone)！\n" NOR;
            } else {
                res += HIY "其中一塊深青色石板 (stone) 表面的厚重青苔已被沖淨，露出平整光滑、堅逾精鋼的墨黑石面 (look stone)。\n" NOR;
            }
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
    add_action("do_sharpen", "sharpen");
    add_action("do_sharpen", "磨刀");
    add_action("do_sharpen", "砥礪");
    add_action("do_wash", "wash");
    add_action("do_wash", "洗臉");
    add_action("do_wash", "洗滌");
    add_action("do_wash", "掬水");
}

int do_gather(string arg) {
    object me = this_player();
    int ret = load_object(WORLD_STATE_D)->gather_herb(me);
    if (ret) {
        object qe = find_object(QUEST_ENGINE_D);
        if (!qe) qe = load_object(QUEST_ENGINE_D);
        if (qe) {
            qe->trigger_event(me, "action", ([
                "verb": "gather",
                "target": "herb"
            ]));
        }
    }
    return ret;
}

int do_wash(string arg) {
    object me = this_player();
    object ws = load_object(WORLD_STATE_D);

    if (arg == "stone" || arg == "stele" || arg == "石板" || arg == "斷碑" || arg == "青苔") {
        if (ws && ws->is_stele_submerged()) {
            write(HIR "此刻正值山洪暴發，滔滔濁浪早已沒過溪石，無法蹲伏清洗！\n" NOR);
            return 1;
        }
        if (me->query(VITAL_SP) < 5) {
            write(HIR "你精疲力竭，雙手無力擦洗石板。\n" NOR);
            return 1;
        }
        me->add(VITAL_SP, -5);
        write("你掬起冰涼刺骨的深潭溪水，捲起衣袖用力擦洗深青色石板上的厚厚青苔與泥垢...\n");
        write(HIY "在水流沖洗與反覆擦拭下，石板表面的滑膩石垢被漸漸洗淨，露出了古怪凹凸的古老紋理！\n" NOR);
        me->set_temp("cleared_stele_moss", 1);
        object qe = find_object(QUEST_ENGINE_D);
        if (!qe) qe = load_object(QUEST_ENGINE_D);
        if (qe) {
            qe->trigger_event(me, "action", ([
                "verb": "wash",
                "target": "stone"
            ]));
        }
        return 1;
    }

    if (!me->consume_drink(25)) return 1;

    write("你俯下身，將雙手浸入冰涼刺骨的深潭溪水中，捧起一捧甘冽清泉拍在臉上並漱口痛飲...\n");
    write(CYN "清澈的水珠沿著面頰滑落，冰冷的水氣驅散了疲憊與濁氣，只覺精神一振，靈台空明！\n" NOR);

    me->add(VITAL_KEE, 15);
    me->add(VITAL_SEN, 25);
    me->add(VITAL_SP, 25);
    write(HIG "【溪泉洗滌，你的氣血 +15、神識 +25、精力 +25！】\n" NOR);

    object qe = find_object(QUEST_ENGINE_D);
    if (!qe) qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([
            "verb": "wash",
            "target": "face"
        ]));
    }

    object career = load_object(CAREER_D);
    if (career && career->query_chain_stage(me, "fa") == 2) {
        career->advance_chain_stage(me, "fa");
    }
    return 1;
}

int do_sharpen(string arg) {
    object me = this_player();
    object ws = load_object(WORLD_STATE_D);

    if (ws && ws->is_stele_submerged()) {
        write(HIR "此刻正值山洪暴發，滔滔濁浪早已沒過溪石，無法蹲伏磨刀！\n" NOR);
        return 1;
    }

    object weapon = me->query_temp("weapon");
    if (weapon && weapon->query("weapon_type") != "blade" && !weapon->id("blade") && !weapon->id("knife") && !weapon->id("柴刀") && !weapon->id("砍刀")) {
        weapon = 0;
    }
    if (!weapon && arg) {
        weapon = present(arg, me);
    }
    if (!weapon) {
        object *inv = all_inventory(me);
        foreach (object ob in inv) {
            if (ob->query("weapon_type") == "blade" || ob->id("blade") || ob->id("knife") || ob->id("柴刀") || ob->id("砍刀")) {
                weapon = ob;
                break;
            }
        }
    }

    if (!weapon) {
        write("你想在石板上磨什麼利刃？（請手持或指定刀刃，例如：sharpen blade）\n");
        return 1;
    }

    if (me->query(VITAL_SP) < 5) {
        write(HIR "你精疲力竭，雙臂發軟，連刀都拿不穩了。\n" NOR);
        return 1;
    }

    me->add(VITAL_SP, -5);

    write("你蹲在深青色洗衣石板旁，舀了一勺冰涼清澈的溪水澆在石面，\n"
          "雙手緊握" + weapon->query_short() + "，沉住呼吸，沙沙地在石板凹陷處來回磨礪...\n");

    if (weapon->id("rusty blade") || base_name(weapon) == "/clone/weapon/rusty_blade") {
        write(HIY "暗紅色的鐵鏽混合著灰白石屑化作濁泥流淌，被清澈急流瞬間沖刷殆盡！\n" NOR);
        write(HIW "【只見刀刃上的頑固鏽斑盡褪，露出了雪亮刺目的森森精鋼寒芒！】\n" NOR);
        weapon->set_name("鋼刃柴刀", ({ "sharpened blade", "blade", "chaidao", "柴刀" }));
        weapon->set_short(HIW "雪亮鋼刃柴刀" NOR);
        weapon->set_long("一把經過溪灘深青古石精細打磨的厚背柴刀。刃口鋒芒畢露，寒光閃爍，\n"
                         "揮動時破風之聲清脆，劈柴防獸銳不可當。\n");
        weapon->set("damage", 10);
    } else {
        write(HIC "刀刃與堅硬青石激烈摩擦，濺起點點微弱火星，刃口被磨得格外鋒利錚亮！\n" NOR);
    }

    me->set_temp("cleared_stele_moss", 1);
    if (ws && !ws->is_moss_cleared()) {
        ws->clear_stream_moss();
        write(HIR "\n【磨刀的劇烈震顫與石屑剝落，震落了厚厚石垢，露出了深青石板內部森嚴的古怪星紋凹槽！】\n" NOR);
        write(WHT "你隱約感覺到石面深處有一股極微弱的冷意刺痛了指尖，這絕非普通石板！\n" NOR);
    }

    write(HIG "【在沉穩有力的磨刀推拉中，你的臂力沉凝了幾分！】\n" NOR);
    me->train_stat(STAT_STR, 15);
    me->gain_exp(8);

    object qe = find_object(QUEST_ENGINE_D);
    if (!qe) qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([
            "verb": "sharpen",
            "target": "blade"
        ]));
    }

    object career = load_object(CAREER_D);
    if (career && (career->query_chain_stage(me, "li") == 2 || career->query_chain_stage(me, "li") == 3)) {
        career->advance_chain_stage(me, "li");
    }
    return 1;
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
    write(HIG "【在極端水壓的沖刷淬鍊下，你的筋骨發出沉悶雷音，根骨得到了磨礪！】\n" NOR);
    me->train_stat(STAT_CON, gain * 25);
    me->gain_exp(gain * 12);
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
    int ret = ::do_tuoyin(arg);
    if (ret) {
        object career = load_object(CAREER_D);
        if (career && career->query_chain_stage(this_player(), "fa") == 2) {
            career->advance_chain_stage(this_player(), "fa");
        }
    }
    return ret;
}

string look_at_item(string id) {
    if (id == "stone" || id == "stele" || id == "石板" || id == "斷碑") {
        object ws = load_object(WORLD_STATE_D);
        if (ws && ws->is_stele_submerged()) {
            return HIR "此刻正逢山洪暴漲，滔滔濁浪早已沒過溪石，石板完全沉在水底！\n" NOR;
        }

        object nd = load_object("/secure/nature_d.c");
        int hour = nd ? nd->query_hour() : 7;
        string weather = nd ? nd->query_weather() : "clear";
        int moss_cleared = (ws && ws->is_moss_cleared()) || this_player()->query_temp("cleared_stele_moss");

        string desc = "這是一塊斜臥在深潭溪灘邊緣的深青色玄黑石板。\n"
                      "千百年來，村婦在上面以木槌捶洗衣物，屠夫與獵戶也常用柴刀在邊緣研磨。\n";

        if (!moss_cleared) {
            desc += "石板表面覆蓋著一層滑膩厚重的青苔與老垢，凡人肉眼只當是一塊尋常洗衣頑石。\n"
                    "（提示：可以 wash 清洗或 sharpen 磨刀震碎石面厚垢）\n";
            return desc;
        }

        desc += HIG "石板表面的厚重青苔與沉積石垢已經被滌蕩震碎，露出了平整光滑、堅逾精鋼的墨色石胎。\n" NOR;

        int is_morning_grazing_light = (hour >= 6 && hour <= 8) && (weather == "clear");

        if (is_morning_grazing_light) {
            string shichen = nd ? nd->query_shichen_name() : "辰時";
            desc += HIY "\n【晨光側影・萬古奇遇】\n" NOR;
            desc += YEL "此刻破曉晨曦破空，天地正逢【" + shichen + "】！一輪赤金旭日剛翻過東山絕壁！\n"
                        "極低角度的金紅晨光以不到十五度的掠射角貼地橫掃而過。\n"
                        "石面上那些被無盡歲月磨蝕到不足微米、撫之如鏡的極淺凹槽，在背光一側拉扯出了無數針尖般細微深沉的陰影！\n"
                        "就如同深空之中唯有在特定日光斜射角度下方才於丘陵陰影中拼出冷峻面孔的「火星人面像」一般——\n"
                        "微薄水膜折射著晨曦，千萬道灰階陰影在原本光潔無奇的石板上精密咬合，赫然浮現出一幅龐大浩瀚的遠古逆向星圖！\n" NOR;
            desc += WHT "（隨著朝陽漸升，光角一旦變大，這幅光影星圖將轉瞬即逝！可把握時機 study 參悟 或 tuoyin 拓印）\n" NOR;
        } else if (hour >= 11 && hour <= 14) {
            desc += WHT "此刻日照當空，強烈的天光直射而下，石面平滑光潔如鏡，凹槽幾無陰影，肉眼看去只是一塊墨黑頑石。\n"
                        "（太古刻痕早已被江河磨平至微毫，唯有在破曉清晨旭日貼地斜射時，方能借微雕陰影窺見端倪）\n" NOR;
        } else {
            desc += CYN "石板在水光下呈現出深沉墨色，撫之平滑冰涼。太古深刻歷經億萬年沖刷磨礪，肉眼直視難以成象，\n"
                        "唯有在每日「元辰、亨辰、利辰、貞辰」旭日初升、極低角度斜射在石槽背光面時，方能如火星人面像般借由光影浮現真容。\n" NOR;
        }

        return desc;
    }

    return ::look_at_item(id);
}

