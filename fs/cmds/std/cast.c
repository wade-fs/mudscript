// cast.c
//fix by airke

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string spell, spl, trg, str;
	int number=1;
	object target;
 
	seteuid(getuid());
    if(me->is_busy())
    return notify_fail("你一時無法聚集法力。\n");
  if(me->query("mana") < 0) {
  me->set("mana",0);
tell_object(me,"沒法力了用什呀?\n"); 
return 1;
  }
	if( environment(me)->query("no_fight") )
		return notify_fail("這裡不准戰鬥。\n");

	if( environment(me)->query("no_magic") )
		return notify_fail("這裡不准念咒文。\n");
	if( !arg )
		return notify_fail("指令格式﹕cast <法術> [on <目標>]\n");
  if(me->query_temp("no_roar"))
    return notify_fail("因為蠍毒的作用，你一句咒語也念不出來。\n");

	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
		target = present(trg, environment(me));
		if( !target ) target = present(trg, me);
		if( !target ) return notify_fail("這裡沒有 " + trg + "。\n");
	if( !living(target) && spl != "control") return notify_fail("他不是生物。\n");
	        if(target->query("family/privs") == -1 &&  uptime() % 900 < 300 && !wizardp(me))
    {           
                return notify_fail("對不起，請給新手一條生路。\n");
    }

        } 
// 召喚術專用格式--------------- by airke
	else if( sscanf(arg, "%d %s invocation", number, str)==2 
		 || sscanf(arg, "%s invocation",str)==1) {
	       if(stringp(spell = me->query_skill_mapped("spells")) )
		 return (int)SKILL_D(spell)->cast_invocation(me, number, str);
	       return notify_fail("你請先用 enable 指令選擇你要使用的咒文系。\n");
	}
//------------------------------
        else {
		spl = arg;
	if( !target = "/std/sserver"->offensive_target(me) )
			return notify_fail("你沒有對象可以讓你打。\n");
              
	}
	
	spl = replace_string( spl, " ", "_");
	
	if(stringp(spell = me->query_skill_mapped("spells")) )
		return (int)SKILL_D(spell)->cast_spells(me, spl, target, number);
	
		
	return notify_fail("你請先用 enable 指令選擇你要使用的咒文系。\n");
}

int help (object me)
{
        write(@HELP
指令格式 : cast <咒文名稱> [on <施咒對象>]
指令說明 :
           使用本命令施放法術﹐你必需要指定 <咒文名稱>﹐<施咒對象>則
         可有可無。
           在你使用某一個咒文之前﹐你必須先用 enable  指令來指定你要
         使用的咒文系。
特別注意 :
           如果你改變自己的咒文系﹐你原本蓄積的法力並不能直接轉換過去﹐
         必須從 0 開始。
HELP
        );
        return 1;
}
