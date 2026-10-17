// d/village/altar.c
// 黑石鋪・西面迎風孤岩與荒廢道壇 (觀星望氣、心神吐納與法道啟蒙)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("迎風孤岩・荒廢道壇");
    set_long("順著陡峭狹窄的石梯登上聚落西面突兀危岩，視野豁然開朗。此處高出地面\n"
             "數十丈，山巔罡風呼嘯凜冽，將衣袍吹得獵獵作響。崖頂中央坐落著半座坍\n"
             "塌的白石法壇，壇面雕刻著早已辨認不清的陰陽卦紋，一株盤根錯節的老松\n"
             "迎風挺立在萬丈深淵之畔。遠離了凡間市井牲畜的煙火騷氣，唯有蒼茫天宇\n"
             "與流轉星漢相伴。順著狹窄石階向下 (down)，可回到山腰的三清偏殿。\n"
             "（可在此打坐 meditate、仰觀天象 stargaze/觀星，或探尋老松盤根 search pine）\n");

    set_exits(([
        "down": "/d/village/daoist_temple.c",
        "east": "/d/village/daoist_temple.c",
    ]));

    set("is_outdoor", 1);
}

void init() {
    ::init();
    add_action("do_meditate", "meditate");
    add_action("do_meditate", "打坐");
    add_action("do_meditate", "觀想");
    add_action("do_search", "search");
    add_action("do_search", "搜查");
    add_action("do_stargaze", "stargaze");
    add_action("do_stargaze", "觀星");
    add_action("do_stargaze", "望氣");
}

int do_meditate(string arg) {
    object me = this_player();

    if (me->query(VITAL_KEE) < 10) {
        write(HIR "你肉身極度疲憊，無法抵禦山巔刺骨寒風，靜不下心來打坐。\n" NOR);
        return 1;
    }

    write(HIC "你在白石殘壇上盤膝而坐，微闔雙目，迎著呼嘯山風緩緩吐納...\n" NOR);
    write("四周喧囂漸遠，你的心神彷彿化作一縷微風，感應著蒼穹之上的日月星光運轉。\n");

    me->add(VITAL_KEE, -5);
    me->add(VITAL_SEN, 15);

    write(HIG "【靈台漸入空明，神識得到滋養，你的靈性微幅提升！】\n" NOR);
    me->train_stat(STAT_SPI, 25);
    me->gain_exp(10);

    string f_sid = me->query("enabled_force");
    if (f_sid && me->query_skill(f_sid) > 0) {
        me->improve_skill(f_sid, 10 + me->query_stat("int") / 2);
    }

    object career = load_object(CAREER_D);
    if (career && career->query_chain_stage(me, "fa") == 3) {
        career->advance_chain_stage(me, "fa");
    }
    return 1;
}

int do_search(string arg) {
    object me = this_player();
    object md = load_object(MYSTERY_D);

    if (!arg || (arg != "pine" && arg != "tree" && arg != "root" && arg != "老松" && arg != "樹根" && arg != "松針")) {
        write("你想在孤岩殘壇的哪裡仔細搜查？提示：search pine（撥開老松盤根與枯松針）\n");
        return 1;
    }

    if (md && md->is_relic_discovered(me, "search_altar_pine")) {
        write("你撥開枯松針，看著深陷於盤根之中的那兩具玉化人形晶骨，心中仍存餘悸，未再發現其他之物。\n");
        return 1;
    }

    // 身世血統排他性檢定 (非道童身世無法察覺死霜異常與共鳴)
    if (md && !md->can_discover_relic(me, "search_altar_pine")) {
        write(CYN "你彎下腰撥了撥老松盤根處的枯松針與泥土，只見粗黑的主根如生鐵般深深扎進岩縫，覆著厚厚凍雪。\n" NOR);
        write(WHT "山巔罡風刺骨，你受限於凡俗常人靈覺，並未察覺出任何異樣。（身世血脈未通無垢靈台）\n" NOR);
        return 1;
    }

    write(CYN "你微闔雙目，憑藉太虛無垢靈台敏銳察覺到老松向陰最深處的三條主根表面，落雪竟化作了細碎的「死寂之霜」！\n" NOR);
    write(YEL "你以無垢神識逆探而入，小心翼翼地撥開深陷岩縫厚達兩尺的陳年枯黃松針與腐土……\n" NOR);
    write(HIW "黑泥翻飛間，兩具盤膝對坐、栩栩如生的道家真人身軀赫然顯露！\n"
              "他們身著太古紫綬道袍，然而每一寸骨骼經絡早已經不再是血肉凡胎，徹底玉化為泛著死寂灰白微光的奇異冷晶！\n"
              "老松粗黑如鐵的根系直接貫穿了他們的胸腔與眼眶，將晶化真人當作汲取生機的肥料！\n" NOR);
    write("你強忍神魂被死氣吸附的劇痛，從其中一具遺骸胸口處取下一塊鬆動脫落的" + HIW "【道化晶石殘片】" NOR + "！\n");

    if (md) {
        md->trigger_relic_discovery(me, "search_altar_pine", me);
    }
    return 1;
}

