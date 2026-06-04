// magnetic by ice
// By frequency 
#include <combat.h>
#include <ansi.h>
inherit SKILL;
void hell(object me, object victim, object  weapon, int damage);
void dark(object me, object victim, object  weapon, int damage);
void suck(object me, object victim, object  weapon, int damage);
void busy(object me, object victim, object  weapon, int damage);
void berserk(object me, object victim, object  weapon, int damage);
void berserk2(object me, object victim, object  weapon, int damage);
void berserk3(object me, object victim, object  weapon, int damage);
void remove_effect(object me);

mapping *action = ({
//1
  ([ "action": HIW + "$N勁聚右拳，身上的氣勢之強，有如海中的核異變虎鯊，瘋狂、兇猛、神出鬼沒又巧妙精深，
成名絕招" + HIM + "『" + HIC + "海虎爆破拳" + HIM + "』" + HIW + "石破天驚般殺到，一往無前，轟向$n的$l" + NOR,
                "dodge":                5,
                "parry":                -20,
                "force":                200,
                "damage":               200,
                "post_action":          (: berserk :),
                "damage_type":  "組織裂傷"
        ]),
//2
  ([ "action": HIB + "$N身上狂霸之氣逐漸收斂，深藏不漏卻又強烈攝人，只當尋得$n的破綻時，才徹徹底底爆發，
一式" + HIW + "『" + HIC + "殺鯨霸拳" + HIW + "』" + HIB + "才毫無保留的轟出，誓殺一切阻擋之人。" + NOR,
        "dodge":        10,
        "parry":        -20,
        "force":        200,
        "damage":       200,
        "post_action":          (: berserk2 :),
        "damage_type":  "組織裂傷"
        ]),
//3
  ([ "action":HIY + "$N殺氣瘋狂爆射，狂霸之勢無人能擋，一生為武而生，為武而死，武道之路即其成皇之路，
所蘊成的一招" + HIR + "『" + HIW + "天武巨鯊拳" + HIR + "』" + HIY + "帶著兇猛的氣勁狂轟$n的$l" + NOR,
           "dodge":        -15,
           "parry":        -30,
           "force":        200,
           "damage":       200,
           "post_action":          (: berserk3 :),
           "damage_type":  "組織裂傷"
      ]),
//4
  ([ "action": HIR + "$N運起物質重組力量，化四週物質為鋒銳利劍，這正是駭人聽聞的" + HIB + "『" + HIM + "地獄之劍" + HIB + "』" + HIR + "
強極殺招" + HIW + "《" + HIY + "日蝕" + HIW + "‧" + HIC + "月缺" + HIW + "》" + HIR + "無情的往$n$l瘋狂絞嗜。" + NOR,
          "dodge":        -20,
          "parry":        -35,
          "force":        300,
          "damage":       220,
          "damage_type":  "割傷"
        ]),
//5
  ([ "action": GRN + "$N展現強大的磁場轉動力量，將包括$n真氣在內的四週空間物質在體內重組排列，快速治療傷勢。" + NOR,
           "dodge":        -20,
           "parry":        -50,
           "force":        200,
           "damage":       0,
           "post_action":      (: suck :),
           "damage_type":  "內傷"
        ]),
//6
  ([ "action": HIM + "$N臉色一沉，四周氣氛頓時顯得陰鬱，空氣凝重，壓得人喘不過氣來，接著$N大喝一聲，
使出殘忍血腥至極的" + HIW + "『" + HIR + "末日震禪" + HIW + "』" + HIM + "，誓要將$n轟為肉泥。" + NOR,
           "dodge":       -10,
           "parry":        -40,
           "force":        350,
           "damage":       200,
           "post_action":      (: dark :),
           "damage_type":  "瘀傷"
        ]),
//7
  ([ "action": HIC + "$N柔勁似水，巧勁連環，一招" + HIW + "『" + HIY + "皇極驚世水母拳" + HIW + "』" + HIC + "暗蓄內勁，試圖將$n困住不動。",
           "dodge":        -20,
           "parry":        10,
           "force":        400,
           "damage":       100,
           "post_action":      (: busy :),
           "damage_type":  "壓縮之傷"
        ]),
//8
  ([ "action": HIR + "$N展現凶邪黑獸氣勢，眼神變得猙獰駭人，全身鬥氣如火焰般燃燒，瘋狂強烈的鋒芒，
引發一式至邪絕招，" + HIW + "『" + HIG + "屠神無悔" + HIW + "‧" + HIG + "分割天空" + HIW + "』" + HIR + "強烈的火焰刀氣無情地想將$n化為灰燼" + NOR,
         "parry":        -55,
         "dodge":        -10,
         "force":        400,
         "damage":       300,
         "damage_type":  "割傷"
        ]),
});

