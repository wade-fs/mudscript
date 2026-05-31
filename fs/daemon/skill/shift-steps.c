// linbo-steps.c

inherit SKILL;

string *dodge_msg = 
({
"$n展開[1;36m『乾坤大挪移』[0m﹐[1m「神龍負圖出洛水，彩鳳啣書碧雲裡．」[0m$n的身形如長虹經天，飛鷹逐日， 翩然遊走於四面八方。\n",
"只見$n施展[1;36m『乾坤大挪移』[0m﹐[1m「陰陽二遁分順逆，縱棋十五在其中．」[0m在電光火石間，$n的身影瞬間消匿無蹤。\n",
"$n踏出[1;36m『乾坤大挪移』[0m﹐[1m「直符前三六合位，太陰之神在前二．」[0m$n腳踏陰陽五行方位，身法詭譎莫測。\n",
"$n使出[1;36m『乾坤大挪移』[0m﹐[1m「伏兵但向太陰位，若逄六合利逃形．」[0m剎那間風雲變色，天旋地轉，敵人只感到時空完全扭曲，再也難辨$n的所在。\n",
"$n展現[1;36m『乾坤大挪移』[0m﹐[1m「地遁日精紫雲蔽，藏形遁跡斯為美．」[0m幻化出無數個虛虛實實的身影，敵人完全迷惑難以捉摸。\n",
"$n斜踏[1;36m『乾坤大挪移』[0m﹐忽高忽低﹐有若[1;33m「坎蓬星水離為火，中宮坤艮土為營．」[0m只見$n腳踏坎位，再換離火，早已移轉到敵人的身後了。\n",
});

int valid_enable(string usage) 
{
	return (usage=="dodge")||(usage=="move");
}

int valid_learn(object me)
{
        if(me->query_skill("literate",1)*2 <= me->query_skill("shift-steps",1))
        {
          write("你的知識不足﹐無法體會乾坤大挪移中易經六十四卦的精要變化。\n");
          return 0;
	}
 if(me->query("class") != "prayer")
return notify_fail("你非聖火徒不能學之\n");
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if((int)me->query("kee")<5)
		return notify_fail("你的氣不夠﹐不能練乾坤大挪移。\n");
	me->receive_wound("kee",5);
	return 1;
}
