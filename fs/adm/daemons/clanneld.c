// channeld.c
// 增加各種頻道, 並增加 gage 功能
// wade (6/6/1996)
// 終於把 chat* 修正好了
// 增加 music 頻道, 需配合 /cmds/std/song.c 跟 /obj/example/song.c
// wade (7/7/1996)
// 增加幫派頻道 By Swy

// airke更新板    舊板本在channeld.air
// 1998/9/3
// Chan在修正增加 ht cb 及 exp5000以下不能用各種頻道

#include <ansi.h>
#include <net/dns.h>

inherit F_DBASE;

void create()
{
        seteuid(getuid());  // This is required to pass intermud access check.
        set_temp("channel_id", "頻道精靈");
}


string myclass,myclan;
string record;

mapping channels = ([
        "sys":  (["msg_speak": "【系統】%s: %s\n",
                  "wiz_only": 1 ]),

        "wiz":  (["msg_speak": "【"HIY"眾神會議"NOR"】"HIY"%s: %s\n"NOR,
                  "wiz_only": 1 ]),

        "gwiz": (["msg_speak": "【"HIG"網際巫師"NOR"】"HIG"%s﹕%s\n"NOR,
                  "wiz_only": 1,
                  "intermud": GWIZ,
                  "channel": "CREATOR",
                  "filter": 1 ]),

        "es":   (["msg_speak":  "【"HIR"狂想空間"NOR"】"HIR"%s﹕%s\n"NOR,
                  "intermud": GCHANNEL,
                  "channel": "es",
                  "filter": (: $1["MUDLIB"]=="Eastern Stories" :) ]),

        "twiz": (["msg_speak":  "【"HIW"台灣巫師"NOR"】"HIW"%s﹕%s\n"NOR,
                  "wiz_only":1,
                  "intermud": GCHANNEL,
                  "channel": "twiz",
                  "filter": (: $1["HOSTADDRESS"][0..2]=="140" :) ]),

        "chat":  (["msg_speak": "【"HIC"閒聊"NOR"】"HIC"%s說道: %s\n"NOR]),


        "music":  (["msg_speak": "【"HIG"天籟"NOR"】"HIG"%s 唱道: %s\n"NOR]),

        "cb":  (["msg_speak": HIC"【"HIW"幫派協商"HIW"】"HIC"%s 談道: %s\n"NOR]),

        "dead":  (["msg_speak": "【"HIR"死亡快報"NOR"】"HIR"%s 爽快地公諸於世 ： %s\n"NOR]),

        "ht":   (["msg_speak": HIY"【"+HIG+"大俠廣播"+HIY"】大俠 %s說道: %s\n"NOR]),
        
        "shout":(["msg_speak": HIR"%s縱聲大叫: %s\n"NOR]),

        "gamble":(["msg_speak": "%s\n",
                   "mud_only": 1, ]),

        "mud":  (["msg_speak": HIG"%s\n"NOR,
                  "mud_only": 1, ]),

        "rumor":(["msg_speak": "【"HIM"謠言"NOR"】"HIM"%s: %s\n"NOR,
                  "anonymous": "某人", ]),

        "rumor*":(["msg_speak": "【"HIM"謠言"NOR"】"HIM""]),

        "ct*":(["msg_speak": "【"HIY"幫派"NOR"】"HIY""]),

        "wiz*": (["msg_speak": "【"HIY"眾神會議"NOR"】"HIY"",
                  "wiz_only": 1        ]),

        "chat*":  (["msg_speak": "【"HIC"閒聊"NOR"】"HIC""]),

        "gt*":(["msg_speak": "【"HIG"公會"NOR"】"HIG""]),

        "gt":(["msg_speak": "【"HIG"公會"NOR"】"]),
        
        "ct":(["msg_speak": "【"HIY"幫派"NOR"】"]),

        "ht*":   (["msg_speak": HIY"【"+HIG+"大俠廣播"+HIY"】"]),

        "cb*":  (["msg_speak": HIC"【"HIW"幫派協商"HIC"】"]),

]);





