// trade.c

inherit SKILL;
int valid_learn(object me)
{
     return notify_fail("這樣技能只能靠交易行為增加熟練度。\n");
}
