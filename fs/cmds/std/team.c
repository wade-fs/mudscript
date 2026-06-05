// team.c

#include <ansi.h>

inherit F_CLEAN_UP;
mapping level = ([
  0:BLU + "【 Ｆ 】" + NOR,
  1:HIB + "【 Ｅ 】" + NOR,
  2:MAG + "【 Ｄ 】" + NOR,
  3:CYN + "【 Ｃ 】" + NOR,
  4:HIC + "【 Ｂ 】" + NOR,
  5:HIW + "【 Ａ 】" + NOR,
  6:HIR + "【 Ｓ 】" + NOR,
  ]);

int count_total_power_lv(object leader);
int count_lv(int power);
int main(object me, string arg)
{
  mapping map;
  object *t;
  string team_name;
  object team_leader;
  object ob1;
  object leader;
  object *member;
  object *mmm;
  string str;
  string targ;
  object *list;
  int team_cnt=0;
  int i,z;

  seteuid(getuid());

  if( !arg ) {
    if( !pointerp(t = me->query_team()) )
      return notify_fail("你現在並沒有參加任何隊伍。\n");
    team_leader=me->query_temp("leader");
    team_name=team_leader->query_temp("team_name");
    write("隊名﹕"+team_name+"\n");
    write("領隊﹕"+team_leader->name()+"\n");
      write("你現在隊伍中的成員有﹕\t氣\t關係     [兵種/帶兵量]\n");
    for( i=0; i<sizeof(t); i++ )
/*
write("  " + "\t"+ t[i]->name(1) + "\t\t"+t[i]->query("kee") +"\t" + me->query("人際關係/"+t[i]->query("id")) +
((t[i]->query("war"))?sprintf("  [%s/%d 人]",t[i]->query("war/兵種"),t[i]->query("war/兵力值")):"")+"\n");
*/
printf("%-22s  %-5d   %-5d  %s \n",
 t[i]->name(1),t[i]->query("kee"), me->query("人際關係/"+t[i]->query("id")),
((t[i]->query("war"))?sprintf("  [%s/%d 人]",t[i]->query("war/兵種"),t[i]->query("war/兵力值")):""));
    return 1;
  }
  if( arg=="query" )
  {
    str="◎ 狂想空間\n";
    str+=sprintf("%-20s%-15s%-10s %-10s%-10s\n","隊名","領隊","ID","隊員人數","強度等級");
    str+="───────────────────────────────────\n";
    list=users();
    for(i=0;i<sizeof(list);i++)
      if(list[i]->is_team_leader())
      {
        team_cnt++;
        leader=list[i];
        str+=sprintf(HIY+"%-20s"+HIC+"%-15s%-10s"+HIW+" %|10d"+"%-10s",list[i]->query_temp("team_name"),list[i]->name(),list[i]->query("id"),sizeof(list[i]->query_team()),level[count_lv(count_total_power_lv(leader))]);
      str+="\n";
      }
    str+="───────────────────────────────────\n";
    str+=sprintf("目前狂想空間共有 %d 支隊伍。\n",team_cnt);
    if(team_cnt>0)
    write(str);
    else write("目前狂想空間沒有任何隊伍。\n");
    return 1;
  }
  if( arg=="dismiss" ) {
    if(me->query_temp("use_form")==1)
      return notify_fail("你的夥伴們現在正在集合力量﹐你忍心脫離 ?\n");
    if( !pointerp(t = me->query_team()) )
      return notify_fail("你現在並沒有參加任何隊伍。\n");
    if( me->is_team_leader() ) {
      message("team", me->name(1) + "將隊伍解散了。\n", t, me);
      write("你將隊伍解散了。\n");
    } else {
      message("team", me->name(1) + "決定脫離隊伍。\n", t, me);
      write("你脫離了你的隊伍。\n");
    }
    team_leader=me->query_temp("leader");
                if(sizeof(team_leader->query_team())==2 && !me->is_team_leader()) //判斷隊伍中是否剩下自己與隊長兩人
                  {                    
                    team_leader->dismiss_team();
                    tell_object (team_leader,HIY + "你的隊伍成員全數脫離隊伍，隊伍解散了!!\n" + NOR);
                  }else
    me->dismiss_team();
    return 1;
  }
  if( sscanf(arg, "find %s", arg)==1) {
    if(!find_player(arg))  return notify_fail("你要尋找的隊伍不存在\n");   
    leader=find_player(arg);
    if(wizardp(leader)) return notify_fail("你要尋找的隊伍不存在\n");
    if( !pointerp(t = leader->query_team()) )
      return notify_fail("你要找的人沒有組織或參加隊伍\n");
    team_leader=leader->query_temp("leader");
    team_name=team_leader->query_temp("team_name");
    str=sprintf("你查詢%s所屬隊伍\n",leader->name());
    str+=sprintf("隊名﹕%s\n",team_name);
    str+=sprintf("領隊﹕%s\n",team_leader->name());
    str+=sprintf("%s現在隊伍中的成員有\n",leader->name());
    for( i=0; i<sizeof(t); i++ ) {
       if(t[i]->query("clan/name"))
         str+=sprintf("%|10s",t[i]->query("clan/name"));
       else
	 str+="          ";
       if( t[i]->query("class") && t[i]->query("class") == "officer" )
           str+="  朝廷命官  ";
       else if(t[i]->query("family/family_name"))
           str+=sprintf("%|12s",t[i]->query("family/family_name"));
       else
           str+="  普通百姓  ";
       str+=sprintf("%16s(%|10s)\n",t[i]->name(1),t[i]->query("id"));
    }
    write(str);
    return 1;
  }	
  if( sscanf(arg, "name %s", arg)==1) {
    if(!me->is_team_leader())  return notify_fail("只有領隊可以設定隊名。\n");
    me->set_temp("team_name",arg);
    write("設定隊名為"+arg+"\n");
    return 1;
  }
  if (sscanf(arg, "with %s", arg)==1) {
    object ob;

    if (!(ob = present(arg, environment(me)))
    ||  !living(ob)
    ||  !ob->is_character()
    ||  ob==me )
      return notify_fail("你想和誰成為夥伴﹖\n");
                
    // 非成員，或非領隊
    if (!pointerp(me->query_team()) || me->is_team_leader()) {
      if (t = me->query_team()) {
        str = ",";
        for (i=0; i<sizeof (t); i++) {
          if (strsrch (str, "," + query_ip_number (ob) + ",") >= 0) {
            write ("請勿邀請與組員同 IP 的人加入。\n");
            return 1;
          }
          str += query_ip_number(t[i])+",";
          write ("組員 IP: " + str + "\n");
        }
      }
      if (query_ip_number(me) == query_ip_number(ob)) {
        write ("不得邀請與你同 IP 的人加入。\n");
        return 1;
      }

      // 允許別人加入，或加入某人
      if (me == (object)ob->query_temp("pending/team")) {
        // 加入某人隊伍
        if (!pointerp(t = me->query_team())) {
          ob->add_team_member(me);
          message_vision("$N決定加入$n的隊伍。\n", me, ob);
          ob->set_temp("leader",ob);
          me->set_temp("leader",ob);
          me->set_leader(ob);
          if (!ob->query_temp("team_name")) 
            ob->set_temp("team_name","未定");
        }
        // 讓某人加入
        else {
          me->add_team_member(ob);
          ob->set_temp("leader",me);
          ob->set_leader(me);
          me->set_temp("leader",me);
          if (!me->query_temp("team_name"))
            me->set_temp("team_name","未定");
          message_vision("$N決定讓$n加入隊伍。\n", me, ob);
        }
        ob->delete_temp("pending/team");
        return 1;
      }

      // 邀請某人加入
      else {
        message_vision("$N邀請$n加入$P的隊伍。\n", me, ob);
        tell_object(ob, YEL + "如果你願意加入﹐請用 team with " + me->query("id") + "。\n" + NOR);
        me->set_temp("pending/team", ob);
        return 1;
      }
    }
    else
      return notify_fail("只有隊伍領袖可以邀請別人加入。\n");
  }
  if( sscanf(arg, "talk %s", arg)==1 ) {
    if( !pointerp(t=me->query_team()) )
      return notify_fail("你現在並沒有和別人組成隊伍。\n");
    message("team", HIW + "【隊伍】" + me->name(1) + "﹕" + arg + "\n" + NOR, t);
    return 1;
  }
  if( sscanf( arg, "form %s at %s", arg, targ ) == 2 ) {
            object obj1;
    map = me->query_skill_map();
    if( undefinedp(map["array"]) )
      return notify_fail( "你目前並無使用陣法。\n" );
    if( map["array"] == "bad-array" && me->query("family/family_name") != "惡人谷" )
      return notify_fail( "你無法使用惡人邪陣。\n" );
    if( map["array"] == "sha-array" && me->query("family/family_name") != "仙劍派" )
      return notify_fail( "你無法使用仙劍劍陣。\n" );

    if( !pointerp( t=me->query_team() ) || !me->is_team_leader() )
      return notify_fail( "你必須是一個隊伍的領袖才能組織陣形。\n" );
    if( !me->query_skill( arg, 1 ) )
      return notify_fail( "這種陣形你沒學過。\n" );
    mmm=me->query_team();
    targ = lower_case(targ);
    ob1 = present( targ, environment(me) );
    if (!ob1) return notify_fail("找不到"+targ+"!!\n");
    if (!ob1->is_character() || ob1->is_corpse())
      return notify_fail("看清楚一點﹐那並不是活物。\n");
    message_vision( "$N所領的隊伍擺\開陣式對$n展開攻擊!\n", me, ob1 );
    me->set_temp("arrayp",1);          //不管leader是何門何派,使用陣法就有5 sec無法使用特功
    call_out("remove_arrayp",5,me);    //因為有這個所以取消下面對仙劍的限制
    for( z=0; z<sizeof(me->query_team()); z++ )
      mmm[z]->kill_ob(ob1);
    return SKILL_D(arg)->form_array(me);
 
// appo 對shasword leader 所加上的限制..避免用hsa_kee
//         if( leader->query("family/family_name") != "仙劍派")
//{
//   leader->set_temp("no_power",1);
//   leader->apply_condition("no_power",1);
//}
  }
}

