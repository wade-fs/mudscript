// channeld.c wade (6/6/1996)
// music 頻道, 需配合 /cmds/std/song.c 跟 /obj/example/song.c wade (7/7/1996)
// ut, mt, war, ot by ACKY
// ct by swy
// ht, cb, exp5000以下不能用各種頻道 by chan

#include <ansi.h>
#include <net/dns.h>

inherit F_DBASE;

void create()
{
	seteuid(getuid()); // This is required to pass intermud access check.
	set_temp("channel_id", "頻道精靈");
}
void reset()
{
CHANNEL_D->do_channel(this_object(),"sys",HIG"物件重生了!!"NOR);
}


string myclass, myclan;
string record;

mapping channels = ([
	"sys"     : (["msg_speak" : "【系統】%s"NOR": %s\n",
                      "arch_only" : 1 ]),

        "wiz"     : (["msg_speak" : HIW"【"HIY"眾神會議"HIW"】"HIY"%s說道: %s\n"NOR,
                      "wiz_only" : 1 ]),

        "gwiz"    : (["msg_speak" : "【"HIG"網際巫師"NOR"】"HIG"%s說道: %s\n"NOR,
                      "wiz_only": 1,
                      "intermud": GWIZ,
                      "channel" : "CREATOR",
                      "filter" : 1 ]),

        "es"      : (["msg_speak":  "【"HIR"狂想空間"NOR"】"HIR"%s說道: %s\n"NOR,
                      "intermud": GCHANNEL,
                      "channel": "es",
                      "filter": (: $1["MUDLIB"]=="Eastern Stories" :) ]),

	// 增加IP by ACKY
	"twiz"    : (["msg_speak": "【"HIW"台灣巫師"NOR"】"HIW"%s說道: %s\n"NOR,
                      "wiz_only":1,
                      "intermud": GCHANNEL,
                      "channel": "twiz",
                      "filter": (: $1["HOSTADDRESS"][0..2]=="140" ||
				   $1["HOSTADDRESS"][0..2]=="163" ||
				   $1["HOSTADDRESS"][0..2]=="168" ||
				   $1["HOSTADDRESS"][0..2]=="192" ||
				   $1["HOSTADDRESS"][0..2]=="203" ||
				   $1["HOSTADDRESS"][0..2]=="210" ||
				   $1["HOSTADDRESS"][0..2]=="211"
			:)]),

        "chat"    : (["msg_speak": "【"HIC"閒聊"NOR"】"HIC"%s說道: %s\n"NOR]),

	"sex"	  : (["msg_speak": HIY"【"HIR"十八禁頻道"HIY"】%s說道: %s\n"NOR]),

        "music"   : (["msg_speak": GRN"【"HIG"天籟"GRN"】"HIG"%s唱道: %s\n"NOR]),

        "cb"      : (["msg_speak": HIC"【"HIW"幫會協商"HIC"】"HIW"%s談道: %s\n"NOR]),

        "dead"    : (["msg_speak": HIB"【死亡快報】%s%s\n"NOR]),

        "war"     : (["msg_speak": "【"HIR"戰爭"NOR"】"HIR"%s喝道: %s\n"NOR]),

        "ct"     : (["msg_speak": "【"HIY"幫會"NOR"】"HIY"%s說道: %s\n"NOR]),

        "gt"     : (["msg_speak": GRN"【"HIG"公會"GRN"】"HIG"%s說道: %s\n"NOR]),

        "ut"      : (["msg_speak": HIM"【"HIW"至尊"HIM"】"HIW"%s冥想: %s\n"NOR]),

        "ht"      : (["msg_speak": HIY"【"HIM"英雄論談"HIY"】"HIM"%s談道: %s\n"NOR]),

        "mt"      : (["msg_speak": HIY"【"HIG"肉腳對話"HIY"】"HIG"%s說道: %s\n"NOR]),

        "ot"     : (["msg_speak": HIB"【夜總會】"HIG"%s冥想: %s\n"NOR]),

        "shout"   : (["msg_speak": HIR"%s縱聲大叫: %s\n"NOR]),

        "gamble"  : (["msg_speak": "%s\n",
                      "mud_only": 1, ]),

        "mud"     : (["msg_speak": HIG"%s\n"NOR,
                      "mud_only": 1, ]),

        "rumor"   : (["msg_speak": BLU"【"HIB"謠言"BLU"】"HIB"%s: %s\n"NOR,
                      "anonymous": "某人", ]),

        "ct*"     : (["msg_speak": "【"HIY"幫會"NOR"】"HIY""]),

        "wiz*"    : (["msg_speak": HIW"【"HIY"眾神會議"HIW"】"HIY"",
                      "wiz_only": 1 ]),

	"sex*"	  : (["msg_speak": HIY"【"HIR"十八禁頻道"HIY"】"]),

        "chat*"   : (["msg_speak": "【"HIC"閒聊"NOR"】"HIC""]),

        "gt*"     : (["msg_speak": GRN"【"HIG"公會"NOR"】"GRN""]),

        "ut*"     : (["msg_speak": HIM"【"HIW"至尊"HIM"】"HIW]),

        "ht*"     : (["msg_speak": HIY"【"HIM"英雄論談"HIY"】"HIM]),

        "mt*"     : (["msg_speak": HIY"【"HIG"肉腳對話"HIY"】"HIG]),

        "cb*"     : (["msg_speak": HIC"【"HIW"幫會協商"HIC"】"HIW]),

        "ot*"     : (["msg_speak": HIB"【夜總會】"HIG]),
]);

