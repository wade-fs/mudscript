// /secure/guild_d.c
// 公會守護進程 (Guild Daemon)

#include "/include/ansi.h"

inherit "/std/object";

mapping guilds;

void create() {
    ::create();
    guilds = ([
        "adventurer": ([
            "name": ([ "en": "Wanderers Hall", "zh-TW": "江湖行館", "zh-CN": "江湖行馆" ]),
            "desc": ([ "en": "Welcome all wanderers, this is your starting post.", "zh-TW": "歡迎所有志在四方的行者，這裡是你的初入驛站。", "zh-CN": "欢迎所有志在四方的行者，这里是你的初入驿站。" ]),
            "ranks": ({ 
                ([ "en": "Novice Wanderer", "zh-TW": "初入江湖客", "zh-CN": "初入江湖客" ]),
                ([ "en": "Official Wanderer", "zh-TW": "持牒遊俠", "zh-CN": "持牒游侠" ]),
                ([ "en": "Senior Wanderer", "zh-TW": "資深行者", "zh-CN": "资深行者" ]),
                ([ "en": "Legendary Wanderer", "zh-TW": "名震一方", "zh-CN": "名震一方" ])
            }),
            "req": ([ "level": 1, "int": 10, "str": 10 ])
        ]),
        "dao_initiate": ([
            "name": ([ "en": "Xuandaosi Registry", "zh-TW": "金石宣道司", "zh-CN": "金石宣道司" ]),
            "desc": ([ "en": "The official observatory of Spirit (Fa) and celestial laws.", "zh-TW": "掌管觀星望氣、繪符鎮煞與度牒核發之【法】道樞紐。", "zh-CN": "掌管观星望气、绘符镇煞与度牒核发之【法】道枢纽。" ]),
            "ranks": ({ 
                ([ "en": "Registered Initiate", "zh-TW": "外門記名經生", "zh-CN": "外门记名经生" ]),
                ([ "en": "Licensed Diviner", "zh-TW": "受牒觀象道人", "zh-CN": "受牒观象道人" ]),
                ([ "en": "Chief Ritualist", "zh-TW": "宣道司典籍", "zh-CN": "宣道司典籍" ]),
                ([ "en": "Grand Astrologer", "zh-TW": "欽天監正", "zh-CN": "钦天监正" ])
            }),
            "req": ([ "level": 5, "int": 20 ])
        ]),
        "wu_initiate": ([
            "name": ([ "en": "Bafang Martial Hall", "zh-TW": "八方行省武館", "zh-CN": "八方行省武馆" ]),
            "desc": ([ "en": "The bastion of Force (Li), blood-furnace cultivation and martial valor.", "zh-TW": "錘鍊肉身烘爐、氣血武道與押鏢軍鎮之【力】道總舵。", "zh-CN": "锤炼肉身烘炉、气血武道与押镖军镇之【力】道总舵。" ]),
            "ranks": ({ 
                ([ "en": "Outer Martial Recruit", "zh-TW": "外門武卒", "zh-CN": "外门武卒" ]),
                ([ "en": "Iron-Belt Vanguard", "zh-TW": "黑鐵銳士", "zh-CN": "黑铁锐士" ]),
                ([ "en": "Banner Commander", "zh-TW": "鎮武校尉", "zh-CN": "镇武校尉" ]),
                ([ "en": "Grand Marshal", "zh-TW": "八方武尊", "zh-CN": "八方武尊" ])
            }),
            "req": ([ "level": 5, "str": 20 ])
        ]),
        "gong_initiate": ([
            "name": ([ "en": "Baigong Artisans Guild", "zh-TW": "府城百工總會", "zh-CN": "府城百工总会" ]),
            "desc": ([ "en": "The guild of Matter (Wu), metallurgy, medicine and mechanisms.", "zh-TW": "匯聚鍛造、木作、醫毒與機巧之【物】道百工總樞。", "zh-CN": "汇聚锻造、木作、医毒与机巧之【物】道百工总枢。" ]),
            "ranks": ({ 
                ([ "en": "Registered Apprentice", "zh-TW": "註冊學徒", "zh-CN": "注册学徒" ]),
                ([ "en": "Licensed Artisan", "zh-TW": "正式大匠", "zh-CN": "正式大匠" ]),
                ([ "en": "Master Engineer", "zh-TW": "司匠主事", "zh-CN": "司匠主事" ]),
                ([ "en": "Grand Artificer", "zh-TW": "天工宗師", "zh-CN": "天工宗师" ])
            }),
            "req": ([ "level": 5, "dex": 20 ])
        ])
    ]);
}

mapping query_guild_info(string gid) { return guilds[gid]; }

int join_guild(object me, string gid) {
    mapping info = guilds[gid];
    if (!info) return 0;

    if (me->query_guild()) {
        if (me->query_guild() == gid) return 1; // 🚀 靜默處理：如果已經在該公會，直接回傳成功
        write(_t("guild_already_joined") + "\n");
        return 0;
    }

    mapping req = info["req"];
    string guild_name = to_string(select_lang(info["name"]));

    if (me->query_level() < req["level"]) {
        string err = to_string(_t("level_low_err"));
        err = replace_string(err, "$guild", guild_name);
        write(err + "\n");
        return 0;
    }
    if (req["int"] && me->query_stat("int") < req["int"]) {
        string err = to_string(_t("stat_low_err"));
        err = replace_string(err, "$stat", to_string(_t("stat_int")));
        err = replace_string(err, "$guild", guild_name);
        write(err + "\n");
        return 0;
    }
    if (req["str"] && me->query_stat("str") < req["str"]) {
        string err = to_string(_t("stat_low_err"));
        err = replace_string(err, "$stat", to_string(_t("stat_str")));
        err = replace_string(err, "$guild", guild_name);
        write(err + "\n");
        return 0;
    }

    me->set_guild(gid);
    me->set_guild_rank(to_string(select_lang(info["ranks"][0])));
    me->set_guild_exp(0);

    string success = to_string(_t("guild_join_success"));
    success = replace_string(success, "$guild", guild_name);
    write("$HIW$" + success + "$NOR$" + "\n");

    string rank_msg = to_string(_t("guild_rank_is"));
    rank_msg = replace_string(rank_msg, "$rank", to_string(me->query_guild_rank()));
    write(rank_msg + "\n");
    
    me->save();
    return 1;
}

int promote_member(object me) {
    string gid = me->query_guild();
    if (!gid) return 0;
    
    mapping info = guilds[gid];
    mixed *ranks = info["ranks"];
    
    // 找出目前職位在數組中的索引
    int current_idx = -1;
    for (int i = 0; i < sizeof(ranks); i++) {
        if (select_lang(ranks[i]) == me->query_guild_rank()) {
            current_idx = i;
            break;
        }
    }

    if (current_idx == -1 || current_idx >= sizeof(ranks) - 1) {
        write(_t("guild_max_rank") + "\n");
        return 0;
    }

    int req_exp = (current_idx + 1) * 1000;
    if (me->query_guild_exp() < req_exp) {
        string err = _t("guild_exp_low");
        err = replace_string(err, "$req", sprintf("%d", req_exp));
        write(err + "\n");
        return 0;
    }

    string next_rank = select_lang(ranks[current_idx + 1]);
    me->set_guild_rank(next_rank);
    
    string success = _t("guild_promote_success");
    success = replace_string(success, "$rank", next_rank);
    write("$HIY$" + success + "$NOR$" + "\n");
    
    me->save();
    return 1;
}

mapping query_all_guilds() { return guilds; }
