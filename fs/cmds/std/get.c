// get.c babe
// fix 地上東西只撿部分就會消失的 bug
// 增加撿屍體告知主人

#include <ansi.h>
#include <carry.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob);

int main(object me, string arg)
{
  string from, item;
  object obj, *inv, env, obj2;
  int i, amount;

	seteuid(getuid());

	if (!NATURE_D->vision(me))
		write ( "四週烏漆媽黑的, 你隨處摸啊摸.........\n");

	if( !arg ) return notify_fail("你要撿起什麼東西﹖\n");

	if( sscanf(arg, "%s from %s", arg, from)==2 ) {
		env = present(from, me);
		if(!env) env = present(from, environment(me));
    		if(!env || living(env))
      			return notify_fail("你找不到 " + from + " 這樣東西。\n");
		// by acky
		if( env->is_corpse() && env->query("victim_id") ) {
			if( obj = find_player(env->query("victim_id")) )
				tell_object( obj, HIB"你突然有陣怪怪的感覺, " + me->name(1) + "(" + getuid(me) + ")正在挖你的屍體。\n"NOR );
		}
	}
  	else
  		env = environment(me);

	if(sscanf(arg, "%d %s", amount, item)==2) {
    		if( !objectp(obj = present(item, env)) )
      			return notify_fail("這裡沒有這樣東西。\n");
    		if( !obj->query_amount() )
      			return notify_fail( obj->name() + "不能被分開拿走。\n");
    		if( amount < 1 )
      			return notify_fail("東西的個數至少是一個。\n");
    		if( amount > obj->query_amount() )
      			return notify_fail("這裡沒有那麼多的" + obj->name() + "。\n");
    		else if( amount == (int)obj->query_amount() ) {
      			return do_get(me, obj);
    			}
    		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			obj2->move( environment(me) );
			return do_get(me, obj2);
    		}
  	}

  if(arg=="all") {
    if( !env->query_max_encumbrance() )  return notify_fail("那不是容器。\n");

    if( env->query("id")=="corpse" && env->query("killer") && wizardp(env->query("killer")) && !wizardp(me) )
      return notify_fail("不要趁機撿便宜。\n");

    inv = all_inventory(env);
    if( !sizeof(inv) )
      return notify_fail("那裡面沒有任何東西。\n");

    for(i=0; i<sizeof(inv); i++) {
  if( userp(inv[i]) || inv[i]->is_character() )
        continue;
      do_get(me, inv[i]);
    }
    write("Ok。\n");
    return 1;
  }

  if ( !objectp(obj = present(arg, env)) )
    return notify_fail("你附近沒有這樣東西。\n");

  if( userp(obj) || living(obj) )
    return notify_fail("你不能拿起活物。\n");

/*  if ( obj->query("no_get") )
    return notify_fail("這個東西拿不起來。\n");
    */

  return do_get(me, obj);
}

int do_get(object me, object obj)
{
  object old_env;
  int equipped;
  int carry = sizeof(all_inventory(me));
  if( carry >= MAX_CARRY ) return notify_fail("你身上的東西太多了。\n");

  old_env = environment(obj);
  if(obj->query("no_get"))
  {
  if(old_env->query("base_file") != "/obj/user" ||
      find_player(old_env->query("victim_id")) != me
      )
    return notify_fail("這東西拿不起來。\n");
  }
	if( obj->query("equipped") )
		equipped = 1;
	if( me->query("id")!=obj->query("boss") && obj->query("boss") )
		return notify_fail( "此物品只有本人才能拿。\n" );
	if( obj->query("id")=="degu sa" )
		return notify_fail( "還想做弊嗎，真 ooxx 。\n" );
	if( obj->move(me) ) {
		if( me->query("food") > 1 )	me->add( "food", -1 );
		if( me->is_fighting() && userp(me) ) me->start_busy(1);
		if( obj->is_character() )
			message_vision( "$N將$n扶了起來揹在背上。\n", me, obj );
		else
			message_vision( sprintf("$N%s一%s$n。\n",
				old_env==environment(me)? "撿起":
					(old_env->is_character() ?
						"從" + old_env->name() + "身上" + (equipped? "除下" : "搜出"):
						"從" + old_env->name() + "中拿出" ),
						obj->query("unit")), me, obj );
		return 1;
	}
	else
		return 0;
}

int help(object me)
{
  write(@HELP
指令格式 : get <物品名稱> [from <容器名>]
指令說明 :
           這個指令可以讓你撿起地上或容器內的某樣物品。
其他參考 :
           drop，give
HELP);
    return 1;
}

