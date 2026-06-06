// fast-blade.c by konn
#include <ansi.h>
#include <combat.h>
inherit SKILL;

mapping *action = ({
([ "action" : HIG"$N身形靈動, 矮身低頭, "+HIM+"幔羅千葉刀法第一式「旋風式」"+HIG+"使了出來, 手中的"+HIY+"$w"+HIG+"飛快的向$n直砍而下, 腿也朝$n下盤踢去, 快刀神腿, 逼的$n手忙腳亂。"NOR,
        "dodge":   -10,
        "parry":   -20,
        "damage":   20,
        "force":    60,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N身子向後一傾, 順勢一招"+HIM+"幔羅千葉刀法第二式「龍翔鳳舞」"+HIG+"向$n襲擊而到, $N身形忽然飄盪, 忽東忽西, 手中"+HIY+"$w"+HIG+"飛快的舞著, 刀光殘影, 只看的$n眼花瞭亂。"NOR,
        "dodge":   -20,
        "parry":   -10,
        "damage":   20,
        "force":    20,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N忽然身形一變, 向後退了半步, 使出一招"+HIM+"幔羅千葉刀法第三式「退步斬馬刀」"+HIG+", 手中"+HIY+"$w"+HIG+"橫劈$n的大腿, 接著刀背一翻, 順勢向$n的腰際滑了過來, 狠斬$n的腰眼。"NOR,
        "dodge":   -30,
        "parry":    20,
        "damage":   20,
        "force":    40,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N左手虛托, 身子略向左斜, 一刀飛出, 正是一式"+HIM+"幔羅千葉刀法第四式「抽樑換柱」"+HIG+"直向$n臂膀砍到, 刀鋒飛快的從$n右臂掃過直飛向面門, 又往左臂砍到, $n驚慌的想要逃開。"NOR,
        "dodge":    20,
        "parry":    10,
        "damage":   30,
        "force":    30,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N手中刀柄向上, 刀背向外, 身子向前微躬, 一式"+HIM+"幔羅千葉刀法第五式「參拜北斗」"+HIG+"向$n的胸前招呼了過來, 瞬間$N刀背一翻, 直砍$n的左臂, 逼的$n向後連退了三步。"NOR,
        "dodge":   -20,
        "parry":   -10,
        "damage":   30,
        "force":    40,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N刀舞身轉, 腳下不停的移動著, 繞著$n不停的尋找破綻, $N忽然使出一招"+HIM+"幔羅千葉刀法第六式「轉身劈山」"+HIG+", 身子向右邊一轉, 斜刺刺一刀的向$n劈到, 待$n發覺時已不及反應了。"NOR,
        "dodge":   -30,
        "parry":   -10,
        "damage":   30,
        "force":    30,
        "damage_type" : "砍傷",
]),


([ "action" : HIG"$N身子向左滑了半步, 刀背略沉, 刀走中偏鋒, 一招"+HIM+"幔羅千葉刀法第七式「橫攔天門」"+HIG+"向$n斬了過來, $n急忙招架, $N又向左滑半步, 刀背上提, 刀鋒直進, 向$n胸口砍了下來。"NOR,
        "dodge":   -35,
        "parry":   -20,
        "damage":   40,
        "force":    50,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N手中的刀一個虛劈, 雙腿蹲了個弓步, 忽然向$n飛奔而去, 手中的"+HIY+"$w"+HIG+"在身前交互著虛砍, 一招"+HIM+"幔羅千葉刀法第八式「雷電交作」"+HIG+"使了出來, 迅速的向$n的腦袋招呼了過來。"NOR,
        "dodge":   -40,
        "parry":   -20,
        "damage":   40,
        "force":    30,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N運起全身內力, 真氣從丹田中遊走全身, 最後在手中食指的商陽穴會聚, 腳下使出「千斤墜」, 手中使出一招"+HIM+"幔羅千葉刀法第九式「獨劈華山」"+HIG+"威猛的向$n急劈而下, 眼見$n就難已活命了。"NOR,
        "dodge":   -10,
        "parry":   -10,
        "damage":   50,
        "force":    10,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N向後退了一步, 集精聚神的舞起千葉刀法的精要, 忽然訊捷的向$n發起"+HIM+"幔羅千葉刀法第十式「分花拂柳」"+HIG+"此招, 身形如行雲流水般的飄盪, 東飄西盪, "+HIY+"$w"+HIG+"輕慢的向$n的小腹砍了下去, 柔中帶鋼, 鋼中有柔。"NOR,
        "dodge":   -10,
        "parry":   -20,
        "damage":   50,
        "force":    30,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N將"+HIY+"$w"+HIG+"舞得滴水不漏, 刀快如飛葉, 忽然轉守為攻, 向$n施展起"+HIM+"幔羅千葉刀法第十一式「四雁南飛」"+HIG+", $N手中的"+HIY+"$w"+HIG+"快速的飛舞著, 分別以上、下、左、右四個門路向$n攻來, $n看來已無法招架了。"NOR,
        "dodge":   -20,
        "parry":   -20,
        "damage":   50,
        "force":    32,
        "damage_type" : "砍傷",
]),


([ "action" : HIG"$N蓄勢待發, 忽然使出一招"+HIM+"幔羅千葉刀法第十二式「懷中抱月」"+HIG+", 身形如箭矢般飛快向前傾, 手中的"+HIY+"$w"+HIG+"則是舞動的飛快異常, 直進中宮, 忽的刀背一翻, 橫劈$n的左肩, 此招變化之快, $n實是閃躲不易。"NOR, 
        "dodge":   -10,
        "parry":    20,
        "damage":   60,
        "force":    35,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N在$n身邊不停的移動, 一招"+HIM+"幔羅千業刀法第十三式「荊軻獻圖」"+HIG+"發將出來, 忽然將手中的"+HIY+"$w"+HIG+"腹向$n拍到, 接著又是刀柄一轉, 向$n的小腹直搓而下, $N又舞著"+HIY+"$w"+HIG+"向$n的下盤斜劈了下去, $n慌忙的想避開這招。"NOR,
        "dodge":   -30,
        "parry":   -20,
        "damage":   60,
        "force":    20,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N將手中的"+HIY+"$w"+HIG+"飛快的舞著, 一招"+HIM+"幔羅千葉刀法第十四式「流星趕月」"+HIG+", 刀鋒直取$n的面門, 腳下踢著「連環十八腿」, 向$n的門戶打了過來, 招式毒辣前所未見, 忽然刀背一轉, 狠狠的向$n的右膀子砍了過來。"NOR,
        "dodge":   -10,
        "parry":   -20,
        "damage":   60,
        "force":    10,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N提起真氣狂舞"+HIY+"$w"+HIG+", 刀氣環繞在$N的四周發出嗶爆聲, 一招"+HIM+"幔羅千葉刀法第十五式「諫果回甘」"+HIG+", 刀光殘影, "+HIY+"$w"+HIG+"迅捷的在$N頭頂上飛舞著, 忽然間猛烈的向$n迎面劈來, 只聽到$n慘叫一聲, 眼看$n已經不能活命了。"NOR,
        "dodge":   -10,
        "parry":   -30,
        "damage":   60,
        "force":    30,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N把"+HIY+"$w"+HIG+"往腰際一收, 擺\了個「先禮後兵」, 隨後身子旋轉一圈, 手中的"+HIY+"$w"+HIG+"突然向$n急刺而出, 這正是一招"+HIM+"幔羅千葉刀法第十六式「藏刀式」"+HIG+", $N飛快的向$n砍了七七四十九刀, 刀刀致命, 招招狠毒, 
眼看$n就要不行了。"NOR,
        "dodge":    20,
        "parry":   -20,
        "damage":   70,
        "force":    30,
        "damage_type" : "砍傷",
]),


([ "action" : HIG"$N眼觀六路, 耳聽八方, 聚精會神的與$n纏鬥著, $N將"+HIY+"$w"+HIG+"狂亂舞起, 使出"+HIM+"幔羅千葉刀法第十七式「陽關折柳」"+HIG+", 只見刀光閃閃, $N全身上下被刀氣所攏罩著, 驟然將"+HIY+"$w"+HIG+"一變二, 二變四, 四變八, 分別及擊向$n全身上下
八大要害。"NOR,
        "dodge":    30,
        "parry":   -20,
        "damage":   80,
        "force":    40,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N形影飄盪, 若隱若現, 手中的"+HIY+"$w"+HIG+"詭異的飛舞著, 這正是"+HIM+"幔羅千葉刀法第十八式「惡虎攔路」"+HIG+", 待$n稍一分神, 立即一剁一砍, 向$n的周身大穴招呼而來, 刀刀命中要害, 令$n感到搏手搏腳, 毫無反擊能力。"NOR,
        "dodge":   -30,
        "parry":   -10,
        "damage":   80,
        "force":    30,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N運起六陽心法, 只見$N頭頂冒出絲絲白煙, "+HIM+"幔羅千葉刀法第十九式「移轉乾坤」"+HIG+"迅捷的使出, 四周突然天旋地轉, 分不出東西南北, $n已感到頭昏, $N瞬間欺進$n的身邊, 舉起"+HIY+"$w"+HIG+"便往$n腦袋砍下。"NOR,
        "dodge":    30,
        "parry":   -20,
        "damage":   90,
        "force":    15,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N氣沉丹田, 力貫刀鋒, 身輕如燕, 一招"+HIM+"幔羅千葉刀法第二十式「上步劈山」"+HIG+"向$n招呼而來, $N手中的"+HIY+"$w"+HIG+"刀鋒閃閃發光, 刀未至, 氣先到, 一股深不可測的"+HIY+"$w"+HIG+"刀氣向$n襲擊而來, 逼的$n連連倒退, 接著強勁的"+HIY+"$w
"+HIG+"又跟著砍了過來, 有如猛虎下山之勢。"NOR,
        "dodge":   -10,
        "parry":   -10,
        "damage":   90,
        "force":    20,
        "damage_type" : "砍傷",
]),

([ "action" : HIG"$N刀快似箭, 刀光閃閃, 片片燐光, 以一招"+HIM+"幔羅千葉刀法第二十一式「刀斬海龍王」"+HIG+"向$n襲掩而到, 急砍向$n的小腹、右臂、左肩等處, 接著臂轉刀至, 刀轉刀氣橫生, $N全身上下被籠照在刀氣之下, 突然一股氣又向$n擊了過來,
直向$n腦門衝了過去。"NOR,
        "dodge":    30,
        "parry":   -30,
        "damage":  100,
        "force":    30,
        "damage_type" : "砍傷",
]),


([ "action" : HIG"$N左手一揮, 手中又多了一把"+HIY+"$w"+HIG+", 雙刀其發, 如虎添翼, 刀氣護身, 抵擋萬敵, 一招"+HIM+"幔羅千葉刀法第二十二式「九龍遊天」"+HIG+"使出, 有如盤古開天闢地般氣象萬千, 峰迴路轉, $N身形飄盪不定, 陰陽倒置, $n全身動彈不得, 刀氣
如九龍騰出,分路向四面八方襲擊而去。 "NOR,
        "dodge":    25,
        "parry":   -24,
        "damage":  110,
        "force":    43,
        "damage_type" : "砍傷",
]),
});

