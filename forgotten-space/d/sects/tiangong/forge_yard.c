// /d/sects/tiangong/forge_yard.c
// 天工閣・地火鍛兵台 (Ch.95：礦車絞盤標準化維修與通往萬機地窟的重型斜行石道)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("天工閣・地火鍛兵台");
    set_long("萬仞天工山腹地熾熱宏闊的鑄造大台，數架待修的礦車絞盤架陳列在冷卻油槽旁，\n"
             "牆邊公告欄釘著一份寫滿「材料疲勞曲線」與「雙契榫楔應力修正圖紙」的內門實修單。\n"
             "靠牆深處一道包鐵重門之後，是一條傾斜向下的寬闊玄武岩石道，直貫地下二十丈。\n"
             "向西返回【千鍛地火廊暨千機院】，向下沿傾斜石道進入【萬機地窟】。\n");

    set_exits(([
        "west": "/d/sects/tiangong/thousand_mechanisms_hall.c",
        "down": "/d/sects/tiangong/machinery_depths.c",
    ]));

    set("is_outdoor", 0);
}
