// clone/npc/su_ningshuang.c
// 蘇凝霜 - 金石商會大掌櫃之女 (小說第10、12章核心角色)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("蘇凝霜");
    set_short(HIY "金石千金" NOR " 蘇凝霜");
    set_long("一位身著素淨棉布短襖的年輕少女，長髮隨意用木簪綰在腦後。\n"
             "她容顏清麗出塵，雙眸若秋水含露，神色間帶著父親剛遭橫禍的深沉悲痛，\n"
             "但眉宇間卻透著一股外柔內剛的名門傲骨。她手中捧著一本浸血的金絲暗賬，\n"
             "正凝神思索著金石商會與城防軍的致命死局。\n");
    set_id(({ "su ningshuang", "su", "ningshuang", "蘇凝霜", "蘇姑娘", "千金" }));

    set_level(5);
    set_stat("int", 24);
    set_stat("per", 26);
    set_stat("con", 16);
    recalc_stats();

    add_response(({ "父親", "蘇遠山", "大掌櫃", "變故" }),
        "少女眼眶泛紅，清淚滑落：「家父蘇遠山，本是金石商會正主管。昨夜二掌櫃在客棧天字號房中暗下『腐骨七步散』將他害死，強奪商隊大權……此仇不共戴天！」");

    add_response(({ "二掌櫃", "叛徒", "仇人" }),
        "蘇凝霜銀牙暗咬：「二掌櫃勾結城防軍大統領，意圖借『地煞異動』封閉黑石關，吞沒商隊全部貨物，並將黑石鋪全鎮百姓屠村滅口！」");

    add_response(({ "信印", "紫金印", "大印", "token" }),
        "「爹爹臨終前將【金石商會·天字總司大印】塞入了我的懷中。只要大印在我手中，二掌櫃便名不正言不順，無法調用金石商會真正的嫡系商衛！」");

    add_response(({ "神機密匙", "密匙", "鑰匙", "key" }),
        "蘇凝霜壓低聲音：「商隊最後三輛黑鐵轅車底層，押送著爹爹自大荒古墓掘出的【太古神機密匙】。傳聞它是開啟黑石鋪北崖地底沉睡萬年的【太古神闕地脈採掘站】的唯一信物！」");

    add_response(({ "北崖", "古礦坑", "塌方", "mine" }),
        "蘇凝霜神色無比焦急：「地煞已然逆衝！二掌櫃為了逼出神機密匙、掩蓋罪證，正在強行引爆地脈，北崖地底的礦工們危在旦夕！」");

    add_response(({ "大山", "魯大山", "老礦工" }),
        "蘇凝霜目光堅毅：「大山叔替商會辛苦開礦三十年，是黑石鋪的頂樑柱！凝霜在此守住天車絞盤，絕不讓叛逆斷了地底後路！」");
}

int do_chat(object me, string topic) {
    if (!me || !topic || topic == "") return 0;

    if (string_in(topic, "委託, commission, 救援, rescue")) {
        tell_object(me, HIY "蘇凝霜神色肅穆，高舉紫金雙龍信印：「凝霜以金石商會少東家之名發布【天字甲級特等緊急救援委託】！\n" +
                            "現場所有鋼釬、絞盤與辟毒藥物皆可調用，只要能救出地下三百米被困的二十三名長輩，\n" +
                            "商會必發千兩白銀撫恤，凝霜更親自為恩公簽發直通金石府城的大荒特等通關保書！」\n" NOR);
        if (!present("mine blueprint", me) && !present("blueprint", me)) {
            object bp = clone_object("/clone/item/mine_blueprint.c");
            if (bp) {
                bp->move(me);
                tell_object(me, HIG "【蘇凝霜將一份《北崖太古玄煞採掘舊志殘圖》鄭重交到了你的手中！】\n" NOR);
            }
        }
        return 1;
    }

    if (string_in(topic, "殘圖, blueprint, 採掘殘圖")) {
        tell_object(me, CYN "蘇凝霜低聲道：「殘圖上清晰標註，地底三百米有一處天然岩石空腔【地煞避風穹頂】，\n" +
                            "但入口被一道【斷龍卡隼石】死死卡住！請恩公帶好殘圖，向鐵鋪阿鐵借鋼鑿破石！」\n" NOR);
        if (!present("mine blueprint", me) && !present("blueprint", me)) {
            object bp = clone_object("/clone/item/mine_blueprint.c");
            if (bp) {
                bp->move(me);
                tell_object(me, HIG "【蘇凝霜將一份《北崖太古玄煞採掘舊志殘圖》遞給了你！】\n" NOR);
            }
        }
        return 1;
    }

    return ::do_chat(me, topic);
}

int accept_object(object who, object ob) {
    if (!who || !ob) return 0;

    if (ob->id("secret letter") || ob->query("is_letter")) {
        tell_object(who, HIY "蘇凝霜接過染血的火漆密信，展信看著上面的字跡，嬌軀劇烈顫抖，美眸中湧出滔天怒火：\n" +
                             "「果然是城防軍大統領與二掌櫃親筆簽下的屠村分贓密約！\n" +
                             "有了這封罪證，只要我們能闖過黑石關，便能在金石府城按律告倒這幫狗官叛賊！」\n" NOR);
        tell_object(who, HIG "蘇凝霜擦乾眼淚，向你深深一福：「恩公大德，凝霜永生難忘！這是家父生前配製的【護心凝露】，請恩公收下防身！」\n" NOR);
        who->add("exp", 150);
        who->add("pot", 80);
        destruct(ob);
        return 1;
    }

    if (ob->id("stone moss") || ob->id("moss")) {
        tell_object(who, HIG "蘇凝霜看著你手中的生石膽苔，驚訝道：「這是在墜龍瀑布絕壁採得的極陰靈草？顧公子曾說此草以生石灰為引，能破重甲，恩公真乃智勇雙全！」\n" NOR);
        return 1;
    }

    return 0;
}
