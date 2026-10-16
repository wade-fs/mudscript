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
    return 1;
}

int do_search(string arg) {
    object me = this_player();

    if (!arg || (arg != "pine" && arg != "tree" && arg != "root" && arg != "老松" && arg != "樹根" && arg != "松針")) {
        write("你想在孤岩殘壇的哪裡仔細搜查？提示：search pine（撥開老松盤根與枯松針）\n");
        return 1;
    }

    if (me->query("searched_altar_pine")) {
        write("你撥開枯松針，看著深陷於盤根之中的那兩具玉化人形晶骨，心中仍存餘悸，未再發現其他之物。\n");
        return 1;
    }

    write(CYN "你彎下腰，用手小心翼翼地撥開老松盤根錯節深處厚厚的枯黃松針與泥土……\n" NOR);
    write(HIW "枯松針散去，赫然露出兩尊盤膝對坐的人形軀體！\n"
              "他們身著太古道袍，肌膚鬚髮竟已徹底玉化成灰白色冷晶，毫無生機。\n"
              "老松粗壯的根系從晶化軀體的胸腔與眼眶穿刺而過，死寂而詭異！\n" NOR);
    write("你屏住呼吸，從其中一具遺骸胸口處取下一塊鬆動脫落的" + HIW "【道化晶石殘片】" NOR + "！\n");

    object crystal = clone_object("/clone/item/dao_crystal.c");
    if (crystal) {
        if (!crystal->move(me)) {
            crystal->move(this_object());
        }
    }
    me->set("searched_altar_pine", 1);
    me->add("exp", 50);
    return 1;
}

int do_stargaze(string arg) {
    object me = this_player();

    if (me->query(VITAL_KEE) < 20 || me->query(VITAL_SEN) < 25) {
        write(HIR "你氣血與神識消耗過劇，此時若強行以神識窺天，恐遭天道意志直接反噬致死！\n" NOR);
        return 1;
    }

    write(HIC "你盤膝端坐於白石殘壇之巔，微闔雙目，將眉心處的一縷純淨神識向著蒼穹緩緩探出……\n" NOR);
    write("那一瞬間，你的靈識彷彿脫離肉身桎梏，高懸於百丈天幕之上！\n");
    write("俯瞰大地，黑石鋪晨煙嫋嫋，南谷溪灘、東林獵寨與打鐵地爐的生機歷歷在目。\n");
    write(HIB "然而，當你的神識仰頭望向萬丈星空極致高處時——\n" NOR);
    write(HIW "周天二十八宿璀璨星光的背後，赫然密佈著一層浩瀚無邊、冰冷死寂的暗灰色網格！\n"
              "無數道粗大如實質的暗灰鎖鏈穿透群星，將周天星斗死死拘禁圈養！\n"
              "【天羅地網！星軌逆行，仙氣皆是毒餌！整座蒼穹竟是一座巨大活體牢籠！】\n" NOR);
    write(HIR "轟！一股恐怖絕倫的天道威壓如山崩海嘯般反噬而下！\n"
              "你神魂巨震，仰天噴出一口熱血，狼狽跌坐回殘壇！\n" NOR);

    me->add(VITAL_KEE, -15);
    me->add(VITAL_SEN, -20);

    if (!me->query("stargazed")) {
        me->set("stargazed", 1);
        me->add(STAT_INT, 2);
        me->add(STAT_SPI, 2);
        me->add("exp", 100);
        write(HIG "【你堪破蒼穹偽籠至暗真相，靈台受太古意志洗禮，悟性+2、靈性+2，獲得 100 點經驗！】\n" NOR);
    } else {
        write(YEL "你再次窺探天羅地網，道心更趨堅毅，深知撕破偽籠任重道遠。\n" NOR);
    }

    return 1;
}
