// auc.c

#include <ansi.h>
#include <room.h>
#include "/open/open.h"

inherit F_CLEAN_UP;

int main( object me, string arg )
{
	int	value;
	string	id, *tuned_ch;
	object	ob, boss, *light, env;

	seteuid(getuid());
        tuned_ch = me->query_temp("channels");
        if( !pointerp(tuned_ch) )
          me->set_temp("channels", ({ "mud" }) );
        else if( member_array("mud", tuned_ch)==-1 )
          me->set_temp("channels", tuned_ch + ({ "mud" }) );
	if(!arg)
	  return notify_fail("不知道格式請help auc\n");
	arg = lower_case(arg);
	env = environment(me);

	if (!catch(load_object(AUROOM))) {
          if (!(boss=find_living("auction boss")) &&
              !(boss=find_object("auction boss")))
          return notify_fail ("老闆出去玩耍了。\n");
 	}
	else return notify_fail ("黑市倒閉了啦，快找巫師來。\n");

  if(arg == "ident")
  {
    boss->ident(me);
  }
  else if( wizardp(me) ) {
		ob = present( arg, me );
		if( !ob ) ob = present( arg, env );
		if( !ob ) return notify_fail( "無此物品。\n" );
		call_other( boss, "do_sell", me, ob );
	}
	else if( sscanf(arg, "%d", value) != 1) {	// 送東西去拍賣

//	if( sscanf(arg, "%d", value) != 1) {	// 送東西去拍賣
	  if ((ob=present(arg, me)) &&
		!ob->query("no_drop") &&
		!ob->query("no_auc") &&
		!ob->query("secured"))
	  {
	    if (ob->query("had_light")) {
	        ob->delete("had_light");
	        ob->delete("short");
		write (sprintf ("當你把%s送去拍賣時，這%s%s漸漸暗淡下來。\n",
		  ob->name(), ob->query("unit"), ob->name()));
	    }
	    if (ob->query("money_id"))
		return notify_fail ("ㄟ....不能拍賣金錢喔, 對不起啦!\n");
	    call_other(boss, "do_sell", me, ob);
	    message_vision("你看到黑市公司的送貨員大老遠的跑來拿走$N手中的"+
			   ob->name()+"\n", me);
	    return 1;
	  }
	  else {
	    tell_object (me, "你想欺騙黑市公司的人員啊。\n");
	    return 1;
	  }
	}
	else if (me->can_afford(value) ) {	// 搶標
	  if( value <= 1800000000 )
	  {
          tell_object (me, "你打電話告訴黑市老闆說，你願意用"+
                           CHINESE_D->cvalue(value)+HIG + "搶標。\n" + NOR);
          call_other(boss, "do_buy", me, value);
//	  me->pay_money(value);
	  }else tell_object(me, HIG + "㊣黑市交易㊣目前規定單筆最大交易金額為十八粒鑽石，搶標下次請早！\n" + NOR);;
	}
	else tell_object (me, "喝! 感情是騙吃騙喝的啊!!\n");
	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: auc <物件>|<錢數>|ident
指令說明 :
           本拍賣系統可以一次丟多件上去，由拍賣公司自行決定要
         拍賣哪件。
           對於正在拍賣的當中，也可以使用本命令搶標。
指令範例 :
           要拍賣可以用   auc <物件>，如 auc sword
           要搶標可以用   auc <金錢>，如 auc 100
           要查看物件資料 auc ident，如 auc ident
特別注意 :
           搶標過程的金錢單位是文錢，由系統自行轉換金幣銀幣.
         例如你要標一兩金子三兩銀子二十文錢，則 auc 10320
         搶標沒有上限，但是每次加的量則跟戰鬥經驗值有關,
         此外，[任何]東西都可以拍賣。
HELP
   );
   return 1;
}
