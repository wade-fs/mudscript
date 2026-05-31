//修正附攻傷害公式 by unfinished 2004 02/09
//補上receive_wound與receive_damage攻擊方的參數 by blazakira 2011/7/24

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void sp_att1(object me, object victim, object  weapon, int damage);
void sp_att2(object me, object victim, object  weapon, int damage);
void sp_att3(object me, object victim, object  weapon, int damage);

mapping *action = ({
  ([
    "action"      : HIG"$N"+HIG+"身形靈動，"+HIM+"幔羅千葉刀法第一式「旋風式」"+HIG+"使了出來，手中的$w"+HIG+"飛快的向$n"+HIG+"直砍而下，腿也朝$n"+HIG+"下盤踢去，\n"
                    "快刀神腿，逼的$n"+HIG+"手忙腳亂。"NOR,
    "dodge"       : 10,
    "parry"       : -10,
    "damage"      : 30,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"身子向後一傾，順勢一招"+HIM+"幔羅千葉刀法第二式「龍翔鳳舞」"+HIG+"向$n"+HIG+"襲擊而到，$N"+HIG+"身形忽然飄盪，忽東忽西，\n"
                    "手中$w"+HIG+"飛快的舞著，只看的$n"+HIG+"眼花撩亂。"NOR,
    "dodge"       : 10,
    "parry"       : -10,
    "damage"      : 30,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"忽然身形一變，向後退了半步，使出"+HIM+"幔羅千葉刀法第三式「退步斬馬刀」"+HIG+"，手中$w"+HIG+"橫劈$n"+HIG+"的大腿，\n"
                    "接著刀背一翻，順勢向$n"+HIG+"的腰際滑了過來，狠斬$n的腰眼。"NOR,
    "dodge"       : 10,
    "parry"       : -15,
    "damage"      : 50,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"左手虛托，身子略向左斜，一刀飛出，正是"+HIM+"幔羅千葉刀法第四式「抽樑換柱」"+HIG+"直向$n"+HIG+"臂膀砍到，\n"
                    "刀鋒飛快的從$n"+HIG+"右臂掃過直飛向面門，$n"+HIG+"驚慌的想要逃開。"NOR,
    "dodge"       : 20,
    "parry"       : -20,
    "damage"      : 100,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"手中刀柄向上，刀背向外，身子向前微躬，一式"+HIM+"幔羅千葉刀法第五式「參拜北斗」"+HIG+"向$n"+HIG+"的胸前招呼了過來，\n"
                    "$N"+HIG+"刀背一翻，直砍$n"+HIG+"的左臂，逼的$n"+HIG+"向後連退了三步。"NOR,
    "dodge"       : 20,
    "parry"       : -15,
    "damage"      : 100,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"刀舞身轉，腳下不停的移動著，$N"+HIG+"忽然使出一招"+HIM+"幔羅千葉刀法第六式「轉身劈山」"+HIG+"，身子向右邊一轉，\n"
                    "斜刺一刀的向$n"+HIG+"劈到，待$n"+HIG+"發覺時已不及反應了。"NOR,
    "dodge"       : 10,
    "parry"       : -10,
    "damage"      : 100,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"身子向左滑了半步，刀背略沉，刀走中偏鋒，一招"+HIM+"幔羅千葉刀法第七式「橫攔天門」"+HIG+"向$n"+HIG+"斬了過來，\n"
                    "$n"+HIG+"急忙招架，$N"+HIG+"又向左滑半步，刀鋒直進，向$n"+HIG+"胸口砍了下來。"NOR,
    "dodge"       : 20,
    "parry"       : -20,
    "damage"      : 100,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"手中的刀一個虛劈，雙腿蹲了個弓步，忽然飛奔而去，手中的$w"+HIG+"在身前交互著虛砍，一招"+HIM+"幔羅千葉刀法第八\n"
                    "式「雷電交作」"+HIG+"使了出來，迅速的向$n"+HIG+"的腦袋招呼了過來。"NOR,
    "dodge"       : 20,
    "parry"       : -15,
    "damage"      : 100,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"運起全身內力，真氣遊走全身，最後在手中食指的商陽穴會聚，腳下使出「千斤墜」，手中使出一招"+HIM+"幔羅千\n"
                    "葉刀法第九式「獨劈華山」"+HIG+"威猛的向$n"+HIG+"急劈而下，眼見$n"+HIG+"就難已活命了。"NOR,
    "dodge"       : 20,
    "parry"       : -20,
    "damage"      : 100,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"向後退了一步，舞起千葉刀法的精要，忽然迅捷的向$n"+HIG+"發起"+HIM+"幔羅千葉刀法第十式「分花拂柳」"+HIG+"此招，身形如\n"
                    "行雲流水般的飄盪，東飄西盪，$w"+HIG+"輕慢的向$n"+HIG+"的小腹砍了下去，柔中帶鋼，鋼中有柔。"NOR,
    "dodge"       : 20,
    "parry"       : -20,
    "damage"      : 100,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"將$w"+HIG+"舞得滴水不漏，忽然轉守為攻，向$n"+HIG+"施展起"+HIM+"幔羅千葉刀法第十一式「四雁南飛」"+HIG+"，$N"+HIG+"手中的$w"+HIG+"快速的飛\n"
                    "舞著，分別以上、下、左、右四門路向$n"+HIG+"攻來，$n"+HIG+"看來已無法招架了。"NOR,
    "dodge"       : 20,
    "parry"       : -20,
    "damage"      : 100,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"蓄勢待發，忽然使出一招"+HIM+"幔羅千葉刀法第十二式「懷中抱月」"+HIG+"，身形如箭矢般飛快向前傾，手中的$w"+HIG+"則是舞\n"
                    "動的飛快，直進中宮，忽的刀背一翻，橫劈$n"+HIG+"的左肩，此招變化之快，$n"+HIG+"實是閃躲不易。"NOR,
    "dodge"       : 20,
    "parry"       : -20,
    "damage"      : 100,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"在$n"+HIG+"身邊不停的移動，一招"+HIM+"幔羅千葉刀法第十三式「荊軻獻圖」"+HIG+"發出來，忽然將手中的$w"+HIG+"腹向$n"+HIG+"拍到，接著\n"
                    "又是刀柄一轉，向$n"+HIG+"的小腹直搓而下，$n"+HIG+"慌忙的想避開這招。"NOR,
    "dodge"       : 10,
    "parry"       : -10,
    "damage"      : 130,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"將手中的$w"+HIG+"飛快的舞著，一招"+HIM+"幔羅千葉刀法第十四式「流星趕月」"+HIG+"，刀鋒直取$n"+HIG+"的面門，腳下踢著「連環十\n"
                    "八腿」，招式毒辣前所未見，刀背一轉，狠狠的向$n"+HIG+"的右膀子砍了過來。"NOR,
    "dodge"       : 10,
    "parry"       : -20,
    "damage"      : 130,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"提起真氣狂舞$w"+HIG+"，刀氣環繞在$N"+HIG+"的四周發出嗶爆聲，一招"+HIM+"幔羅千葉刀法第十五式「諫果回甘」"+HIG+"，刀光殘影，\n"
                    "$w"+HIG+"迅捷的在$N"+HIG+"頭頂上飛舞著，忽然間猛烈的向$n"+HIG+"迎面劈來，只聽到$n"+HIG+"慘叫一聲，眼看$n"+HIG+"已經不能活命了。"NOR,
    "dodge"       : 20,
    "parry"       : -20,
    "damage"      : 160,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"把$w"+HIG+"往腰際一收，擺\了個「先禮後兵」，隨後身子旋轉一圈，手中的$w"+HIG+"突然向$n"+HIG+"急刺而出，這正是一招"+HIM+"幔羅\n"
                    "千葉刀法第十六式「藏刀式」"+HIG+"，$N"+HIG+"飛快的向$n"+HIG+"砍了七七四十九刀，招招狠毒，眼看$n"+HIG+"就要不行了。"NOR,
    "dodge"       : 10,
    "parry"       : -20,
    "damage"      : 160,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"眼觀六路，耳聽八方，聚精會神的與$n"+HIG+"纏鬥著，$N"+HIG+"將$w"+HIG+"狂亂舞起，使出"+HIM+"幔羅千葉刀法第十七式「陽關折柳」\n"
                    +HIG+"，只見刀光閃閃，$N"+HIG+"全身上下被刀氣所籠罩著，驟然將$w"+HIG+"一變二，二變四，四變八，擊向$n"+HIG+"全身上下八大要害。"NOR,
    "dodge"       : 10,
    "parry"       : -20,
    "damage"      : 160,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"形影飄盪，若隱若現，手中的$w"+HIG+"詭異的飛舞著，這正是"+HIM+"幔羅千葉刀法第十八式「惡虎攔路」"+HIG+"，待$n"+HIG+"稍一分神，\n"
                    "立即一剁一砍，向$n"+HIG+"的周身大穴招呼而來，令$n"+HIG+"感到搏手搏腳，毫無反擊能力。"NOR,
    "dodge"       : 20,
    "parry"       : -15,
    "damage"      : 160,
    "force"       : 160,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"運起六陽心法，只見$N"+HIG+"頭頂冒出白煙，"+HIM+"幔羅千葉刀法第十九式「移轉乾坤」"+HIG+"迅捷的使出，四周突然天旋地轉，\n"
                    "分不出東西南北，$n"+HIG+"已感到頭昏，$N"+HIG+"瞬間欺進$n"+HIG+"的身邊，舉起$w"+HIG+"便往$n"+HIG+"腦袋砍下。"NOR,
    "dodge"       : 10,
    "parry"       : -20,
    "damage"      : 200,
    "force"       : 200,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"氣沉丹田，力貫刀鋒，一招"+HIM+"幔羅千葉刀法第二十式「上步劈山」"+HIG+"向$n"+HIG+"招呼而來，$N"+HIG+"手中的$w"+HIG+"刀鋒閃閃發光，\n"
                    "刀未至，氣先到，一股深不可測的刀氣向$n"+HIG+"襲擊而來，接著強勁的$w"+HIG+"又跟著砍了過來，有如猛虎
下山之勢。"NOR,
    "dodge"       : 10,
    "parry"       : -15,
    "damage"      : 200,
    "force"       : 200,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"刀快似箭，刀光閃閃，片片燐光，以一招"+HIM+"幔羅千葉刀法第二十一式「刀斬海龍王」"+HIG+"向$n"+HIG+"襲掩而到，急砍向$n\n"
                    +HIG+"的小腹、右臂、左肩等處，$N"+HIG+"接著臂轉刀至，$n"+HIG+"全身上下被籠罩在刀氣之下，突然一股刀氣又向$n"+HIG+"擊了過來，\n"
                    "直向$n"+HIG+"腦門衝了過去。"NOR,
    "dodge"       : 20,
    "parry"       : -20,
    "damage"      : 230,
    "force"       : 230,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIG"$N"+HIG+"左手一揮，手中又多了一把$w"+HIG+"，雙刀其發，如虎添翼，一招"+HIM+"幔羅千葉刀法第二十二式「九龍遊天」"+HIG+"使出，\n"
                    "有如盤古開天闢地般氣象萬千，峰迴路轉，$N"+HIG+"身形飄盪不定，刀氣如九龍騰出，分路向四面八方襲擊而去。 "NOR,
    "dodge"       : 5,
    "parry"       : -20,
    "damage"      : 230,
    "force"       : 230,
    "damage_type" : "砍傷",
  ]),
  ([
    "action"      : HIW"$N"+HIG+"六陽心法一提，使出"HIR"『六陽三刀"HIW"～"HIR"天刀』"HIW"！"NOR,
    "damage"      : 300,
    "force"       : 300,
    "damage_type" : "砍傷",
    "post_action" : (: sp_att1 :),
  ]),
  ([
    "action"      : HIW"$N"+HIG+"六陽心法一提，使出"HIR"『六陽三刀"HIW"～"HIR"地刀』"HIW"！"NOR,
    "damage"      : 300,
    "force"       : 300,
    "damage_type" : "砍傷",
    "post_action" : (: sp_att2 :),
  ]),
  ([
    "action"      : HIW"$N"+HIG+"六陽心法一提，使出"HIR"『六陽三刀"HIW"～"HIR"人刀』"HIW"！"NOR,
    "damage"      : 300,
    "force"       : 300,
    "damage_type" : "砍傷",
    "post_action" : (: sp_att3 :),
  ]),
});

