// d/city/under/shang_secret.c
// 天字一號密室 (舊商盟地下遺址、需【天門引】驗證開啟)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太古遺構・天字一號密室");
    set_long("這是一座深埋地下三十餘丈的史前舊商盟秘密藏室。\n"
             "四壁皆以整塊不融太古黑鐵無縫澆築，室內乾燥異常，中央石台上供奉著一隻\n"
             "通體雕刻九子連環金印的【沉鐵九子連環保祕匣】。\n"
             "牆上殘存著三十年前大清洗前夕金石商盟元老留下的未結指示與血字誓約。\n"
             "太古元力在此緩緩流轉，令人心馳神往。\n"
             "向西推開沉重的玄鐵重門，可回到城下古暗渠水網樞紐。\n");

    set_exits(([
        "west": "/d/city/under/canal_hub.c",
        "up":   "/d/city/south/shanghui_hq.c",
    ]));

    set("is_underground", 1);
    set("is_secret_room", 1);

    set_touch("default", WHT "整塊澆築的太古黑鐵壁面乾燥冰冷如玄冰，九子連環保祕匣金印紋路卻隱含一絲餘溫。" NOR);
    set_smell("default", YEL "陳年不散的乾燥古紙墨味、乾涸暗紅血字鐵鏽氣與奇異的太古金屬清味。" NOR);
    set_listen("default", HIC "密室極靜之中，隱約能聽見腳下極深處太古元力緩緩流轉的低沉嗡鳴。" NOR);

    mapping oath_rule = ([
        "targets": ({ "oath", "wall", "誓約", "血字", "" }),
        "sp_cost": 5,
        "sensory_msg": HIY "你湊近黑鐵壁逐字辨讀三十年前商盟元老留下的未結血字誓約，字裡行間滿是孤注一擲的悲壯決絕。" NOR,
        "train_stat": ([ "int": 8, "spi": 6 ]),
        "exp_gain": 10
    ]);
    add_action_rule("read_oath", oath_rule);
    add_action_rule("讀誓", oath_rule);
}

int can_receive(object ob) {
    if (!ob || !userp(ob)) return 1;
    // 檢查是否持有天門引信物或沈氏身世
    if (present("tianmen token", ob) || present("tianmen_token", ob) || present("天門引", ob)) {
        tell_object(ob, HIG "你懷中的【天門引】青金古令發出微弱共鳴，太古玄鐵重門緩緩洞開！\n" NOR);
        return 1;
    }
    if (ob->query("background") == "beggar" && ob->query("level") >= 10) {
        tell_object(ob, HIG "太古感應栓辨識出熟悉的血脈氣息，厚重的太古重門無聲向兩側滑開！\n" NOR);
        return 1;
    }
    tell_object(ob, HIR "一道三千斤重的太古玄鐵重門死死封閉，門中太古元力感應栓毫無反應，無法開啟！\n" NOR);
    return 0;
}
