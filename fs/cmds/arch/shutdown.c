// shutdown.c 修正 by babe

#include <net/daemons.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob, pal;
	int i;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status!="(manager)" && wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("只有 (arch) 以上的巫師才能重新啟動" + MUD_NAME + "\n");

//message( "system", "遊戲重新啟動﹐請稍候一分鐘再 login 。\n", users() );

	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		if( pal=user[i]->query_temp("pal") )
			pal->save();
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();

	shutdown(0);
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : shutdown
指令說明 :
    本命令會讓系統馬上停止一切動作, 當然, 正常情況下是
    跟當機不一樣, 而是先將玩家的資料存檔, 然後再關機.
其他參考 :
    reboot
HELP
  );
  return 1;
}
