 

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
string *dodge_msg=({
   "$n使出雪蒼武學中的"HIW"「鬼腳步法」"NOR"雙腳殘幻﹐身形一轉﹐避了開去。\n",
   "$n使出迷蹤身法中的"HIM"「靈影浮動」"NOR"身形微晃﹐使$N這招撲了空。\n",
   "$n步法交錯﹐身形移位﹐使出"HIG"「幻影謎蹤」"NOR"閃了開去。\n",
   "$n使出"HIC"「轉風遊」"NOR"，意隨風行，輕輕巧巧地避了開來。\n",
   "$n身形一晃，使出"HIB"「殘影式」"NOR"只見數個黑影兔起鷂落，讓$N攻的不知所措招招落空。\n",
    });
string *array_msg=({
        "$n守在東位﹐一手"HIW"「盤天式」"NOR"攻得$N手忙腳亂﹗\n",
        "$n守在西位﹐一招"HIY"「臥地式」"NOR"企圖擾亂$N的攻勢﹗\n",
        "$n站在南位﹐一式"HIB"「南風迷」"NOR"連遞數個虛招﹗\n",
        "$n站在北位﹐一式"HIR"「北風狂」"NOR"連續猛攻$N﹗\n",
        "$n立在活門﹐一招"HIC"「八卦式」"NOR"使$N陷入八卦陣裡的死門﹗\n",
	});
int valid_learn(object me)
{
	return 1;
}
string query_dodge_msg(string limb)
{
    if(!this_player()) return "";
	if(this_player()->query_temp("use_form")==1)
    message_vision( array_msg[random(sizeof(array_msg))],offensive_target(this_player()),this_player());
	return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_enable(string  usage)  {
	return (usage=="dodge"||usage=="move");
}
int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的氣不夠﹐不能練黑影迷蹤步。\n");
	me->receive_damage("kee", 30);
	return 1;
}