varargs int do_channel( object me, string verb, string arg, int emote )
{
	string *tuned_ch, who, emote_verb, emote_arg, cls , type;
	object *usr;
	int exp, clanrank, age;
  // 作頻道內的分類
  sscanf(verb,"%s:%s",verb,type);
	if( undefinedp(channels[verb]) && !mapp(channels) )
		return notify_fail("無任何頻道存在。\n");
	if(!channels[verb])
 		return 0;

	/*
  if( wizardp(me) && verb == "record" ) {
		if (!arg)
			tell_object( me, "現在錄音況狀是: "+record+"\n");
		else if( arg == "stop" )
			record = 0;
		else if( arg == "wiz" || arg == "chat" ) {
			if( write_file("/log/RECORD/"+arg,
				me->query("id")+" 啟動錄音："+ctime(time()), 1)) {
				record = arg;
				tell_object( me, "現在錄音開始錄 " + arg + " 頻道。\n");
			}
		}
		return 1;
	}
*/
	if( userp(me) ) { //玩家使用頻道的限制
		exp=me->query("combat_exp");
      		clanrank = me->query("clan/rank");
      		myclass  = me->query("class");
      		myclan   = me->query("clan/name");
      		tuned_ch = me->query_temp("channels");
      		age      = me->query("age");

		if( arg == me->query_temp("last_channel_msg") )
		        return notify_fail("說話請不要重複相同的訊息。\n");

   		me->set_temp("last_channel_msg", arg);

      		// 非巫師不能打開巫師頻道
 if( channels[verb]["arch_only"] && wiz_level(me) <= 3 )
			return notify_fail("這是巫師專用頻道。\n");

if( channels[verb]["wiz_only"] && wizardp(me) != 1 )
return notify_fail("這是巫師專用頻道。\n");

      		// 沒幫會不能用 ct By Swy
      		if( verb == "ct" && !myclan )
		        return notify_fail("你尚未加入任何幫會。\n");

		// 沒加入幫會, 無法使用幫會戰爭頻道 by ACKY
		if( verb == "war" && !myclan )
        		return notify_fail("您尚未加入任何幫會。\n");

		if( verb == "gt" && !myclass )
			return notify_fail("你尚未加入任何公會。\n");

		//幫會協商
		if( verb == "cb" && clanrank>3 )
        		return notify_fail("只有位階在[三級]以上者才能使用此頻道。\n");

		if( verb == "mt" && exp>=3000000 )
		        return notify_fail("只有肉腳才能使用此頻道。\n");

		if( verb == "ht" && (exp<3000000) )
     			return notify_fail("您的實戰經驗未滿三百萬, 不算是英雄。\n");

		if( verb == "ut" && (exp<10000000) )
     			return notify_fail("您的實戰經驗未滿一千萬, 無法使用此頻道。\n");

		if( verb == "ot" && ( age < 100 ) )
			return notify_fail( "您未滿一百歲, 別急著加入夜總會。\n" );

     		// 如果未滿15歲不能開"es"頻道
		if( verb == "es" && (int)me->query("age")<15 )
		        return notify_fail("要滿15歲才有使用es頻道的權力。\n");

	        // shoutup 閉嘴指令
 		if( me->query("shutup") )
          		return notify_fail("你已被取消使用公用頻道的權利了。\n");

		// exp在5000以下不能用任何頻道, 防止別人來擾亂!
if( (verb=="shout" || verb=="sex" || verb=="music" || verb=="rumor" || verb=="chat") && (exp<50) )
            return notify_fail("您的實戰經驗未滿50, 無法使用所有的頻道。\n");

      		//設定聽眾
      		usr = filter_array(users(), "listen_me", this_object(), me, verb , type);
	}
	else {
	//mob使用頻道,聽眾是所有user
		if( me->query("master") )
			return 0;
//		usr = users();
      		usr = filter_array(users(), "listen_me", this_object(), me, verb , type);

	}

//以下change by bss,試試看另一種寫法
/*
	// 使用後自動打開該頻道
  	if( pointerp(tuned_ch) )
		if( member_array(verb, tuned_ch)==-1 )
        		me->set_temp("channels", tuned_ch + ({ verb }) );
  	else
     		me->set_temp( "channels", ({ verb }) );
*/
     tuned_ch=me->query_temp("channels");
     if(!pointerp(tuned_ch))
       me->set_temp("channels",({verb}));
     else if(member_array(verb,tuned_ch)==-1)
       me->set_temp("channels",tuned_ch+({verb}));

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


	// 動作訊息
	if( verb == "ht*" || verb == "cb*" || verb == "wiz*" || verb == "ut*" || verb == "chat*" ||
	verb=="sex*"||verb == "ct*" || verb == "gt*" || verb == "war*" || verb == "mt*" || verb == "ot*" ) {
		if( !arg )
			return notify_fail("用法: <動作> <對象> \n");
		if( sscanf( arg, "%s %s", emote_verb, emote_arg ) != 2 )
			emote_verb = arg;
		return( EMOTE_D->do_emote(me,emote_verb,emote_arg,usr,channels[verb]["msg_speak"]) ) ? 1:0;
	}

	// 公會頻道
	if( verb == "gt" ) {
		cls = (me->query("gender") == "女性") ?
			to_chinese("f_"+myclass) : to_chinese(myclass);
		message( "class_channel",
			sprintf(HIG"%s"NOR"%s說道: %s\n"NOR, cls, who, arg ),
			usr );
		return 1;
	}

	// 幫會頻道
	if( verb == "ct" ) {
		message( "clan_channel",
			sprintf("【"HIC"%s"NOR"】"HIY"%s說道: %s\n"NOR, myclan, who, arg ),
			usr );
		return 1;
	}

	// 幫會戰爭頻道
	if( verb == "war" ) {
		message( "clan_channel",
			sprintf("【"HIR"%s"NOR"】"HIR"%s喝道: %s\n"NOR, myclan, who, arg ),
			usr );
		return 1;
	}

	// mud_only 頻道(mud_only頻道沒列出說話者)
	if( channels[verb]["mud_only"] ) {
		message( "channel:" + verb,
			sprintf( channels[verb]["msg_speak"], arg ),
                	usr );
      		return 1;
	}

	// 一般頻道
	message( "channel:" + verb,
		sprintf( channels[verb]["msg_speak"], who, arg ),
		usr );

	if( verb == record )
		write_file( "/log/RECORD/"+record,
			sprintf( channels[verb]["msg_speak"], who, arg ) );

	if( verb == "rumor" && wiz_level(me) <=2 ) {
		write( "由於你到處散佈謠言, 感覺全身虛脫無力……\n");
                if(userp(me)) {
	        me->receive_damage("gin", (me->query("gin"))/5 + random(10));
        	me->receive_damage("kee", (me->query("kee"))/5 + random(10));
        	me->receive_damage("sen", (me->query("sen"))/5 + random(10));
                me->set("startroom","/open/wiz/courthouse");
                }
                else
                {me->unconcious();}
		do_channel(this_object(), "sys",
        		me->name()+"("+me->query("id")+")"+ "散佈謠言道: "+arg, 0);
                write_file("/log/wiz/rumor",sprintf("%s 散佈謠言: %s 於 %s\n",me->query("id"),arg,ctime(time())));
	}


	if( !undefinedp(channels[verb]["intermud"]) && base_name(me) != channels[verb]["intermud"] )
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

// 處理玩家是否接收訊息
int listen_me( object who, object me, string verb ,string type)
{
	if( !environment(who) ) // 分辨已上線完畢沒
      		return 0;

  if(who == me) return 1;
	// 分辨是否tune on
	if( !who->query_temp("channels") || member_array(verb, who->query_temp("channels")) == -1)
		return 0;
  if( who->query_temp("tuneoff") && member_array(type, who->query_temp("tuneoff")) != -1)
    return 0;

	if( channels[verb]["wiz_only"] )
		return wizardp(who);
  // wiz 收任何頻道
  if(wizardp(who) ) return 1;

	// 公會頻道 guild talk
	if((verb == "gt" || verb == "gt*") && who->query("channel/gt")==1 ) return 1;
	if( verb == "gt" || verb == "gt*" )
		return( myclass == who->query("class") ) ? 1 : 0;

	// 幫會頻道 clan talk
	if((verb == "ct" || verb == "ct*") && who->query("channel/ct")==1 ) return 1;
	if( verb == "ct" || verb == "ct*" )
		return( myclan == who->query("clan/name") ) ? 1 : 0;

	// 幫會戰爭頻道 war
	if( verb == "war" || verb == "war*" )
		return( myclan == who->query("clan/name") ) ? 1 : 0;

	// 幫會協商 clan business
	if( verb == "cb" || verb == "cb*" )
		return( who->query("clan/rank")<4 && who->query("clan/rank")>0 ) ? 1 : 0;

	// 至尊 ultimate talk
	if( verb == "ut" || verb == "ut*" )
		return( who->query("combat_exp") >= 10000000 ) ? 1 : 0;

	// 英雄論談 hero talk
	if( verb == "ht" || verb == "ht*" )
		return( who->query("combat_exp") >= 3000000 ) ? 1 : 0;

	// 老人 old men's talk
	if( verb == "ot" || verb == "ot*" )
		return( who->query("age") >= 100 ) ? 1 : 0;

	// 肉腳對話 meat foot talk
	if( verb == "mt" || verb == "mt*" )
		return( who->query("combat_exp") < 3000000) ? 1 : 0;

	return 1;
}
