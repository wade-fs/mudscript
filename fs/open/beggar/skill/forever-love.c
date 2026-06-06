#include <ansi.h>
#include <combat.h>
inherit SKILL;
mapping *action = ({


(["action":
"$N左手五指並攏，一掌擊出，有撼動山河的氣魄；握著$w的右手則揮動如飛，如長江之水一般源源不絕的
向對手攻去，如此一山一水，真有如"+HIM+"『"+HIG+"水是眼波橫，山是眉峰聚。"+HIM+"』"+NOR+"令對手無法抵擋，
不知所措。",
        "damage":   50,
        "force":    50,
        "damage_type" : "掌擊和鞭傷",
]),

(["action":
"$N右手翻轉，轉瞬之間$w化作無數鞭圈，猶如深海中之怒蛟，好似"+HIM+"『"+HIG+"大江東去，浪淘盡，千古風流人物。"+HIM+"』"+NOR+"
要將一切的英雄好漢，全都吞沒於$N的滔天巨浪下。",
        "damage":   50,
        "force":    50,
        "damage_type" : "鞭傷",
]),

(["action":
"$N悄無聲息的貼進對手，無聲無息的一掌拍去，但真正的殺招是那繞過對手的$w，呈現出
兩面夾擊之勢，剛好符合了"+HIM+"『"+HIG+"二十四橋仍在，波心蕩，冷月無聲。"+HIM+"』"+NOR+"那股安靜無聲的奇妙意境。",
        "damage":   50,
        "force":    50,
        "damage_type" : "鞭傷",
]),

(["action":
"$N鼓運情傾七式，霎時一股白霧自$w騰出，頓時$N的身影逐漸隱沒於白霧之中，正當對手感到不知所措時，
一道掌風赫然自雲霧中飄出，將"+HIM+"『"+HIG+"忽聞海外有仙山，山在虛無縹緲間。"+HIM+"』"+NOR+"縹緲虛無的招意表現到了極致。",
        "damage":   50,
        "force":    50,
        "damage_type" : "掌傷",
]),

(["action":
"$N暴喝一聲，衣衫頓時啪啪作響，數條鞭氣竄出，可知是惡招來臨的前奏，因為光是鞭氣，就刮的對手衣
衫盡烈，膚頰生痛，頗有"+HIM+"『"+HIG+"山雨欲來風滿樓。"+HIM+"』"+NOR+"的感覺。",
        "damage":   50,
        "force":    50,
        "damage_type" : "刮傷",
]),
   
(["action":
"$N一言不發，掌鞭齊出，剎那間氣勁所及之處，草木不生，鳥獸飛竄，而可憐的對手，更是被籠罩在一層
"+HIM+"『"+HIG+"千山鳥飛絕，萬徑人蹤滅。"+HIM+"』"+NOR+"的可怕招意下，真是打心底為他感到悲哀。",
        "damage":   50,
        "force":    50,
        "damage_type" : "掌鞭擊傷",
]),
 
(["action":
"$N輕搖右臂，$w柔和的朝對手擊去，雖然威力不大，但那"+HIM+"『"+HIG+"一葉葉，一聲聲，空階滴到明。"+HIM+"』"+NOR+"
一般連綿不絕的招意，仍給予對手不小的損傷。",
        "damage":   50,
        "force":    50,
        "damage_type" : "鞭傷",
]),

(["action":
"$N虛晃一下身形，$w有如靈蛇般飛快的朝對手的下盤攻去，頃刻間飛沙走石，不但迷惑了對手的心神，
也間接攻擊了對手，正是"+HIM+"『"+HIG+"一川碎石大如斗，隨風滿地石亂走。"+HIM+"』"+NOR+"的最佳寫照。",
        "damage":   50,
        "force":    50,
        "damage_type" : "鞭傷",
]),

(["action":
"$N心中想到"+HIM+"『"+HIG+"花自飄零水自流。"+HIM+"』"+NOR+"的詩句，一股愁緒頓時湧上心頭，所散發的
招意亦使草木為之含悲，而對手也因而被困於這愁雲慘霧的招意中，久久無法自拔，也因而亂了方寸，輕易中招。",
        "damage":   50,
        "force":    50,
        "damage_type" : "鞭傷",
]),

(["action":
"$N將身法提升至極限，剎那間幻化出無限身影，但"+HIM+"『"+HIG+"濃綠萬枝紅一點，動人春色不須多。"+HIM+"』"+NOR+"
真正的殺著，只要一招便夠了，只見千重幻影轉瞬幻化為一，以風馳電徹之勢一掌拍來，叫人防不勝防。",
        "damage":   50,
        "force":    50,
        "damage_type" : "掌傷",
]),

(["action":
"$N腳下輕點，掌影幻化，再加上$w變幻難測的奇妙走勢，正是"+HIM+"『"+HIG+"雲破月來花弄影。"+HIM+"』"+NOR+"
令對手輕易的拜倒在你玄妙的招式中，久久不能自已。",
        "damage":   50,
        "force":    50,
        "damage_type" : "瘀傷",
]),

(["action":
"$N低聲輕頌："+HIM+"『"+HIG+"淚\眼問花花不語，亂紅飛過秋千去。"+HIM+"』"+NOR+"頓時受到詩中招意所感動，眼框
中充滿著淚\水，手中$w也跟著舞出了一股悲痛莫名的感覺，而這一種感覺，也帶出了一股無堅不摧的殺意。",
        "damage":   50,
        "force":    50,
        "damage_type" : "瘀傷",
]),

(["action":
"$N突然失去了理性，狂舞起收中的$w，$w也彷彿受到了$N的感動，亦將氣勢抬到了最高潮，對手只見到一陣排山倒海的
氣流迎面撲來，其威力有若"+HIM+"『"+HIG+"過江千尺浪，入竹萬竿斜。"+HIM+"』"+NOR+"一樣，擋都沒法擋。",
        "damage":   50,
        "force":    50,
        "damage_type" : "鞭傷",
]),

(["action":
"$N急速的揮動$w，使$w有如細雨一般縝密的灑在對手的身上，威力雖然不大，但因其中招意帶有一種玄奧的
"+HIM+"『"+HIG+"清明時節雨紛紛，路上行人欲斷魂。"+HIM+"』"+NOR+"的意味，令再強大的敵人，也會禁不住滿腹的愁緒，
而興起退縮的念頭。",
        "damage":   50,
        "force":    50,
        "damage_type" : "鞭傷",
]),

(["action":
"$N默唸："+HIM+"『"+HIG+"天長地久有時盡，此恨綿綿無絕期。"+HIM+"』"+NOR+"手中$w突然以一種不規則的走勢朝對手游去
，彷彿要將$N那綿綿無盡的恨意，以此招告知對手，以破其心志。",
        "damage":   50,
        "force":    50,
        "damage_type" : "鞭傷",
]),

(["action":
"$N抬頭高唱："+HIM+"『"+HIG+"恨人間，情是何物，直教生死相許\。"+HIM+"』"+NOR+"，$N的心中頓時將生死拋諸腦後，為了
心中所愛，就是失去性命，亦在所不惜。$N全身蓄滿功\力，毫不保留的將對手投去，完全是以命搏命的打法，
對手見來勢洶洶，只有輾轉游鬥，不敢以命相搏。",
        "damage":   50,
        "force":    50,
        "damage_type" : "鞭傷",
]),


(["action":
"$N低頭吟道："+HIM+"『"+HIG+"無情不似多情苦，一寸還成千萬縷\"+HIM+"』"+NOR
+"手中的$w也跟著由一條，變成十條，百條，甚至千萬條，由四面八方向對手攻去，無孔不入般的突破對手的防守。",
        "damage":   50,
        "force":    50,
        "damage_type" : "瘀傷",
]),

(["action":
"$N憶起"+HIM+"『"+HIG+"天涯地角有窮時，只有相思無盡處。"+HIM+"』"+NOR+"便把那遙遙無期的相思之情，化做無邊無際
的鞭風掌影，那怕對手躲往天涯海角，也難逃你有如相思一般的無涯攻勢。",
        "damage":   50,
        "force":    50,
        "damage_type" : "掌擊和鞭傷",
]),

(["action":
"$N一掌拍出，擊中對手的卻是鞭梢；一鞭橫掃，卻在對手身上留下一個掌印。如此虛實難料，變幻莫測的攻
勢，正是"+HIM+"『"+HIG+"花非花，霧非霧，來如春夢幾多時，去似朝雲無覓處。"+HIM+"』"+NOR+"那種來如春夢，去如朝雲
一般，讓人很難掌握。",
        "damage":   50,
        "force":    50,
        "damage_type" : "掌擊和鞭傷",
]),

(["action":
"$N屏氣凝神，剎那間整個戰場毫無聲息，瀰漫著一股殺意，突然間"+HIM+"『"+HIG+"銀瓶乍破水漿迸，鐵騎突出刀槍鳴。" + HIM+"』"+NOR+"
$N猝然出招，對手在猝不及防的情況下，只有倉皇躲避，但以其身法，又怎及的上九天靈影？",
        "damage":   50,
        "force":    50,
        "damage_type" : "鞭傷",
]),

(["action":
"$N縱身一躍，身形化作一道長虹，向對手投去，在貼進的一瞬間，$N揮掌急拍，於第一時間擊向對手要穴，
頗有"+HIM+"『"+HIG+"挾飛仙以遨遊，抱明月以長終。"+HIM+"』"+NOR+"那般飛仙遨遊之姿，和明月長終之勢，這種氣魄，就
算是敵仇，亦會暗暗稱讚。",
        "damage":   50,
        "force":    50,
        "damage_type" : "掌傷",
]),

(["action":
"$N屯蓄功\力，對手知是勁招將至，連忙閃避游鬥，但待他躲至遠處，才赫然發現，你那股發自心中的恨意，
正如"+HIM+"『"+HIG+"離恨恰如春草，更行更遠還生。"+HIM+"』"+NOR+"一樣，越是遠離，就越被籠罩在無邊無際的恨意之中。",
        "damage":   50,
        "force":    50,
        "damage_type" : "內傷",
]),


(["action":
"$N爆喝一聲，手中的$w突然迅速的振動起來，頓時化作一條綿綿不絕的鞭勁向對手襲捲而去，對手雖盡力
阻斷鞭勢，豈料"+HIM+"『"+HIG+"剪不斷，理還亂，是離愁，別是一般滋味在心頭。"+HIM+"』"+NOR+"，對手頓時傻了眼，只有
坐以待斃。",
        "damage":   50,
        "force":    50,
        "damage_type" : "鞭傷",
]),

(["action":
"$N屏氣寧神，頓時心如明鏡，想起了"+HIM+"『"+HIG+"由來征戰地，不見有人還。"+HIM+"』"+NOR+"心中一股豪情壯志油然而
升，而那股一去不復反的氣魄，亦深深的震撼了對手的心靈，造成了不小的打擊。",
        "damage":   50,
        "force":    50,
        "damage_type" : "心靈創傷",
]),

(["action":
"$N身形一晃，抓著了對手出招的空隙，憑著過人的身法撞入了對手的防衛網，給予其沉重的打擊，這一切
，都是憑著"+HIM+"『"+HIG+"有花堪折直須折，莫待無花空折枝。"+HIM+"』的招意。",
        "damage":   50,
        "force":    50,
        "damage_type" : "創傷",
]),



});

