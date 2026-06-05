// say.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  if(me->query_temp("no_roar")){
    write("因為蠍毒的作用，你一句話也說不出來。\n");
    return 1;
  }


	if (!arg) {
		write("你自言自語不知道在說些什麼。\n");
		message("sound", me->name() + "自言自語不知道在說些什麼。\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("kee") < (int)me->query("max_kee") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}

	arg = trans_color(arg);

write("『"+HIG+"暢談"+NOR+"』"+HIY+"你說道: " + arg + "\n" + NOR); 
say("『"+HIG+"暢談"+NOR+"』"+HIY+me->name() + "說道: " +  arg + "\n" + NOR, 
		environment(me), me);
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式 : say <訊息>
指令說明 : 
           說話﹐所有跟你在同一個房間的人都會聽到你說的話。
 
註 : 本指令可用單引號 ' 取代。
HELP
	);
	return 1;
}
