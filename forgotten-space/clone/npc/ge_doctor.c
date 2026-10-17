// clone/npc/ge_doctor.c
// 瘋郎中 葛半仙 - 採藥草廬的怪異撫養者

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("葛半仙");
    set_short(CYN "瘋郎中" NOR " 葛半仙");
    set_long("一位披頭散髮、身著百納舊青布袍的老郎中，腰間繫著七八個大小葫蘆與皮囊。\n"
             "他身上常年瀰漫著苦草藥膏與黃酒的刺鼻怪味，雙目時而渾濁如泥、時而精芒畢露。\n"
             "雖然行事瘋癲、言語顛三倒四，但黑石鋪的鄉民都知道，他那一手採藥敷傷\n"
             "的偏方，曾救活過無數被毒蟲咬傷、被落石砸斷筋骨的採藥人與老礦工。\n");
    set_id(({ "ge", "doctor", "herbalist", "ge banxian", "葛半仙", "郎中", "瘋郎中" }));

    set_level(20);
    set_stat("int", 25);
    set_stat("spi", 20);
    set_stat("con", 15);
    recalc_stats();

    set_skill_to_teach("herb_breathe", 10);
    set_skill_to_teach("alchemy", 20);

    add_response(({ "心法", "功法", "百草吐納法", "吐納", "調息", "herb_breathe" }),
        "人在草木間，一呼一吸皆是藥理！老夫這門『百草吐納法(初級)』(learn herb_breathe from ge)，" +
        "教你如深谷青木般吐濁納清，調息時生機源源不絕！");

    add_response(({ "草藥", "採藥", "收藥", "herb" }), 
        "天地草木皆含神機！去南谷溪灘採集新鮮草藥 (gather)，送來給老夫 (give herb to ge)，老夫自會給你分潤工錢與活絡藥劑！");

    add_response(({ "身世", "孤兒", "background" }), 
        "問老夫你從哪來的？十四年前連日暴雨山洪，你在南谷溪灘的大石板上啼哭，身旁就擱著那只竹編舊藥簍..." +
        "嘿嘿，黑石鋪的蠢人都以為那石板是塊平整洗衣石，唯獨老夫知道，那上頭刻著太古殘缺的天機！");

    add_response(({ "石板", "洗衣石板", "斷碑", "stele" }), 
        "那就是太古大清洗前遺留下來的逆星神碑！世人眼睛全被無形迷障糊住了，只當它是洗衣服的頑石。" +
        "你身懷天命，去石碑前仔細參悟 (study stele) 或拓印 (tuoyin)，莫要學那些凡夫俗子！");

    add_response(({ "瘋子", "半仙", "道統" }), 
        "世人笑我太瘋癲，我笑世人瞎了眼！法、力、物三道割裂，各走偏門，到頭來要麼道化化為飛灰，" +
        "要麼肉身氣竭而亡，沒一個能得善終！");
}

int accept_object(object who, object ob) {
    if (!who || !ob) return 0;

    if (ob->id("dew herb") || ob->query("herb_type") == "dew") {
        tell_object(who, HIY "葛半仙雙眼精芒畢露，一把奪過晨露草，狂喜大笑：\n" +
                         "「好小子！果然是在清晨破曉（卯辰時分）採來的上等晨露草！露水未散，草木清靈之氣猶存！」\n" NOR);
        tell_object(who, "葛半仙轉身在石臼裡飛快將草藥搗碎，加入兩味不知名的藥散，隨後遞給你一包微溫的藥散。\n");
        tell_object(who, HIG "【葛半仙為你調配了一包「葛氏活絡散」！】\n" NOR);
        
        object powder = clone_object("/clone/item/huoluo_dan.c");
        if (powder) {
            powder->move(who);
        }
        who->add("exp", 50);
        destruct(ob);

        object career = load_object(CAREER_D);
        if (career && career->query_chain_stage(who, "wu") == 2) {
            career->advance_chain_stage(who, "wu");
        }
        return 1;
    }

    if (ob->id("herb") || ob->id("chenlucao") || ob->query("herb_type") == "common") {
        tell_object(who, HIG "葛半仙接過新鮮草藥放在鼻尖嗅了嗅，滿意點頭道：\n" +
                         "「泥土清芬猶在，藥性生機尚存，正好入藥調配百草膏散！這是你的勞動份額！」\n" NOR);
        destruct(ob);
        return 1;
    }

    tell_object(who, "葛半仙撇了撇嘴：「老夫只要清晨採得的新鮮靈草，拿這些俗物來糊弄老夫作甚？」\n");
    return 0;
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    object engine = load_object(QUEST_ENGINE_D);
    if (engine && engine->check_and_handle_lost_item(me, "ge", topic)) {
        return 1;
    }
    if (string_in(topic, "任務, 生計, job, career, 解毒, 魯大山")) {
        object career = load_object(CAREER_D);
        int st = career ? career->query_chain_stage(me, "wu") : 1;
        if (st == 2) {
            tell_object(me, query_name() + " 瞪眼道：「魯老頭吸了地底陰瘴？哼，那老骨頭命硬！去南谷溪灘採一株破曉帶露的【晨露草】(gather) 回來，老夫給他配一包葛氏活絡散！」\n");
            return 1;
        } else {
            tell_object(me, query_name() + " 哼道：「天地草木皆含神機，去採點晨露草來，老夫自有用處！」\n");
            return 1;
        }
    }
    if (string_in(topic, "避毒, 烈酒, wine, 地煞, 辟煞酒")) {
        tell_object(me, query_name() + " 吹鬍子瞪眼大罵道：「地底九幽地煞毒性烈如蛇蠍！拿上這壺老夫秘製的【雄黃辟煞烈血酒】！\n" +
                                       "要是敢給老子死在底下，老子掀了你的祖墳！！」\n");
        if (!present("disha wine", me) && !present("wine", me)) {
            object wn = clone_object("/clone/item/disha_wine.c");
            if (wn) {
                wn->move(me);
                tell_object(me, HIG "【瘋郎中將一小罈熱氣騰騰的雄黃辟煞烈血酒塞進了你懷裡！】\n" NOR);
            }
        }
        return 1;
    }

    return ::do_chat(me, topic);
}
