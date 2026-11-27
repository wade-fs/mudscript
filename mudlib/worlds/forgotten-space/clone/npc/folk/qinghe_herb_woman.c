// clone/npc/folk/qinghe_herb_woman.c
// 採藥婦翠嬸・青河渡口與百草坪採藥婦人（渡口漲價、水勢與草藥日常互動） (Ch.59-64)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("採藥婦翠嬸");
    set_short(HIG "百草坪藥婦" NOR " 翠嬸");
    set_long("一位背著半滿竹編藥簍、褲腳捲到小腿並沾著河灘濕泥的中年婦人。\n"
             "她清早到百草坪剪洗靈草，上午趕去蘆花渡或駁船碼頭搭早班渡船賣草換鹽米，\n"
             "黃昏時總在河鮮粗茶棚歇腳跟鄰舍抱怨渡船船資又漲了。\n");
    set_id(({ "qinghe_herb_woman", "cuishen", "herb woman", "採藥婦翠嬸", "翠嬸", "藥婦" }));

    setup_archetype("H", 7);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "herbalist", "info" }));
    set("no_combat", 1);

    add_response(({ "渡船", "船資", "漲價", "水閘" }),
        "翠嬸拍著竹簍嘆氣道：「定神道觀上頭一落水閘，河水就淺得刮船底，船老大推說怕擱淺，連擺渡費都漲了兩文錢！咱們背兩斤洗靈草過河，扣掉船錢簡直白忙一場。」");
    add_response(({ "洗靈草", "百草坪", "柳伯" }),
        "翠嬸望了眼河面點頭道：「柳伯撐了三十年船，性子雖倔心腸倒熱，只要水路沒被山洪堵死，還是會留個船角幫咱們老少放藥簍。」");
    add_response(({ "纜樁", "漲水", "修樁" }),
        "翠嬸指著碼頭邊晃動的木樁焦急道：「上游水頭一放下來，渡船纜繩扯著老木樁嘎吱響，快去搶修加固一下纜樁 (repair mooring)，別讓藥船漂走啦！」");
}
