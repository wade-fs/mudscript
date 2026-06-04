// KING_ROAD_SWORD.c
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void sp_attack0(object me, object victim, object  weapon, int damage);

mapping *action = ({
	([	"action":		
HIW + "$N將真氣灌注於$w" + HIC + "﹐劍身本身劍靈與真氣激盪﹐緩緩發出共鳴之聲

                        " + HIY + "王者之路" + HIW + "之「" + HIR + "秋末悲歌" + HIW + "」

" + HIW + "共鳴之聲漸漸轉變為陣陣亡者悲鳴之聲﹐$n漸漸受悲鳴之聲所擾﹗",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                300,
                "force"      :                300,
                "damage_type":               "刺傷"
	]),
	([	"action":		
HIW + "$N將劍氣隨意而發﹐劍氣在真氣流轉之間化為陰陽劍氣﹐劍氣形成日月雙形

                         " + HIY + "王者之路" + HIW + "之「" + HIR + "日" + HIY + "月" + HIC + "同天" + HIW + "」

" + HIW + "日月劍氣一剛一柔互相彌補﹐日月劍氣漸化太極之勢毫無破綻﹐擊向$n﹗",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                350,
                "force"      :                350,
                "damage_type":               "刺傷"
	]),
	([	"action":		
HIW + "$N心神突然受劍招影響﹐心性漸漸轉為狂暴﹐劍隨心行﹐劍招漸漸越舞越狂

                          " + HIY + "王者之路" + HIW + "之「" + WHT + "搏命" + HIW + "」

" + HIW + "劍招狂亂中帶有逼殺之意﹐$n無法看清$N瘋狂劍舞中之破綻﹗",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "damage_type":               "刺傷"
	]),
	([	"action":		
HIW + "$N真氣突然如海翻騰﹐劍氣也隨著真氣如波濤一般﹐只見劍氣化為一道道劍浪

                          " + HIY + "王者之路" + HIW + "之「" + HIB + "慾望之海" + HIW + "」

" + HIW + "劍浪在$n四週突然匯流﹐瞬間形成一道無形漩渦迅捷的將$n捲入其中﹗",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                450,
                "force"      :                450,
                "damage_type":               "刺傷"
	]),
	([	"action":		
HIW + "$N真氣漸轉陰柔﹐劍氣隨真氣漸漸轉化成一陰柔劍氣﹐如絲如絮﹐飄緲難尋

                           " + HIY + "王者之路" + HIW + "之「" + HIM + "無怨無尤" + HIW + "」

" + HIW + "劍氣在與$n接觸的一瞬間﹐劍氣由$l透體竄入﹐進入$n經脈之中﹗",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                500,
                "force"      :                500,
                "damage_type":               "刺傷"
	]),
	([	"action":		
HIW + "$N真氣於丹田中運轉﹐運轉中真氣越運越加激烈﹐劍招在無意中變得剛烈

                           " + HIY + "王者之路" + HIW + "之「" + HIG + "廬山不動一劍痕" + HIW + "」

" + HIW + "劍勢之猛如同狂龍嘯天﹐$n如驚弓之鳥臨時想不出應對之策",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                550,
                "force"      :                550,
                "damage_type":               "刺傷"
	]),
	([	"action":		
HIW + "$N緩唸一段劍訣「" + HIR + "指天為名" + HIW + "、" + WHT + "拄地為功" + HIW + "、" + HIM + "忘棄紅塵" + HIW + "」，隨後身形急旋而上

                           " + HIY + "王者之路" + HIW + "之「" + HIM + "忘棄紅塵" + HIW + "」

" + HIW + "幻化出無數身影後﹐劍氣四散而出﹐$n瞬時被劍氣籠罩",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                340,
                "force"      :                340,
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

