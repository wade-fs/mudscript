// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;

        seteuid(getuid());
  if((!wizardp(me) && environment(me)->query("no_fight"))||me->query("id")=="guest")
		return notify_fail("這裡禁止對打。\n");

	if(!arg || !objectp(obj = present(lower_case(arg), environment(me))))
		return notify_fail("你想攻擊誰﹖\n");
        arg = lower_case(arg);

	if( !obj->is_character() )
		return notify_fail("看清楚一點﹐那並不是生物。\n");

	if (obj->query("no_kill")) return
          notify_fail ("這傢伙你不能動就是不能動。\n");

if(obj->query("family/privs") == -1 &&  uptime() % 900 < 300 )
return notify_fail("你沒看到他現在沒空，你等一會再試試看。");
	if( obj->is_fighting(me) )
		return notify_fail("加油﹗加油﹗加油﹗\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "已經無法戰鬥了。\n"); 

	if(obj==me)	return notify_fail("你不能攻擊自己。\n");

if( !userp(obj) && !obj->accept_fight(me) ) return
    notify_fail ("看起來你砍不到"+obj->name()+"\n");

	if (in_edit(obj) || in_input(obj) || obj->query_temp("netdead"))
          return notify_fail ("等他醒過來再砍吧.\n");

	if( userp(obj) && (object)obj->query_temp("pending/fight")!=me ) {
		message_vision("\n$N對著$n說道﹕" 
			+ RANK_D->query_self(me) 
			+ me->name() + "﹐領教"
			+ RANK_D->query_respect(obj) + "的高招﹗\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "取消了和你比試的念頭。\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL "如果你願意和對方進行比試﹐請你也對" + me->name() + "("+(string)me->query("id")+")"+ "下一次 fight 指令。\n" NOR);
		write(YEL "由於對方是由玩家控制的人物﹐你必須等對方同意才能進行比試。\n" NOR);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N對著$n說道﹕" 
			+ RANK_D->query_self(me) 
			+ me->name() + "﹐領教"
			+ RANK_D->query_respect(obj) + "的高招﹗\n\n", me, obj);


		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N大喝一聲﹐開始對$n發動攻擊﹗\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : fight <人物>
指令說明 : 
           這個指令讓你向一個人物「討教」或者是「切磋武藝」﹐
         這種形式的戰鬥純粹是點到為止﹐因此只會消耗體力﹐不
         會真的受傷﹐但是並不是所有的  NPC 都喜歡打架﹐因此
         有需多狀況你的比武要求會被拒絕。
附    註 :
           如果對方不願意接受你的挑戰﹐你仍然可以逕行用 kill
         指令開始戰鬥﹐有關 fight 跟 kill 的區分請看
其他參考 :
           kill，help combat
HELP
    );
    return 1;
}
 
