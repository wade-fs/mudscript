// d/city/outer/tenement_alley.c
// 金石南關外・流民賃居矮巷（Tier 1 城市底層生活支翼：無路引苦力與流民互助）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("南關外・流民賃居矮巷");
    set_long("這條緊貼金石南城牆根外側的潮濕土坯矮巷，擠滿了用舊木板、油氈布與破草蓆搭成的簡陋棚屋。\n"
             "來自六縣的失地流民、跛腳老車夫與幫工婦人在此合租落腳，盼著天亮前去城門外接幾趟苦力散活。\n"
             "屋簷下晾著打滿補丁的粗布短褂，角落幾口小泥爐裡燒著拾來的煤核與枯枝，正燉著稀薄菜粥。\n"
             "往西走進巷尾草棚是免費替流民看診的【南關外・施藥義棚】，往東穿過缺口即是【南關官道】。\n");

    set_exits(([
        "east": "/d/city/outer/south_road.c",
        "west": "/d/city/outer/charity_clinic_shed.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);

    set_touch("default", WHT "潮濕陰涼的城牆磚石與粗糙土坯牆縫裡夾著發霉草繩與陳年泥灰的濕氣。" NOR);
    set_smell("default", YEL "低廉蜂窩煤灰、水煮白菜湯氣與潮濕粗布衣物混合出沉重而真實的底層煙火味。" NOR);
    set_listen("default", WHT "巷底傳來低沉咳嗽聲、木輪手推車軸的吱呀聲，以及城內打更人遙遠模糊的梆子聲。" NOR);

    mapping help_rule = ([
        "targets": ({ "wood", "stove", "coal", "木柴", "泥爐", "" }),
        "sp_cost": 5,
        "sensory_msg": YEL "你蹲下身替幾戶孤寡流民把濕透的煤核掰開添進小泥爐裡，火星劈啪竄起，泥屋裡總算多了幾分暖意。" NOR,
        "train_stat": ([ "con": 6, "per": 6 ]),
        "exp_gain": 8,
        "quest_verb": "tend_stove",
        "quest_target": "alley"
    ]);
    add_action_rule("stoke", help_rule);
    add_action_rule("添火", help_rule);

    spawn_npc("/clone/npc/folk/sun_old_carter.c");
}

void init() {
    ::init();
    add_action("do_alley_sleep", "lodge");
    add_action("do_alley_sleep", "投宿");
    add_action("do_alley_porridge", "porridge");
    add_action("do_alley_porridge", "買粥");
    add_action("do_register_temp_pass", "register_pass");
    add_action("do_register_temp_pass", "領暫住牌");
}

int do_alley_sleep(string arg) {
    object me = this_player();
    if (!me) return 0;
    int money = me->query("money");
    if (money >= 2) {
        me->add_money(-2);
        write(WHT "你掏出兩文銅錢分了一席潮濕稻草通鋪，裹著舊布衫在微弱炭火旁勉強睡了一覺。（氣血 +15、精力 +20）\n" NOR);
    } else {
        write(WHT "看你身上連兩文通鋪錢都湊不出，孫伯擺手讓你免費擠在屋簷角落草堆避寒打盹。（氣血 +10、精力 +15）\n" NOR);
    }
    me->add(VITAL_KEE, 15);
    me->add(VITAL_SP, 20);
    return 1;
}

int do_alley_porridge(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (me->query("money") < 3) {
        write("你摸了摸空空如也的錢袋，連三文錢一碗的碎米菜粥都買不起，只好抓把熱水充飢。\n");
        return 1;
    }
    me->add_money(-3);
    write(YEL "你花三文銅錢向巷口老嫗打了碗熱氣騰騰的粗米青菜粥灌下，肚腹暖和了些。（氣血 +12、精力 +18）\n" NOR);
    me->add(VITAL_KEE, 12);
    me->add(VITAL_SP, 18);
    return 1;
}

int do_register_temp_pass(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (present("temp residency pass", me)) {
        write("你懷裡已經領過《金石南關暫住牌》了，不必重複領取。\n");
        return 1;
    }
    object pass_ob = clone_object("/clone/item/temp_residency_pass.c");
    if (pass_ob) {
        pass_ob->move(me);
        write(HIY "你在矮巷保正帳簿上捺下手印報明去向，領到一面薄槐木刻字《金石南關暫住牌》！自此可在外城正大光明扛包做散活、免遭夜間無籍鎖拿。\n" NOR);
    }
    return 1;
}
