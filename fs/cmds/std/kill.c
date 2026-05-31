// kill.c
//Modify By Acelan...99.7.27......Chan 大大說 同一個人對同一個人下 kill 指令 需間隔五秒

#include <ansi.h>

int help( object me );

int wait_kill( object me , object obj )
{
        message_vision( HIY "$n遭到$N突如其來攻擊﹐頓時驚訝萬分﹐不知所措﹗\n" NOR,me,obj);
     obj->start_busy(1); //修正..因為躲起來下kill話會busy三回..修正為一回 by chan
        me->delete_temp("invis");
}

int group_kill( object me , object obj )
{
        object *all = me->query_team();
        int i;
        for( i = 0 ; i < sizeof(all) ; i ++ ) {
        if(present(obj,environment(all[i]))) {
                all[i]->kill_ob( obj );
                obj->kill_ob( all[i] );

//Add By AceLan...是我方下 kill 所以在 obj 身上設 mark
                obj->set_temp("killer"+ all[i]->query("id"), 1);
//五秒鐘後解除
                call_out("remove_killer",5,obj,all[i]->query("id"));

        }
        }
}

//移除 killer 的 mark...By AceLan
int remove_killer(object obj,string name)
{
    if(obj)
   obj->delete_temp("killer"+ name);
   return 1;
}

int main(object me, string arg)
{
  object obj, pal;
  string *killer, callname;


  if( !arg )
    return help(me);

  arg = lower_case(arg);
  me->delete_temp("cmd_cnt");  
  if(!objectp(obj = present(arg, environment(me))) || obj->gage(me))
    return notify_fail("你想殺死誰啊?!\n");

  if( !obj->is_character() || obj->is_corpse() )
    return notify_fail("看清楚一點﹐那並不是活物。\n");

  if(!obj->query("pker")) //pker沒有安全的區域
   {
   if( environment(me)->query("no_kill") || environment(me)->query("no_fight") || me->query("id")=="guest")
     return notify_fail("這裡不准砍殺。\n");
   }
  if (in_edit(obj) || in_input(obj) || obj->query_temp("netdead"))
    return notify_fail ("等他醒過來再砍吧.\n");

  if(obj==me) return notify_fail ("想自殺嗎? 用 suicide -f\n");

 if( wizardp(obj) && !wizardp(me) )  
		return notify_fail( "你無論怎麼砍, 就是碰不著" + obj->query("name") + "。\n" );
	if( wizardp(me) && userp(obj) && wizhood(me)!="(manager)" && wizhood(me) != "(admin)" )
		return notify_fail( "巫師不能亂砍玩家, 若要測試請以專門的測試員來測試。\n" );
	if( !userp(obj) && obj->query("no_kill") )
		return notify_fail( "你不得砍殺他。\n" );
	if( ((me->query("mud-age") - obj->query("mud_age")) > 172800) && userp(obj) && userp(me) )
		return notify_fail("請勿以長輩身份欺負晚輩。\n");
        if( me->query("combat_exp") < 10000 && userp(obj) && userp(me) )//限制exp小於1萬玩家不得pk以避免搗蛋者
                return notify_fail("戰鬥經驗不足，等經驗夠高在來砍玩家吧。\n");
	if( obj->query_temp("killer"+(string)me->query("id")))
		return notify_fail( "你已砍殺得滿身大汗。\n" );
    // 新增師父要重生後5分鐘才能殺
if(obj->query("family/privs") == -1 &&  uptime() % 900 < 300 && !wizardp(me))
    {           
                return notify_fail("對不起，現在不是時候。\n");
    }

  callname = obj->query("name");

  message_vision("\n$N對著$n喝道﹕「" 
    + callname + "﹗今日不是你死就是我活﹗」\n\n", me, obj);

  if( !userp(obj) && !obj->accept_kill(me) )
	return notify_fail( "看起來你砍不到"+obj->name()+"。\n" );

  if( obj->query("master") )
	if( obj->query("combat_exp") < 100000 || environment(obj)->query("pkroom") ||
		environment(obj)->query("no_die_room") )
		return notify_fail( "留給" +obj->name()+ "一條生路吧。\n" );

  me->set_temp("killer_time",time());

  if( obj->query_temp("pal")==me && !wizardp(obj) )
	return notify_fail( "你殺昏頭啦?\n" );

  if( pal=me->query_temp("pal") )
	if( present( pal, environment(me) ) ) {
		pal->kill_ob(obj);
	}
  me->kill_ob(obj);
  obj->kill_ob(me);

//Add By AceLan...是我方下 kill 所以在 obj 身上設 mark
  obj->set_temp("killer"+ me->query("id"),1);
//五秒鐘後解除
  call_out("remove_killer",5,obj,me->query("id"));

  if( me->is_team_leader() ) group_kill( me , obj );
  if( me->query_temp("invis") && obj->query_temp("see-wait") != me )
                wait_kill( me , obj );

  return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : kill <人物>
指令說明 : 
           這個指令讓你主動開始攻擊一個人物﹐並且嚐試
         殺死對方﹐kill 和 fight 最大的不同在於雙方將
         會真刀實槍地打鬥﹐也就是說﹐會真的受傷。由於
          kill 只需單方面一廂情願就可以成立﹐因此你對
         任何人使用 kill 指令都會開始戰鬥﹐通常如果對
         方是 NPC 的話﹐他們也會同樣對你使用 kill。
           當有人對你使用 kill 指令時會出現紅色的字樣
         警告你﹐對於一個玩家而言﹐如果你沒有對一名敵
         人使用過 kill 指令﹐就不會將對方真的打傷或殺
         死( 使用法術除外 )。
其他參考 :
           fight
特別說明 :
           有關 fight 跟 kill 的區分請看 'help combat'。
           有關 pk的問題請看"help pk"。
HELP
    );
    return 1;
}
 
