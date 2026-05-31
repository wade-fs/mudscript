// condition.c
//排版 與新增clean_condition()例外的狀態"money_crazy" by blazakira 2011/9/3
//排版 與新增clean_condition()例外的狀態"wn_move" by blazakira 2011/10/7

mapping conditions;

// This function is called by heart_beat to update "continously active"
// conditions. These conditions will be saved as well. Because such type
// of conditions costs heart beat evaluation time, don't make player got
// too much this kind of conditions or you might got lots fo "Too long
// evaluation" error message in the log file.

nomask int update_condition()
{
  mixed *cnd, err;
  int i, update_flag;
  object cnd_d;

  // 🚀 防禦性修復：如果 conditions 是 Integer 0，自動修正為空 Mapping
  if (intp(conditions) && conditions == 0) conditions = ([ ]);

  if( !mapp(conditions) || !(i=sizeof(conditions)) )
    return 0;
  cnd = keys(conditions);
  while(i--) {

    // In order to not casue player lost heart beat occasionally while
    // calling external condition daemons, we take careful calling
    // convention here.

    cnd_d = find_object(CONDITION_D(cnd[i]));
    if( !cnd_d ) {
      err = catch(call_other(CONDITION_D(cnd[i]), "???"));
      cnd_d = find_object(CONDITION_D(cnd[i]));

      // If we failed to load the external condition daemon, remove
      // it before we stuff log files with error messages.

      if( err || !cnd_d ) {
        log_file("condition.err",
            sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
            CONDITION_D(cnd[i]), this_object(), err)
      );
      map_delete(conditions, cnd[i]);
      continue;
    }
  }

  // We assume since the condition daemon is loaded successfully, the
  // calling on its update_condition() should success as well. Because
  // catch() is somewhat costly, so we don't attempt to catch possible
  // error from the call_other. It is condition daemon's reponsibility
  // that don't cause error in users's heart beat.
  // If condition daemon returns 0 (or update_condition() not defined),
  // we can just assume the condition expired and remove it.

  if( !call_other(cnd_d, "update_condition", this_object(), conditions[cnd[i]]) )
    map_delete(conditions, cnd[i]);
  }
  if( !sizeof(conditions) ) conditions = ([ ]);
}

// apply_condition()
//
// This function applies the specific condition to the character. Note we 
// don't check if the condition already exist before setting condition info.
// It is condition giver's reponsibility to check if the condition should
// override the old one if same condition already exists.(Use query_condition
// to check)

nomask void apply_condition(string cnd, mixed info)
{
  object cnd_d;
  mixed err;
  if(this_object()->query_temp("anti_condition"))    //加入使condition無法apply的狀況
  {
    if(cnd != "god_out" &&cnd !="mogi" && cnd !="giftout" && cnd !="mkpowerup" && cnd !="bloodcloth" && cnd !="power_pill" && cnd !="blade_pill" && cnd !="kang_pill" && cnd !="poison_pill" && cnd !="dodge_pill" && cnd !="white_pill" && cnd !="sword_pill" && cnd !="ghost" && cnd !="crazy" && cnd !="kang_power" && cnd !="powerup" && cnd !="bell" && cnd !="young" && cnd!="force" && cnd != "mon_pill" && cnd != "dhyana")
    {
      return ;
    }
  }
  if( !mapp(conditions) )
    conditions = ([ cnd : info ]);
  else
    conditions[cnd] = info;

  cnd_d = find_object(CONDITION_D(cnd));
  if( !cnd_d ) {
    err = catch(call_other(CONDITION_D(cnd), "???"));
    cnd_d = find_object(CONDITION_D(cnd));

    // If we failed to load the external condition daemon, remove
    // it before we stuff log files with error messages.

    if( err || !cnd_d ) {
      CHANNEL_D->do_channel(this_object(),"sys",sprintf("condition:%s , user=%s",cnd,file_name(this_object())));
      log_file("condition.err",
          sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
          CONDITION_D(cnd), this_object(), err)
      );
      map_delete(conditions, cnd);
    }
  }
}

// query_condition()
//
// This function returns info about the specific condition if any.

nomask mixed query_condition(string cnd)
{
  if (!cnd)
    return conditions;
  if( !mapp(conditions) || undefinedp(conditions[cnd]) )
    return 0;
  return conditions[cnd];
}

nomask void clear_condition( string cnd )
{
  int i,j;
  mixed *con;

  if( !mapp(conditions) || sizeof(conditions) == 0 ) return;

  if( !cnd ) {
    con = keys(conditions);
    for( j=0; j<sizeof(con); j++ ) {
      if( con[j]=="mogi" || con[j]=="lyssa" || con[j]=="giftout" ||
          con[j]=="mkpowerup" || con[j]=="bloodcloth" || con[j]=="power_pill" ||
          con[j]=="blade_pill" || con[j]=="kang_pill" || con[j]=="poison_pill" ||
          con[j]=="dodge_pill" || con[j]=="white_pill" || con[j]=="sword_pill" ||
          con[j]=="ghost" || con[j]=="crazy" || con[j]=="kang_power" || con[j]=="wn_move" ||
          con[j]=="powerup" || con[j]=="bell" || con[j]=="young" || con[j]=="money_crazy" ||
          con[j]=="force" || con[j] =="dhyana" || con[j]=="god_out")
        continue;
      map_delete(conditions, con[j]); 
    }
    if (sizeof(conditions) == 0) conditions = ([ ]);
  }
  else
    map_delete(conditions, cnd);
}