int do_stargaze(string arg) {
    object me = this_player();

    if (me->query(VITAL_KEE) < 20 || me->query(VITAL_SEN) < 25) {
        write(HIR "你氣血與神識消耗過劇，此時若強行以神識窺天，恐遭天道意志直接反噬致死！\n" NOR);
        return 1;
    }

    object ws = load_object(WORLD_STATE_D);
    object md = load_object(MYSTERY_D);

    // 身世血統排他性檢定
    if (md && !md->can_discover_relic(me, "stargaze_altar")) {
        write(CYN "你盤膝端坐於白石殘壇之上，抬頭仰觀蒼穹星河……\n" NOR);
        write(WHT "山巔罡風呼嘯凜冽，漫天星斗閃爍如常。你受限於凡俗肉眼凡胎，未能窺見雲層之後的太古天機。\n" NOR);
        return 1;
    }

    write(HIC "你盤膝端坐於白石殘壇之巔，雙手結子午印，將眉心處那一縷太虛無垢神識逆衝九霄、出神探天！\n" NOR);
    write("那一瞬間，你的靈識脫離肉身桎梏，高懸於數百丈天幕之上！\n");
    if (ws) {
        write(sprintf("俯瞰大地，黑石鋪一覽無遺：北崖礦脈穩定度 %d%%、南谷水情（%s）、東林地煞濃度 %d%%，\n"
                      "全村氣機流轉與地脈濁氣在你的神識映照下纖毫畢現。\n",
                      ws->query_mine_stability(), ws->query_water_level_desc(), ws->query_disha_activity()));
    } else {
        write("俯瞰大地，黑石鋪晨煙嫋嫋，南谷溪灘、東林獵寨與打鐵地爐的生機歷歷在目。\n");
    }
    write(HIB "然而，當你的無垢神識穿透蔚藍天幕、直視萬丈星空極致至高之處時——\n" NOR);
    write(HIW "【天穹至暗黑幕！】周天二十八宿璀璨星光的背後，赫然密佈著一層浩瀚無邊、冰冷死寂的暗灰色玄鐵羅網！\n"
              "無數條如山脈般的暗灰鎖鏈穿透星核，將周天星斗死死釘死圈養！鎖鏈汲取星魄化為細雨，灑向人間成為偽靈氣！\n"
              "【天羅地網！星軌逆行，仙氣皆是毒餌！整座蒼穹竟是一座巨大活體牢籠！道化即是定時收割！】\n" NOR);
    write(HIR "轟！僅僅因為直視囚天鐵網核心，一股恐怖絕倫的神罰因果威壓自九天逆流碾壓而下！\n"
              "你神魂巨震龜裂，仰天噴出一道猩紅黑血！手背皮表驟然泛起不可磨滅的【灰白道化冷晶斑】！\n" NOR);

    me->add(VITAL_KEE, -20);
    me->add(VITAL_SEN, -30);

    if (md && !md->is_relic_discovered(me, "stargaze_altar")) {
        me->add(STAT_INT, 2);
        me->add(STAT_SPI, 2);
        md->trigger_relic_discovery(me, "stargaze_altar", me);
        write(HIG "【你承受道化晶斑反噬代價，堪破蒼穹偽籠至暗真相，悟性+2、靈性+2，獲得 100 點經驗！】\n" NOR);
        write(HIY "【你膝前染血的經卷夾層中，隱隱顯露出一角太古青銅絲線交織的「逆星軌道殘紋」！】\n" NOR);
    } else {
        write(YEL "你再次窺探天羅地網，道心更趨堅毅，深知撕破偽籠任重道遠。\n" NOR);
    }

    object career = load_object(CAREER_D);
    if (career && career->query_chain_stage(me, "fa") == 3) {
        career->advance_chain_stage(me, "fa");
    }

    return 1;
}
