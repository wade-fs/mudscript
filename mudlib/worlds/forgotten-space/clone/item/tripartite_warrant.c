// clone/item/tripartite_warrant.c
// 三方會審三印合符裁決書 - 卷二第四幕終極裁決文卷

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("三方會審三印合符裁決書", ({ "tripartite warrant", "tripartite_warrant", "caijueshu", "裁決書", "合符裁決" }));
    set_short(HIY "【三方會審三印合符裁決書】" NOR);
    set_long("依據七百年《金石共治盟約》，由三方會審庭當堂聯合頒布之最高法定公文。\n"
             "黃絹公文之上，赫然蓋有金石府尹正堂官印（法度）、鎮武軍鎮黑石虎符（軍武）、\n"
             "以及常平倉後勤糧餉總印（民政）三印合符！\n"
             "裁定將商會副會長錢百川革職枷鎖投入死牢候審，強制破封三號大庫查抄十二萬兩現銀，\n"
             "分撥常平倉平糶、北關邊軍欠餉與通寶總號飛錢重啟，宣告蘇凝霜蒙冤昭雪！\n");
    set_weight(100);
    set_value(5000);
    set("is_legal_warrant", 1);
    set("warrant_type", "tripartite_verdict");
}
