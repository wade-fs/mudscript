// clone/npc/mo_beggar.c
// 瘸腿老丐 莫三 - 客棧後巷柴房的市井老乞兒

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("莫三");
    set_short(WHT "瘸腿老丐" NOR " 莫三");
    set_long("一位披著幾層破爛油垢粗麻破布的枯瘦老乞丐，左腿受過陳年重傷，怪異蜷縮著。\n"
             "他臉上沾滿泥灰，亂髮糾結如蓬蒿，但一雙骨碌碌亂轉的小眼卻極為敏銳精明。\n"
             "他正斜靠著潮濕柴堆，一邊在粗布衣領抓蝨子，一邊側耳傾聽前街客棧茶棚的動靜。\n");
    set_id(({ "mo", "beggar", "old beggar", "mo san", "莫三", "老丐", "老叫花" }));

    set_level(18);
    set_stat("per", 28);
    set_stat("dex", 22);
    set_stat("int", 20);
    recalc_stats();

    set_skill_to_teach("dream_sleep", 10);

    add_response(({ "心法", "功法", "睡夢大法", "調息", "睡覺", "dream_sleep" }),
        "叫花子捱餓受凍，哪來的靈丹妙藥？全靠老祖宗傳下來的一手『睡夢大法(初級)』(learn dream_sleep from mo)！" +
        "睡夢中如老龜蟄伏，哪怕天塌下來也當被蓋，最能養足精氣神！");

    add_response(({ "討飯", "乞討", "beg", "市井" }), 
        "在泥濘市井裡刨食，臉皮要比城牆厚，眼色要比野狗尖！誰兜裡有銅板、哪家客棧後廚倒泔水" +
        "帶肉沫，全憑這一雙眼力辨識！");

    add_response(({ "消息", "傳聞", "news" }), 
        "想打聽黑石鋪的底細？老叫花這雙招風耳可不是吃乾飯的！金石商會哪天進山、" +
        "鐵匠鋪接了什麼軍械暗活、北崖礦坑哪條道鬧地煞，前街客棧飄出來的三言兩語我都聽得一清二楚！");

    add_response(({ "身世", "乞兒", "乾糧袋", "background" }), 
        "你從小跟我縮在這破柴房裡避冬，脖子上掛的那只粗布乾糧袋縫了十七八道粗麻補丁。" +
        "咱們雖然命比紙薄，但看遍人情冷暖，只要胸口這口氣不咽，就沒人能把咱們踩死！");

    add_response(({ "金石城", "路引", "城門" }), 
        "去金石城？省省吧！城門口的城防軍凶得像狼，見了窮鬼一腳踹下護城河。" +
        "要想進城，非得在黑石鋪弄到商隊或百工的保書路引不可！");

    add_response(({ "天門引", "古令", "令牌", "token" }), 
        "三十年前，老子也是金石商會名震大荒的第一快刀趟子手！在大荒深處掘出史前商盟通關神令，" +
        "金石城那幫雜碎勾結軍中伏擊老子，三十位同生共死的兄弟全被射成刺蝟！唯有老子吞下此令、拖著斷腿爬回黑石鋪！");

    add_response(({ "黑石關", "關卡", "封路" }), 
        "城防軍大統領要吃金石商會三成乾股，才生生卡死黑石關！一張蓋硃砂印的保書路引黑市炒到八十兩，" +
        "但跟太古天門引相比，廢紙罷了！");

    add_response(({ "腿", "斷腿", "仇", "血仇" }), 
        "老子這條瘸腿，浸著三十位把兄弟的血！總有一天，這筆血債要從金石城那些道貌岸然的老爺身上連皮帶骨剁回來！");
}

int accept_object(object who, object ob) {
    if (!who || !ob) return 0;

    if (ob->id("tianmen token") || ob->query("relic_type") == "shang_token") {
        tell_object(who, HIY "莫三渾濁的老眼中猛地爆發出前所未有的仇恨與熾熱，雙手顫抖著捧著青金古令，仰天厲笑：\n" +
                             "「好！好一匹狼崽子！你果然把老子藏了三十年的命根子給刨出來了！\n" +
                             "三十年前三十位把兄弟的血海深仇，老子沒忘，這面【天門引】也沒忘！\n" +
                             "八十兩銀子的官府路引，能帶你進城給人當奴才；但這枚天門引，能帶你踩著那些官老爺的腦袋，走上真正的九天商道！」\n" NOR);
        tell_object(who, HIG "莫三抹了一把老淚，慎重地將天門引塞回你胸前縫滿補丁的乾糧袋中。\n" NOR);
        who->add("exp", 100);
        return 1;
    }

    if (ob->id("dry meat") || ob->id("meat") || ob->query("is_food")) {
        tell_object(who, HIG "莫三一把搶過肉乾，狼吞虎嚥地嚼著，含糊不清地誇道：「算你小子有孝心！沒白疼你一場！」\n" NOR);
        destruct(ob);
        return 1;
    }

    if (ob->id("broken bowl") || ob->query("is_bowl")) {
        tell_object(who, YEL "莫三瞪了你一眼：「拿著破碗去前街要飯、打探消息去！把碗給老子幹啥？老子牙口不好又啃不動陶土！」\n" NOR);
        return 1;
    }

    return 0;
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    object ws = load_object(WORLD_STATE_D);

    if (topic == "黑石關" || topic == "關卡" || topic == "封路" || topic == "官軍" || topic == "商隊" || topic == "news") {
        if (ws) {
            tell_object(me, query_name() + " 嗤笑一聲，壓低嗓子道：「" + ws->query_garrison_narrative(1) + " 一張蓋硃砂印的保書路引黑市炒到八十兩，但在太古天門引面前，不過是張擦屁股的廢紙！」\n");
            return 1;
        }
    }

    if (topic == "異動" || topic == "獸群" || topic == "野獸") {
        if (ws) {
            tell_object(me, query_name() + " 側耳聽著風聲，哼道：「" + ws->query_beast_movement_narrative(1) + "」\n");
            return 1;
        }
    }

    return ::do_chat(me, topic);
}
