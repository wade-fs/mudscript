// clone/npc/kumu_daoist.c
// 盲眼老道 枯木 - 破落道觀的避世修行者

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("枯木");
    set_short(HIC "盲眼老道" NOR " 枯木");
    set_long("一位盤坐於發霉蒲團之上的枯槁老道，身著褪色補丁藍布道袍，鬚髮皓白如霜。\n"
             "他的雙目覆著一層厚厚灰白盲膜，但周身氣機如古井無波，隱隱透出一股悠遠道意。\n"
             "案几上燃著半截冷香，一本泛黃缺角的道經殘頁攤在膝前。他無聲撥弄著龜甲，\n"
             "彷彿正在推演著某種早已在大清洗中失傳的周天星軌。\n");
    set_id(({ "kumu", "daoist", "old daoist", "枯木", "老道", "道士", "盲眼老道" }));

    set_level(28);
    set_stat("int", 32);
    set_stat("spi", 30);
    set_stat("con", 18);
    recalc_stats();

    set_skill_to_teach("still_heart", 10);

    add_response(({ "心法", "功法", "止心大法", "still_heart" }),
        "天地靈氣早已暗藏道化之毒，尋常引氣入體無異飲鴆止渴。老道傳你這門『止心大法(初級)』(learn still_heart from kumu)，" +
        "專修止念存神、不引外邪，於靜坐吐納間自生清虛之氣！");

    add_response(({ "吐納", "修行", "meditate", "打坐" }), 
        "凡俗世人，強行搬運駁雜氣機，動輒道化瘋魔。唯有靈台空明、澄澈神識，" +
        "方能感應太古失落的清虛道意。可向老道請教『止心大法』(learn still_heart from kumu)，或登上後山孤岩殘壇盤膝打坐 (meditate)。");

    add_response(({ "殘卷", "經卷", "符文", "scroll" }), 
        "你身隨的那卷殘破引氣訣，乃是昔年道觀鼎盛時的古卷殘鈔。你可仔細研讀 (read scroll)，" +
        "印證『止心大法(初級)』的吐納真意。");

    add_response(({ "身世", "道童", "道觀", "background" }), 
        "大清洗之後，正統三清大道凋零，天下偽派各走偏門。這座殘觀雖漏風飄雨，" +
        "卻是天地間難得的清淨避劫之地。既在此修習，休得受山下濁世煙火牽扯。");

    add_response(({ "大清洗", "天命", "星象", "fate" }), 
        "世人皆以為日月如常、周天恆久，卻不知蒼穹之上的星軌早已逆行反震！" +
        "若非身負天命異數，終其一生也不過是迷障泥塵罷了。");

    add_response(({ "道化", "晶石", "仙氣", "daohua" }), 
        "世人皆以為天門仙氣是登仙大道，卻不知那是催生道化的無形詛咒！" +
        "修為越深，離天道越近，道化之期便越不可避！到頭來，不過是給天地這具腐屍增添人形晶石罷了！");

    add_response(({ "天羅地網", "窺天", "牢籠", "stargaze" }), 
        "蒼穹之上密佈著暗灰鎖鏈，周天二十八宿早已被穿透拘禁。這片天是座活體牢籠！" +
        "若無通天心性與避劫道行，莫要輕易以神識仰窺天羅！");
}

