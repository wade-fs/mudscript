// clone/npc/center_teacher_lu.c
// 金石學塾塾師 陸夫子 - 三日通牒合法身分緩衝路徑 A

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("陸夫子");
    set_short(CYN "學塾塾師" NOR " 陸夫子");
    set_long("一位頭戴儒巾、手持戒尺的老夫子，神態嚴肅古板。\n"
             "他在金石學塾設席講授前朝政制與初階道藏，為入城無依流民提供文墨謄抄以謀合法身份。\n");
    set_id(({ "teacher_lu", "lu", "scholar", "陸夫子", "夫子" }));

    set_level(20);
    set_stat("int", 30);
    recalc_stats();

    add_response(({ "抄書", "青衿", "身分", "通牒", "緩衝" }),
        "陸夫子扶正戒尺道：「流民初入府城，若無道牒，三日即淪為瘋魔流民。可願在學塾謄抄五卷《道藏初訓》以代保證金？老夫賜你【學塾白鹿青衿】，保你十四日合法居留。」");
}

int do_chat(object me, string topic) {
    if (!me || !topic || topic == "") return 0;
    if (string_in(topic, "抄書, copy, 青衿, 登記")) {
        if (!present("academy token", me) && !present("qingjin", me)) {
            object token = clone_object("/clone/item/academy_token.c");
            if (token) {
                token->move(me);
                tell_object(me, HIG "【陸夫子點頭稱善，為你簽立抄書契約，贈予一件《學塾白鹿青衿》！】\n" NOR);
                return 1;
            }
        } else {
            tell_object(me, YEL "陸夫子道：「你身上已有學塾青衿，安心謄抄經卷即可。」\n" NOR);
            return 1;
        }
    }
    return 0;
}
