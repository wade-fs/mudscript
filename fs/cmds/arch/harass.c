//harass.c 本來是要給玩家反迫害的，看哪個大神要拿去用在這方面，歡迎。
//
//這個命令會記錄玩家所見到的訊息！
//
//by wade@FS 89/10/26

inherit F_CLEAN_UP;
int help (object);

int main(object me, string str)
{
  if (!str)
    return (help (me));

  if (str == "stop") {
    me->delete_temp ("記錄");
  }
  else {
    me->set_temp("記錄長度", 0);
    me->set_temp("記錄", str);
  }
  return 1;
}

int help(object me)
{
write(@HELP
指令格式 : harass 檔名|stop

	這個指令會讓巫師記錄他所見到的所有訊息。
	檔案會記錄在 "/log/harass/檔名"
	要停止就下  harass stop
	注意：會造成記錄檔過大的問題。
	      請在啟動檔中設定：
		#define HARASS 100	<-- 100 行

HELP
    );
    return 1;
}
