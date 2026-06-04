//血戰十式 by bss
//皇城mob專用，不開放
//排版 by blazakira 2011/10/6

#include <ansi.h>
#include <combat.h>
inherit SKILL;

void sp_attack(object me,object victim,object weapon,int damage);

mapping *action = ({
([  "action"     :
HIC + "$N" + HIC + "手中刀身前探，使出" + HIR + "血戰十式" + HIC + "的起手式"BLINK+HIY + "「兩軍對壘」" + NOR + "" + HIC + "，一道道如熱風般的刀氣由$w" + HIC + "散出，
$N" + HIC + "腳下一動，向$n" + HIC + "狂奔而至，手中$w" + HIC + "毫無花巧的砍向了$n" + HIC + "的$l，其招意在於以穩固之陣式
喝阻敵方，使敵方不敢輕舉妄動。" + NOR,
    "damage": 100,
    "dodge": -100,
    "parry": -100,
    "force": 100,
    "damage_type": "砍傷",
    "post_action": (:call_other,__FILE__,"damage_weapon":),
]),
([  "action"     :
HIC + "$N" + HIC + "忽然冷笑一聲，手中$w" + HIC + "化作一道黃芒，砍向$n" + HIC + "的$l，正是" + HIR + "血戰十式" + HIC + "的第二式"BLINK+HIY + "「烽芒畢露」" + NOR + "" + HIC + "，
其招意在以全軍最強之攻勢攻擊敵方，使敵方陷於被動之狀態，使主動權在我方，$n" + HIC + "受到
$N" + HIC + "那一聲冷笑的影響，稍微遲疑了一下，黃芒卻已經逼近了。" + NOR,
    "damage": 300,
    "dodge": -100,
    "parry": -100,
    "force": 100,
    "damage_type": "砍傷",
    "post_action": (:call_other,__FILE__,"damage_weapon":),
    "post_action": (: sp_attack:),
]),
([  "action"     :
HIC + "$N" + HIC + "身形展開，腳下一快，$w" + HIC + "有如一道利刃般刺向了$n" + HIC + "的$l，正是" + HIR + "血戰十式" + HIC + "的第三式"BLINK+HIY + "「輕騎突出」" + NOR + "" + HIC + "，
其招意在以快速準確的攻擊，攻破對方防線，使敵方自亂陣腳，因招式所帶起的刀氣，如旋
風般已先一步的攻向$n" + HIC + "。" + NOR,
    "damage": 300,
    "dodge": -100,
    "parry": -100,
    "force": 100,
    "damage_type": "刺傷",
    "post_action": (:call_other,__FILE__,"damage_weapon":),
]),
([  "action"     :
HIC + "$N" + HIC + "手中$w" + HIC + "向前一探，刀尖挑向$n" + HIC + "左腋下的淵腋穴，正是" + HIR + "血戰十式" + HIC + "中的第四式"BLINK+HIY + "「探囊取物」" + NOR + "" + HIC + "，
因招式所引起的刀氣牢牢鎖定著$n" + HIC + "，$n" + HIC + "見刀勢猛烈，忙展開身形，務必要躲開這致命的一
刀。" + NOR,
    "damage": 300,
    "dodge": -100,
    "parry": -100,
    "force": 100,
    "damage_type": "刺傷",
    "post_action": (:call_other,__FILE__,"damage_weapon":),
    "post_action": (: sp_attack:),
]),
([  "action"     :
HIC + "$N" + HIC + "眼中精光大放，將氣勢升高至最頂點，刀身前放，忽地大喊"BLINK+HIW + "「必殺一擊」" + NOR + "" + HIC + "，身子疾往前
衝，$n" + HIC + "被$N" + HIC + "那一去無回的氣勢所嚇了一大跳，此招正是" + HIR + "血戰十式" + HIC + "中的第五式"BLINK+HIY + "「一戰功\成」" + NOR + "" + HIC + "，
其招意在以此一招達到致敵於死地的效果，畢其功\於一役。" + NOR,
    "damage": 300,
    "dodge": -100,
    "parry": -100,
    "force": 100,
    "damage_type": "劈傷",
    "post_action": (:call_other,__FILE__,"damage_weapon":),
]),
([  "action"     :
HIC + "$N" + HIC + "手中$w" + HIC + "忽然脫手，正當$n" + HIC + "以為有機可乘之際，$N" + HIC + "以右手的中指及食指連著刀柄，忽然快
速的劈出上六路，中六路，下六路，共十八刀，正是" + HIR + "血戰十式" + HIC + "中的第六式"BLINK+HIY + "「批亢搗虛」" + NOR + "" + HIC + "，
其招意在不論敵方攻勢如何，皆以此猛烈之形式擊出，以嚇退敵人，達到不戰而驅人之兵
的兵法最高境界。" + NOR,
    "damage": 300,
    "force": 100,
    "dodge": -100,
    "parry": -100,
    "damage_type": "劈傷",
    "post_action": (:call_other,__FILE__,"damage_weapon":),
    "post_action": (: sp_attack:),
]),
([  "action"     :
HIC + "$N" + HIC + "手中$w" + HIC + "忽然開始隨意的晃動，越晃越快，漸漸地失去了$w" + HIC + "的影子，$n" + HIC + "只覺得$w" + HIC + "隨時有可
能從任何一個地方砍向自己，此招正是" + HIR + "血戰十式" + HIC + "中的第七式"BLINK+HIY + "「兵無常勢」" + NOR + "" + HIC + "，其招意在以絕
快的行動奇襲敵方，攻其不備，使敵方重創。" + NOR,
    "damage":       300,
    "dodge":        -100,
    "parry":        -100,
    "force":        100,
    "damage_type": "砍傷",
    "post_action": (:call_other,__FILE__,"damage_weapon":),
]),
([  "action"     :
HIC + "$N" + HIC + "忽然暴喝一聲："BLINK+HIG + "「狗賊！！今日不是你死就是我亡」" + NOR + "" + HIC + "，雙手將$w" + HIC + "高舉過頭，猛力向下一
劈，其刀氣大有可以開山斷海的氣勢，此招正是" + HIR + "血戰十式" + HIC + "中的第八式"BLINK+HIY + "「死生存亡」" + NOR + "" + HIC + "，其招
意在以全身勁力劈出這驚天一刀，以此驚天刀勢殲殺敵方。" + NOR,
    "damage":       300,
    "force":        100,
    "dodge":        -100,
    "parry":        -100,
    "damage_type": "劈傷",
    "post_action": (:call_other,__FILE__,"damage_weapon":),
    "post_action": (: sp_attack:),
]),
([  "action"     :
HIC + "$N" + HIC + "向前大跨一步，殺氣忽然由$N的身旁湧出，$N眼中血光一現，霍地旋身而起，刀隨身轉，
旋風般攻向$n" + HIC + "，此招正是" + HIR + "血戰十式" + HIC + "中的第九式"BLINK+HIY + "「強而避之」" + NOR + "" + HIC + "，其招意在以自身為穿透敵方
防陣的鑿子，破入敵方陣地，以收裡外挾攻，事半功\倍之用。" + NOR,
    "damage":       300,
    "dodge":        -100,
    "parry":        -100,
    "force":        100,
    "damage_type": "割傷",
    "post_action": (:call_other,__FILE__,"damage_weapon":),
]),
([  "action"     :
HIC + "$N" + HIC + "握緊手中$w" + HIC + "，將全身真力貫入$w" + HIC + "內，霎那間狂風大作，四週激起了因招式而產生了颶風，
$n" + HIC + "不敢相信世上竟有如此驚人之招式，一時間無法動作，$N" + HIC + "眼看時機成熟，大喝一聲：
"BLINK+HIM + "「天降大任於我，～君～臨～天～下～」" + NOR + "" + HIC + "，刀勢如雪花般飄向$n" + HIC + "，此招正是" + HIR + "血戰十式" + HIC + "中的
第十式"BLINK+HIY + "「君臨天下」" + NOR + "" + HIC + "，其招意在以驚人攻勢使敵方畏懼，使我方可以不費吹灰之力的取得
絕對的勝利。" + NOR,
    "damage":       300,
    "dodge":        -100,
    "parry":        -100,
    "force":        100,
    "damage_type": "砍傷",
    "post_action": (:call_other,__FILE__,"damage_weapon":),
    "post_action": (: sp_attack:),
  ]),
});

int valid_learn(object me)
{
  return 1;
}

int valid_enable(string usage)
{
  return (usage=="blade");
}

mapping query_action(object me, object weapon)
{
  return action[random(sizeof(action))];
}

void sp_attack(object me,object victim, object weapon,int damage)
{
  int i,j;
  if(40 > random(100) && !me->query_temp("conti")) {
    message_vision(HIY + "\n$N殺的興起，手中$n" + HIY + "忽然綻放金光，$n" + HIY + "有如神龍般使出連擊技。\n" + NOR,me,weapon);
    victim->start_busy(1);
    me->set_temp("conti",1);
    switch(random(4)) {
      case 1:
        j=1;
        break;
      case 2:
        j=2;
        break;
      case 3:
        j=3;
        break;
      case 0:
        j=4;
        break;
      default:
        j=1;
        break;
    }
    for(i=0;i<j;i++)
      COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    me->delete_temp("conti");
    me->start_busy(1);
  }
}
