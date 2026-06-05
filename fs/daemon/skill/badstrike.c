// badstrike.c by ice
// modify by oda (4/10/96)
// 增加殺氣對特攻威力的影響 (5/1/96)
// By Swy 最後修正 QC 98/6/20
// By Chan 從新改寫 98/10/07
// By Swy QC 98/10/11 未經許可請勿亂改
#include <combat.h>
#include <ansi.h>
inherit SKILL;
void bleed(object me, object victim, object  weapon, int damage);
void block(object me, object victim, object  weapon, int damage);
void suck(object me, object victim, object  weapon, int damage);
void upforce(object me, object victim, object  weapon, int damage);
void berserk(object me, object victim, object  weapon, int damage);
void remove_effect(object me);

mapping *action = ({
//1
  ([ "action": "$N邪念一動使出[1;37m『惡向膽邊生』[0m，化解$n的層層防守﹐攻向$n的最弱處$l",
                "dodge":                5,
                "parry":                -20,
                "force":                200,
                "damage":               100,
                "damage_type":  "瘀傷"
        ]),
//2
  ([ "action": "$N使出一招[1;36m『厄運當頭』[0m，擊向$n的天庭蓋\",
        "dodge":        10,
        "parry":        -20,
        "force":        200,
        "damage":       150,
        "damage_type":  "瘀傷"
        ]),
//3
  ([ "action":"$N雙眼氾紅，破口大罵，突然一招[1;35m『惡人當道』[0m出其不意的擊向$n下鄂",
           "dodge":        -15,
           "parry":        -30,
           "force":        200,
           "damage":       200,
           "damage_type":  "瘀傷"
      ]),
//4
  ([ "action": "$N使出一招[1;34m『惡意中傷』[0m，無情的往$n的$l狂攻而去",
          "dodge":        -20,
          "parry":        -35,
          "force":        300,
          "damage":       250,
          "post_action":          (: suck :),
          "damage_type":  "瘀傷"
        ]),
//5
  ([ "action": "$N使出[1;33m『餓虎撲食』[0m，身形如餓虎般欺至$n身前﹐噬向$n的$l",
           "dodge":        -20,
           "parry":        -50,
           "force":        300,
           "damage":       300,
           "post_action":      (: bleed :),
           "damage_type":  "瘀傷"
        ]),
//6
  ([ "action": "$N身形一變，使出[1;31m『扼殺訣』[0m，如死神般攻向$n的$l",
           "dodge":       -10,
           "parry":        -40,
           "force":        350,
           "damage":       350,
           "post_action":      (: block :),
           "damage_type":  "瘀傷"
        ]),
//7
  ([ "action": "$N大喝一聲，捲起一股[31m『惡勢力』[0m擊向$n，要$n屈服於其下",
           "dodge":        -20,
           "parry":        10,
           "force":        400,
           "damage":       400,
           "post_action":      (: upforce :),
           "damage_type":  "瘀傷"
        ]),
//8
  ([ "action": "[32m$N吐氣揚聲，真氣運至最高境界，終極奧義[35m『鬼哭神嚎』[32m呼之欲出，\n[1;31m無情地想將$n化為灰燼[0m",
         "parry":        -55,
         "dodge":        -10,
         "force":        400,
         "damage":       400,
         "post_action":          (: berserk :),
         "damage_type":  "瘀傷"
        ]),
});

int valid_learn(object me)
{
        int skill, bell;
        object wea1, wea2;
        skill = me->query_skill("badstrike", 1);
        bell = me->query("bellicosity");
        wea1 = me->query_temp("weapon");
        wea2 = me->query_temp("secondary_weapon");

        if( (wea1 && wea1->query("skill_type")!="unarmed") || (wea2 && wea2->query("skill_type")!="unarmed") )
                return notify_fail("練惡霸掌不能使用刀劍等武器。\n");
    if(me->query("class") != "bandit")
       return notify_fail("只有惡人能學惡霸掌!!!\n");
    //限定只有惡人能學badstrike...
        if( (int)me->query_skill("badforce", 1) < 10 )
                return notify_fail("你的惡化魔功\不夠惡化﹐無法修練惡霸掌。\n");
        if( (int)me->query("max_force") < 20 )
                return notify_fail("你的內力太弱﹐無法練惡霸掌法。\n");

        // modify by oda
        //if((int)me->query("bellicosity") < 30 )
        if( (skill<50 && bell<(skill*5)) || (skill>=50 && bell<250) )
                return notify_fail("你的殺氣不夠，不能修練惡霸掌。\n");

        return 1;
}

int valid_enable(string usage)
{
        if( this_player()->query_skill("badstrike",1)>=50 )
                return ( usage=="unarmed" || usage=="parry" );
        else
                return ( usage=="unarmed" );
}

