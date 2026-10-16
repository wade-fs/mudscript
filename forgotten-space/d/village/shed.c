// d/village/shed.c
// 黑石鋪・客棧背街・廢柴房 (流浪乞兒出生地)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("客棧背街・廢柴房");
    set_long("這是一間蜷縮在老客棧後巷陰暗處的破爛柴棚。屋頂泥草剝落，四周堆滿了\n"
             "發霉的潮濕朽木與碎瓦，唯有一角鋪著幾捆陳年稻草，算是唯一的棲身窩鋪。\n"
             "破爛木板的縫隙間，不時飄來前街客棧廚房的滾燙肉湯香氣與粗獷吆喝聲。\n"
             "角落裡放著一隻豁口的舊粗陶破碗，脖頸上那只縫滿補丁的粗布乾糧袋已磨得\n"
             "發黑。推開吱呀作響的柴門，鑽出泥濘後巷便是人聲鼎沸的青石街市。\n"
             "（可在此貼牆偷聽 eavesdrop/聽風，或翻扒最深處的陳年爛木堆 search wood）\n");

    set_exits(([
        "northeast": "/d/village/square.c",
    ]));

    set("is_outdoor", 0);

    spawn_npc("/clone/npc/mo_beggar.c");
    spawn_item("/clone/item/broken_bowl.c");
}

void init() {
    ::init();
    add_action("do_eavesdrop", "eavesdrop");
    add_action("do_eavesdrop", "偷聽");
    add_action("do_eavesdrop", "聽風");
    add_action("do_eavesdrop", "listen");
    add_action("do_search", "search");
    add_action("do_search", "搜查");
    add_action("do_search", "翻找");
    add_action("do_nap", "nap");
    add_action("do_nap", "小憩");
    add_action("do_nap", "窩鋪");
}

int do_nap(string arg) {
    object me = this_player();
    write("你鑽進避風牆角的陳年乾稻草堆裡，蜷縮起身體，聽著前街客棧傳來的熱鬧動靜小憩片刻...\n");
    write(YEL "鬆軟乾燥的稻草隔絕了寒氣，你緊繃的神經徹底放鬆，手腳重新充滿了力氣。\n" NOR);
    me->add(VITAL_KEE, 25);
    me->add(VITAL_SEN, 15);
    me->add(VITAL_SP, 30);
    write(HIG "【窩鋪小憩，你的氣血 +25、神識 +15、精力 +30！】\n" NOR);

    if (me->query("background") == "beggar" && me->query_skill("dream_sleep") <= 0) {
        write(WHT "\n瘸腿老丐莫三斜靠在柴堆上嘿嘿笑道：「小子，叫花子睡覺也有大學問！像老龜一樣把氣收進肚子裡，這叫『睡夢大法』，學著點！」\n" NOR);
        load_object("/secure/skill_d.c")->grant_starter_force(me, "dream_sleep");
    }
    return 1;
}

int do_eavesdrop(string arg) {
    object me = this_player();

    if (me->query(VITAL_SEN) < 5) {
        write(HIR "你腹中飢腸轆轆、精神渙散，根本靜不下心來分辨後街嘈雜的聲息。\n" NOR);
        return 1;
    }

    object ws = load_object(WORLD_STATE_D);
    object md = load_object(MYSTERY_D);

    write(CYN "你把耳朵緊緊貼在木板的一處蛀孔上，凝神屏息，側耳傾聽四方風聲動靜……\n" NOR);
    write("透過木板縫隙，客棧大廚房翻滾的牛雜肉湯香氣混著高粱酒霧撲面而來。\n");
    write(YEL "【聽風辨器・八方動態情報入耳】：\n" NOR);

    if (ws) {
        // 1. 礦坑與西崖動向
        if (ws->is_mine_collapsed()) {
            write(WHT "一、北崖礦場傳來轟隆悶響與礦工驚呼——古礦道發生塌方，急需青壯前往清理碎石 (clear)；\n" NOR);
        } else {
            write(sprintf(WHT "一、北崖古礦道岩層穩定度目前為 %d%%（粗礦儲量 %d），西崖孤岩殘壇不時有異樣罡風呼嘯；\n" NOR,
                ws->query_mine_stability(), ws->query_mine_ore_reserve()));
        }

        // 2. 東林地煞與獸潮動態 (由 WORLD_STATE_D 狀態驅動)
        write(WHT "二、" + ws->query_beast_movement_narrative(1) + "\n" NOR);

        // 3. 商隊動態與官道黑幕真相 (由 WORLD_STATE_D 官軍封關狀態驅動)
        write(WHT "三、" + ws->query_garrison_narrative(1) + "\n" NOR);
    }

    me->add(VITAL_SEN, -5);

    if (md && !md->is_relic_discovered(me, "eavesdrop_shed")) {
        me->add(STAT_PER, 1);
        md->trigger_relic_discovery(me, "eavesdrop_shed", me);
        write(HIG "【你在市井雜訊中抽絲剝繭洞悉實情，察言觀色能力微幅提升（定力/感知+1），獲得 30 點經驗！】\n" NOR);
    }
    return 1;
}

int do_search(string arg) {
    object me = this_player();
    object md = load_object(MYSTERY_D);

    if (!arg || (arg != "wood" && arg != "firewood" && arg != "柴堆" && arg != "爛木" && arg != "柴火")) {
        write("你想在破柴房裡搜查什麼？提示：search wood（翻找最深處發霉的陳年爛木堆）\n");
        return 1;
    }

    if (md && md->is_relic_discovered(me, "search_shed_wood")) {
        write("柴堆底座深處只剩下潮濕腐爛的爛木樁與黑泥，未再發現其他物件。\n");
        return 1;
    }

    write(YEL "你撲上前去，雙手如利爪般瘋狂扒開那些潮濕腐朽的爛木與碎瓦……\n" NOR);
    write("木屑翻飛間，你在最底層深陷於黑泥半尺深的地方，摸到了一隻被油布層層包裹的沉重金屬鐵盒！\n");
    write("鐵盒銅鎖早已銹死，你撿起半截斷鐵條狠狠一別，「喀嚓」一聲脆響將鎖舌崩斷——\n");
    write(HIY "在油布與松脂包裹中，赫然顯露出一枚巴掌大小、通體泛著暗啞青金光澤的非鐵非木古老殘令！\n" NOR);
    write(HIC "令符正面雕著雙龍環抱太古神闕，背面嵌著四個斑駁古篆：【萬物行商・天門引】（目前處於休眠殘缺狀態）！\n" NOR);

    if (md) {
        md->trigger_relic_discovery(me, "search_shed_wood", me);
    }
    return 1;
}
