// clone/npc/zhao_hunter.c
// 老獵戶 趙老獵 - 林邊哨亭的老獵人

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("趙老獵");
    set_short(GRN "老獵戶" NOR " 趙老獵");
    set_long("一位身形瘦削精悍的老獵人，人稱趙老獵，村裡晚輩與張屠戶等熟人也常呼他為「趙老頭」。\n"
             "臉頰被大荒山風吹得如同枯乾老樹皮，雙目卻亮得宛如夜隼。他身著一件油光發亮的陳舊鹿皮背心，\n"
             "腰間懸著角刀與牛角藥壺，腿上留有幾道被兇獸利爪撕裂的可怖深疤。他正坐在門檻上專注地削製著竹箭。\n");
    set_id(({ "zhao", "hunter", "old hunter", "趙老獵", "老獵戶", "獵戶", "趙老頭", "老趙頭", "zhao laotou" }));

    set_level(22);
    set_stat("dex", 28);
    set_stat("per", 26);
    set_stat("str", 20);
    recalc_stats();

    set_skill_to_teach("beast_breath", 10);

    add_response(({ "心法", "功法", "山林龜息法", "龜息法", "調息", "beast_breath" }),
        "在深山老林裡伏擊凶獸，氣息哪怕粗了一分都會驚走獵物！學學這門『山林龜息法(初級)』(learn beast_breath from zhao)，" +
        "呼吸細若游絲卻綿密深長，最能收斂氣機、恢復體力！");

    add_response(({ "打獵", "狩獵", "hunt", "大荒" }), 
        "在大荒裡討生活，光靠死力氣走不遠！靈巧的身法是避劫的根本，敏銳的感知能救你的命。" +
        "一絲腐葉微動、一滴野獸腥臊，都分得出活路還是死局！");

    add_response(({ "陷阱", "trap", "機巧" }), 
        "林口我下了幾副竹刺吊套。去東面荒林走走，蹲下身調校竹刺彈簧與套鎖 (trap)，" +
        "把雙手指節和眼力磨得靈巧了，才算入了門！");

    add_response(({ "身世", "柴刀", "background" }), 
        "你從小在大荒林莽與猛獸尖牙下長大，手裡那把生鏽柴刀是你大伯當年進深山前留給你的。" +
        "刀背厚重，砍柴劈路、防狼斷喉全靠它，別弄丟了。");

    add_response(({ "野獸", "異動", "狼群" }), 
        "這幾日深山裡總有些古怪聲響，夜裡連狼群都不敢在斷魂嶺多啼。大荒深處有些不可說的古物，" +
        "莫要貪功冒進。");

    add_response(({ "圖騰", "戰神", "totem" }), 
        "太古大清洗之前，力道宗師以純粹肉身撕天裂地，在荒林泥沼深處留有太古戰神獵獸圖騰。" +
        "若能以肉身氣血與圖騰共鳴 (totem)，蠻荒戰意將淬入筋骨！");

    add_response(({ "濁血", "煞氣", "異獸" }), 
        "深山地煞能讓走獸異變嗜血，流出紫黑濁血。獵這種兇物，需備好鐵胎柘木重弓 (heavy bow) 與破甲竹箭！");
}

