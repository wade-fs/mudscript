// clone/npc/under_black_market_broker.c
// 鬼見愁・黑市牙商 (under_black_market_broker) - 地下鬼市暗街

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("鬼見愁");
    set_short(MAG "地下黑市牙商" NOR " 鬼見愁");
    set_long("一位戴著青銅半臉鬼面、披著寬大黑斗篷的神秘牙商，在磷火搖曳的地下鬼市收售違禁毒藥、無印生銅與黑貨。\n");
    set_id(({ "gui_jianchou", "under_black_market_broker", "guijianchou", "gui jianchou", "black market broker", "鬼見愁", "黑市牙商", "牙商" }));

    setup_archetype("I", 25);
    set("class", "mortal");
    set("faction", "jianghu");
    set("roles", ({ "shop", "broker", "info" }));
    set("schedule", "24h");

    add_response(({ "黑貨", "銷贓", "血精", "無印生銅", "毒藥" }),
        "鬼見愁發出夜梟般的低笑：「地面上四關查得再嚴又如何？濁水縣的黑水蟾毒、烈礬縣未打官印的私銅、乃至北崖流出來的地煞血精晶錠，只要你有銀子或暗號，鬼市裡應有盡有！」");

    add_response(({ "契版", "青銅契版", "史前" }),
        "鬼見愁壓低聲音：「這塊【史前商盟青銅契版殘片】是濁水暗河淘出來的古物。實不相瞞，過去半年在黑市大批掃貨收購高純血精的，正是那些身穿無標記長袍、持有二階名山靈石的採辦經生！」");

    add_response(({ "黑鐵箱", "萬寶閣", "舊約", "情報", "延命私盟" }),
        "鬼見愁發出夜梟似的低笑，伸出乾枯手指比出三道價碼：「雲海鬼市可不替你保什麼證據鏈！\n"
        "一枚靈石聽市井傳聞；五枚靈石說實見證——初七廿二半夜有人從萬寶閣後門扛出三口黑鐵箱，領隊穿著沒三宗標記的洗白灰布棉襖；\n"
        "三十枚靈石票不還價——昨日下午何萬金在後門茶攤差點掉了一本未上公所帳的『北境延命私盟』薄索引冊。\n"
        "那灰袍經生每回交割後常走萬寶閣後門與鬼市暗巷交界……你若敢散『通寶總號稽核跨州飛錢』風聲（wanbao_back_alley 指令：rumor audit），自有驚弓之鳥替你掉東西。」");

    add_response(({ "後勤契約", "九城舊約", "雲記副本" }),
        "鬼見愁冷哼一聲敲了敲青銅半面：「舊約交易副本上印著乙巳年未結代號『玄木』，經金石商會暗帳流向『丹鼎丙柒』與『天工赤火』——不過鬼市流出的紙片向來得拎去雲海票號雙邊互核才算數。」");
}