int help(object me)
{
  write(@HELP
隊伍指令使用方法:

team name <名稱>           - 設定隊伍名稱。
team with <某人>           - 跟某人組成隊伍。必須要雙方都同意加入才會生效。
team dismiss               - 離開隊伍。若下此指令的是領隊，則整個隊伍會解散。
team talk <訊息>           - 跟隊伍裡其他的人談話，可以用 tt <訊息> 替代。
team form <陣法> at <目標> - 如果隊伍的領隊學過陣法的話﹐可以將隊伍中的成員
                             組織成某種陣形﹐組成陣形的狀態只要領袖一移動
                             就會解除。
team query                 - 查詢目前有那些玩者組成的隊伍。
team find <某人>           - 查詢玩家的隊伍陣容

直接下 team 指令時則會顯示你目前是否有加入隊伍及隊員名單。
HELP
  );
  return 1;
}
int count_total_power_lv(object leader)
{
  int total=0;
  object *member;
  int i;
  member=leader->query_team();
  for(i=0;i<sizeof(member);i++)
    total+="/daemon/skill/array"->get_attack_skill_lv(member[i])+member[i]->query_temp("apply/attack");
  return total;
}
int count_lv(int power)
{
  if(power<30) return 0;
  if(power<300) return power/50;
  return 6;
}
int remove_arrayp(object me)
{
  if (me) me->delete_temp("arrayp",1);
  return 1;
}


