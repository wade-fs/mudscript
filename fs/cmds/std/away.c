// away.c by ACKY

int help(object me);
int main( object me, string arg )
{
	int i;
	string msg;
	
    if(!arg && !me->query("away"))
        return help(me);
    if( !arg && (me->query("away")[0]=='1') ) {
		msg = me->query("away")[1..-1];
		me->set( "away", "0"+msg );
		write( "解除 away 狀態。\n");
	}
	else if( !arg ) {
		msg = me->query("away")[1..-1];
		me->set( "away", "1"+msg );
		write("進入 away 狀態。\n"); 
	}
  	else {
		me->set( "away", "1"+arg );
    		write("您的 away 訊息設成 " + arg + "。\n");
 	}
	me->delete("away_msg");
  	return 1;
}

int help( object me )
{
	write(@HELP
	away <訊息> : 設定 away 狀態。

	當別人 tell 您時, 系統自動幫您回覆 away 的訊息。

	若想解除 away 狀態, 只要再下一次 away 指令便可解除。
	如果已輸入過 away 訊息, 只要直接下 away 指令, 而不需
	重複輸入訊息, 便可進入 away 狀態。

	[範例] away 我去一下廁所。
	[說明] 當別人 tell 你時, 將出現"我去一下廁所。"。

	                                        by ACKY 06/01/2000
HELP);
        return 1;

}
