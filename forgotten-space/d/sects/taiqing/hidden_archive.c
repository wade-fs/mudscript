// /d/sects/taiqing/hidden_archive.c
// 太清玄天宮・藏星秘閣 (Ch.91：六百年《紫微星官錄》紙墨核校與蟲蛀舊箱原測廢頁)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太清玄天宮・藏星秘閣");
    set_long("開鑿於天柱峰背陰處厚重花崗岩山腹裡的石閣，過了包鐵石門便瀰漫著濃重的樟腦、\n"
             "乾艾草與冷鐵氣味。十餘盞覆著青銅防風罩的長明油燈照亮兩排高過丈餘的鐵梨木書架。\n"
             "東廂甲字三架擺著《紫微星官錄》的三代抄本，牆上懸著嚴禁觸碰的老祖宗星盤；\n"
             "西邊最底層角落塞著幾口未入目錄的蟲蛀舊箱，須持手令以炭筆分規核對誤差（指令：collate archive）。\n"
             "向南走出石門返回【周天星律院】。\n");

    set_exits(([
        "south": "/d/sects/taiqing/star_law_hall.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", WHT "天柱背陰山腹石室陰冷乾燥，角落蟲蛀舊箱的銅鎖覆滿陳年灰塵。" NOR);
    set_smell("default", YEL "數百年羊皮星曆卷宗、防蟲樟腦丸與陳舊松煙墨混雜的古書房氣息。" NOR);
    set_listen("default", WHT "山腹石室四面厚壁隔絕外風，只聽得見分規尺輕叩案面與細微翻卷聲。" NOR);

    spawn_npc("/clone/npc/yu_shouzhuo.c");
}

void init() {
    ::init();
    add_action("do_collate", "collate");
}

int do_collate(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "archive" && arg != "starlog" && arg != "星圖" && arg != "秘閣") {
        notify_fail("你想校讀什麼檔案？試試：collate archive\n");
        return 0;
    }
    message_vision("$N不動火折子亦不催動靈力，僅以雙腳分規與細頭炭筆比對東廂甲字三架\n"
                   "北境粗麻原卷與南境青檀宣紙定本，赫然抄下「甲子冬至相鄰七十餘星宿被順時針\n"
                   "人為平推一度半」之紙墨斷層紀錄！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "collate", "target": "archive" ]));
    }
    return 1;
}
