// clone/item/mine_blueprint.c
// 《北崖太古玄煞採掘舊志殘圖》 (小說第13、14章核心信物)

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("太古採掘殘圖");
    set_short(HIY "《北崖太古玄煞採掘舊志殘圖》" NOR);
    set_long("這是一卷以粗糙防水油紙拓印的泛黃羊皮古卷，以暗紅朱砂標註著北崖\n"
             "地下三百米深處的古老採掘結構。圖中清晰標註：地下三百米處有一座天然\n"
             "岩石空腔【地煞避風穹頂】，但入口被一道重逾萬斤的【斷龍卡隼石】死死卡住。\n"
             "若想排空地煞救出被困礦工，必須以剛猛破煞重器擊碎卡隼石眼，引動落石排入暗渠！\n"
             "（可使用 read blueprint 細看地脈線路）\n");
    set_id(({ "mine blueprint", "blueprint", "map", "殘圖", "採掘殘圖", "太古採掘殘圖" }));

    set_weight(200);
    set_value(500);
    set("is_relic", 1);
    set("relic_type", "mine_map");
}

void init() {
    ::init();
    add_action("do_read", "read");
}

int do_read(string arg) {
    if (!arg || (arg != "blueprint" && arg != "map" && arg != "殘圖")) return 0;
    
    write(HIY "\n【《北崖太古玄煞採掘舊志殘圖》密要】\n" NOR);
    write(CYN "你展開泛黃油紙，就著微光凝神審視：\n" +
              "  一、北崖深處萬年前並非凡俗礦穴，而是一座太古神闕的基建採石排沙道。\n" +
              "  二、地下百米處為主採掘面，前方常有巨型沉鐵黑玄石崩塌阻塞。\n" +
              "  三、崩塌處右下角三尺厚之「斷龍卡隼石」為連通排沙暗渠之死穴。\n" +
              "  四、若遇塌方，深層礦工退守【地煞避風穹頂】，常以鐵軌敲擊「三長兩短」為信！\n\n" NOR);
    return 1;
}
