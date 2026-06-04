//金風細雨樓skill 之樓訣身法
//這是金風細雨樓npc的標誌,使用這一個dodge skill
#include <combat.h>
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
 "$n步踩蓮花身形飄晃地踏出一式" + HIC + "『樓步蓮車』" + NOR + "，眼光犀利地讀出$N的攻勢，不多不少的閃出一個空隙閃過了$N攻擊\n",
 "眼看$N的攻擊無法退閃，$n索性應前突進，使出一式" + HIR + "『樓侵火華』" + NOR + "，直接踏著$N的攻擊飛空而過\n",
 "$n不急不徐地轉身踮步，使出一式" + HIB + "『樓轉天渦』" + NOR + "，以極快的速度踏天奔走，$N根本無法追擊\n",
 "$n使出一式" + HIW + "『樓珀雙彗』" + NOR + "，躲躍如流風，任$N的攻勢再激烈也傷不到$n一根汗毛\n",
 "$n躍如鶯燕使出了一式" + HIG + "『樓尾追鳩』" + NOR + "，身形矯若禽鳥亂飛亂舞，不費吹灰之力的閃過了$N的攻擊\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge")||(usage=="move");
}


string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}


