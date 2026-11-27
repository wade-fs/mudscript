// /secure/quest_d.c
// 輕量級任務註冊後備守護進程

inherit "/std/object.c";

mapping quest_list;

void create() {
    ::create();
    quest_list = ([]);
}

void register_quest(string qid, mapping info) {
    if (!quest_list) quest_list = ([]);
    quest_list[qid] = info;
}

mapping query_quest_info(string qid) {
    return quest_list ? quest_list[qid] : 0;
}
