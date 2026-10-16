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
        return 1;
    }

    if (ob->id("scroll") || ob->query("is_scroll")) {
        tell_object(who, YEL "枯木老道撫摸著殘卷墨跡，淡淡道：「殘缺無妨，道理在心不在紙，且收好自行研習。」\n" NOR);
        return 1;
    }

    return 0;
}