int valid_learn(object me)
{
        object weapon = me->query_temp("weapon");

        if( !weapon || weapon->query("skill_type") != "whip" ) {
            tell_object(me, "手中無鞭怎麼個練法呀？\n");
            return 0;
        }
        if( !me->query("mark/love",1) ) {
            tell_object(me, "你不會傾城之戀。\n");
            return 0;
        }
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("poisoner")+"/forever-love/"+action;
}

int valid_enable(string usage)
{
        return ( usage == "whip" );
}


mapping query_action(object me, object weapon)
{
        mapping do_action;
        object *enemy, weaponn;
        string actionn;
        int i, j, k, level, kee, poi;
        poi = me->query("poison",1);
        level = me->query_skill("forever-love", 1);
        level = (int) level / 10;
        if(level>10) level=10;
if(poi > 250 && random(9) >= 7 && me->query("class") == "poisoner")
{
            enemy = me->query_enemy();
        if( random(me->query_skill("whip")+me->query_skill("forever-love")) >
            random(enemy[i]->query_skill("parry")+enemy[i]->query_skill("dodge")) ) {
                        me->add("poison", -10);
            enemy = me->query_enemy();
            for(i=0; i<sizeof(enemy); i++) {
                for(j=0; j<level+2; j++) {
                    k = level;
                    if( level > 10 ) k = 10;
                    k = (k*2) + 5;
                    do_action = action[random(k)];
                    actionn = "\n";
                    actionn += do_action["action"];
                    if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
                    message_vision(actionn, me, enemy[i]);
                    if( random(me->query_skill("whip")+me->query_skill("forever-love")) >
                        random(enemy[i]->query_skill("parry")+enemy[i]->query_skill("dodge")) ) {
                        kee = enemy[i]->query("eff_kee")/40;
                        if(kee > 80) kee=80;
                        enemy[i]->add("eff_kee", (int) -kee);
                        kee = enemy[i]->query("kee")/40;
                        if(kee > 80) kee=80;
                        enemy[i]->add("kee", (int) -kee);
write(HIW + "\n你體內寒毒流轉，詩意了然於胸，連綿不絕的向對手攻去。\n" + NOR);
message_vision(HIB + "\n$N左支右拙，被這一鞭掃中。\n" + NOR, enemy[i]);
                        COMBAT_D->report_status(enemy[i]);
                    }
              else
message_vision(HIB + "\n$N福至心靈，瞧破了這招的招意，輕鬆避了開去。\n" + NOR,enemy[i]);
                }
            }
            if(random(me->query("poison",1))<random(300) ) {
tell_object(me,"\n你體內寒氣運轉漸緩，招式回歸成穩。\n\n");
            me->start_busy(1);
            }
        } }
        return action[random(25)];
}

