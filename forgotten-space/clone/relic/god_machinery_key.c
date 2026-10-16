// clone/relic/god_machinery_key.c
// 太古神機密匙 - 蘇凝霜隨身攜帶、開啟北崖古採掘站的核心信物 (小說第10、12章)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("太古神機密匙", ({ "machinery key", "key", "神機密匙", "密匙", "鑰匙" }));
    set_short(HIY "太古神機密匙" NOR);
    set_long("一截長約半尺、非金非玉的奇異青銅古匙。匙身布滿了細微如蟻的微型齒輪\n"
             "與流動的暗金靈軌，握在手中時隱隱傳來與大地深處同頻的微弱心跳震鳴。\n"
             "這柄密匙是大掌櫃自大荒神魔古墓中掘出，乃是開啟北崖地底沉睡萬年的\n"
             "【太古神闕地脈採掘站】的唯一鑰匙。(史詩級任務信物)\n");
    set_weight(500);
    set_value(10000);
    set("no_sell", 1);
    set("no_drop", 1);
}