mapping query_action(object me, object weapon)
{
        int skill_level;
        skill_level=(int)me->query_skill("badstrike", 1);
if(me->query("class")=="bandit") {
if(me->query_temp("damage-busy1") == 1) return action[6];
if(me->query_temp("damage-busy2") == 1) return action[7];
}
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

void bleed(object me, object victim, object weapon, int damage)
{
        int bellpower;
        bellpower= (int)me->query("bellicosity",1)/500+1;
        damage=bellpower*10;
        if(damage > 400)
        damage=400;
         if(70>random(100) && !me->query_temp("berserk2"))
        {
         me->add("force", -3*bellpower);
         victim->receive_wound("kee",damage,me);
         message_vision(HIR + "$N使用惡化魔功\精義用內力把$n震傷，使$n不停的狂吐鮮血。\n" + NOR, me, victim);
         COMBAT_D->report_status(victim);
        }
}

void block(object me, object victim, object weapon, int damage)
{

   if (70>random(100) && !me->query_temp("berserk2"))
{
  victim->start_busy(1);
  if(!me->query_temp("damage-busy1")) {
  me->set_temp("damage-busy1",1); }
  me->add("force",-100); //扣內力
  message_vision(HIB + "$N暗使內力，使得$n為其惡化魔功\所震而暫時無法動彈。\n" + NOR, me, victim);
}
}


void suck(object me, object victim, object  weapon, int damage)
{
        int lose;
        int bellpower = (int)me->query("bellicosity")/250+1;
if(victim->query("force")>0&&me->query_skill_mapped("force")=="badforce"&&!me->query_temp("berserk2")
   && 70>random(100))
        {
           lose = ((int)me->query_skill("badforce",1)/5+10)*bellpower;
           if(lose > 800) lose=800;
        me->add("kee", lose/2);
        me->add("force",lose);
        victim->add("force",-lose);
        victim->receive_damage("kee",lose/2,me);
        if(victim->query("force",1) < 0) victim->set("force",0);
        message_vision(HIY + "$N使出惡化魔功\之吸功\大法，把$n的功\力吸去不少。\n" + NOR, me, victim);
        COMBAT_D->report_status(victim);
        }
}

void upforce(object me, object victim, object weapon, int damage)
{
        int skill = (int)me->query_skill("badforce", 1)/10;
        int bellpower = (int)me->query("bellicosity")/300+1;
        if( bellpower > 4 ) bellpower = 4;
        if(skill > 15) skill=15;
                if(me->query_temp("damage-busy1") == 1 ) {
                me->delete_temp("damage-busy1");
                me->set_temp("damage-busy2",1);  }
        if( !me->query_temp("berserk") && !me->query_temp("upforce")
            && 70>random(100) && me->query("class")=="bandit" )
        {
                message_vision(HIG + "$N一擊得手，$n噴出的鮮血激起了$N的瘋狂殺意，內力暴長。\n" + NOR, me, victim);
                me->set_temp("oldforce", me->query("force_factor"));
                me->set("force_factor", (4*skill*bellpower)/4);
                me->set_temp("upforce", 1);
                call_out("remove_effect", 10, me);
        }
}

void remove_effect(object me)
{
        if(!me) return ;
        if(me->query("gin")>50) {
        me->receive_damage("gin", 30); }
        me->set("force_factor", me->query_temp("oldforce"));
        me->delete_temp("oldforce");
        me->delete_temp("upforce");
        message_vision(HIW + "$N狂意漸退，內力漸漸收回。\n" + NOR, me);
}

void berserk(object me, object victim, object weapon, int damage)
{
        int lose, i;
        int bellpower = (int)me->query("bellicosity")/300+1;
        if(bellpower>8)
        bellpower=8;
                if(me->query_temp("damage-busy2")==1) {
                me->delete_temp("damage-busy2"); }
if(me->query("class")=="bandit"&& !me->query_temp("berserk") && 70>random(100)) 
        {
                lose = 4+bellpower;
                me->set_temp("berserk", 1);
                me->set_temp("berserk2",1);
                for(i = 0;i < lose; i++)
                {
                        message_vision(HIR + "$N打出惡霸掌之連擊技，向$n狂風暴雨般橫掃而去。\n" + NOR, me, victim);
                        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
                }
                me->delete_temp("berserk");
                me->delete_temp("berserk2");
                if(!me->query_temp("crazy"))
                {
                      message_vision(HIW + "一陣狂打之後，$N體內氣息大亂，趕緊趁機調息。\n" + NOR,me);
                      me->start_busy(1);
                }
        }
}


string perform_action_file(string action)
{
        return CLASS_D("bandit")+"/badstrike/"+action;
}