int accept_object(object who, object ob) {
    if (!who || !ob) return 0;

    if (ob->id("dao crystal") || ob->query("is_dao_crystal")) {
        tell_object(who, HIC "枯木老道空洞的眼眶微顫，伸出枯瘦如乾柴的手指摩挲著冰冷晶石，長嘆道：\n" +
                         "「這便是六十年前紫霄道宮三十六位元嬰真人在玉皇頂以身合道後留下的遺骸……\n" +
                         "漫天仙氣倒灌，肉身化晶，神魂俱滅！這不是天劫，是【道化（Dao-transformation）】！\n" +
                         "老道自剜雙目、自碎三成神識，方才苟活至今。你既已見過此物，定要切記：想活命，就別信這片天！」\n" NOR);
        tell_object(who, HIG "【枯木老道傳授了你一縷道家清心避劫心訣，你的心境更趨堅毅，獲得 100 點經驗！】\n" NOR);
        who->add("exp", 100);
        who->add(STAT_SPI, 1);
        destruct(ob);

        object career = load_object(CAREER_D);
        if (career && career->query_chain_stage(who, "fa") == 3) {
            career->advance_chain_stage(who, "fa");
        }
        return 1;
    }

    if (ob->id("scroll") || ob->query("is_scroll")) {
        tell_object(who, YEL "枯木老道撫摸著殘卷墨跡，淡淡道：「殘缺無妨，道理在心不在紙，且收好自行研習。」\n" NOR);
        return 1;
    }

    return 0;
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    if (topic == "路引" || topic == "出鄉" || topic == "文牒" || topic == "ceremony" || topic == "pass") {
        if (me->query_level() < 10) {
            tell_object(me, query_name() + " 雙目微闔，沙啞道：「大荒之外，偽天籠罩，殺機萬重。以你如今微弱道行（需達 10 級），若強行離鄉，頃刻化為齏粉。靈台未淨，莫談遠行。」\n");
            return 1;
        }
        if (me->query("quest/pass_village_ceremony")) {
            tell_object(me, query_name() + " 淡淡道：「你已獲道牒路引，去留隨心，好自為之。」\n");
            return 1;
        }
        object qd = load_object("/secure/quest_d.c");
        if (qd) {
            if (!me->query_quest("pass_village_ceremony")) {
                qd->accept_quest(me, "pass_village_ceremony");
            }
            qd->complete_quest(me, "pass_village_ceremony");
            me->set("quest/pass_village_ceremony", 1);
            tell_object(me, HIC + query_name() + " 空洞的雙眼微動，枯槁手指拂過一卷宣紙，烙下天道暗印：「你靈台清明，神識已具雛形（已達 10 級）。這紙金石城官辦保書路引你且收好，出關之後，切莫忘了心中明鏡……」\n" + NOR);
            return 1;
        }
    }

    if (topic == "任務" || topic == "生計" || topic == "job" || topic == "career" || topic == "法修" || topic == "傳道") {
        object career = load_object(CAREER_D);
        int st = career ? career->query_chain_stage(me, "fa") : 0;
        if (st == 0 || st == 1) {
            if (st == 0) career->start_chain(me, "fa");
            career->advance_chain_stage(me, "fa");
            tell_object(me, query_name() + " 閉目掐指道：「天地氣機逆亂，陰煞正順水脈滲入聚落。你去南谷溪灘掬水洗心 (wash) 並拓印殘碑 (tuoyin stele)，查探源頭！」\n");
            return 1;
        } else if (st == 2) {
            tell_object(me, query_name() + " 淡淡道：「既已拓得碑文，持拓片登上後方迎風殘壇盤膝入定 (meditate) 或仰觀星軌 (stargaze)！」\n");
            return 1;
        } else if (st == 3) {
            tell_object(me, query_name() + " 閉目道：「去孤岩殘壇體悟天地星軌（meditate 或 stargaze），歸來方可點化！」\n");
            return 1;
        } else if (st == 4) {
            tell_object(me, HIC "枯木老道空洞的眼眶微動，伸出枯槁食指，輕輕點在你的眉心靈台之上...\n" +
                                 "剎那間，一縷澄澈冰涼的太古道意如清泉灌注神識，心中雜念與陰煞濁氣蕩滌一空！\n" NOR);
            career->advance_chain_stage(me, "fa");
            return 1;
        } else {
            tell_object(me, query_name() + " 微微頷首道：「大道無形，靈台常清。好生體悟，切莫被偽天迷了道心。」\n");
            return 1;
        }
    }
    return ::do_chat(me, topic);
}

