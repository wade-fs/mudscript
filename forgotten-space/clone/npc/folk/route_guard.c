// clone/npc/folk/route_guard.c
// 跨縣官道關卡什長／巡檢卒（依 WORLD_STATE_D 即時反映封關盤查與路引規定）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("關卡巡檢卒");
    set_short(WHT "官道關隘" NOR " 巡檢卒");
    set_long("一名身披半舊牛皮鑲鐵胸甲、手拄長槍站在拒馬旁的官道關卡兵卒。\n"
             "他每日盤查往來挑夫、騾馬車隊與無籍流民，依照金石府城發下的公文放行或索要通關路引。\n");
    set_id(({ "route_guard", "guard", "checkpoint_guard", "巡檢卒", "關卡巡檢卒", "官兵", "守卒" }));

    setup_archetype("D", 14);
    set("class", "mortal");
    set("faction", "city");
    set("roles", ({ "guard", "info" }));

    add_response(({ "通關", "盤查", "規矩", "check_pass" }),
        "巡檢卒把長槍往地上一墩：「想走官道進府城或往各縣辦事，最好備妥『金石路引』或商會保單！在這關口輸入『check_pass』便知今日放行與否。」");
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    object env = environment(this_object());
    mapping seg = env ? env->query_segment_info() : 0;
    object ws = load_object(WORLD_STATE_D);

    if (topic == "路引" || topic == "封關" || topic == "商隊" || topic == "世道") {
        string garr = ws ? ws->query_garrison_narrative(0) : "官道照常盤查放行。";
        string seg_name = mapp(seg) ? seg["name"] : "這段官道";
        tell_object(me, query_name() + sprintf(" 壓低嗓門道：「眼下【%s】由上面緊盯著：%s 要是沒路引硬闖，給巡檢司扣下可別怪咱們公事公辦。」\n",
            seg_name, garr));
        return 1;
    }

    return ::do_chat(me, topic);
}
