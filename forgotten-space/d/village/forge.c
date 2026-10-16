// d/village/forge.c
// 黑石鋪・老鐵匠鋪・打鐵爐房 (打鐵學徒出生地)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

int furnace_heat; // 爐火熱度

void create() {
    ::create();
    set_short("老鐵匠鋪・打鐵爐房");
    set_long("這是一間坐落於街市東側的粗獷打鐵工坊。粗大的巨木樑柱被炭煙熏得烏黑，\n"
             "屋角一人高的巨大牛皮風箱伴隨著拉動發出沉悶的呼哧喘息 (bellows)。\n"
             "中央炭火地爐中赤炎翻滾，地上散落著幾塊沉重的鐵砧 (anvil)、碎粗礦與盛\n"
             "滿黑褐色淬火水的石槽 (trough)。你從小在火星四濺與叮噹鐵鳴中長大，隨身\n"
             "那柄打鐵舊鐵錘已被握得溫熱錚亮。\n");

    set_exits(([
        "west": "/d/village/square.c",
    ]));

    set("is_outdoor", 0);
    set("has_forge", 1);
    furnace_heat = 50;

    add_item("bellows", "這是一具一人高的巨型牛皮風箱，連接著地爐底部的通風道。你可以用力拉動它 (bellows) 來鼓旺爐火。");
    add_item("風箱", "這是一具一人高的巨型牛皮風箱，連接著地爐底部的通風道。你可以用力拉動它 (bellows) 來鼓旺爐火。");
    add_item("anvil", "一塊重達數百斤的烏黑鐵砧，表面佈滿了長年累月千錘百鍊留下的凹痕。手持鐵錘時可在上面鍛打 (strike / forge)。");
    add_item("鐵砧", "一塊重達數百斤的烏黑鐵砧，表面佈滿了長年累月千錘百鍊留下的凹痕。手持鐵錘時可在上面鍛打 (strike / forge)。");
    add_item("trough", "一口整塊青石鑿成的長槽，裡頭盛滿了黑褐色的淬火井水，可以用來為燒紅的鐵胚淬火 (quench)。");
    add_item("石槽", "一口整塊青石鑿成的長槽，裡頭盛滿了黑褐色的淬火井水，可以用來為燒紅的鐵胚淬火 (quench)。");

    spawn_npc("/clone/npc/tie_smith.c");
    spawn_item("/clone/item/ore_chunk.c");
}

void init() {
    ::init();
    add_action("do_bellows", "bellows");
    add_action("do_bellows", "拉風箱");
    add_action("do_bellows", "風箱");
    add_action("do_strike", "strike");
    add_action("do_strike", "forge");
    add_action("do_strike", "打鐵");
    add_action("do_strike", "鍛造");
    add_action("do_strike", "敲礦");
    add_action("do_quench", "quench");
    add_action("do_quench", "淬火");
}

int do_bellows(string arg) {
    object me = this_player();
    if (me->query(VITAL_SP) < 10) {
        write(HIR "你雙臂酸軟脫力，拉不動這沉重的巨型牛皮風箱了。\n" NOR);
        return 1;
    }

    me->add(VITAL_SP, -10);
    furnace_heat += 20;
    if (furnace_heat > 150) furnace_heat = 150;

    write("你雙手握住牛皮風箱的巨木長柄，沉腰扎馬，大開大合地全力推拉！\n");
    write(HIY "狂風如怒濤般灌入地爐底部，炭火陡然暴亮，熾白的金焰如火龍翻滾！\n" NOR);

    me->add(STAT_STR, 1);
    me->add(STAT_CON, 1);
    write(HIG "【在與狂暴烈火與厚重風箱的對抗中，你的臂力與根骨得到了磨礪！】\n" NOR);
    return 1;
}

int do_strike(string arg) {
    object me = this_player();
    if (me->query(VITAL_SP) < 10) {
        write(HIR "你精疲力竭，手腕發抖，無法精準揮錘。\n" NOR);
        return 1;
    }

    // 檢查是否有鐵錘武器
    object hammer = me->query_temp("weapon");
    if (!hammer && arg) hammer = present(arg, me);
    if (!hammer) {
        object *inv = all_inventory(me);
        foreach (object ob in inv) {
            if (ob->query("weapon_type") == "hammer" || ob->id("smith hammer") || ob->id("hammer") || ob->id("鐵錘")) {
                hammer = ob;
                break;
            }
        }
    }

    if (!hammer) {
        write("打鐵鍛造需手持鐵錘，方能定胚淬礪！（例如：wield smith hammer 或指定鐵錘）\n");
        return 1;
    }

    me->add(VITAL_SP, -10);

    // 檢查身上或房間是否有粗鐵礦核
    object ore = present("ore chunk", me);
    if (!ore) ore = present("ore chunk", this_object());
    if (!ore) ore = present("ore", me);

    if (ore && ore->query("is_ore")) {
        write("你用長鐵鉗將" + ore->query_short() + "牢牢鉗在鐵砧上，右臂青筋暴起，高舉鐵錘！\n");
        write(HIY "「當——！！」一聲巨響震徹工坊，漫天火星如暴雨散落，粗糙的岩殼寸寸崩裂！\n" NOR);

        destruct(ore);

        // 35% 機率震裂出太古不融黑鐵，否則鍛造成大荒開山柴刀
        if (random(100) < 40) {
            write(HIR "【反震異變】只聽一聲清脆龍吟，錘面被一股極恐怖的金屬反震彈開！\n" NOR);
            write(HIB "岩石碎殼深處，赫然露出一截通體烏黑、帶有微型齒輪與榫卯的【太古不融黑鐵構件】！\n" NOR);
            object relic = clone_object("/clone/relic/ancient_black_iron.c");
            if (relic) relic->move(me);
        } else {
            write(HIW "经过千錘百鍊的敲打，粗鐵胚料褪去雜質，鍛打成了一柄沉甸甸的【大荒開山柴刀】！\n" NOR);
            object blade = clone_object("/clone/weapon/clearing_blade.c");
            if (blade) blade->move(me);
        }
    } else {
        write("你沉穩地揮動鐵錘在空鐵砧上節奏敲擊，「叮、噹、叮、噹」的金石脆響在工坊迴盪...\n");
        write("隨每一次落錘的震顫，你對發力技巧與筋骨協調的領悟又深了一分。\n");
    }

    me->add(STAT_STR, 1);
    me->add(STAT_DEX, 1);
    write(HIG "【百工手藝在千錘百鍊中昇華，你的臂力與靈巧提升了！】\n" NOR);
    return 1;
}

int do_quench(string arg) {
    object me = this_player();
    write("你用長鐵鉗夾起燒得通紅的金屬胚料，猛然按入身旁盛滿井水的淬火石槽之中！\n");
    write(HIC "「轟——！」整槽淬火水劇烈沸騰，濃白滾燙的水霧如雲海翻湧，瞬間瀰漫了整間爐房！\n" NOR);
    write("白霧散去，淬透的金屬表面泛出一層深沉堅韌的精鋼暗藍色澤。\n");
    return 1;
}