int valid_learn(object me)
{
        int skill, bell;
        object wea1, wea2;
        skill = me->query_skill("magnetic", 1);
        bell = me->query("bellicosity");
        wea1 = me->query_temp("weapon");
        wea2 = me->query_temp("secondary_weapon");

        if( (wea1 && wea1->query("skill_type")!="unarmed") || (wea2 && wea2->query("skill_type")!="unarmed") )
                return notify_fail("練磁場轉動不能使用刀劍等武器。\n");

        if( (skill<50 && bell<(skill*5)) || (skill>=50 && bell<250) )
                return notify_fail("你的殺氣不夠，不能修練磁場轉動。\n");

        return 1;
}

int valid_enable(string usage)
{
        if( this_player()->query_skill("magnetic",1)>=50 )
                return ( usage=="unarmed" || usage=="parry" );
        else
                return ( usage=="unarmed" );
}

mapping query_action(object me, object weapon)
{
        int skill_level;
        skill_level=(int)me->query_skill("magnetic", 1);

        if (skill_level < 10)
                return action[random(2)];
        else if (skill_level < 20 )
                return action[random(3)];
        else if (skill_level < 35 )
                return action[random(4)];
                else if (skill_level < 50 )
                return action[random(5)];
                else if (skill_level < 70 )
                        return action[random(6)];
                else if (skill_level < 90 )
                        return action[random(7)];
        else
                        return action[random(7)+1];
}

/*
//地獄武學         暫停開發
void hell(object me, object victim, object weapon, int damage)
{

}
*/


//黑暗武學
void dark(object me, object victim, object weapon, int damage)
{
        int lose, i;
        int bellpower = (int)me->query("bellicosity")/300+1;
        int con = me->query_con();
        if(70>random(100))
        {
        message_vision(HIM + "\n$N將意識、肉體沉淪於生死間，逆運達摩經，悟出了驚世駭俗的" + CYN + "《" + HIW + "修" + HIC + "‧" + HIY + "羅""‧" + YEL + "道" + CYN + "》!!\n\n" + NOR,me);
        message_vision(HIM + "$N使出" + HIR + "【" + HIW + "六道輪迴" + CYN + "‧" + HIC + "九天輪迴" + HIR + "】" + HIM + "，磁場力量如蛇般的力量噬向$n，將其鎖扣住。\n" + NOR,me,victim);
        victim->start_busy(1);
        COMBAT_D->report_status(victim);
        message_vision(HIM + "$N使出" + HIR + "【" + HIW + "六道輪迴" + CYN + "‧" + HIR + "地獄輪迴" + HIR + "】" + HIM + "，兇猛的磁場天刀瘋狂砍殺，$n有如置身地獄。\n" + NOR,me,victim);
        victim->receive_damage("kee",con*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIM + "$N使出" + HIR + "【" + HIW + "六道輪迴" + CYN + "‧" + HIY + "無我輪迴" + HIR + "】" + HIM + "，趁著九天輪迴餘勁未消，強行擠壓$n的骨膈。\n" + NOR,me,victim);
        victim->receive_damage("kee",con*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIM + "$N使出" + HIR + "【" + HIW + "六道輪迴" + CYN + "‧" + HIG + "震禪輪迴" + HIR + "】" + HIM + "，內勁再上一層，粉碎了$n的重要關節和骨頭。\n" + NOR,me,victim);
        victim->receive_damage("kee",con*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIM + "$N使出" + HIR + "【" + HIW + "六道輪迴" + CYN + "‧" + HIB + "黑暗輪迴" + HIR + "】" + HIM + "，梵語呢喃，同時看穿$n破綻，一招擊中要害。\n" + NOR,me,victim);
        victim->receive_damage("kee",con*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIM + "$N使出" + HIR + "【" + HIW + "六道輪迴" + CYN + "‧" + HIM + "修羅輪迴" + HIR + "】" + HIM + "，百年生命力一瞬間爆發，將$n轟至肢離破散。\n" + NOR,me,victim);
        victim->receive_damage("kee",con*bellpower);
        COMBAT_D->report_status(victim);
        }else{
        message_vision(HIW + "\n$N逆運達摩經，超越細胞重組的" + HIR + "-=◎ " + HIM + "修羅" + HIB + "‧" + HIW + "永" + HIW + "※" + HIC + "生" + HIW + "※" + HIG + "訣" + HIR + " ◎=-" + HIW + "立時發動，身上傷勢完全復原。\n\n" + NOR,me);
        me->set("kee",me->query("max_kee"));
        me->set("eff_kee",me->query("max_kee"));
        me->set("gin",me->query("max_gin"));
        me->set("max_gin",me->query("max_gin"));
        me->set("sen",me->query("max_sen"));
        me->set("max_sen",me->query("max_sen"));
        COMBAT_D->report_status(me);
              }
}