int valid_learn(object me)
{
  object weapon = me->query_temp("weapon");

  if( !weapon || weapon->query("skill_type") != "blade" ) {
    tell_object(me, "手中無刀怎麼個練法呀？\n");
    return 0;
  }
  else if( me->query("max_force") < 1200 ) {
    tell_object(me, "你的內力修為不夠，最少要有一千二百點。\n");
    return 0;
  }
  else if( me->query("force") < 600 ) {
    tell_object(me, "你目前的內力不到六百點，無法練此刀法。\n");
    return 0;
  }
  else if( me->query_skill("gold-blade", 1) < 90 ) {
    tell_object(me,"你的紫金六陽刀法不夠純熟，最少需要九十級。\n");
    return 0;
  }
  else if( (me->query("potential") - me->query("learned_points")) < 2 ) {
    tell_object(me, "你的潛能不到二點，無法練此刀法。\n");
    return 0;
  }
  tell_object(me, "學此刀法需扣潛能二點。\n");
  me->add("potential", -2);
  return 1;
}

string perform_action_file(string action)
{
  return CLASS_D("blademan")+"/fast-blade/"+action;
}

int valid_enable(string usage)
{
  return ( usage == "blade" );
}

mapping query_action(object me, object weapon)
{
  mapping do_action;
  object enemy, weaponn;
  string actionn;
  int i,j,k,level,kee,cpss;
  level = me->query_skill("fast-blade", 1);
  level = (int) level / 10;
  if( level > 10 ) level=10;
  if(me->query("family/family_name")=="金刀門"&&me->query("env/連擊",1)&&!me->is_busy())
  {
    if( random(9) >= 4 && me->query("sen") > 60 && !me->query_temp("f-b") )
    {
      me->set_temp("f-b",1);
      enemy=offensive_target(me);
      if(!enemy) return action[random(sizeof(action))];
      if(me->query_temp("conti")==1) level=4;
      for(j=0; j<level+2; j++) {
        k = level;
        if( level > 10 ) k = 10;
        k = (k+1) * 2;
        do_action = action[random(k)];
        actionn = "\n";
        actionn += do_action["action"];
        if( weaponn=me->query_temp("weapon") )
        actionn = replace_string(actionn, "$w", weaponn->name());
        message_vision(actionn, me, enemy);
        if( random(me->query_skill("blade")) > 70 ) 
        {
          kee = me->query_skill("blade");
          if ( kee <= 120 )
          {
            kee = 80;
          }
          else
          {
            kee = (kee/2)+20;
          }			
          enemy->receive_wound("kee",kee,me);
          message_vision(HIC "\n$N閃躲不及，被這一刀砍中了要害。\n" NOR, enemy);
          COMBAT_D->report_status(enemy);
        }
        else
          message_vision(HIC "\n$N人比刀快，驚險地閃過了這一刀。\n" NOR,enemy);
      }
      cpss = me->query_cps();
      if (cpss >= 35) cpss = 35;
      if (random(cpss) <= 7 ) 
      {
        me->start_busy(1);
        me->add("sen",-20);
        tell_object(me,"\n你使了快刀斬後，由於定力不夠，以致於精神無法集中。\n");
      }      
    }
  }
  if(me->query("family/family_name")=="金刀門") {
    me->delete_temp("f-b");
    return action[random(5)+20];
  } else {
    return action[0];
  }
}

