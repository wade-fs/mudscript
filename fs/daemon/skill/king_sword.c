// KING_ROAD_SWORD.c

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void sp_attack0(object me, object victim, object  weapon, int damage);

mapping *action = ({
	([	"action":		HIC + "$N將真氣灌注於$w$" + HIC + "﹐使出" + HIY + "「秋末悲歌」" + HIC + "一式﹐只聽見$w" + HIC + "發出陣陣悲鳴之聲﹐$n漸漸受悲鳴之聲所擾﹗",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                300,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "刺傷"
	]),
	([	"action":		HIC + "$N將真氣化為陰陽兩勁﹐使出" + HIR + "「日月同天」" + HIC + "一式﹐連續配合劍氣揮擊﹐只見劍氣化為日月兩形﹐以不同方向擊向$n",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                350,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "刺傷"
	]),
	([	"action":		HIC + "$N突然將招式狂轉已身法為主﹐使出" + WHT + "「搏命」" + HIC + "一式﹐$n只見到$N的之殘影在身邊﹐無法確定$N真身所在﹐已在$n$l留下數道劍痕",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                400,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "刺傷"
	]),
	([	"action":		HIC + "$N狂舞手中$w" + HIC + "﹐使出" + HIB + "「慾望之海」" + HIC + "﹐劍氣瞬間形成一道無形漩渦迅捷的將$n捲入其中",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                450,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "刺傷"
	]),
	([	"action":		HIC + "$N將劍氣凝聚成一陰柔劍氣﹐使出治病劍招" + HIM + "「無怨無尤」﹐劍氣瞬間由$n的$l竄入﹐進入$n經脈之中",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                500,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "刺傷"
	]),
	([	"action":		HIC + "$N真氣遊走全身，使出" + HIG + "「廬山不動一劍痕」" + HIC + "，真氣化為無形劍氣在周身產生綿密的保護網，$n絲毫看不透此招近身攻擊，$n陷入網中",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                550,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "刺傷"
	]),
  ([  "action"     :      HIC + "$N緩唸一段劍訣：" + HIW + "「指天為名、拄地為功\、忘棄紅塵」" + HIC + "，隨後身形急旋而上，幻化出無數身影後，劍氣四散而出﹐$n瞬時被劍氣籠罩",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                340,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "刺傷"
	]),
});
int valid_enable(string usage)
{
        return (usage=="sword")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{

        return action[random(sizeof(action))];
}
void sp_attack0(object me, object victim, object  weapon, int damage)
{
  int i;

  message_vision(HIR + "$N領悟出將王者之路招與招之間串連之法、連綿不絕的劍訣, "
    "劍式一式接著一式連貫出招, 劍式有如濤濤江水連綿不絕!!\n" + NOR, me, victim);
  for (i = 0;i < 15; i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}