//修羅永生訣
void suck(object me, object victim, object  weapon, int damage)
{

if(victim->query("force") > 0 && 70 > random(100))
        {
        message_vision(HIW + "\n$N逆運達摩經，超越細胞重組的" + HIR + "-=◎ " + HIM + "修羅" + HIB + "‧" + HIW + "永" + HIW + "※" + HIC + "生" + HIW + "※" + HIG + "訣" + HIR + " ◎=-" + HIW + "立時發動，身上傷勢完全復原。\n\n" + NOR,me);
        me->set("kee",me->query("max_kee"));
        me->set("eff_kee",me->query("max_kee"));
        me->set("gin",me->query("max_gin"));
        me->set("max_gin",me->query("max_gin"));
        me->set("sen",me->query("max_sen"));
        me->set("max_sen",me->query("max_sen"));
        COMBAT_D->report_status(me);
        }
}


//醜男
void busy(object me, object victim, object weapon, int damage)
{
       if(70>random(100))
        {
                message_vision(HIG + "$N的柔韌巧勁完全牽制了$n的行動，$n頓時動彈不得。\n" + NOR, me, victim);                me->set_temp("oldforce", me->query("force_factor"));
                victim->start_busy(random((me->query_skill("magnetic"))/25));
        }
}


//海虎
void berserk(object me, object victim, object weapon, int damage)
{
        int lose, i;
        int bellpower = (int)me->query("bellicosity")/300+1;
        int cor = me->query_cor();
        if(70>random(100))
        {
        message_vision(HIW + "\n$N心有所感，頓悟自然運行真理，連續不斷使出瘋狂攻勢。\n\n" + NOR,me);
        message_vision(HIW + "$N使出" + HIR + "【" + HIC + "極速子彈拳" + HIR + "】" + HIW + "，高速拳影如砲彈般飛向$n。\n" + NOR,me,victim);
        victim->receive_damage("kee",cor*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIW + "$N使出" + HIR + "【" + HIR + "火極七重天" + HIR + "】" + HIW + "，拳勁挾帶幟熱融岩轟向$n。\n" + NOR,me,victim);
        victim->receive_damage("kee",cor*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIW + "$N使出" + HIR + "【" + HIG + "風" + HIR + "火" + HIY + "雷" + HIM + "電" + HIC + "雪" + HIR + "】" + HIW + "，五極原力交替不斷折磨$n。\n" + NOR,me,victim);
        victim->receive_damage("kee",cor*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIW + "$N使出" + HIR + "【" + HIB + "魔極十八重" + HIR + "】" + HIW + "，瘋狂凶惡之氣立即噬向$n。\n" + NOR,me,victim);
        victim->receive_damage("kee",cor*bellpower);
        COMBAT_D->report_status(victim);
        }
}