//can learn

int valid_learn(object me)
{
        object weapon = me->query_temp("weapon");

        if( !weapon || weapon->query("skill_type") != "blade" ) {
            tell_object(me, "手中無刀怎麼個練法呀?\n");
            return 0;
        }
        if( me->query("max_force") < 1500 ) {
            tell_object(me, "你的內力修為不夠, 最少要有一千五百點。\n");
            return 0;
        }
        if( me->query("force") < 1000 ) {
            tell_object(me, "你目前的內力不到一千點, 無法練此刀法。\n");
            return 0;
        }
        if( me->query_skill("gold-blade", 1) < 90 ) {
            tell_object(me, "你的紫金六陽刀法不夠純熟, 最少需要九十級。\n");
            return 0;
        }
        if( (me->query("potential") - me->query("learned_points")) < 3 ) {
            tell_object(me, "你的潛能不到三點, 無法練此刀法。\n");
            return 0;
        }
	if( me->query_skill("fast-blade", 1)*20 > me->query("bellicosity") ) {
            tell_object(me, "你殺氣太低, 以致無法領會幔羅千葉刀法的精要。\n");
            return 0;
        }

        tell_object(me, "學此刀法需扣潛能、精、氣、神各三點。\n");
        me->add("gin", -3);
        me->add("kee", -3);
        me->add("sen", -3);
        me->add("potential", -3);
        return 1;
}

