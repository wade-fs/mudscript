// nine-steps.c

inherit SKILL;

string *dodge_msg = ({

"\n$n展現『[1;31m移形幻影[0m』似真似幻，似幻似真，讓$N捉摸不定,忽然一個轉身,就輕易閃開\n",

"\n$n使出『[1;32m鬼魅身法[0m』猶如一形十影，追風逐電，迅速移位，頃刻如鬼魅般飛到$N身旁\n",

"\n面對$N的攻擊，只要中任何一招，便會筋碎骨斷，於是$n利用『[1;33m金蟬脫殼[0m』閃開\n",

"\n$n凝神入定，口中唸唸有詞，瞬間伸手一指發出『[1;34m定身法[0m』嘗試把$N給定住不動！\n",

"\n$n施展『[1;33m九天靈影身法[0m』身法式『[1;35m魚遊身法[0m』，身隨意行，四方遊走，避開$N攻擊\n",

"\n$n展現『[1;33m九天靈影身法[0m』拆卸式『[1;36m懷中抱月[0m』，見招拆招，見式破式，靜觀$N的弱點\n",

"\n$n使出『[1;33m九天靈影身法[0m』攻擊式『[1;31m八臂邪神[0m』，如狂風暴雨綿綿不斷攻擊$N永不停息\n",

"\n$n打出『[1;33m九天靈影身法[0m』困住式『[1;35m閻羅召喚[0m』，出現鬼魂，神出鬼沒撲到$N的身後\n",
});

int valid_enable(string usage) {
	return (usage=="dodge")||(usage=="move");

}

int valid_learn(object me)
{
	return 1;
}
string perform_action_file(string action)
{
return CLASS_D("poisoner")+"/nine-steps/"+action;
} 
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if((int)me->query("kee")<5)
		return notify_fail("你的氣不夠﹐不能練九天靈影步。\n");
	me->receive_wound("kee",5);
	return 1;
}