//奧加
void berserk2(object me, object victim, object weapon, int damage)
{
        int lose, i;
        int bellpower = (int)me->query("bellicosity")/300+1;
        int cor = me->query_cor();
        if(70>random(100))
        {
        message_vision(HIB + "\n$N感嘆時勢所逼不得不為，連環盡使本身絕學。\n\n" + NOR,me);
        message_vision(HIB + "$N使出" + HIR + "【" + HIC + "真空劍刃" + HIR + "】" + HIB + "，劍氣如光似電，以驚人速度一一劃過$n。\n" + NOR,me,victim);
        victim->receive_damage("kee",cor*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIB + "$N使出" + HIR + "【" + HIY + "皇極劍道" + HIR + "】" + HIB + "，集盡天下劍法奧義的劍招，逐一蝕向$n。\n" + NOR,me,victim);
        victim->receive_damage("kee",cor*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIB + "$N使出" + HIR + "【" + HIW + "鯨霸天下" + HIR + "】" + HIB + "，速度與破壞力倍增，轉眼間$n已遭重擊。\n" + NOR,me,victim);
        victim->receive_damage("kee",cor*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIB + "$N使出" + HIR + "【" + HIM + "無極震禪" + HIR + "】" + HIB + "，收斂的殺氣瞬間爆發，如狼似虎捲向$n。\n" + NOR,me,victim);
        victim->receive_damage("kee",cor*bellpower);
        COMBAT_D->report_status(victim);
        }
}


//天道
void berserk3(object me, object victim, object weapon, int damage)
{
        int lose, i;
        int bellpower = (int)me->query("bellicosity")/300+1;
        int cor = me->query_cor();
        if(70>random(100))
        {
        message_vision(HIY + "\n$N將自身道義、情感、慾望融入武學，頓悟驚世神功\!!\n\n" + NOR,me);
        message_vision(HIY + "$N使出" + HIR + "【" + HIW + "天武" + HIR + "‧" + HIG + "斷頭道" + HIR + "】" + HIY + "，腿勁迅如閃電，重重掃中$n脖子。\n" + NOR,me,victim);
        victim->receive_damage("kee",cor*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIY + "$N使出" + HIR + "【" + HIW + "天武" + HIR + "‧" + HIB + "斷生道" + HIR + "】" + HIY + "，身形晃動，隨即一掌重擊$n人中。\n" + NOR,me,victim);
        victim->receive_damage("kee",cor*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIY + "$N使出" + HIR + "【" + HIW + "天武" + HIR + "‧" + HIM + "斷心道" + HIR + "】" + HIY + "，繞至$n後方，掌化利刃刺向後心。\n" + NOR,me,victim);
        victim->receive_damage("kee",cor*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIY + "$N使出" + HIR + "【" + HIW + "天武" + HIR + "‧" + HIC + "斷天道" + HIR + "】" + HIY + "，雙臂運勁交擊，爆發殺氣射向$n。\n" + NOR,me,victim);
        victim->receive_damage("kee",cor*bellpower);
        COMBAT_D->report_status(victim);
        message_vision(HIY + "$N使出" + HIR + "【" + HIW + "天武" + HIR + "‧" + HIY + "斷神道" + HIR + "】" + HIY + "，無數巨鯊光影湧至啃噬$n的肉體。\n" + NOR,me,victim);
        victim->receive_damage("kee",cor*bellpower);
        COMBAT_D->report_status(victim);
        }
}


string perform_action_file(string action)
{
        return CLASS_D("bandit")+"/badstrike/"+action;
}
