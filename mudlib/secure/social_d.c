// /secure/social_d.c
// 社交動作守護進程 (Social Daemon)
// 管理遊戲中預設的社交動作與描述

#include "/include/ansi.h"

inherit "/std/object";

mapping socials;

void create() {
    ::create();
    socials = ([
        "smile": ([
            "en": "You smile broadly.",
            "zh-TW": "你露出了燦爛的笑容。",
            "zh-CN": "你露出了灿烂的笑容。",
            "icon": "😊"
        ]),
        "laugh": ([
            "en": "You laugh out loud.",
            "zh-TW": "你哈哈大笑了起來。",
            "zh-CN": "你哈哈大笑了起来。",
            "icon": "😆"
        ]),
        "nod": ([
            "en": "You nod in agreement.",
            "zh-TW": "你點了點頭表示贊同。",
            "zh-CN": "你点了点表表示赞同。",
            "icon": "👍"
        ]),
        "shake": ([
            "en": "You shake your head slowly.",
            "zh-TW": "你緩緩地搖了搖頭。",
            "zh-CN": "你缓缓地摇了摇头。",
            "icon": "👎"
        ]),
        "cry": ([
            "en": "You sob quietly.",
            "zh-TW": "你低聲抽泣著。",
            "zh-CN": "你低声抽泣著。",
            "icon": "😭"
        ]),
        "wave": ([
            "en": "You wave goodbye.",
            "zh-TW": "你揮了揮手打招呼。",
            "zh-CN": "你挥了挥手打招呼。",
            "icon": "👋"
        ]),
        "shrug": ([
            "en": "You shrug your shoulders.",
            "zh-TW": "你聳了聳肩表示無奈。",
            "zh-CN": "你耸了耸肩表示无奈。",
            "icon": "🤷"
        ]),
        "sigh": ([
            "en": "You let out a long sigh.",
            "zh-TW": "你長長地嘆了一口氣。",
            "zh-CN": "你长长地叹了一口气。",
            "icon": "😔"
        ]),
        "think": ([
            "en": "You seem lost in thought.",
            "zh-TW": "你陷入了沉思之中。",
            "zh-CN": "你陷入了沉思之中。",
            "icon": "🤔"
        ]),
        "dance": ([
            "en": "You dance around happily.",
            "zh-TW": "你開心地手舞足蹈。",
            "zh-CN": "你开心地手舞足蹈。",
            "icon": "💃"
        ])
    ]);
}

mapping query_socials() { return socials; }

// 執行社交動作
int execute_social(object me, string verb, string arg) {
    if (!socials[verb]) return 0;
    
    mapping data = socials[verb];
    string msg = select_lang(data);
    
    // 如果有目標
    if (arg) {
        object target = present(arg, environment(me));
        if (target && living(target)) {
            string target_name = target->query_name();
            string my_msg = "";
            string room_msg = "";
            
            switch(verb) {
                case "smile": 
                    my_msg = "你對著 " + target_name + " 微微一笑。"; 
                    room_msg = me->query_name() + " 對著 " + target_name + " 微微一笑。";
                    break;
                case "laugh": 
                    my_msg = "你對著 " + target_name + " 哈哈大笑。"; 
                    room_msg = me->query_name() + " 對著 " + target_name + " 哈哈大笑。";
                    break;
                default:
                    my_msg = "你對著 " + target_name + " 做了一個 " + verb + " 的動作。";
                    room_msg = me->query_name() + " 對著 " + target_name + " 做了一個 " + verb + " 的動作。";
            }
            write(my_msg + "\n");
            say(room_msg + "\n");
            return 1;
        }
    }

    // 無目標廣播
    write(msg + "\n");
    say(me->query_name() + " " + substr(msg, 2, strlen(msg)-2) + "\n");
    return 1;
}

// 取得提供給前端的清單
mapping get_ui_list() {
    mapping list = ([]);
    string *ks = keys(socials);
    foreach (string k in ks) {
        list[k] = ([ 
            "label": select_lang(socials[k]),
            "icon": socials[k]["icon"]
        ]);
    }
    return list;
}
