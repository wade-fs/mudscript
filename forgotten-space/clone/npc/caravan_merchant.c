// clone/npc/caravan_merchant.c
// 金石商會掌櫃 - 隨商隊抵達黑石鋪的大商賈

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("錢富貴");
    set_short(HIY "金石商會掌櫃" NOR " 錢富貴");
    set_long("一位身著團花綢緞錦袍的富態中年商賈，手指上戴著幾枚溫潤的玉韘。\n"
             "他身旁堆放著幾口厚重的紅木行商大箱，幾名體格彪悍的護衛正警惕地按刀\n"
             "四顧。他滿臉堆笑，正精明地撥弄著手中的紫檀算盤。\n");
    set_id(({ "merchant", "caravan merchant", "qian", "fugui", "錢富貴", "掌櫃" }));

    set_level(15);
    set_stat("str", 15);
    set_stat("con", 15);
    recalc_stats();

    add_response(({ "商隊", "caravan" }), 
        "我們金石商會常年往返於大荒與金石城之間。若不是黑石鋪的粗礦質地厚重，這險惡商道我們可不願輕易涉足。");

    add_response(({ "收購", "特產", "trade" }), 
        "本商隊常年溢價收購兩樣東西：北崖的【粗鐵礦石】與南谷的【晨露草】！你若採得，輸入 sell 即可賣予我換取現錢！");

    add_response(({ "消息", "news", "路引" }), 
        "客官想去金石城？那可不容易。自從大荒邊境出了怪異的動靜，城防軍只認宗門保書或百工路引，尋常流民連城門都摸不著。");
}

void init() {
    ::init();
    add_action("do_sell", "sell");
    add_action("do_sell", "賣");
    add_action("do_list", "list");
    add_action("do_list", "價目");
}

int do_list(string arg) {
    write("\n" + HIY "【金石商會・收購價目表】" NOR + "\n");
    write("  北崖粗鐵礦核 (ore chunk)    : 每塊 30 銅幣 (用於府城軍械鍛造)\n");
    write("  大荒開山柴刀 (blade)        : 每柄 80 銅幣 (商隊急需五十柄開山刀闢路)\n");
    write("  新鮮草藥 (fresh herb)       : 每株 15 銅幣 (尋常止血草)\n");
    write("  帶露晨露草 (dew herb)       : 每株 50 銅幣 (破曉所採之極品靈藥)\n");
    write("  百年鐵角七 (rare herb)      : 每株 200 銅幣 (絕壁罕見靈根)\n");
    write("\n輸入指令：sell <物品代號> 或 sell all 即可將採集或鍛造的物資換成現錢。\n\n");
    return 1;
}

int do_sell(string arg) {
    object me = this_player();

    if (!arg || arg == "") {
        write("你想把什麼賣給金石商會？（輸入 list 可查看價目表，或輸入 sell all 出售所有採集物）\n");
        return 1;
    }

    object *inv = all_inventory(me);
    int total_gain = 0;
    int count = 0;

    foreach (object ob in inv) {
        if (!ob) continue;
        string name = ob->query_name();
        int val = 0;

        if ((ob->query("is_ore") || name == "粗鐵礦" || name == "粗鐵礦石") &&
            (arg == "all" || arg == "ore" || arg == "ore chunk" || arg == "礦石" || arg == "粗礦" || arg == "粗鐵礦" || arg == "粗鐵礦石")) {
            val = 30;
        } else if ((name == "開山柴刀" || base_name(ob) == "/clone/weapon/clearing_blade") &&
                   (arg == "all" || arg == "blade" || arg == "clearing blade" || arg == "柴刀" || arg == "開山柴刀")) {
            val = 80;
        } else if (name == "新鮮草藥" && (arg == "all" || arg == "herb" || arg == "草藥")) {
            val = 15;
        } else if (name == "帶露晨露草" && (arg == "all" || arg == "dew" || arg == "晨露草")) {
            val = 50;
        } else if (name == "百年鐵角七" && (arg == "all" || arg == "rare" || arg == "鐵角七")) {
            val = 200;
        }

        if (val > 0) {
            total_gain += val;
            count++;
            destruct(ob);
            if (arg != "all") break;
        }
    }

    if (count == 0) {
        write("錢富貴撥了撥算盤，搖頭笑道：「客官身上並無商隊所需的礦石或草藥。」\n");
        return 1;
    }

    me->gain_money(total_gain);
    write(HIY "錢富貴笑得合不攏嘴，收下物資後遞過一袋銅板：「承惠！共收購 " + count + " 件貨物，合計 " + total_gain + " 銅幣，請收好！」\n" NOR);
    return 1;
}
