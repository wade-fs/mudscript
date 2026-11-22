// clone/npc/folk/county_worker.c
// 六縣地方底層匠工／藥農／礦工／石匠／漁民（展現非主線的平凡生計與地方細節）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("地方老匠工");
    set_short(WHT "風塵僕僕" NOR " 地方老匠工");
    set_long("一位皮膚粗糙、十指滿是老繭與泥垢的當地老手藝人。\n"
             "不論上面官府與商會怎麼鬥法，他每天想的仍是如何多掙幾十文養家活口。\n");
    set_id(({ "county_worker", "worker", "craftsman", "peasant", "地方老匠工", "老匠工", "苦力", "鄉民" }));

    setup_archetype("B", 8);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "info" }));

    add_response(({ "生計", "日子", "煩惱", "活計" }),
        "老匠工揉了揉發酸的腰背嘆道：「咱們莊稼漢與手藝人哪懂什麼大道統？只求官道別塌、米價別一天一個數，下工還能喝碗熱湯便謝天謝地啦。」");
    add_response(({ "送湯", "綠豆湯", "涼茶", "解暑" }),
        "老匠工接過陶罐咕嘟咕嘟灌了半肚子，抹著嘴長舒一口氣笑道：「嘶——這清涼回甘的熱天綠豆湯救命啊！替我多謝縣城官道旁茶棚的掌櫃，有空我把空罐還他！」");
    add_response(({ "石料", "大車", "條石", "裝車" }),
        "老匠工扶著墨斗朝大車棚方向點點頭：「這四塊重玄條石早已切齊驗過了！等大車鐵軸潤好牛油，天一亮就能套上挽馬直接起運。」");
    add_response(({ "薑湯", "驅瘴", "熱湯", "橋工" }),
        "老匠工搓著發冷的手腕灌下一大碗老薑熱湯，額角頓時冒出熱汗：「舒坦！有老譚這鍋薑湯撐著，夜裡值守浮橋就不怕濕毒入骨啦！」");
    add_response(({ "玄鐵", "爐渣", "廢料", "齒輪", "差事" }),
        "老匠工放下鐵銼抹了把臉上的油灰：「冷卻爐渣槽裡每天都沉著不少好玄鐵珠！你要不嫌水髒煙嗆，去【冷卻爐渣槽】幫我濾一勺出來（quench slag），拿回磨件棚算你一份額外工錢！」");
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    object env = environment(this_object());
    string cid = env ? env->query_county() : "";
    object ws = load_object(WORLD_STATE_D);
    mapping st = (ws && cid != "") ? ws->query_county_status(cid) : 0;

    if (topic == "工作" || topic == "手藝" || topic == "這裡" || topic == "辛苦") {
        string trade_msg = "扛貨修路";
        if (cid == "liefan") trade_msg = "背赤銅渣、防硫磺酸煙燒肺";
        else if (cid == "qinghe") trade_msg = "赤腳泡冷水洗草藥、盯著上游水閘開合";
        else if (cid == "panmu") trade_msg = "在林海濕霧裡拉大鋸放紅杉、防山坡落石";
        else if (cid == "zhenfeng") trade_msg = "頂著割臉朔風開採石英、替邊軍修護皮甲";
        else if (cid == "zhongshi") trade_msg = "拉萬斤條石絞盤、打楔子聽岩層裂聲";
        else if (cid == "zhuoshui") trade_msg = "冒著瘴氣淺灘淘金砂、還要防黑幫抽頭盤剝";

        tell_object(me, query_name() + " 擦了把額頭汗灰道：「我們整日都在" + trade_msg + "。" +
            (mapp(st) ? sprintf("這幾天縣裡『%s』，工錢沒漲幾文，傷藥卻貴得嚇人。", st["stage_desc"]) : "") + "」\n");
        return 1;
    }

    return ::do_chat(me, topic);
}