int accept_object(object who, object ob) {
    if (!who || !ob) return 0;

    if (ob->id("tainted pelt") || ob->query("is_tainted_pelt")) {
        tell_object(who, HIG "趙老獵接過染煞異獸皮翻看，指尖摸過深紫色的焦灼焦痕，倒吸一口涼氣：\n" +
                             "「好濃烈的地煞凶腥！這是深山泥沼那頭巨獸蛻下的皮甲！\n" +
                             "好小子，身法果決、膽大心細，沒給咱們獵戶丟臉！拿著這袋鹿肉乾，進山補足氣力！」\n" NOR);
        object meat = clone_object("/clone/item/dry_meat.c");
        if (meat) {
            meat->move(who);
        }
        who->add("exp", 60);
        destruct(ob);

        object career = load_object(CAREER_D);
        if (career && (career->query_chain_stage(who, "li") == 3 || career->query_chain_stage(who, "li") == 4)) {
            career->advance_chain_stage(who, "li");
        }
        return 1;
    }

    if (ob->id("heavy bow") || ob->query("is_heavy_bow")) {
        tell_object(who, YEL "趙老獵撫摸著鐵胎柘木弓身，點頭道：「這張硬弓是深山伏獵的重器，好生收著，拉滿弓弦需要足夠的臂力！」\n" NOR);
        return 1;
    }

    return 0;
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    object ws = load_object(WORLD_STATE_D);

    if (topic == "野獸" || topic == "異動" || topic == "狼群" || topic == "獸潮" || topic == "大荒" || topic == "hunt") {
        if (ws) {
            tell_object(me, query_name() + " 望著東面密林，神情嚴峻道：「" + ws->query_beast_movement_narrative(1) + "」\n");
            return 1;
        }
    }

    if (topic == "商隊" || topic == "封路" || topic == "黑石關" || topic == "官軍") {
        if (ws) {
            tell_object(me, query_name() + " 哼了一聲道：「" + ws->query_garrison_narrative(1) + "」\n");
            return 1;
        }
    }

    if (topic == "路引" || topic == "出鄉" || topic == "文牒" || topic == "ceremony" || topic == "pass") {
        if (me->query_level() < 10) {
            tell_object(me, query_name() + " 吐出一口草根，搖頭道：「大荒深處與黑石關外儘是豺狼凶煞，手底下沒硬功夫（需達 10 級）出鄉，只會白白送命！且把筋骨底子再磨練磨練！」\n");
            return 1;
        }
        if (me->query("quest/pass_village_ceremony")) {
            tell_object(me, query_name() + " 笑道：「你早已取得出鄉文牒，大荒萬里任你馳騁！」\n");
            return 1;
        }
        object qd = load_object("/secure/quest_d.c");
        if (qd) {
            if (!me->query_quest("pass_village_ceremony")) {
                qd->accept_quest(me, "pass_village_ceremony");
            }
            qd->complete_quest(me, "pass_village_ceremony");
            me->set("quest/pass_village_ceremony", 1);
            tell_object(me, HIY + query_name() + " 咧嘴大笑，重重拍了拍你的肩膀：「好小子！以你如今的筋骨氣魄（已達 10 級），黑石鋪困不住你這頭大荒獵隼。老夫以老獵戶的名義替你具保，這紙金石城官辦保書路引你且收好！」\n" + NOR);
            return 1;
        }
    }

    if (topic == "任務" || topic == "生計" || topic == "job" || topic == "career" || topic == "力修") {
        object career = load_object(CAREER_D);
        int st = career ? career->query_chain_stage(me, "li") : 0;
        if (st == 0 || st == 1) {
            if (st == 0) career->start_chain(me, "li");
            career->advance_chain_stage(me, "li");
            tell_object(me, query_name() + " 望著東面密林道：「東林深處獸群受地煞激盪暴動！你去東面荒林調校獵戶陷阱 (trap)，順著濁血追蹤異獸 (track)！」\n");
            return 1;
        } else if (st == 2) {
            tell_object(me, query_name() + " 催促道：「荒林陷阱與濁血排查得如何了？去林中調校陷阱 (trap) 與追蹤 (track)！」\n");
            return 1;
        } else if (st == 3) {
            tell_object(me, query_name() + " 說道：「帶上獸皮去溪灘找張屠戶，他那把剔骨刀最擅對付異獸筋骨，在石板上磨刀抗煞！」\n");
            return 1;
        } else if (st == 4) {
            tell_object(me, query_name() + " 讚許道：「把獵得的染煞異獸皮交給我 (give tainted pelt to zhao)，老子檢視你的搏殺成果！」\n");
            return 1;
        }
    }

    return ::do_chat(me, topic);
}
