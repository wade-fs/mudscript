// clone/item/bronze_treaty_plate.c
// 史前商盟青銅契版殘片 - 卷二第五幕太古遺物與舊約信物

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("史前商盟青銅契版殘片", ({ "bronze treaty plate", "treaty_plate", "bronze_plate", "qiban", "青銅契版", "契版殘片" }));
    set_short(HIC "【史前商盟青銅契版殘片】" NOR);
    set_long("自城下暗渠地下鬼市黑集中收購的殘破青銅契版，邊緣呈劇烈撕裂狀。\n"
             "青銅表面沒有任何世俗王朝年號或官印，卻以極致工差銘刻著太古九大仙城星軌度量衡。\n"
             "與沈泥貼身攜帶的【天門引】具備同源頻率，貼近時能誘發青金微光與微熱共鳴，\n"
             "為開啟三十年舊商盟「太古舊約」與名山迷局的核心信物（relic）。\n");
    set_weight(150);
    set_value(3000);
    set("is_relic", 1);
    set("relic_type", "treaty_plate");
}
