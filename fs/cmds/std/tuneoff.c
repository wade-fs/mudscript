// tune.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *tuned_ch;

	tuned_ch = me->query_temp("tuneoff");
	if( !arg ) {
     if(!sizeof(tuned_ch)) return notify_fail("你現在接收所有種類的訊息。\n");
			write("你現在不收聽的頻道的種類為﹕" + implode(tuned_ch, ", ") + "。\n");
		return 1;
	}
  if(!sizeof(tuned_ch))
    tuned_ch = ({});
	if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 ) {
		write("打開 " + arg + " 頻道種類。\n");
		tuned_ch -= ({ arg });
		me->set_temp("tuneoff", tuned_ch);
		return 1;
	} else {
		tuned_ch += ({ arg });
		me->set_temp("tuneoff", tuned_ch);
		write("你關閉了 " + arg +" 頻道種類。\n");
		return 1;
	}
}

int help(object me)
{
	write(@HELP
指令格式 : tuneoff [<頻道種類>]
指令說明 :
    目前全堿廣播訊息有許多的種類，如果你有不喜歡聽的種類，可以使用
    這個指令關閉。

    目前有的種類為： 
      玩家 pkla,combat
      巫師 login


其他參考 : 
           help channels
HELP
	);
	return 1;
}

