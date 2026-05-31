// buddhism.c
//僅供en給予神瞑提昇與增加靈氣「佛法」的最大值判定 by blazakira
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_enable(string usage) {
	object me=this_player();
	if ( me->query("bonze/force/arhatforce",1) || me->query("bonze/force/yijinforce",1) ) //en資格 學會阿羅漢神功與易筋經
	{
		return usage=="magic"; 
	}
}

int valid_learn(object me) 
{
	if( (int)me->query("bellicosity") > 100 )
		return notify_fail("你的殺氣太重﹐無法修煉大乘佛法。\n");
	return 1;
}