void sp_att1(object me, object victim, object  weapon, int damage)
{
  if(85>random(100)&&me->query("force",1)>120)
  {
    message_vision(sprintf(HIG"
忽然$N"+HIG+"口中唸著口訣，身形步法也跟著加快，手中的"HIY"刀刃"HIG"也跟著急舞起來，
幔羅千葉刀法的第二十三式"HIW"「無式」"HIG"已在不知不覺中使出，只見$n"+HIG+"急忙招架，
但不知所擋的全是虛招，就在$n"+HIG+"擋的分不開神之際，你氣運"HIY"刀刃"HIG"，紛紛
向$n"+HIG+"全身招呼而去，只見無聲無息中，$n"+HIG+"已身中$N"+HIG+"無數刀招。\n"NOR),me,victim);
    victim->receive_damage("kee",me->query_skill("blade")+100,me);
    victim->apply_condition("blade",1);
    COMBAT_D->report_status(victim);
    me->add("force",-100);
    message_vision(sprintf("\n"),me,victim);
  }
}

void sp_att2(object me, object victim, object  weapon, int damage)
{
  if(85>random(100)&&me->query("force",1)>120)
  {
    message_vision(sprintf(HIG"
$N"+HIG+"運起紫金六陽刀法和幔羅千葉刀法的頂級功\力，讓手上的"HIY"武器"HIG"發出無比燦爛光茫，
令$n"+HIG+"望而生寒，就在這時，一道霸道無比的刀氣夾著$N"+HIG+"的怒吼聲衝向$n"+HIG+"，
令$n"+HIG+"不知如何抵擋，原來這就是失傳已久的刀招，"HIR"【傲笑天下】，"HIG"
只見$n"+HIG+"運起氣力招架，但仍莫名受傷，令$n"+HIG+"不知所措之下已受重傷。\n"NOR),me,victim);
    victim->receive_damage("kee",me->query_skill("blade")+200,me);
    victim->apply_condition("blade",2);
    COMBAT_D->report_status(victim);
    me->add("force",-100);
    message_vision(sprintf("\n"),me,victim);
  }
}

void sp_att3(object me, object victim, object  weapon, int damage)
{
  if(85>random(100)&&me->query("force",1)>120)
  {
    message_vision(sprintf(HIG"
$N"+HIG+"忽地收刀入鞘，整個人呆在原地，似乎對眼前的敵人毫不放在心上，
$n"+HIG+"見狀，舉起武器，使出武學中的精妙殺招，看來$N"+HIG+"就要慘死在$n"+HIG+"的
手下，但當$n"+HIG+"碰到$N"+HIG+"的身體時，$n"+HIG+"臉上表情突變，心知不妙，原來
$N"+HIG+"已化做無數身影團團圍住$n"+HIG+"，令$n"+HIG+"不知如何逃避，就在$n"+HIG+"驚訝之際，
無數的$N"+HIG+"使出一種$n"+HIG+"從未看過的刀法，紛紛向$n"+HIG+"全身的各大要害猛烈擊
去。原來這是傳說中的刀法"HIC"【反樸歸真】。\n"NOR),me,victim);
    victim->receive_wound("kee",me->query_skill("blade")+300,me);
    victim->apply_condition("blade",3);
    COMBAT_D->report_status(victim);
    me->add("force",-100);
    message_vision(sprintf("\n"),me,victim);
  }
}
