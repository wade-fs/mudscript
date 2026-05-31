// by ~babe~ (小雪球) ^O^
#include <ansi.h>
inherit F_CLEAN_UP;
int help (object me);
int main (object me, string str)
{
	string  id, title;
	int  rank_o,rank, temp,i=0, ppl_cnt, j;
	object who, *inv, ob, user, *list, wiz;
/*
  if (me->query("id")=="acky") {
    list= children("/obj/user");		
    ppl_cnt = sizeof(list);
    j = ppl_cnt;
    tell_object (me, sprintf("--%d--",j));

    while (j--) {
      if (!environment(list[j]))
        write("(null)");
      tell_object (me, sprintf("%s(%s)\n",
        list[j]->query("name"), list[j]->query("id")));
      if (list[j]->query("id")==str) {
        who= list[j];
        tell_object (me, sprintf("!!%s(%s)!!\n",
          who->query("name"), who->query("id"))); 
      }
    }
    write("\n");
    return 1;
  }*/

	if( !str )
		return notify_fail("指令格式：c_appoint <id> <階級> <職銜>\n");
	if( sscanf(str, "%s %d %s", id, rank, title) != 3 )
		return notify_fail("指令格式：c_appoint <id> <階級> <職銜>\n");
	if( me->query("clan/rank") > 4 )
		return notify_fail("您無權使用此指令。\n");
	if( strlen(title) > 10 )
		return notify_fail("職銜最長只能五個字。\n");
	if( me->query("clan/rank") >= rank)
		return notify_fail("您只能任命位階比您低的職位。\n");
	if( (rank<2) || (rank>7) )
		return notify_fail("所能任命的階級只能為(2~7)六級。\n");
	if( !who = FINGER_D->acquire_login_ob(id) )
		return notify_fail("沒有這個人。\n");

  who = find_player(id);

  if (!who) {
    list = children("/obj/user");		
    ppl_cnt = sizeof(list);
    j = ppl_cnt;
    while (j--)
      if (environment(list[j])&& list[j]->query("id")==id) {
        who= list[j];
        break;    
      }
  }
/*
  if (who->query_temp("unconcious")) {
    log_file ("cmd/cheat_log", sprintf ("%s %s %s(%s)->%s(%s)\n",
      ctime(time()), who->query("clan/name"), me->query("name"), me->query("id"), who->query("name"), who->query("id")));
    return notify_fail ("");
  }
*/
  if (!who) {
		ob="/adm/daemons/cappointd.c"->get_user_ob(id);
		user="/adm/daemons/cappointd.c"->get_user_body(ob);
		user->set_temp("link_ob", ob);
		user->setup();
    if(sizeof(all_inventory(user))) all_inventory(user)->set("autoload",1);
		who=user;
		i=1;
	}

  if( !who->is_character() || me->query("id")==id )
			return notify_fail("請不要開玩笑。\n");
		if( who->query("clan/name") != me->query("clan/name") )
			return notify_fail("對方並不和你同幫派。\n");
		switch( rank ) {
		case 2: temp = 4000000; break;
		case 3: temp = 2000000; break;
		case 4: temp = 1000000; break;
		case 5: temp =  500000;	break;
		case 6: temp =       0;	break;
		case 7: temp =       0;	break;
	}
	if( me->query("clan/rank") >= who->query("clan/rank") )
		return notify_fail("您只能任命位階比您低的職位。\n");
	if( who->query("combat_exp") < temp )
		return notify_fail("對方的江湖歷練不足以勝任此職務。\n");
	if( !CLAN_D->clan_promote(me->query("clan/id"), who->query("id"), "level"+rank))
		return notify_fail("此階級已額滿。\n");
	rank_o = who->query("clan/rank");
	who->set("clan/rank",rank);
	who->set("clan/title",title);
	if( rank < rank_o )
		CHANNEL_D->do_channel(me, "ct",
			"\n\t我 -「"HIW+me->query("clan/title")+HIY"」鄭重的宣佈……\n\t提拔"+
			who->query("name")+"("+who->query("id")+")為「"HIC+who->query("clan/title")+HIY"」。"NOR);
	else if( rank > rank_o )
		CHANNEL_D->do_channel(me, "ct",
			"\n\t我 -「"HIW+me->query("clan/title")+HIY"」鄭重的宣佈……\n\t將"+
			who->query("name")+"("+who->query("id")+")貶為「"HIC+who->query("clan/title")+HIY"」。"NOR);
	else
		CHANNEL_D->do_channel(me, "ct",
			"\n\t我 -「"HIW+me->query("clan/title")+HIY"」鄭重的宣佈……\n\t將"+
			who->query("name")+"("+who->query("id")+")調任「"HIC+who->query("clan/title")+HIY"」。"NOR);
  if (i) {
    who->save();
    destruct(who);
  }
	return 1;
}

int help (object me)
{
	write(@HELP
	c_appoint <ID> <位階> <職銜>

	任命某人的位階及職銜，高階者可以任命低階者。

	<位階> 請輸入數字(2~7)
	<職銜> 請輸入中文(1~5字)

	各階級之人數限定 -
		階級２：二人	經驗值-四百萬
		階級３：四人	經驗值-二百萬
		階級４：八人	經驗值-一百萬
		階級５：不限	經驗值-五拾萬
		階級６：不限	經驗值-　不限
		階級７：不限	經驗值-　不限
HELP    );
	return 1;
}
