// yu-needle
// 七奇針訣--- 手鍼(unarmed), 針鍼(stabber)
// by adam..

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void bleed(object me, object victim, object weapon, int damage);
void kforce(object me, object victim, object weapon, int damage);
void busyk(object me, object victim, object weapon, int damage);
void sp1(object me,object victim, object weapon, int damage);
void sp2(object me,object victim, object weapon, int damage);
void sp3(object me);
string *parry_msg=
    ({
   "$n身軀一引，指間長針平平搭在$N的武器上，一招『"HIM" 攔雀尾"NOR" 』將$N的武器曳了開去。\n",
   "$n將身體靠向$N，一招『"HIC" 沾衣十八跌 "NOR"』，將$N黏在原地，使不開招式!\n",
   "$n手中長針上下舞動，一招『"HIW" 飛瀑長虹"NOR" 』, 逼得$N不得不守住自身!\n",
   "$n把手中的長針舞成圓環一招『"HIB" 雲迴圓月 "NOR" 』，將$N的攻勢盡數擋了下來。\n",
   "$n以靜制動，手中長針平舉胸前，一招『"CYN" 如封似閉"NOR" 』，化解了$N的攻勢!\n",
});

//unarmed, stabber_action

mapping *action = ({
([ "action":"$N一招『"HIW" 白蛇吐信"NOR" 』，下身稍曲，步履前跨，雙掌微分，手指尖往$n的胸前『"HIC" 鳩尾穴"NOR" 』用力戳了去!",
        "dodge": -20,
        "parry": -20,
        "damage": 30,
        "force":  50,
        "damage_type":  "刺傷",
]),

([ "action":"$N手掌一張，一式『"HIR" 惡虎撲羊"NOR" 』，縱身一跳，由上往下向$n的頭頂『"HIY" 百會穴"NOR" 』撲了去!",
        "dodge": -20,
        "parry": -20,
        "damage": 40,
        "force":  50,
        "damage_type": "刺傷",
]),

([ "action":"$N雙手一拉一按一壓，將$n的左手背『"MAG" 合谷穴"NOR" 』制住，往外迴轉一圈，用力地將$n拋了開去!",
        "dodge": -20,
        "parry": -20,
        "damage": 50,
        "force":  60,
        "damage_type": "摔傷",
]),
([ "action" : "$N拗膝微蹲，倏地身軀一轉，繞到了$n的背後，中指向$n背後『"HIW" 命門穴"NOR"』戳了去!",
        "dodge": -20,
        "parry": -20,
        "damage": 60,
        "force":  70,
        "damage_type": "刺傷",
]),
([ "action" : "$N身行突然地往後退了數步，$n跟進，忽然$N身行立停，手肘一曲，轉退為進，肘尖往$n腹部『"HIR" 氣血穴"NOR" 』急頂而去!",
        "dodge": -30,
        "parry": -30,
        "damage": 70,
        "force":  80,
        "damage_type": "刺傷",
]),
([ "action":"$N呼嘯一聲，身法輕靈地往$n背後縱了去，雙手一打一戳，向$n的左邊『"HIY" 太陽穴"NOR" 』，後腦『"HIG" 風府穴"NOR" 』攻擊!",
        "dodge": -30,
        "parry": -30,
        "damage": 80,
        "force":  90,
        "damage_type": "刺傷",
]),
(["action":"$N一招『"HIM" 轉身六合"NOR" 』，身形輕輕左右搖擺\，雙手上下翻動，急速地向著$n拍打，或擒拿，往$n的全身各大要穴招呼!",
        "dodge": -30,
        "parry": -30,
        "damage": 90,
        "force":  90,
        "damage_type": "刺傷",
]),

//weapon_action

([ "action":"$N左手一揮，右手一勾，一招『"HIG" 飛花落葉"NOR"  』，把手中$w舞向$n的雙臂『"HIG" 尺澤穴"NOR" 』!",
        "dodge": -35,
        "parry": -35,
        "damage": 90,
        "force":  90,
        "damage_type":  "刺傷",
]),

([ "action":"$N運使$w, 左右開弓, 綿綿不盡, 戳向$n的胸前『"HIM" 膻中穴"NOR" 』, 背後『"HIR" 腎內穴"NOR" 』",
        "dodge": -40,
        "parry": -40,
        "damage": 90,
        "force":  90,
        "damage_type": "刺傷",
        "post_action": (: busyk :),
]),

([ "action":"$N身軀一蹲，雙手掐$w，平平往前直刺，一招『"HIC" 海底翻花"NOR" 』蓄勢待發，迎向$n的腳底『"HIC" 湧泉穴 "NOR"』",
        "dodge": -45,
        "parry": -45,
        "damage": 100,
        "force":  100,
        "damage_type": "刺傷",
        "post_action": (: busyk :),
]),
([ "action":"$N身法輕靈，一招『"HIY" 飛步拗鸞"NOR" 』，輕身一躍，$w刺向$n肩胛『"HIW" 雲門穴"NOR"』，肩頂『"WHT" 肩膠穴"NOR" 』",
        "dodge": -45,
        "parry": -45,
        "damage": 110,
        "force":  100,
        "damage_type": "刺傷",
        "post_action": (: busyk :),]),
([ "action":"$N雙臂向外一張，一式『"HIC" 大鵬展翅"NOR" 』，緊跟一招『"HIM" 平沙落雁"NOR" 』，手中$w疾向$n的咽喉『"HIB" 天突穴"NOR" 』刺去!\n",
        "dodge": -45,
        "parry": -45,
        "damage": 110,
        "force":  100,
        "damage_type": "刺傷",
      "post_action": (: kforce :),
]),
([ "action":"$N身形一轉，一式『"HIM" 轉身六合"NOR" 』，將手中$w舞成一股氣流，迴旋在$n四週，倏地一招『"HIY" 回望春月"NOR" 』，將$w刺向$n腦門『"WHT" 天柱穴"NOR" 』，『"HIC" 啞門穴"NOR" 』",
        "dodge": -50,
        "parry": -50,
        "damage": 110,
        "force":  100,
        "damage_type": "刺傷",
        "post_action": (: kforce :),
]),
([ "action":"$N大喝一聲『 絕命七針 』，鼓動全身內勁，手中$w舞成七點光點，分別
向$n的『"HIR" 百會穴"NOR" 』，『"WHT" 印堂穴"NOR" 』，『"HIC" 天突穴"NOR" 』，『"HIM" 膻中穴"NOR" 』，『"HIY" 中脘穴"NOR" 』，『"MAG" 鳩尾穴"NOR" 』，『"HIR" 氣海穴"NOR" 』，急急突刺!",
        "dodge": -50,
        "parry": -50,
        "damage": 110,
        "force":  120,
        "damage_type":"刺傷",
        "post_action": (: bleed :),
]),
//後三第一式
([ "action":
HIC"        $N忽的狂舞手中的針，使出一式"HIW"ζ"HIY"七奇"HIR"祕針˙"HBBLU+HIC"月映寒道玄冰滅"NOR+HIW"ζ！！\n\n\n"NOR+
HIC"                  $N聚氣針尖，使其散發出幽藍色的光芒，旋即身影一閃，\n
          形移到敵的面前三步處，隨又分身影化三，忽現一道寒芒向敵撲去，光芒過穿體\n
而過，使得敵身上"NOR"『"HIW"手太陰肺經"NOR"』，『"HIG"足太陰脾經"NOR"』，『"HIC"手少陰心經"NOR"』，『"HIR"足少陰腎經"NOR"』，『"HIB"手厥陰心\n
          包經"NOR"』，『"HIM"足厥陰肝經』"HIC"，六大陰經之個要穴血花斑斑，敵陰經脈受創，剎時感\n
                    到一股寒意引出，迅速遍佈全身由如置身極圈中的寒滅！\n
\n"NOR,
        "dodge": -50,
        "parry": -50,
        "damage": 110,
        "force":  120,
        "damage_type":"刺傷",
        "post_action": (: sp2 :),
]),
//後三第二式，恐怖連擊
([ "action":
"$N爆吼一聲，對$n連綿使出不絕之勢"HIW"ζ"HIY"七奇"HIR"祕針˙"HBRED+HIY"日照神州赤炎毀"NOR+HIW"ζ的極致連擊！！\n"NOR,
        "dodge": -50,
        "parry": -50,
        "damage": 110,
        "force":  120,
        "damage_type":"刺傷",
        "post_action": (: sp1 :),
]),
});

