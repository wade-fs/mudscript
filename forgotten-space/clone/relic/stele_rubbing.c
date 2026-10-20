// clone/relic/stele_rubbing.c
// 殘缺星圖拓片 - 史前大清洗斷碑的拓本

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("拓片", ({ "stele rubbing", "rubbing", "tuopian", "拓片" }));
    set_short("殘缺星圖拓片");
    set_long("這是一張從南谷溪灘深青石板上搶拓下來的古老星紋拓片。\n"
             "那塊太古斷碑歷經億萬年江河沖刷與凡夫磨礪，刻痕深不及數十微米，撫之平滑如鏡；\n"
             "唯有在深秋枯水、晨霧消散之際，借由清晨旭日貼地掠射的極低角陰影，\n"
             "方如『火星人面像』般在凹槽背光處顯現出一幅浩瀚的光影星圖。\n"
             "紙面上的炭黑痕跡精準拓下了這抹轉瞬即逝的天地奇遇——\n"
             "角宿居幽西，箕宿踏正東，蒼龍七宿的運轉軌道與當今天地完全顛倒逆轉，\n"
             "隱隱記錄著太古大清洗之前，諸天星辰被恐怖偉力生生逆轉替換的萬古隱秘。\n"
             "（你可以研讀 read/study 拓片以細察其中星象古意）\n");
    set_weight(30);
    set_value(50);
}

void init() {
    ::init();
    add_action("do_read", "read");
    add_action("do_read", "study");
    add_action("do_read", "研讀");
    add_action("do_read", "參悟");
}

int do_read(string arg) {
    if (!arg || (arg != "rubbing" && arg != "stele rubbing" && arg != "tuopian" && arg != "拓片" && arg != "星圖")) {
        return 0;
    }
    object me = this_player();
    write(HIY "你展開這張散發著淡淡草木苦味與炭香的【殘缺星圖拓片】細細端詳...\n" NOR);
    write(WHT "紙面上由無數細微炭點勾勒出的東方蒼龍七宿逆向流轉，線條森嚴冷冽，完全違背如今周天星軌。\n" NOR);
    write(CYN "拓片邊緣依稀留有幾行以極限陰影拓下的太古殘字：\n"
              "『太古天曆……逆行九宿……星軌反震……大清洗紀元始……』\n" NOR);
    write(HIG "凝視著這幅在萬古晨光陰影中甦醒的史前殘卷，你體內氣息隱隱共鳴，靈台不由為之一清！\n" NOR);
    return 1;
}

