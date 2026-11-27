// d/city/under/canal_hub.c
// 城下暗渠・古暗渠樞紐 (匯集全城排污排澇、天然溶洞水系)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城下暗渠・水網樞紐");
    set_long("這裡是一座巨大的太古石拱地下水殿，匯集了整座府城的排澇水流與天然地下溶洞暗河。\n"
             "黑色濁浪在石柱間轟鳴翻滾，水汽刺骨冰寒。\n"
             "一名黑衣擺渡盲叟手持長篙立於小舟頭上，暗中接應走私客與江湖探子。\n"
             "往北沿石階步道可走回地下鬼市，向西穿過鏽蝕水閘直通護城河盲區，\n"
             "東面有一道緊閉的太古玄鐵重門【天字一號密室】，向南則延伸入史前殘殿地宮。\n");

    set_exits(([
        "north":     "/d/city/under/black_market.c",
        "west":      "/d/city/under/drain_gate.c",
        "east":      "/d/city/under/shang_secret.c",
        "south":     "/d/city/under/ruins_hall.c",
        "southeast": "/d/routes/under_karst_river.c",
    ]));

    set("is_underground", 1);
    set("is_outdoor", 0);
    set_touch("default", CYN "石階覆著一層滑膩冰寒的墨綠淤泥，涉水處濁浪拍打小腿，刺骨腥臭。" NOR);
    set_smell("default", YEL "濃重的腐泥排污臭氣、潮濕青苔味與地下陰寒地煞水氣撲鼻而來。" NOR);
    set_listen("default", WHT "黑色濁浪拍擊太古石拱的悶響聲中，夾雜著盲叟竹篙點水的輕響與地下溶洞回音。" NOR);
    spawn_npc("/clone/npc/under_canal_hub_ferryman.c");
}

void init() {
    ::init();
    object me = this_player();
    if (!me || (!userp(me) && strsrch(base_name(me), "/std/user") != 0)) return;

    object cd = find_object(CITY_D);
    if (!cd) cd = load_object(CITY_D);
    if (!cd) return;

    object *inv = all_inventory(me);
    if (!inv) return;
    foreach (object ob in inv) {
        string bn = base_name(ob);
        int is_fragile_ev = (
            strsrch(bn, "detonator_serial_ledger") != -1 ||
            strsrch(bn, "liefan_clay_batch") != -1 ||
            strsrch(bn, "relay_poison_sample") != -1 ||
            strsrch(bn, "miner_thumbprints") != -1 ||
            strsrch(bn, "under_canal_deed") != -1 ||
            strsrch(bn, "ev3_yanshan_blood_note") != -1 ||
            strsrch(bn, "ev3_private_purchase_ledger") != -1 ||
            strsrch(bn, "ev3_expedition_roster") != -1
        );
        if (is_fragile_ev && !ob->query("sealed_custody") && !ob->query("contaminated")) {
            mapping cres = cd->contaminate_evidence(ob, "暗渠腥濁污水浸透");
            if (mapp(cres) && cres["msg"]) {
                tell_object(me, cres["msg"] + "\n");
            }
        }
    }
}
