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
}

int do_eavesdrop(string arg) {
    object me = this_player();

    if (me->query(VITAL_SEN) < 5) {
        write(HIR "你腹中飢腸轆轆、精神渙散，根本靜不下心來分辨後街嘈雜的聲息。\n" NOR);
        return 1;
    }

    write(CYN "你把耳朵緊緊貼在木板的一處蛀孔上，凝神屏息，側耳傾聽四方風聲動靜……\n" NOR);
    write("透過木板縫隙，客棧大廚房翻滾的牛雜肉湯香氣混著高粱酒霧撲面而來。\n");
    write(YEL "【聽風辨器・八方情報入耳】：\n" NOR);
    write(WHT "一、西崖老松殘壇方才起了一陣怪風，隱隱有血腥之氣飄散——小道童柳清虛疑似逆行引氣吐血；\n"
              "二、東林鹿角柵欄外傳來三聲急促狼哨，趙老獵正佈設破甲機弩，張屠戶天不亮提刀磨礪準備隨隊進山；\n"
              "三、客棧天字號房裡金石商會二掌櫃摔了茶碗！黑石關封路並非山體滑坡，乃是城防軍勒索三成乾股！\n"
              "    如今一張官方【保書路引】，在黑市已被炒至整整八十兩雪花銀！\n" NOR);

    me->add(VITAL_SEN, -5);

    if (!me->query("eavesdropped_shed")) {
        me->set("eavesdropped_shed", 1);
        me->add(STAT_PER, 1);
        me->add("exp", 30);
        write(HIG "【你在市井雜訊中抽絲剝繭洞悉實情，察言觀色能力微幅提升（定力/感知+1），獲得 30 點經驗！】\n" NOR);
    }
    return 1;
}

int do_search(string arg) {
    object me = this_player();

    if (!arg || (arg != "wood" && arg != "firewood" && arg != "柴堆" && arg != "爛木" && arg != "柴火")) {
        write("你想在破柴房裡搜查什麼？提示：search wood（翻找最深處發霉的陳年爛木堆）\n");
        return 1;
    }

    if (me->query("searched_shed_wood")) {
        write("柴堆底座深處只剩下潮濕腐爛的爛木樁與黑泥，未再發現其他物件。\n");
        return 1;
    }

    write(YEL "你撲上前去，雙手如利爪般瘋狂扒開那些潮濕腐朽的爛木與碎瓦……\n" NOR);
    write("木屑翻飛間，你在最底層深陷於黑泥半尺深的地方，摸到了一隻被油布層層包裹的沉重金屬鐵盒！\n");
    write("鐵盒銅鎖早已銹死，你撿起半截斷鐵條狠狠一別，「喀嚓」一聲脆響將鎖舌崩斷——\n");
    write(HIY "在油布與松脂包裹中，赫然顯露出一枚巴掌大小、通體泛著深邃青金光澤的非鐵非木古老令牌！\n" NOR);
    write(HIC "令符正面雕著雙龍環抱太古神闕，背面嵌著四個森嚴古篆：【萬物行商・天門引】！\n" NOR);

    object token = clone_object("/clone/relic/tianmen_token.c");
    if (token) {
        if (!token->move(me)) {
            token->move(this_object());
        }
    }
    me->set("searched_shed_wood", 1);
    me->add("exp", 50);
    write(HIG "【你掘出了莫三塵封三十年的太古商道密寶，獲得 50 點經驗！】\n" NOR);
    return 1;
}
