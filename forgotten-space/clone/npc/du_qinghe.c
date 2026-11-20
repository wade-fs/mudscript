// /clone/npc/du_qinghe.c
// 杜青禾・八荒傷兵養息院醫官 (du_qinghe) - 傷兵養息院 (Ch.93)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("杜青禾");
    set_short(GRN "傷兵養息院醫官" NOR " 杜青禾");
    set_long("三十三歲的女醫官，曾是煞血營弟子，因早年強行催動煞血功震傷內臟而轉入醫務。\n"
             "她手端黑陶藥盤與病案紀錄簿，在理想與前線保命之間苦苦記錄著每一名宿將的病程。\n");
    set_id(({ "du_qinghe", "du qinghe", "qinghe", "杜青禾", "醫官" }));

    setup_archetype("F", 68);
    set("class", "wu");
    set("faction", "bahuang");
    set("roles", ({ "doctor", "recorder", "quest" }));
    set("home_room", "/d/sects/bahuang/restoration_hall.c");

    add_response(({ "傷兵", "咳血", "燥火", "病案" }),
        "杜青禾輕輕合上病案簿，眉頭鎖緊：「練《煞血霸體訣》引地煞入髓久了，氣血反過來烤乾五臟，\n"
        "老兵白日還能扛百斤戟，夜裡卻控制不住地躁狂、向銅盆吐瀝青狀黑血塊。\n"
        "我是個醫官，只記體溫、脈象、脾胃衰弱跟失控天數——在沒驗清藥理成分前，不要亂給前線扣黑帽子。」");

    add_response(({ "急鎮丸", "定心急鎮丸", "藥丸", "丹鼎宗" }),
        "杜青禾壓低聲音：「這叫『定心急鎮丸』，沒有公開藥單，每月只按軍務配額從丹鼎宗或雲津秘道領來。\n"
        "連雷將軍這個月都超量乾吞三次了……我明知越吃脾胃越僵，可明早就要守長城豁口，不吃又怎麼撐過今晚？」");
}
