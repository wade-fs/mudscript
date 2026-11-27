// /secure/social_d.c
// 共用社交動作守護進程

#include "/include/ansi.h"

inherit "/std/object.c";

mapping socials;

void create() {
    ::create();
    socials = ([
        "smile": ([ "en": "You smile broadly.", "zh-TW": "你露出了燦爛的笑容。", "icon": "😊" ]),
        "laugh": ([ "en": "You laugh out loud.", "zh-TW": "你哈哈大笑了起來。", "icon": "😆" ]),
        "nod":   ([ "en": "You nod in agreement.", "zh-TW": "你點了點頭表示贊同。", "icon": "👍" ]),
        "shake": ([ "en": "You shake your head slowly.", "zh-TW": "你緩緩地搖了搖頭。", "icon": "👎" ]),
        "wave":  ([ "en": "You wave goodbye.", "zh-TW": "你揮了揮手打招呼。", "icon": "👋" ]),
        "sigh":  ([ "en": "You let out a long sigh.", "zh-TW": "你長長地嘆了一口氣。", "icon": "😔" ]),
        "think": ([ "en": "You seem lost in thought.", "zh-TW": "你陷入了沉思之中。", "icon": "🤔" ]),
        "clap":  ([ "en": "You clap your hands.", "zh-TW": "你熱烈地鼓掌。", "icon": "👏" ])
    ]);
}

mapping query_socials() { return socials; }

int execute_social(object me, string verb, string arg) {
    if (!socials[verb]) return 0;

    mapping data = socials[verb];
    string msg = select_lang(data);

    if (arg && arg != "") {
        object target = present(arg, environment(me));
        if (target && living(target)) {
            string target_name = target->query_name();
            write("你對著 " + target_name + " 做了一個 " + verb + " 的動作。\n");
            say(me->query_name() + " 對著 " + target_name + " 做了一個 " + verb + " 的動作。\n");
            return 1;
        }
    }

    write(msg + "\n");
    say(me->query_name() + " " + msg + "\n");
    return 1;
}

mapping get_ui_list() {
    mapping list = ([]);
    foreach (string k in keys(socials)) {
        list[k] = ([
            "label": select_lang(socials[k]),
            "icon": socials[k]["icon"]
        ]);
    }
    return list;
}
