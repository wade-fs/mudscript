// d/village/mine.c
// 黑石鋪・北面黑石斷崖與古礦坑 (重勞動與打熬區)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑石斷崖・古礦道口");
    set_long("此處高懸於聚落北側，山風凜冽，寸草不生。黑色的怪石嶙峋突兀，宛如\n"
             "猙獰的獸齒。面前立著一個半塌陷的古老礦洞，四周散落著廢棄的鐵鎬與\n"
             "碎石渣，幾道烏黑的軌道延伸進幽暗深處，隱約能聽見洞穴內部傳來的滴水\n"
             "聲與微弱的金屬摩擦聲。幾名皮膚黝黑的老礦工正倚著石壁歇息喘氣。\n");

    set_exits(([
        "south": "/d/village/square.c",
        "down": "/d/village/mine_depths.c",
    ]));

    set("is_outdoor", 1);

    spawn_npc("/clone/npc/lao_miner.c");
    spawn_npc("/clone/npc/mine_rat.c");
}

string query_long() {
    object ws = load_object(WORLD_STATE_D);
    string res = "此處高懸於聚落北側，山風凜冽，寸草不生。黑色的怪石嶙峋突兀，宛如\n"
                 "猙獰的獸齒。面前立著一個半塌陷的古老礦洞，四周散落著廢棄的鐵鎬與\n"
                 "碎石渣。\n";

    if (ws) {
        if (ws->is_mine_collapsed()) {
            res += HIR "【嚴重塌方】數十塊萬斤黑石巨岩徹底堵死了幽深礦洞，碎石泥沙不斷滾落，\n"
                       "濃重的煙塵自石縫漫出！洞口兩側架設著天車重型絞盤與生鐵索具，\n"
                       "幾名老礦工急得團團轉，需清理巨石 (clear) 或順著索具攀入地下深處 (down)！\n" NOR;
        } else {
            int stab = ws->query_mine_stability();
            int res_amt = ws->query_mine_ore_reserve();

            if (stab <= 30) {
                res += HIR "洞頂岩壁裂紋密佈，碎石不時簌簌墜落，地質極其脆弱危險！\n" NOR;
            } else if (stab <= 65) {
                res += YEL "洞口岩壁有幾道新鮮的石裂痕跡，連日開採震動已使地煞略有鬆動。\n" NOR;
            } else {
                res += "黑石岩層堅實深沉，礦道內部隱隱透出一股陰涼地煞之氣。\n";
            }

            if (res_amt > 10) {
                res += HIG "黝黑的礦脈石壁上露出一處處鐵青色的金屬反光，粗礦儲量相當豐盈 (mine)。\n" NOR;
            } else if (res_amt > 0) {
                res += "岩壁上的優質鐵脈已開採得七七八八，需費力深鑿才能敲出粗礦 (mine)。\n";
            } else {
                res += WHT "這片岩層已被徹底挖空，滿地盡是崩碎的劣質石粉。\n" NOR;
            }
        }
    }

    res += "幾名皮膚黝黑的老礦工倚著石壁歇息，擦拭著沾滿黑灰的粗糙手掌。\n";
    return res;
}

void init() {
    ::init();
    add_action("do_mine", "mine");
    add_action("do_mine", "採礦");
    add_action("do_clear", "clear");
    add_action("do_clear", "清理");
    add_action("do_clear", "搬石");
}

int do_mine(string arg) {
    return load_object(WORLD_STATE_D)->mine_ore(this_player());
}

int do_clear(string arg) {
    return load_object(WORLD_STATE_D)->clear_mine_rubble(this_player());
}
