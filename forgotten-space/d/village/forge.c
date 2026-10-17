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
    add_item("trough", "一口整塊青石鑿成的長槽，裡頭盛滿了黑褐色的淬火井水，可以用來為燒紅的鐵胚淬火 (quench)；槽旁還放著一桶甘冽的深井涼水供人飲水歇息 (drink)。");
    add_item("石槽", "一口整塊青石鑿成的長槽，裡頭盛滿了黑褐色的淬火井水，可以用來為燒紅的鐵胚淬火 (quench)；槽旁還放著一桶甘冽的深井涼水供人飲水歇息 (drink)。");
    add_item("scrap", "堆在工坊西北角的一座廢料渣堆，裡面全是十幾年來敲碎挑剩下的劣質石皮、死煤結焦與畸形碎塊。\n在最底層厚厚的黑炭灰下，似乎深埋著一塊阿鐵師傅嫌小難熔而隨手踢去墊底的焦黑頑石料 (dark stone)。");
    add_item("廢料堆", "堆在工坊西北角的一座廢料渣堆，裡面全是十幾年來敲碎挑剩下的劣質石皮、死煤結焦與畸形碎塊。\n在最底層厚厚的黑炭灰下，似乎深埋著一塊阿鐵師傅嫌小難熔而隨手踢去墊底的焦黑頑石料 (dark stone)。");
    add_item("dark stone", "一塊僅有拳頭大小、長滿焦黑石瘤的畸形頑石。阿鐵師傅當年嫌它『太小太畸形打不了農具，皮殼死硬難熔又費炭火』，隨手踢到廢料坑底墊腳。");
    add_item("頑石", "一塊僅有拳頭大小、長滿焦黑石瘤的畸形頑石。阿鐵師傅當年嫌它『太小太畸形打不了農具，皮殼死硬難熔又費炭火』，隨手踢到廢料坑底墊腳。");

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
    add_action("do_drink", "drink");
    add_action("do_drink", "喝水");
    add_action("do_drink", "飲水");
}

int do_drink(string arg) {
    object me = this_player();
    if (!me->consume_drink(30)) return 1;

    write("你走到石槽旁的木桶邊，舀起一瓢冰涼甘冽的深井水，「咕咚咕咚」大口痛飲而下！\n");
    write(HIC "清涼井水順喉而下，瞬間驅散了爐房內灼人的火毒與滿身疲憊，四肢百骸說不出的舒暢！\n" NOR);
    me->add(VITAL_KEE, 25);
    me->add(VITAL_SP, 25);
    write(HIG "【深井涼水潤澤肺腑，你的氣血 +25、精力 +25！】\n" NOR);
    return 1;
}

int do_bellows(string arg) {
    object me = this_player();
    if (me->query(VITAL_KEE) < 10 || me->query(VITAL_SP) < 10) {
        write(HIR "你氣血虧耗、雙臂酸軟脫力，拉不動這沉重的巨型牛皮風箱了（可 drink 飲水或 調息/吐納 恢復）。\n" NOR);
        return 1;
    }

    me->add(VITAL_KEE, -5);
    me->add(VITAL_SP, -5);
    furnace_heat += 20;
    if (furnace_heat > 150) furnace_heat = 150;

    write("你雙手握住牛皮風箱的巨木長柄，沉腰扎馬，大開大合地全力推拉！\n");
    write(HIY "狂風如怒濤般灌入地爐底部，炭火陡然暴亮，熾白的金焰如火龍翻滾！\n" NOR);

    write(HIG "【在與狂暴烈火與厚重風箱的對抗中，你的臂力與根骨得到了磨礪！】\n" NOR);
    me->train_stat(STAT_STR, 20);
    me->train_stat(STAT_CON, 20);
    me->gain_exp(10);

    if (me->query("background") == "smith" && me->query_skill("crazy_forge") <= 0) {
        write(YEL "\n老鐵匠阿鐵在一旁沉聲喝道：「小子，別光用死力氣憋氣！拿你的胸膛當風箱、拿你的呼吸跟上爐火的吞吐！」\n" NOR);
        load_object("/secure/skill_d.c")->grant_starter_force(me, "crazy_forge");
    }
    return 1;
}

