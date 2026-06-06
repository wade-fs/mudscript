//by roger
//極火掌;魔界之王專屬skill
inherit SKILL;
inherit SSERVER;
#include <ansi.h>
#include <combat.h>
void burn(object me, object victim, object  weapon, int damage);
mapping *action = ({
([	"action": "$N左掌火勁一吐，身形頓時向右平飄三尺，$n見此怪招不禁愕然!!$N趁機勁運右臂鼓起極火功\八成功\力將火勁悍然灌入$n的體內，正是" + HIR + "『五內具焚』" + NOR + "，$n被燒的哀嚎連連，鮮血狂吐",
		"dodge":		-60,
		"parry":		-60,
		"force":		350,
		"damage":               360,
                "post_action":               (: burn :),
		"damage_type":	"內臟灼傷"
	]),
([	"action": "$N勁運雙臂，雙手成爪狀不停地急旋下，使出霸道的" + HIR + "『風車火輪』" + NOR + "，$n被絞的防守盡失下，$N趁勢中宮直入，其急旋的氣勢幾乎將$n的手臂絞斷!!",
		"dodge":		-60,
		"parry":		-60,
		"force":		350,
		"damage":               360,
                "post_action":               (: burn :),
		"damage_type":	"火爪灼傷"
	]),
([	"action": "$N運起極火真氣,天靈聚起一片炙火,身形一旋,雙掌內攏,使出" + HIR + "『極火燎天崖』"+NOR + ",一圈,一吐,催起一股凌厲的氣焰,掃向$n!!",
		"dodge":		-60,
		"parry":		-60,
		"force":		350,
		"damage":               360,
                "post_action":               (: burn:),
		"damage_type":  "燒傷"
	]),
([	"action": "$N全身火勁暴吐之下，縱身在高空一式" + HIR + "『焚天極火』" + NOR + "從空中悍然以雙掌向$n直壓而下，剎那間$n的四周全部籠罩在強烈無匹的雄渾火勁中，鋪天蓋\地，無法閃避",
		"dodge":		-60,
		"parry":		-60,
		"force":		350,
		"damage":               360,
                "post_action":               (: burn :),
		"damage_type":	"極火內傷"
	]),
([	"action": "$N揉身而上,飄然滑行,順勢使出" + HIR + "『極火刀』"+NOR + ",雙掌火勁暴吐成刀,揮動之際,泛起一片紅光,有如電光之勢,$n頓時眼前罩上一片炙光,一陣昏眩,光刀迅速的朝$n各部位砍去!!",
                "dodge":                -60,
		"parry":		-60,
  		"force":		350,
		"damage":               360,
                "post_action":               (: burn :),
		"damage_type":	"極火刀傷"
	]),        
});

void burn(object me, object victim, object  weapon, int damage)
{
         int burn;
         burn=victim->query_condition("burn");
message_vision("$N的極火勁在$n的體內亂竄，使$n受到了嚴重的燒傷，兼且內息嚴重紊亂\n",me,victim);
         victim->apply_condition("burn",burn+3);
         victim->add("kee",-30);
         victim->add("force",-30);
         COMBAT_D->report_status(victim, 1);
 }
int valid_enable(string usage) { return ( usage=="unarmed" || usage=="parry"); }

mapping query_action(object me,object weapon)
{
 int i,force,kee,burn;
 object victim,*enemy;
 enemy = me->query_enemy();
 i=sizeof(enemy);
 victim = enemy[random(i)];
 burn=victim->query_condition("burn");
 force=victim->query("force",1);
 kee=140;
        if( random(100) < 10){    
             message_vision(HIY + "
$N狂笑說：「死在極火三掌下，你也不枉此生了！」


" + HIR + "                       看，極 火 三 掌 ！" + NOR + "


" + HIM + "第一掌
" + HIR + "---天羅火網---" + NOR + "
" + HIR + "$N穩穩地站在原地，雙手在胸前交叉畫了個圓，瞬間熊熊烈火
捲成一道漩渦般的火柱，其勢磅礡威猛，直捲向$n的面門！
" + NOR + "結果$n被極火柱當胸貫穿，鮮血狂吐，全身陷入熊熊烈火中！\n",me,victim);
             victim->receive_damage("kee",(int)kee,me);
             COMBAT_D->report_status(victim);
             message_vision("


" + HIG + "第二掌
" + HIR + "---極火雙摧---" + NOR + "
" + HIR + "$N運起極火功\，雙掌翻飛下火舌暴吐急衝往$n的上中盤，一
瞬間$n的面門以被極火掌印中，嗤嗤聲中夾雜著焦肉味和$n的慘叫聲...
" + NOR + "結果$n更被極火掌透胸而過，眼看是不活了\n",me,victim);
             victim->receive_damage("kee",(int)kee,me);
             COMBAT_D->report_status(victim);     
             message_vision(HIY + "

$N大吼：「死吧！」

" + HIW + "第三掌
" + HIR + "---極火焚盡九重天---
$N狂吼一聲，豁盡所能將渾身熾熱極火以鋪天蓋\地之勢向
$n籠罩而下頓時天地全部都籠罩在火海中，燒得$n皮開
肉綻，哀嚎不斷！
\n" + NOR,me,victim);
             victim->receive_damage("kee",190,me);
             victim->apply_condition("burn",burn+18);
             me->start_busy(2);
            COMBAT_D->report_status(victim);
                             }

    return action[random(sizeof(action))];
}

string *parry_msg = ({
HIR + "\n但$n運起極火真氣硬架，$N只覺得一股非比尋常的熱氣從手中的$w傳來，不得不撤招防禦\n" + NOR,
            });
string query_parry_msg(string limb)
{
   return parry_msg[random(sizeof(parry_msg))] ;
}
             
