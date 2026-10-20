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
    ]));

    set("is_underground", 1);
    set("is_secret_room", 1);
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