//超強攻擊

void bleed(object me, object victim, object weapon, int damage)
{
    int j=0;
    if (random(me->query_skill("stabber")) > 80 && me->query_temp("bleed")!=1 && me->query("class")=="doctor")
{
        me->set_temp("bleed",1);
        for(j = 0;j < 7; j++)
{
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        COMBAT_D->report_status(victim);
}
        me->delete_temp("bleed");
    if (random(100) > 65 && !me->is_busy())
{
        me->start_busy(1);
        message_vision(HIR"$N使勁過度無法繼續發動攻擊!!\n"NOR,me);
    }
  }
}

void kforce(object me, object victim, object weapon, int damage)
{
if (random(me->query("functions/break-kee/level")+100) > 70 && victim->query("force_factor") > 1
    && me->query("functions/break-kee/level") > 50 && me->query("force") > 50 && me->query("class")=="doctor")
{
message_vision(HIY"$N運起破穴指頂級技巧打散$n體內的內勁!!\n"NOR,me,victim);
if (victim->query("force_factor")>1) victim->add("force_factor",-1);
if (victim->query("force") > 400) victim->add("force",-300);
me->add("force",-50);
}}
void busyk(object me, object victim, object weapon, int damage)
{
if (random(me->query("functions/gold-needle/level")+100) > 75 && me->query_temp("bleed")!=1
    && me->query("functions/gold-needle/level") > 50 && me->query("force") > 50 && me->query("class")=="doctor")
{
message_vision(HIC"$N運起金針封穴頂級技巧封阻$n的行動!!\n"NOR,me,victim);
victim->start_busy(1);
me->add("force",-50);
  }
}
void sp1(object me,object victim, object weapon, int damage)
{
        int sklv,str,i,flag;

        sklv=me->query_skill("yu-needle",1);
        str=victim->query_str();

        if(sklv >100) sklv = 100;
        sklv*=(5+random(3));//最少500,最多700
        str*=(6+random(5));//最多350(除非剛剛加完str的話就370)

        if(!damage && 500 < random(1500)) return ;//被躲掉了，不一定要這樣寫
        if(me->query("force") < 600) return ;//內力不夠，以後可以加敘述
        if(me->query("kee") < 200) return;//kee不夠也不能發
        if(me->query_temp("bleed"))//不可以又被包含在連擊裡面
          return ;
        if(60 < random(100) && !me->query_temp("crazy_hit")) return;
        if(me->query("family/family_name")!="銀針門") return ;
        if(userp(me) && !me->query("env/六絕針")) return ;

        if(me->query_temp("crazy_hit")){
          me->delete_temp("crazy_hit");
          sklv*=2;
        }

        flag=0;
        for(i=1;i<=6;i++){
          switch(i){
            case 1:
        message_vision("
                  $N使出 --- "HBRED+HIW"◎ "HIY"赤 炎 六 絕 針 "HIW"◎"NOR" ---「"HIR"怒火燎原"NOR"」
$N"HIR"漫步提腰，雙腳一橫，手中的針斜斜裡從而刺出，突化做一股熱浪直戳向$n的"HIG"『勞宮穴』"HIR"！\n"NOR,me,victim);
            break;
            case 2:
        message_vision("
                  $N使出 --- "HBRED+HIW"◎ "HIY"赤 炎 六 絕 針 "HIW"◎"NOR" ---「"HIR"狂絕霸炎"NOR"」
$N"HIR"雙手交叉，大喝一聲，右手挺針當頭直刺，針忽脫手幻為一道火藤猛捲向$n的"HIC"『膻中穴』"HIR"！\n"NOR,me,victim);
            break;
            case 3:
        message_vision("
                  $N使出 --- "HBRED+HIW"◎ "HIY"赤 炎 六 絕 針 "HIW"◎"NOR" ---「"HIR"狂心炙焰"NOR"」
$N"HIR"身隨意轉，手隨心動，左手突發托住對方手腕，只見一陣針芒萬丈猛刺向$n的"HIW"『曲池穴』"HIR"！\n"NOR,me,victim);
            break;
            case 4:
        message_vision("
                  $N使出 --- "HBRED+HIW"◎ "HIY"赤 炎 六 絕 針 "HIW"◎"NOR" ---「"HIR"熾烈雄火"NOR"」
$N"HIR"側身而上，兩腳移步，將丹田之火貫於針尖，猛然向前直戳，針影直逼向$n的"HIM"『紫宮穴』"HIR"！\n"NOR,me,victim);
            break;
            case 5:
        message_vision("
                  $N使出 --- "HBRED+HIW"◎ "HIY"赤 炎 六 絕 針 "HIW"◎"NOR" ---「"HIR"赤血紅輪"NOR"」
$N"HIR"步走輕靈，身形向後，手捏針訣亂旋，突而針舞成輪，突現火紅針網罩向$n的"HIY"『至陽穴』"HIR"！\n"NOR,me,victim);
            break;
            case 6:
        message_vision("
                  $N使出 --- "HBRED+HIW"◎ "HIY"赤 炎 六 絕 針 "HIW"◎"NOR" ---「"HIR"玄炙火鳳"NOR"」
$N"HIR"輕靈飄忽，雙手後撤，手中之針突幻化為火鳳翔空，口吐火浪，滾滾撲向$n的"HIB"『百會穴』"HIR"！\n\n"NOR,me,victim);
            break;
          }
          if(50 > random(100)){
            message_vision(HIY"$N"HIY"不幸中招，傷處開始流血!!!\n"NOR,victim);
            victim->receive_damage("kee", sklv-str);
            COMBAT_D->report_status(victim);
            flag=1;
          }
          else{
            message_vision(HIG"$N"HIG"一個閃身，躲掉了致命的一針!!!\n"NOR,victim);
          }
        }
        if(flag){
          victim->apply_condition("burn", random(6)+3);
          victim->apply_condition("star-stial", random(6)+1);
          COMBAT_D->report_status(victim);
        }
        me->add("force",-600);
        message_vision("$N"HIB"因為使出了連擊技，幾乎耗盡了體內的真氣，趕緊立定調息！！\n"NOR,me);
        me->start_busy(1);
        COMBAT_D->report_status(me);
}
void sp2(object me,object victim, object weapon, int damage)
{
        int mforce,mkee;

        if(!damage) return ;
        if(me->query("force") <100)
          return notify_fail(HIR"你使出了七奇秘針之第二式之後，由於竭盡內力，竟無力再使！\n"NOR);
        mforce = (int)me->query("max_force");
        mkee = (int)me->query("max_kee");
        victim->start_busy(random(2)+1);//這樣子至少busy 1,所以me也要busy 1
        victim->apply_condition("cold", random(5)+3);
        victim->apply_condition("star-stial", random(6)+1);
        victim->receive_damage("kee",400,me);
        COMBAT_D->report_status(victim);
        me->add("force",-100);
        message_vision("$N"HIB"狂猛的使出七奇秘針之第二式之後，腦中一時血氣倒轉，幾欲暈厥！\n"NOR,me);
        me->start_busy(random(2));
}
//後三第三式，補血式
void sp3(object me)
{
        int force;
        string out;
out=
HIW"$N運起"HIW"ζ"HIY"七奇"HIR"祕針˙"HBCYN+HIW"星熾雲空極引破"NOR+HIW"ζ！！\n"NOR+
HIW"$N抓準時機，聚全身力於針鋒，向著自身運功\行氣之"HIM"奇經八脈"HIW"刺去～～～\n
                     "HIG"【～任  脈～】"HIR"            【～督  脈～】\n
                           "HIY"【～陽  蹻～】"HIC"【～陰  蹻～】\n
                     "HIW"【～陽  維～】"NOR+RED"            【～陰  維～】\n
               "HIB"【～衝  脈～】"HIM"                        【～帶  脈～】"NOR"\n
$N"HIR"一時感到體力回復了不少，又開始生龍活虎了起來！！！"NOR"\n"NOR;

        message_vision(out,me);

        force = (int)me->query_skill("force",1);
        force = force*(random(4)+2);
        me->receive_curing("gin",force);
        me->receive_curing("kee",force);
        me->receive_curing("sen",force);
        me->receive_heal("gin",force);
        me->receive_heal("kee",force);
        me->receive_heal("sen",force);
        COMBAT_D->report_status(me);
}

mapping query_action(object me, object weapon)
{
    int i, damage, sklv, limit;
    object *enemy, target;
    enemy = me->query_enemy();
    i = sizeof(enemy);
    target = offensive_target(me);
    sklv = (int)me->query_skill("yu-needle",1);
    damage = sklv+random(sklv);
    
    if(target)
{
    if(me->query("family/family_name") == "銀針門" && weapon->query("id")=="pnx_needle")
    {
    if(me->query("doctor/killpnx") == 1 && sklv >= 120)
        {
        message_vision("忽然從$N手中的ζ赤焰ζ鳳羽針中湧出一道炙熱的暖流注入$N的四經八脈
.....\n"NOR,me,target);
        message_vision("\t$N似乎有所頓悟，意隨身轉使出奧義祕式－《火鳳翔空》\n"NOR,me,target);
message_vision(HIR+@LONG
                                          .
                                        .::.
                                      .:::..
                                    .:::::..
                                  .:::::::..
                               .:::::::::::
                             .:::::::::::.
                          .::::::::::::::
                       .::::::::::::::::
                      ::::::::::::::::'
                      :::::::::::::::'
                       ::::::::::::::
                    .  :::::::::::.::                      '::::::'
                   .  . :::::::::::::                .:
                 .  .   ::::::::::::'            .::::::.    ':::::'   ::::'
                . .    .:::::::::::'                      ':::::::::::'
               . .   .::::::::::::'        .:::::::.
             .::.. .:::::::::::::.......:::::::.    ':::::::::.               '
          .:::: * ::::::::::::::::::::::      '::::::.        ':::::.  :::::'
       ..:::::::::::::::::::::::''''''':::::::'     '::::::.                   '
                  ':::::::::::::.            ':::::::'          :::::.     '
                    '::::::::::::.                     ':::::'      :::::
                     '::::::::::::.                           :::::'
                     .::::::::::::::
                     .::::::::::::::
                    .:::::::::::::::
                    ::::::::::::::::
                      ':::::::::::::.
                        '::::::::::::.
                          ':::::::::::.
                            '::::::::::
                              ':::::::''
                                ':::::''
                                  ':::''
                                    '::'
                                      '
LONG+NOR,me,target);
        message_vision(HIR"火鳳放出道道赤煉之火，將$n包圍在火光之中，$N似乎受傷不輕
...\n"NOR,me,target);
        target->apply_condition("bleeding",random(20)+5);
        target->receive_damage("kee",-sklv);
        COMBAT_D->report_status(target);
        me->add("force",-300);
        me->start_busy(1);
        }
    }
}

    limit=me->query_skill("yu-needle",1)/10;

    if(30 > random(100) && !me->query_temp("bleed") &&
       me->query("doctor/sosman") && limit >8)
       sp3(me);

    if (limit < 2 )
      return action[random(2)+2];
    if (limit == 2 )
      return action[random(3)+3];
    if (limit == 3 )
      return action[random(3)+4];
    if (limit == 4 )
      return action[random(3)+5];
    if (limit == 5 )
      return action[random(3)+6];
    if (limit == 6 )
      return action[random(3)+7];
    if (limit == 7 )
      return action[random(4)+7];
    if (limit == 8 ){
      return action[random(5)+7];
    }
    if (limit == 9 ){
      if(me->query("doctor/sosman"))
        return action[random(7)+8];
      else
        return action[random(6)+7];
    }
    if(limit>=10){
      if(me->query("doctor/sosman"))
        return action[random(7)+9];
      else
        return action[random(6)+8];
    }
}

int valid_enable(string usage)
{
    return (usage=="stabber") || (usage=="parry");
}

int practice_skill(object me)
{
        if(!me->query_temp("weapon") || !me->query_temp("secondary_weapon") )
          return notify_fail("練七奇針訣還是要拿根針吧!....\n");
        if( (int)me->query("gin") < 5 )
          return notify_fail("你的精不夠﹐無法練習。\n");
        if( (int)me->query("kee") < 30 )
          return notify_fail("體力不夠囉! 休息一下再繼續練吧.\n");
        if( (int)me->query("force") < 1 )
          return notify_fail("目前內力不足,休息一會兒再練吧.\n");
        me->receive_damage("gin", 5);
        me->receive_damage("kee", 30);
        me->add("force", -1);
        return 1;
}
string query_parry_msg(string limb)
{
   return parry_msg[random(sizeof(parry_msg))];
}
string perform_action_file(string action)
{
        return CLASS_D("doctor")+"/yu-needle/"+action;
}