int do_strike(string arg) {
    object me = this_player();
    if (me->query(VITAL_KEE) < 10 || me->query(VITAL_SP) < 10) {
        write(HIR "你精疲力竭，手腕發抖，無法精準揮錘（可 drink 飲水或 rest 調息恢復）。\n" NOR);
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

    // 檢查身上或房間是否有未打完的常規粗鐵礦核
    object ore = present("ore chunk", me);
    if (!ore) ore = present("ore chunk", this_object());
    if (!ore) ore = present("ore", me);

    // 玩家嘗試直接敲打廢料堆或壓底頑石 (strike stone / scrap)
    if (arg == "stone" || arg == "dark stone" || arg == "scrap" || arg == "廢料" || arg == "頑石") {
        if (ore && (ore->query("is_ore") || ore->id("ore chunk") || ore->id("ore") || ore->id("粗礦") || ore->id("礦石"))) {
            write(CYN "阿鐵師傅交代選揀鍛造的常規粗鐵礦尚未打完，莫要分心去翻那些死煤廢渣！先把手頭的正料打完吧。\n" NOR);
            return 1;
        }

        object md = load_object(MYSTERY_D);
        if (md && md->is_relic_discovered(me, "forge_ancient_black_iron")) {
            write("廢料坑裡剩下的皆是尋常碎石與焦炭渣，那枚太古構件已被你取出了。\n");
            return 1;
        }

        if (md && !md->can_discover_relic(me, "forge_ancient_black_iron")) {
            write(CYN "你隨手敲了敲廢料坑底層的焦黑頑石，石頭崩裂成一地尋常焦渣，毫無奇異。（身世未具工聖血脈靈犀）\n" NOR);
            return 1;
        }

        me->add(VITAL_KEE, -5);
        me->add(VITAL_SP, -10);

        write(CYN "你蹲下身撥開廢料堆最底層的厚厚黑炭灰，將那塊阿鐵師傅當年嫌小難熔而踢去墊底的焦黑頑石料 (dark stone) 摳出夾上鐵砧。\n" NOR);
        write(YEL "【福至心靈】此頑石比重沉墜如鼎，屈指輕彈隱有空靈龍吟，宛如深藏絕世美玉的賭石盲料！\n" NOR);
        write("你右臂青筋暴起，沉腰扎馬，那柄七斤舊鐵錘化作狂暴弧光狠狠砸落！\n");
        write(HIR "「當——嗡——！！」一聲清脆龍吟如太古神龍長吟，漫天火星如暴雨散落，焦黑石皮寸寸崩裂！\n" NOR);
        write(HIR "【反震異變】一股極恐怖的金屬反震狂暴倒灌，撕裂虎口，錘面被狠狠彈開！\n" NOR);
        write(HIB "岩石碎殼深處，赫然露出一截通體烏黑、帶有微型齒輪與榫卯的【太古不融黑鐵構件】！\n" NOR);

        if (md) md->trigger_relic_discovery(me, "forge_ancient_black_iron", me);
        return 1;
    }

    me->add(VITAL_KEE, -5);
    me->add(VITAL_SP, -10);

    if (ore && (ore->query("is_ore") || ore->id("ore chunk") || ore->id("ore") || ore->id("粗礦") || ore->id("礦石"))) {
        write("你用長鐵鉗將" + ore->query_short() + "牢牢鉗在鐵砧上，右臂青筋暴起，高舉鐵錘！\n");
        write(HIY "「當——！！」一聲巨響震徹工坊，漫天火星如暴雨散落，粗糙的岩殼寸寸崩裂！\n" NOR);

        destruct(ore);

        write(HIW "經過千錘百鍊的敲打，粗鐵胚料褪去雜質，鍛打成了一柄沉甸甸的【大荒開山柴刀】！\n" NOR);
        object blade = clone_object("/clone/weapon/clearing_blade.c");
        if (blade) {
            if (!blade->move(me)) blade->move(this_object());
        }

        // 檢查是否所有常規粗礦均已鍛打完畢 (正料用盡)
        object remaining_ore = present("ore chunk", me);
        if (!remaining_ore) remaining_ore = present("ore chunk", this_object());
        if (!remaining_ore) remaining_ore = present("ore", me);

        object md = load_object(MYSTERY_D);
        if (!remaining_ore && md && !md->is_relic_discovered(me, "forge_ancient_black_iron")) {
            write(YEL "\n【常規正料用盡】手頭送來的粗鐵礦石已悉數打成柴刀！但地爐烈焰正旺，你渾身氣血沸騰、意猶未盡……\n" NOR);
            write(CYN "你的目光不由自主地落在了工坊角落那個十幾年未動的【廢料堆 (scrap)】最底層。\n"
                      "厚厚黑炭灰下，露出一塊阿鐵師傅當年嫌小難熔而隨手踢去墊底的焦黑頑石料 (dark stone)。\n"
                      "你走上前伸手握住頑石，【福至心靈】——此石比重沉墜如鼎，屈指輕彈隱有太古空鳴，宛如賭石盲料！\n" NOR);
            write("你將這塊壓底頑石夾上鐵砧，以全身力道全力一錘砸落——\n");
            write(HIR "「當——嗡——！！」一聲宛如太古神龍引頸長吟般的尖銳嘯音震徹工坊，漫天火星如暴雨散落！\n" NOR);
            write(HIR "【反震異變】一股極恐怖的金屬反震狂暴倒灌，撕裂虎口，錘面被狠狠彈開！焦黑石皮寸寸崩裂！\n" NOR);
            write(HIB "岩石碎殼深處，赫然露出一截通體烏黑、帶有微型齒輪與榫卯的【太古不融黑鐵構件】！\n" NOR);
            md->trigger_relic_discovery(me, "forge_ancient_black_iron", me);
        }

        object career = load_object(CAREER_D);
        if (career && career->query_chain_stage(me, "wu") == 4) {
            career->advance_chain_stage(me, "wu");
        }
    } else {
        write("你沉穩地揮動鐵錘在空鐵砧上節奏敲擊，「叮、噹、叮、噹」的金石脆響在工坊迴盪...\n");
        write("隨每一次落錘的震顫，你對發力技巧與筋骨協調的領悟又深了一分。\n");
    }

    write(HIG "【百工手藝在千錘百鍊中昇華，你的臂力與靈巧提升了！】\n" NOR);
    me->train_stat(STAT_STR, 20);
    me->train_stat(STAT_DEX, 20);
    me->gain_exp(12);
    return 1;
}

int do_quench(string arg) {
    object me = this_player();
    write("你用長鐵鉗夾起燒得通紅的金屬胚料，猛然按入身旁盛滿井水的淬火石槽之中！\n");
    write(HIC "「轟——！」整槽淬火水劇烈沸騰，濃白滾燙的水霧如雲海翻湧，瞬間瀰漫了整間爐房！\n" NOR);
    write("白霧散去，淬透的金屬表面泛出一層深沉堅韌的精鋼暗藍色澤。\n");
    return 1;
}
