
// fole-ken.c //風雷八式// write by ｃｃｈ..

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action":"$N狂吼一聲,上空平身挪後三寸,左手拍地,右手股動內勁,一招" + HIW + "『氣臨山河動』"+NOR + ",破天而出,
掌勁如山,激起無濤的氣勁,夾著雷霆萬駒之勢朝$n而來!!",
	        "dodge":		-10,
		"parry":		-40,
		"force":		200,
		"damage":               135,
		"damage_type":	"瘀傷"
	]),
([	"action": "$N使出一招" + HIW + "『雷鼓震山川』"+NOR + ",力與神會,勁由意生,一鼓雄渾的內勁.起自足底,
順勁推出,連暴聲聲巨響,完全發揮" + HIC + "『一川碎石大如斗』"+NOR + "之精義,$n勁風彿面,
已處萬劫險境,虎虎的勁風擊向$n胸口!!",
		"dodge":		-40,
		"parry":		-10,
		"force":		270,
		"damage":               150,
		"damage_type":	"震傷"
	]),
([	"action": "$N使出風雷八式" + CYN + "『水精勢絕倫』"+NOR + ",雙掌猛揚,一片青色的勁氣,尤如萬丈飛瀑,
夾著一股排山倒海的掌風,衝向$n身前,怒海洪濤般的擊向$n..",
		"dodge":		-15,
		"parry":		-20,
		"force":		120,
		"damage":               60,
		"damage_type":	"劈傷"
	]),
([	"action": "$N左足橫移,挫腰沈身,單袖一揚使出" + YEL + "『風沙暗夜吼』"+NOR + ",瞬時狂風拂起, 
塵沙飛揚,乃武訣之" + HIY + "『平沙莽莽黃入天,隨風滿地石亂走』"+NOR + "$N趁飛沙走石之際,
朝$n的天靈蓋\連續出數掌!!",
		"dodge":		-50,
		"parry":		-25,
		"force":		160,
		"damage":               110,
		"damage_type":	"瘀傷"
	]),
([	"action": "$N運起陽剛真氣,天靈聚起一片炙火,身形一旋,雙掌內攏,使出" + HIR + "『火光燎天戈』"+NOR + ",一圈,
一吐,催起一股凌厲的氣焰,掃向$n!!",
		"dodge":		-30,
		"parry":		-10,
		"force":		100,
		"damage":               60,
		"damage_type":  "燙傷"
	]),
([	"action": "$N雙掌飄飄,連遞數十掌,領悟武訣中之" + HIW + "『長風吹林雨墜瓦』"+NOR + ",
此乃風雷八式之" + HIC + "『雨凝破山石』" + NOR + ",掌影瀰漫,看似狂風暴雨,
掌氣有如細雨般同時灑向$n全身要穴!!",
		"dodge":		-10,
		"parry":		-30,
		"force":		150,
		"damage":               70,
		"damage_type":	"侵蝕之傷"
	]),
([	"action": "$N揉身而上,飄然滑行,順勢使出" + HIW + "『電花照天河』"+NOR + ",雙掌如刀如劍,揮動之際,
泛起一片光芒,有如電光之勢,$n頓時眼前罩上一片炙光,一陣昏眩,
光刀迅速的朝$n各部位砍去!!",
                "dodge":                -35,
		"parry":		 20,
  		"force":		120,
		"damage":                80,
		"damage_type":	"破體之傷"
	]),
([      "action": "$N運起寒冰真氣,不覺體泛冰氣,瞬間.....捲起一陣寒風,此時雙掌疾吐,
施展一招" + HIC + "『冰寒囓人心』"+NOR + ",煞時寒氣從掌心飄出,$n已被寒氣逼的步法錯亂,
刺骨冰寒的掌氣,不斷的往$n各處拍去!!!",
                "dodge":               -10,
                "parry":               -40,
                "force":               130,
                "damage":              100,	
                "damage type":  "凍體之傷"
        ]),        
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("風雷八式是掌法..必須放下兵刃。\n");

	if( (int)me->query("max_force") < 200 )
		return notify_fail("你的內力太弱,硬練會導致經脈破裂.\n");
	return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的體力不夠,不能再練了。\n");
	if( (int)me->query("force") < 5 )
		return notify_fail("你沒有足夠的內力一展絕學.\n");
	me->receive_damage("kee", 20);
	me->add("force", -5);
    write("你提起真氣將絕式練了一遍,頓時覺得功\力又更上一層樓. \n"); 
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
 if( damage_bonus < 100 ) return 0;
  if( random(damage_bonus/2) > victim->query_str() ) {
    victim->receive_wound("kee", (damage_bonus - 100) / 2 );
        switch(random(3)) {
        case 0: return "$N的掌氣紮實的擊中,$n連退數十步,並吐了一口鮮血!!\n";
        case 1: return "$N勁力一吐﹐$n的身體發出「喀」地一聲爆響,似乎骨頭以被擊碎.\n";
        case 2: return "一聲慘叫,$n的以被擊中,$n已面含驚懼之色,神情慘然.\n";
              }}}
              