// perform blade.fast-dest && perform blade.fast-die

string perform_action_file(string action)
{
        return CLASS_D("blademan")+"/fast-blade/"+action;
}

// can enable

int valid_enable(string usage)
{
        return ( usage == "blade" );
}

// action message

mapping query_action(object me, object weapon)
{
        mapping do_action;
        object *enemy, weaponn;
        string actionn;
        int i, j, k, level, kee;

	level = me->query_skill("fast-blade", 1);
        level = (int) level / 10;
        if( level*10 > me->query_skill("fast-blade", 1) )
        level --;
    if(me->query("family/family_name")=="金刀門")
{
        if( random(5) == 0 && me->query("sen") > 15 ) {
            enemy = me->query_enemy();
            for(i=0; i<sizeof(enemy); i++) {
                for(j=0; j<level+4; j++) {
                    k = level;
                    if( level > 10 ) k = 10;
                    k = (k+1) * 2;
                    do_action = action[random(k)];
                    actionn = "\n";
                    actionn += do_action["action"];
		    if( weaponn=me->query_temp("weapon") )
                        actionn = replace_string(actionn, "$w", weaponn->name());
                    message_vision(actionn, me, enemy[i]);
                    if( random(me->query("combat_exp")) >
                        random(enemy[i]->query("combat_exp"))/5 ) {
                        kee = enemy[i]->query("eff_kee");
                        enemy[i]->add("eff_kee", (int) -kee/20);
                        kee = enemy[i]->query("kee");
                        enemy[i]->add("kee", (int) -kee/20);
                        message_vision(HIC "\n$N閃躲不及, 被這一刀砍中了要害。\n" NOR, enemy[i]);
                        COMBAT_D->report_status(enemy[i]);
                    }

                    else message_vision(HIC "\n$N人比刀快, 驚險地閃過了這一刀。\n" NOR, enemy[i]);
                }
            }
}
            if( random(me->query_cps()) < 10 ) {
                me->add("sen", -10);
                me->add("kee", -30);
                tell_object(me,
                     "\n你使了快刀斬後, 由於定力不夠, 以致於精神無法集中。\n\n");
            }
        }
        if( level > 10 ) level = 10;
        i = (level+1) * 2;
        if( i == 21 ) {
            enemy = me->query_enemy();
            for(j=0; j<sizeof(enemy); j++)
                enemy[j]->start_busy(3);
        }
        return action[random(i)];
}