varargs int do_channel(object me, string verb, string arg, int emote)
{
  
  string *tuned_ch, who, emote_verb, emote_arg,cls;
  object *usr;
  int exp,clanrank;

  if (wizardp(me) && verb == "record") {
    if (!arg) tell_object (me, "現在錄音況狀是："+record+"\n");
    else if (arg == "stop") record = 0;
    else if (arg == "wiz" || arg == "chat") {
      if (write_file ("/log/RECORD/"+arg,
        me->query("id")+" 啟動錄音："+ctime(time()), 1))
      {
        record = arg;
        tell_object (me, "現在錄音開始錄 " + arg + " 頻道。\n");
      }
    }
    return 1;
  }

  if( undefinedp(channels[verb]) && !mapp(channels))
    return notify_fail("無任何頻道存在。\n");
  if(!channels[verb])
    return 0;


  if( userp(me) ) //玩家使用頻道的限制
  {                               

      exp=me->query("combat_exp");
      clanrank=me->query("clan/rank");
      myclass=me->query("class");
      myclan=me->query("clan/name");
      tuned_ch = me->query_temp("channels");

      if( arg==me->query_temp("last_channel_msg") )
         return notify_fail("說話請不要重複相同的訊息。\n");

      me->set_temp("last_channel_msg", arg);

      // 非巫師不能打開巫師頻道
      if( channels[verb]["wiz_only"]
       && !wizardp(me) )
        return notify_fail("這是巫師專用頻道。\n");

      // 沒幫派不能用 ct By Swy
      if(verb == "ct" && !myclan)
        return notify_fail("你尚未加入任何幫派。\n");
      
      if(verb == "gt" && !myclass)
        return notify_fail("你尚未加入任何公會。\n");
      //幫派協商頻導
      if(verb == "cb" && (clanrank > 2))
        return notify_fail("你幫派層級不足!!無法使用此頻道。\n");

      if(verb == "ht" && (exp<3000000))
        return notify_fail("你經驗值未滿三百萬!!不算是大俠!!。\n");
      
      // 如果未滿15歲不能開"es"頻道
      if( verb =="es"
       && (int)me->query("age")<15 )
        return notify_fail("要滿15歲才有使用es頻道的權力。\n");

      //新增: shoutup 閉嘴指令
      if(me->query("shutup"))
          return notify_fail("你已經被取消使用公用頻道的權利了!\n");
      if(exp < 5000)
      //新增exp在5000以下不能用任何頻道,防止別人來擾亂!!!!
          return notify_fail("你經驗值未滿5000無法使用所有的頻道!!!\n");

      //設定聽眾
      usr = filter_array(users(), "listen_me", this_object(), me, verb);
  } else {
      //mob使用頻道,聽眾是所有user
      usr = users();
  }
  
  // 使用後自動打開該頻道
  if( pointerp(tuned_ch) )
  {
     if( member_array(verb, tuned_ch)==-1 )
        me->set_temp("channels", tuned_ch + ({ verb }) );
  } 
  else
     me->set_temp("channels", ({ verb }) );

  // 玩家可以打開 mud 頻道收聽, 但是不能使用 mud 頻道
  if ( channels[verb]["mud_only"] && !wizardp(me) && userp(me) )
     return 1;
    

  //  處理who 變數
  if( channels[verb]["anonymous"] )
    who = channels[verb]["anonymous"];
  else
    if( !(who = me->query_temp("channel_id") ) )
      if( !(who = me->query("channel_id") ) )
        who = me->query("name") + "(" + (me->query("id")) + ")";

  arg = ( stringp(arg) ) ? trans_color(arg) : "...";

 
//以下是各頻道送出訊息


//emote
  if( verb == "ht*" ||verb == "cb*" ||verb == "chat*" || verb== "wiz*" || verb== "ct*" || verb =="rumor*" || verb == "gt*")
  {
    if (!arg )
      return notify_fail("用法: <動作> <對象> \n");
    if( sscanf (arg, "%s %s", emote_verb, emote_arg) != 2 )
      emote_verb = arg;

    return ( EMOTE_D->do_emote(me,emote_verb,emote_arg,usr,channels[verb]["msg_speak"]) ) ? 1:0;
  }


 
//公會頻道
  if( verb == "gt" )
  {
      cls = (me->query("gender") == "女性") ? to_chinese("f_"+myclass) :
                                                to_chinese(myclass) ;
      message( "class_channel",
               sprintf(HIG"%s"NOR"%s說道: %s\n"NOR, cls, who, arg ),
               usr );
      return 1;
  }

//幫派頻道
  if( verb == "ct" )
  { 
      message( "clan_channel",
               sprintf(HIY"【"HIC"%s"HIY"】%s說道: %s\n"NOR, myclan, who, arg ),
               usr );
      return 1;
  }  

// mud_only 頻道(mud_only頻道沒列出說話者)
  if( channels[verb]["mud_only"] )
  {
      message( "channel:" + verb,
               sprintf( channels[verb]["msg_speak"], arg ),
                usr );
      return 1;
  }


// 一般頻道 
  message( "channel:" + verb, sprintf( channels[verb]["msg_speak"],
               who, arg ), usr );
  if (verb == record)
    write_file ("/log/RECORD/"+record, sprintf( channels[verb]["msg_speak"],
               who, arg ) );
   
      


  if( (verb == "rumor"|| verb == "rumor*")
       && wiz_level(me) <=1)
  {
        write ("由於你到處散佈謠言, 感覺全身虛脫無力.\n");
        me->receive_damage("gin", 10);
        me->receive_damage("kee", 10);
        me->receive_damage("sen", 10);
        do_channel(this_object(), "sys",
        me->name()+"("+me->query("id")+")"+ "散佈謠言道: "+arg, 0);
  }
    

    if( !undefinedp(channels[verb]["intermud"])
     &&  base_name(me) != channels[verb]["intermud"] )
      channels[verb]["intermud"]->send_msg(channels[verb]["channel"],
            me->query("id"),me->name(1),arg,0,channels[verb]["filter"] );
    return 1;




 return 0;
/*
  if( channels[verb]
   && !undefinedp(channels[verb]["intermud"])
   &&  base_name(me) != channels[verb]["intermud"] )
    channels[verb]["intermud"]->send_msg(channels[verb]["channel"],
           me->query("id"),me->name(1),arg,0,channels[verb]["filter"] );
    return 1; */
}



//處理玩家是否接收訊息

int listen_me(object who, object me, string verb)
{
  
  if( !environment(who) )  // 分辨已上線完畢沒
      return 0;
  
//現在gage好像沒用....先封了
//  if(who->gage(me))
//      return 0;
 
  //分辨是否tune on
  if( !who->query_temp("channels")
        || member_array(verb, who->query_temp("channels")) == -1)
      return 0;
  
  if( channels[verb]["wiz_only"] )
      return wizardp(who);  
  

  //公會頻道
  if (verb == "gt" || verb == "gt*" )
      return (myclass == who->query("class"))?1:0;   
  //幫派頻道
  if (verb == "ct" || verb == "ct*") 
      return (myclan == who->query("clan/name"))?1:0; 


  return 1;
}
