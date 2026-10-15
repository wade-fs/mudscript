// include/background.h
// 《遺忘的世界》(THE FORGOTTEN SPACE) 身世背景常數與配置

#ifndef BACKGROUND_H
#define BACKGROUND_H

#define BACKGROUND_DATA ([ \
    "hunter" : ([ \
        "name" : "獵戶之子", \
        "desc" : "生長於荒山林莽，熟悉野獸習性與機巧陷阱。", \
        "item" : "/clone/weapon/rusty_blade.c", \
        "item_desc" : "一把生鏽柴刀", \
        "start_room" : "/d/village/hunter_cabin.c" \
    ]), \
    "daoist" : ([ \
        "name" : "破落道童", \
        "desc" : "曾於殘破道觀抄錄經卷，略識吐納與殘缺符文。", \
        "item" : "/clone/item/broken_scroll.c", \
        "item_desc" : "一卷泛黃殘卷", \
        "start_room" : "/d/village/daoist_temple.c" \
    ]), \
    "beggar" : ([ \
        "name" : "流浪乞兒", \
        "desc" : "混跡於市井泥濘，看遍人情冷暖，眼力靈活。", \
        "item" : "/clone/item/rough_pouch.c", \
        "item_desc" : "一個粗布乾糧袋", \
        "start_room" : "/d/village/shed.c" \
    ]), \
    "herbalist" : ([ \
        "name" : "採藥孤兒", \
        "desc" : "常年攀附絕壁懸崖採擷草藥，手腳俐落、識百草。", \
        "item" : "/clone/item/herb_basket.c", \
        "item_desc" : "一只竹編藥簍", \
        "start_room" : "/d/village/herb_hut.c" \
    ]), \
    "smith" : ([ \
        "name" : "打鐵學徒", \
        "desc" : "在炭火與叮噹鐵砧聲中長大，臂力沉穩，耐得勞苦。", \
        "item" : "/clone/weapon/smith_hammer.c", \
        "item_desc" : "一把打鐵舊鐵錘", \
        "start_room" : "/d/village/forge.c" \
    ]) \
])

#define BACKGROUND_LIST ({ "herbalist", "smith", "hunter", "daoist", "beggar" })

#endif // BACKGROUND_H
