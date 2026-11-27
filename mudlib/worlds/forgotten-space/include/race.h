#ifndef RACE_H
#define RACE_H

/* 
   物種 (Species/Race) 定義 
   格式：([ "id" : ([ "name": "名稱", "desc": "說明", "stats": ([ "str": 0, ... ]) ]) ])
*/

#define RACE_DATA ([ \
    "human" : ([ \
        "name" : "人族", \
        "desc" : "大乾王朝與邊陲地帶的凡人百工，六維均衡，兼具力、法、物三道潛質。", \
        "stats" : ([ "str": 2, "con": 2, "int": 2, "spi": 2, "dex": 2, "per": 2 ]) \
    ]), \
    "mountain_folk" : ([ \
        "name" : "山民", \
        "desc" : "世代居於南嶺與重石深山的獵戶石工，臂力與根骨強健。", \
        "stats" : ([ "str": 4, "con": 4, "int": 0, "spi": 0, "dex": 2, "per": 2 ]) \
    ]), \
    "river_folk" : ([ \
        "name" : "水鄉民", \
        "desc" : "常年行舟於青河與濁水之間的住民，靈巧與感知敏銳。", \
        "stats" : ([ "str": 1, "con": 1, "int": 2, "spi": 2, "dex": 3, "per": 3 ]) \
    ]) \
])

/* 
   天性 (Nature/Personality) 定義 
   影響初始技能或微幅六維屬性修正
*/
#define NATURE_DATA ([ \
    "brave" : ([ \
        "name" : "勇猛", \
        "desc" : "氣血充沛，近身搏殺時更具爆發力。", \
        "stats" : ([ "str": 3, "con": 1 ]), \
        "skills": ({ "unarmed" }) \
    ]), \
    "wise" : ([ \
        "name" : "悟道", \
        "desc" : "神識清明，對天地法理與星象感應敏銳。", \
        "stats" : ([ "int": 3, "spi": 1 ]), \
        "skills": ({ "dao_tuna" }) \
    ]), \
    "agile" : ([ \
        "name" : "機巧", \
        "desc" : "手眼靈巧，善於辨析物性與結構破綻。", \
        "stats" : ([ "dex": 3, "per": 1 ]), \
        "skills": ({ "dodge" }) \
    ]), \
    "tough" : ([ \
        "name" : "堅毅", \
        "desc" : "筋骨強韌，能承受嚴酷環境與重負荷勞作。", \
        "stats" : ([ "con": 3, "str": 1 ]), \
        "skills": ({ "parry" }) \
    ]) \
])

#endif
