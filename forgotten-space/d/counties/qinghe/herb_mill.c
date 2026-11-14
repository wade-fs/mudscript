// /d/counties/qinghe/herb_mill.c
// 青河縣 (Qinghe County) 房間 9/14：青河洗藥總坊・採百草分號 (【物】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_branch_org("org_xinglin");
    set_qual_path("wu");
    set_short("青河洗藥總坊・採百草分號");
    set_long("引自青河支流的清澈活水順著竹筧流入一排排青石洗藥槽中，數十名藥工\n"
             "正忙著洗去鮮藥根部的泥沙，並依藥性寒熱分揀切片。此處為都城採百草分堂與杏林\n"
             "醫館共設的青河總坊，坐堂主事【蘇明月】專司審核地方藥師資質。有志於【物】道\n"
             "醫藥分支的行者可在此參加考核（輸入 exam 或 考取），獲發與都城完全等效之【杏林坐堂行醫資格】。\n"
             "往南出坊即回【百草糧油水集】。\n");

    set_exits(([
        "south": "/d/counties/qinghe/market.c",
    ]));

    set_has_guild(1);
    set_is_outdoor(0);
    set_coordinate(-8, 11, 0);
}
