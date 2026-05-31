inherit F_CLEAN_UP;

int main( object me, string arg )
{
	string	magic, spl, trg;
	object	target;
	
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail( "你用力聚集靈氣, 發覺靈力一時難以發出。\n" );

   if(me->query("atman") < 0 ) {
   me->set("atman",0);
   tell_object(me,"沒靈力了用什呀?\n");
   return 1;
   }
	if( environment(me)->query("no_magic") )
		return notify_fail( "此處無法使用法術。\n" );

	if( !arg )
		return notify_fail( "指令格式: conjure <法術> [on <目標>]\n" );
  if(me->query_temp("no_roar"))
    return notify_fail("因為蠍毒的作用，你一句咒語也念不出來。\n");


	if( sscanf( arg, "%s on %s", spl, trg )==2 ) {
		target = present( trg, environment(me) );
		if( environment(me)->query("no_fight") || environment(me)->query("no_kill") )
			return notify_fail( "此處無法使用法術。\n" );
		if( !target )
			return notify_fail( "這裡沒有 " + trg + "。\n" );
		if( !living(target) )
			return notify_fail( "他不是生物。\n" );
		if( target->query("no_kill") )
			return notify_fail( "你不得對他施法。\n");
	}
	else {
		spl = arg;
		target = 0;
	}
	spl = replace_string( spl, " ", "_");

	if( stringp( magic = me->query_skill_mapped("magic") ) )
		return (int)SKILL_D(magic)->conjure_magic( me, spl, target );
	return notify_fail( "請先用 enable 指令選擇所要使用的法術系。\n" );
}

int help (object me)
{
        write(@HELP
指令格式﹕conjure <法術名稱> [on <對象>]
 
施法﹐你必需要指定<法術名稱>﹐<對象>則可有可無。
在你使用某一個法術之前﹐你必須先用 enable 指令來指定你要使用的法術系。
 
HELP
        );
        return 1;
}
