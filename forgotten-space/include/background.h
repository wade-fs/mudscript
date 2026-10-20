// include/background.h
// 《遺忘的世界》(THE FORGOTTEN SPACE) 身世背景常數與配置

#ifndef BACKGROUND_H
#define BACKGROUND_H

#define BACKGROUND_DATA ([ \
    "herbalist" : ([ \
        "name" : "採藥孤兒", \
        "desc" : "常年攀附絕壁懸崖採擷草藥，手腳俐落、識百草。", \
        "story_hook" : "靠採藥維生，在山林與絕壁間討生活", \
        "verify_world" : "山地地形、藥草分布、採集、藥鋪、草藥知識", \
        "growth_direction" : "身法、感知、生存與物性知識", \
        "growth_desc" : "身法(DEX)與感知(PER)極佳，通曉草木地脈生存之理", \
        "base_stats" : ([ "str": 1, "con": 3, "dex": 5, "int": 2, "spi": 2, "per": 5 ]), \
        "growth_affinity" : ([ "dex": 200, "per": 200, "con": 130, "int": 100, "spi": 100, "str": 100 ]), \
        "item" : "/clone/item/herb_basket.c", \
        "item_desc" : "一只竹編藥簍", \
        "start_room" : "/d/village/herb_hut.c" \
    ]), \
    "smith" : ([ \
        "name" : "打鐵學徒", \
        "desc" : "在炭火與叮噹鐵砧聲中長大，臂力沉穩，耐得勞苦。", \
        "story_hook" : "從鐵匠鋪的工作與人際關係開始", \
        "verify_world" : "原料、燃料、鍛造、工具、商業與工匠生活", \
        "growth_direction" : "力量、體魄、工藝與材料知識", \
        "growth_desc" : "臂力(STR)與根骨(CON)卓絕，百工千錘百鍊耐勞苦", \
        "base_stats" : ([ "str": 5, "con": 5, "dex": 3, "int": 1, "spi": 1, "per": 3 ]), \
        "growth_affinity" : ([ "str": 200, "con": 200, "dex": 130, "per": 100, "int": 100, "spi": 100 ]), \
        "item" : "/clone/weapon/smith_hammer.c", \
        "item_desc" : "一把打鐵舊鐵錘", \
        "start_room" : "/d/village/forge.c" \
    ]), \
    "hunter" : ([ \
        "name" : "獵戶之子", \
        "desc" : "生長於荒山林莽，熟悉野獸習性與機巧陷阱。", \
        "story_hook" : "從狩獵、追蹤與山林生活開始", \
        "verify_world" : "動物習性、足跡、陷阱、獵物分布與交易", \
        "growth_direction" : "感知、敏捷、體魄與野外生存", \
        "growth_desc" : "感知(PER)與身法(DEX)出眾，機巧陷阱與荒山獵殺敏銳", \
        "base_stats" : ([ "str": 3, "con": 3, "dex": 4, "int": 1, "spi": 2, "per": 5 ]), \
        "growth_affinity" : ([ "per": 200, "dex": 180, "con": 140, "str": 130, "spi": 100, "int": 100 ]), \
        "item" : "/clone/weapon/rusty_blade.c", \
        "item_desc" : "一把生鏽柴刀", \
        "start_room" : "/d/village/hunter_cabin.c" \
    ]), \
    "daoist" : ([ \
        "name" : "破落道童", \
        "desc" : "曾於殘破道觀抄錄經卷，略識吐納與殘缺符文。", \
        "story_hook" : "從殘破道觀、經卷與符文開始", \
        "verify_world" : "道壇、古籍、知識傳承、殘缺符文與歷史謎團", \
        "growth_direction" : "精神、悟性、知識與法門理解", \
        "growth_desc" : "靈性(SPI)與悟性(INT)超然，靈台清虛洞悉天機符理", \
        "base_stats" : ([ "str": 1, "con": 2, "dex": 2, "int": 5, "spi": 6, "per": 2 ]), \
        "growth_affinity" : ([ "spi": 200, "int": 200, "con": 120, "dex": 100, "per": 100, "str": 100 ]), \
        "item" : "/clone/item/broken_scroll.c", \
        "item_desc" : "一卷泛黃殘卷", \
        "start_room" : "/d/village/daoist_temple.c" \
    ]), \
    "beggar" : ([ \
        "name" : "流浪乞兒", \
        "desc" : "混跡於市井泥濘，看遍人情冷暖，眼力靈活。", \
        "story_hook" : "從街市、客棧與人情世故開始", \
        "verify_world" : "NPC 關係、交易、情報、地方勢力與社會規則", \
        "growth_direction" : "感知、敏捷、交涉與應變", \
        "growth_desc" : "感知(PER)與靈巧(DEX)敏銳，看透人情冷暖通曉市井規矩", \
        "base_stats" : ([ "str": 2, "con": 2, "dex": 4, "int": 3, "spi": 2, "per": 5 ]), \
        "growth_affinity" : ([ "per": 200, "dex": 180, "int": 140, "con": 120, "spi": 100, "str": 100 ]), \
        "item" : "/clone/item/rough_pouch.c", \
        "item_desc" : "一個粗布乾糧袋", \
        "start_room" : "/d/village/shed.c" \
    ]) \
])

#define BACKGROUND_LIST ({ "herbalist", "smith", "hunter", "daoist", "beggar" })

#endif // BACKGROUND_H
