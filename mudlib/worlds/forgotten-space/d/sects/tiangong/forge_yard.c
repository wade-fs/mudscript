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
        "east": "/d/sects/tiangong/slag_pit.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", RED "地火鍛台邊的鑄鐵絞盤架還殘留餘溫，油槽邊沿沾著滑膩的冷卻黑油。" NOR);
    set_smell("default", YEL "熾熱鐵漿、高溫淬火油煙與焦煤燃燒後的滾燙燥味充斥整個山腹大廳。" NOR);
    set_listen("default", RED "數架風箱怒吼鼓風，伴隨著鐵砧受擊震耳欲聾的「叮噹！」金屬交響。" NOR);

    mapping check_winch_rule = ([
        "targets": ({ "winch", "blueprint", "絞盤", "圖紙", "" }),
        "sp_cost": 8,
        "sensory_msg": YEL "你對照牆邊《雙契榫楔應力修正圖紙》檢查礦車絞盤架的疲勞裂紋，順手敲緊了幾枚鬆動鐵銷。" NOR,
        "train_stat": ([ "int": 8, "str": 6 ]),
        "exp_gain": 12
    ]);
    add_action_rule("check_winch", check_winch_rule);
    add_action_rule("檢修絞盤", check_winch_rule);

    spawn_npc("/clone/npc/folk/county_worker.c");
}
