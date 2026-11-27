// /clone/item/hometown_letters_bag.c
// 【南方故人加急家書驛袋】（第三卷 Ch.125：蘇凝霜、阿鐵、葛半仙、趙老獵與枯木老道）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("故人家書驛袋", ({ "hometown_letters_bag", "letters_bag", "故人家書", "家書驛袋" }));
    set_short(HIG "邱禾轉交・【南方故人加急家書驛袋】" NOR);
    set_long("沉甸甸的油布縫口驛袋，分裝著五位黑石鋪與金石故人託冬糧車隊捎上的信物：\n"
             "・蘇凝霜親筆小楷：「虎跳峽今春跑通三百輛重車……這人間的後路便永遠替你們留著。」\n"
             "・老鐵匠阿鐵託人代筆三行歪字：「錘子是硬的，人是活的，別把自己活成死鐵柱。」\n"
             "・葛半仙附三包新收野菊花種與一撮防蟲草灰：「死不了就給老頭子留口氣寫張方子回來。」\n"
             "・趙老獵由魯大山代寫短訊：「找不到你大伯也別拿命往死坑裡填。」\n"
             "・夾在袋底無字無署名的一截冷松枝纏半截洗淨細麻繩——是破落道觀枯木老道的默送。\n");
    set_weight(160);
    set_value(0);
    set("is_lore", 1);
}
