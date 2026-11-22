// clone/npc/folk/yunjin_tea_vendor.c
// 茶市老孫頭・雲津山神廟會茶市（北境散修、說書與地方茶市）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("茶市老孫頭");
    set_short(HIY "廟會茶攤" NOR " 老孫頭");
    set_long("一位戴著氈帽、守著滾燙大銅壺在山神廟外賣磚茶與炒黃豆的乾瘦老漢。\n"
             "他見慣了三宗外門弟子與北境走山客在茶攤上高談闊論，自己卻只默默數著銅板。\n");
    set_id(({ "yunjin_tea_vendor", "old sun", "tea_vendor", "茶市老孫頭", "老孫頭", "茶販" }));

    setup_archetype("F", 10);
    set("class", "mortal");
    set("faction", "yunjin");
    set("roles", ({ "shop", "info" }));
    set("no_combat", 1);

    add_response(({ "廟會", "磚茶", "散修", "聽戲" }),
        "老孫頭往大碗裡倒滿滾熱濃磚茶笑道：「甭管你是哪家宗門高徒還是走商的，進了這山神廟會喝碗兩文錢的熱磚茶、聽一段北方皮影鼓詞（listen_opera），心裡那點北風寒氣全散了！」");
    add_response(({ "北荒", "風聲", "雪原" }),
        "老孫頭壓低聲音：「這陣子往北邊去的腳夫十個回來三個，個個臉色發青，說什麼黑山外面雪原上連野狼都不敢亂叫了。」");
}
